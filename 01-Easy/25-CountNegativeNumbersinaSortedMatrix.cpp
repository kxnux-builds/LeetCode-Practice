/*
Problem: Count Negative Numbers in a Sorted Matrix
Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
Difficulty: Easy
Topic: Matrix / Binary Search

Problem Statement:
Given a m x n matrix grid where each row is sorted in non-increasing order,
return the number of negative numbers in the matrix.

Example:
Input:
[
  [4,3,2,-1],
  [3,2,1,-1],
  [1,1,-1,-2],
  [-1,-1,-2,-3]
]
Output: 8

Approach (Optimal – Binary Search for Each Row):
Since each row is sorted in decreasing order:
1. For each row, use binary search to find the first negative number.
2. If found at index idx → all elements from idx to end are negative.
3. Add (n - idx) to the answer.

Time Complexity: O(m * log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (auto &row : grid) {
            int idx = firstNegativeIndex(row);
            if (idx != -1) {
                count += (n - idx);
            }
        }

        return count;
    }

private:
    int firstNegativeIndex(vector<int>& row) {
        int l = 0, r = row.size() - 1, pos = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (row[mid] < 0) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return pos;
    }
};