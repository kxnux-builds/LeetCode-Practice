/*
Problem: Construct Product Matrix
Link: https://leetcode.com/problems/construct-product-matrix/description/
Difficulty: Medium
Topic: Matrix / Prefix Product / Simulation

Problem Statement:
Given a 2D matrix `grid` of size `m x n`, construct a matrix `p`
of the same size where:

p[i][j] = product of **all elements in grid except grid[i][j]**, modulo 12345.

Return the matrix `p`.

Example 1:
Input: grid = [[1,2],[3,4]]  
Output: [[24,12],[8,6]]

Example 2:
Input: grid = [[12345],[2],[1]]  
Output: [[2],[0],[0]]

--------------------------------------------------

Approach (Prefix + Suffix Product – Optimal):

Key Idea:
This is a 2D version of **"Product of Array Except Self"**.

Instead of division, we use:
- Prefix product (left → right)
- Suffix product (right → left)

Steps:
1. Flatten the matrix conceptually into a 1D array.
2. Compute prefix product for each position.
3. Compute suffix product while traversing backward.
4. Multiply prefix and suffix for each position.
5. Take modulo 12345 at each step.

--------------------------------------------------

Time Complexity: O(m × n)  
Space Complexity: O(1) (excluding output)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 12345;

        vector<vector<int>> result(m, vector<int>(n, 1));

        // Step 1: Prefix product
        int prefix = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = prefix;
                prefix = (prefix * grid[i][j]) % mod;
            }
        }

        // Step 2: Suffix product
        int suffix = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                result[i][j] = (result[i][j] * suffix) % mod;
                suffix = (suffix * grid[i][j]) % mod;
            }
        }

        return result;
    }
};