/*
Problem: Separate Squares II
Link: https://leetcode.com/problems/separate-squares-ii/description/
Difficulty: Hard
Topic: Geometry / Binary Search / Sweep Line / Segment Tree

Problem Statement:
You are given a 2D integer array `squares`, where each `squares[i] = [xi, yi, li]`
represents the coordinates of the bottom-left point `(xi, yi)` and the side length `li`
of a square parallel to the x-axis.

Find the **minimum y-coordinate value** of a horizontal line such that the **total area
covered by squares above the line equals the total area covered by squares below the line**.
Squares may overlap, and **overlapping areas are counted only once** in this version.  
Answers within `1e-5` of the actual answer are accepted. :contentReference[oaicite:0]{index=0}

Approach (Binary Search on y + Sweep Line Union Area Calculation):
1. Convert each square into a rectangle: `[x, y] → [x, y+l]` with width `l`.  
2. The target is to find the smallest `h` such that the **union area below** `y=h`  
   is equal to **half of the total union area** of all squares.
3. **Precompute total union area** of all squares using a sweep line along y with a  
   segment tree to track *covered x-lengths*.
4. Binary search `h` between the minimum bottom and maximum top of all squares.
5. For each candidate `mid`, compute *union area below `mid`*:
   - Clip each square’s top to `mid` → treat clipped rectangles
   - Sweep events by y, maintaining covered x-length using a segment tree
   - Accumulate area segments until you reach `mid`
6. If *areaBelow(mid) < halfTotal*, increase `low`; otherwise `high = mid`.

Time Complexity: O(N log N) — sorting events + segment tree updates  
Space Complexity: O(N) — events + segment tree arrays
*/

#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
public:
    double separateSquares(const vector<vector<int>>& in_squares) {
        // using SegTree = SegTreeLazy; // 240ms
        using SegTree = SegTreeSimple; // 200ms

        // Coordinate compression for x-coordinates
        vector<int> comp2x;
        for (const auto& v : in_squares) {
            comp2x.push_back(v[0]);
            comp2x.push_back(v[0] + v[2]);
        }
        sort(comp2x.begin(), comp2x.end());
        comp2x.erase(unique(comp2x.begin(), comp2x.end()), comp2x.end());

        auto squares = in_squares
            | views::transform(
                [&comp2x](const auto& v) {
                    return Square{
                        v[0], v[1], v[2],
                        static_cast<int>(::distance(
                            comp2x.begin(), ::lower_bound(comp2x.begin(), comp2x.end(), v[0]))),
                        static_cast<int>(::distance(
                            comp2x.begin(), ::lower_bound(comp2x.begin(), comp2x.end(), v[0] + v[2])))};
                })
            | ::ranges::to<vector>();

        // Create events for sweeping: each square generates two events (top and bottom)
        vector<SquareTopBottom> sq_tb;
        sq_tb.reserve(squares.size() * 2);
        for (const auto& sq : squares) {
            sq_tb.emplace_back(&sq, true);
            sq_tb.emplace_back(&sq, false);
        }
        ::sort(sq_tb.begin(), sq_tb.end());

        // Perform sweep line algorithm, creating accumulation stages
        // Each stage represents the covered x-length at a specific y-range
        const auto acc_stages = sq_tb
            | ::views::chunk_by([](const auto& a, const auto& b) { return a.y == b.y; })
            | ::views::transform([&sq_tb, segt = SegTree(comp2x)](const auto& chunk) mutable {
                long long cur_y = chunk.back().y;
                long long nxt_y = &chunk.back() == &(sq_tb.back()) ? cur_y : (&chunk.back() + 1)->y;
                for (const auto& sq : chunk) // Update with events at this y-coordinate
                    segt.inc(sq.sq->x_comp_beg, sq.sq->x_comp_end - 1, sq.is_beg ? 1 : -1);
                // Current stage: y-range and covered x-length
                return SquareAccumulateStage{cur_y, nxt_y, segt.get_length_x()};
            })
            | ::ranges::to<vector>();

        // Calculate total area and find where half of it is reached
        double remain_sq = 0.5 * accumulate(
            acc_stages.begin(), acc_stages.end(), 0.0,
            [](double acc, const auto& stage) { return acc + (stage.nxt_y - stage.cur_y) * stage.len_x; });
        // Find the exact y-coordinate where half the area is reached
        for (const auto& stage : acc_stages) {
            double stage_sq = (stage.nxt_y - stage.cur_y) * stage.len_x;
            if (stage_sq > remain_sq - kEps)
                return stage.cur_y + remain_sq / stage.len_x; // Linear interpolation within stage
            remain_sq -= stage_sq;
            if (abs(remain_sq) < kEps) return stage.nxt_y; // Exact match
        }
        return acc_stages.back().cur_y;
    }

