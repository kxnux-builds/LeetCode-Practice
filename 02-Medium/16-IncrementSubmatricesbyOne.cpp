/*
Problem: Increment Submatrices by One
Link: https://leetcode.com/problems/increment-submatrices-by-one/description/
Difficulty: Medium
Topic: Difference Array / Prefix Sum / Matrix

Problem Statement:
You are given an integer n and a 2D integer array queries where each query is of the form
[l1, r1, l2, r2] representing the top-left (l1, r1) and bottom-right (l2, r2) corners of a submatrix.
For each query, increment every cell inside the submatrix by 1.

Return the final n x n matrix after all queries.

Approach (Optimized Using Difference Matrix):
1. A brute-force approach increments all cells inside each query → O(q * n²) → too slow.
2. Instead, use a **2D difference array**:
   - For each query (r1,c1,r2,c2), do:
        diff[r1][c1]       += 1
        diff[r1][c2 + 1]   -= 1
        diff[r2 + 1][c1]   -= 1
        diff[r2 + 1][c2+1] += 1
3. After processing all queries, compute:
   - Prefix sum row-wise
   - Prefix sum column-wise
4. This reconstructs the final incremented matrix.

Time Complexity: O(n² + q)  
Space Complexity: O(n²)  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));

        // Apply difference increments
        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];

            diff[r1][c1] += 1;
            if (c2 + 1 < n) diff[r1][c2 + 1] -= 1;
            if (r2 + 1 < n) diff[r2 + 1][c1] -= 1;
            if (r2 + 1 < n && c2 + 1 < n) diff[r2 + 1][c2 + 1] += 1;
        }

        // Prefix sum row-wise
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        // Prefix sum column-wise
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < n; ++i) {
                diff[i][j] += diff[i - 1][j];
            }
        }

        // Final n x n matrix
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                result[i][j] = diff[i][j];

        return result;
    }
};