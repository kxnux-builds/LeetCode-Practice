/*
Problem: Merge Intervals
Link: https://leetcode.com/problems/merge-intervals/description/
Difficulty: Medium
Topic: Array / Sorting / Greedy

Problem Statement:
Given an array of intervals where `intervals[i] = [start_i, end_i]`, 
merge all overlapping intervals and return *an array of the non-overlapping intervals*
that cover all the intervals in the input.

Example:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]  
Output: [[1,6],[8,10],[15,18]]  
Explanation: Intervals [1,3] and [2,6] overlap → merged [1,6].

Example:
Input: intervals = [[1,4],[4,5]]  
Output: [[1,5]]  
Explanation: Because 4 overlaps with the end of [1,4], they join into [1,5].

Approach (Sort + Merge – Optimal):
1. Sort `intervals` by starting time.
2. Initialize an empty result list.
3. For each interval:
   - If result is empty or current start > last end → no overlap → append.
   - Otherwise → overlap exists:
       - Update the last interval’s end to `max(last_end, curr_end)`.
4. Return the result.

Time Complexity: O(n log n) — sorting dominates  
Space Complexity: O(n) — for output
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(), 
             [](const auto &a, const auto &b) {
                 return a[0] < b[0];
             });

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            auto &last = merged.back();

            if (intervals[i][0] <= last[1]) {
                // Overlap → merge
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap → add new interval
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};