/*
Problem: Create Grid With Exactly One Path
Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/description/
Difficulty: Easy
Topic: Matrix / Simulation / Construction

Problem Statement:
You are given two integers m and n.
Construct an m x n grid containing only '.' and '#'.

'.' represents a free cell.
'#' represents an obstacle.

A valid path:
- Starts at (0, 0).
- Ends at (m - 1, n - 1).
- Moves only right or down.

Return any grid that contains exactly one valid path
from the top-left cell to the bottom-right cell.

Example 1:
Input: m = 2, n = 3
Output: ["..#", "#.."]

Example 2:
Input: m = 3, n = 3
Output: ["..#", "#..", "##."]

Example 3:
Input: m = 1, n = 4
Output: ["...."]

Explanation:
Keep the entire grid filled with obstacles ('#').
Make every cell in the first row and last column free ('.').

This creates exactly one path:
Move right across the first row, then down the last column.

Approach (Grid Construction):
1. Create an m x n grid filled with '#'.
2. Make every cell in the first row '.'.
3. Make every cell in the last column '.'.
4. Return the constructed grid.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        // Make the first row free.
        grid[0] = string(n, '.');

        // Make the last column free.
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};