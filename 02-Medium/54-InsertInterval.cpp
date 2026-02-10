/*
Problem: Insert Interval
Link: https://leetcode.com/problems/insert-interval/description/
Difficulty: Medium
Topic: Array / Intervals / Greedy

Problem Statement:
You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [start_i, end_i]`
are sorted by `start_i` in ascending order, and a new interval `newInterval`.

Insert `newInterval` into `intervals` such that the resulting list of intervals is
still sorted and non-overlapping (merge overlapping if necessary).

Return *the updated intervals* after the insertion.

Example:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]  
Output: [[1,5],[6,9]]
Explanation: [2,5] overlaps with [1,3] → merge to [1,5].

Example:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]],  
       newInterval = [4,8]  
Output: [[1,2],[3,10],[12,16]]
Explanation: Many overlaps → merge all in the region.

Approach (One-Pass Greedy – Optimal):
1. Initialize an empty result vector.
2. Add all intervals with end < newInterval.start (no overlap).
3. Merge all intervals that overlap with `newInterval`:
   - Update `newInterval.start = min(newInterval.start, curr.start)`
   - Update `newInterval.end = max(newInterval.end, curr.end)`
4. Append the merged `newInterval`.
5. Add all remaining intervals with start > newInterval.end.
6. Return result.

Time Complexity: O(n)  
Space Complexity: O(n) — for result list
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // Step 1: Add all intervals ending before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i++]);
        }

        // Step 2: Merge all overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Append the merged newInterval
        result.push_back(newInterval);

        // Step 3: Add the remaining intervals
        while (i < n) {
            result.push_back(intervals[i++]);
        }

        return result;
    }
};