private:
    static constexpr double kEps = 1e-5;

    struct Square {
        long long x, y, side;
        int x_comp_beg = -1, x_comp_end = -1;
    };

    struct SquareTopBottom { // Event for sweep line
        const Square* sq;
        bool is_beg = true;
        long long y;
        SquareTopBottom(const Square* sq, bool is_beg)
            : sq(sq), is_beg(is_beg), y(is_beg ? sq->y : sq->y + sq->side) {}
        bool operator<(const SquareTopBottom& other) {
            if (y != other.y) return y < other.y;
            return sq->x < other.sq->x;
        }
    };

    struct SegTreeLazy { // Segment tree with lazy propagation
        const vector<int>& comp2x;
        vector<int> covr, lazy_covr; // aggregate as min
        vector<long long> xacc; // aggregate as sum
        int half_size;
        SegTreeLazy(const vector<int>& comp2x) : comp2x(comp2x) {
            int pow = 0;
            while ((1 << pow) < comp2x.size())
                ++pow;
            half_size = 1 << pow;
            covr.resize(half_size * 2);
            lazy_covr.resize(half_size * 2);
            xacc.resize(half_size * 2);
        }

        long long get_length_x() const { return xacc[1]; }

        void inc(int beg, int end, int delta) { inc_impl(1, 0, half_size - 1, beg, end, delta); }

        void inc_impl(int node, int left, int rght, int beg, int end, int delta) {
            if (beg <= left && rght <= end) {
                lazy_covr[node] += delta;
                delta = 0;
            }

            if (lazy_covr[node]) {
                if (left < rght) {
                    lazy_covr[node * 2] += lazy_covr[node];
                    lazy_covr[node * 2 + 1] += lazy_covr[node];
                }
                covr[node] += lazy_covr[node];
                lazy_covr[node] = 0;
                xacc[node] =
                    covr[node] ? comp2x[rght + 1] - comp2x[left] :
                    left < rght ? xacc[node * 2] + xacc[node * 2 + 1] :
                    0;
            }

            if (rght < beg || left > end || left == rght) return;

            if (beg <= left && rght <= end && covr[node] > 0) {
                xacc[node] = comp2x[rght + 1] - comp2x[left];
                return;
            }

            int mid = (left + rght) / 2;
            inc_impl(node * 2, left, mid, beg, end, delta);
            inc_impl(node * 2 + 1, mid + 1, rght, beg, end, delta);
            xacc[node] = xacc[node * 2] + xacc[node * 2 + 1];
        }
    };

    struct SegTreeSimple { // Optimized segment tree implementation
        const vector<int>& comp2x;
        vector<int> covr; // aggregate as min
        vector<long long> xacc; // aggregate as sum
        int half_size;
        SegTreeSimple(const vector<int>& comp2x) : comp2x(comp2x) {
            int pow = 0;
            while ((1 << pow) < comp2x.size())
                ++pow;
            half_size = 1 << pow;
            covr.resize(half_size * 2);
            xacc.resize(half_size * 2);
        }

        long long get_length_x() const { return xacc[1]; }

        void inc(int beg, int end, int delta) { inc_impl(1, 0, half_size - 1, beg, end, delta); }

        void inc_impl(int node, int left, int rght, int beg, int end, int delta) {
            if (rght < beg || left > end) return;

            if (beg <= left && rght <= end) {
                covr[node] += delta;
            } else {
                int mid = (left + rght) / 2;
                inc_impl(node * 2, left, mid, beg, end, delta);
                inc_impl(node * 2 + 1, mid + 1, rght, beg, end, delta);
            }

            xacc[node] =
                covr[node] ? comp2x[rght + 1] - comp2x[left] :
                left < rght ? xacc[node * 2] + xacc[node * 2 + 1] :
                0;
        }
    };

    struct SquareAccumulateStage {
        long long cur_y, nxt_y, len_x;
    };
};