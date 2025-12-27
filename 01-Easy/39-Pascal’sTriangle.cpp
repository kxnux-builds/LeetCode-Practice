/*
Problem: Pascal’s Triangle
Link: https://leetcode.com/problems/pascals-triangle/description/
Difficulty: Easy
Topic: Array / Math / Simulation

Problem Statement:
Given an integer `numRows`, return the first `numRows` of Pascal’s triangle.

In Pascal’s triangle:
Each number is the sum of the two numbers directly above it.

Example:
Input: numRows = 5  
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Approach (Build Row by Row – Optimal):
1. Start with the first row: `[1]`.
2. For each new row `i` from 2 to `numRows`:
   - Create a row of size `i`.
   - Set first and last element to `1`.
   - For each position `j` in between:
       row[j] = prevRow[j-1] + prevRow[j]
3. Append each row to the result.

Time Complexity: O(numRows²)  
Space Complexity: O(numRows²) — for result storage
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.reserve(numRows);

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }

        return result;
    }
};