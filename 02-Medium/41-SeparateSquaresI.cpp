/*
Problem: Separate Squares I
Link: https://leetcode.com/problems/separate-squares-i/description/
Difficulty: Medium
Topic: Binary Search / Geometry / Area Calculation

Problem Statement:
You are given a 2D integer array `squares` where each `squares[i] = [xi, yi, li]` 
represents the coordinates of the bottom-left point `(xi, yi)` and the side length 
`li` of a square parallel to the x-axis.

Find the **minimum y-coordinate value** of a horizontal line such that the **total area of the squares above the line equals the total area of the squares below the line**.

Notes:
- Squares may overlap and overlapping areas are counted **multiple times** in area calculations.
- Answers within `1e-5` of the actual answer are accepted. :contentReference[oaicite:0]{index=0}

Example:
Input: squares = [[0,0,1],[2,2,1]]  
Output: 1.00000  
Explanation: Any horizontal line between `y = 1` and `y = 2` divides the total square area evenly. :contentReference[oaicite:1]{index=1}

Approach (Binary Search on Horizontal Line):
1. Compute `totalArea` = sum of `li * li` for all squares.
2. Our goal is to find the smallest `h` such that the area **below** the horizontal line `y = h` is **≥ totalArea / 2**.
3. Define a function `areaBelow(h)`:
   - For each square `[x, y, l]`:
     * If `h <= y`: contributes `0` (line below square).
     * If `h >= y + l`: contributes full square area `l * l`.
     * Otherwise (`y < h < y + l`): contributes `(h - y) * l` (partial area below line).
4. Because `areaBelow(h)` is monotonic non-decreasing in `h`, use binary search on the y-range 
   from the minimum bottom edge up to the maximum top edge of all squares.
5. Stop when the binary search interval is within tolerance (e.g., `1e-6`).

Time Complexity: O(N * log R), where R is range of y values  
Space Complexity: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = DBL_MAX, high = 0.0;

        // Compute total area and y-range
        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }
        double target = totalArea / 2.0;

        // Binary search for minimum y coordinate
        for (int it = 0; it < 80; ++it) { // ~1e-5 precision
            double mid = (low + high) * 0.5;
            if (areaBelow(mid, squares) < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }

private:
    double areaBelow(double h, vector<vector<int>>& squares) {
        double area = 0.0;
        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];
            if (h <= y) {
                // no contribution if line below square
            } else if (h >= y + l) {
                area += l * l;
            } else {
                area += (h - y) * l;
            }
        }
        return area;
    }
};