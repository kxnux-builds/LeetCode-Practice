/*
Problem: Count Islands With Total Value Divisible by K
Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/description/
Difficulty: Medium
Topic: DFS / Graph / Matrix

Problem Statement:
You are given an m x n grid and a positive integer k.
An island is a group of positive integers connected horizontally
or vertically. The total value of an island is the sum of all
its cell values.

Return the number of islands whose total value is divisible by k.

Example 1:
Input: grid = [[0,2,1,0,0],
               [0,5,0,0,5],
               [0,0,1,0,0],
               [0,1,4,7,0],
               [0,2,0,0,8]], k = 5
Output: 2

Example 2:
Input: grid = [[3,0,3,0],
               [0,3,0,3],
               [3,0,3,0]], k = 3
Output: 6

Explanation:
Use DFS to explore each island and calculate its total value.
If the island's sum is divisible by k, increase the answer.
Mark visited cells as 0 to avoid counting them again.

Approach (DFS):
1. Traverse every cell in the grid.
2. If a cell is positive, start DFS to explore its island.
3. Add the values of all connected positive cells.
4. Mark each visited cell as 0.
5. If the island's total sum is divisible by k, increment the count.
6. Return the final count.

Time Complexity: O(m * n)
Space Complexity: O(m * n) for the DFS recursion stack in the worst case.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;

    long long dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols ||
            grid[r][c] == 0) {
            return 0;
        }

        long long sum = grid[r][c];
        grid[r][c] = 0;

        sum += dfs(grid, r - 1, c);
        sum += dfs(grid, r + 1, c);
        sum += dfs(grid, r, c - 1);
        sum += dfs(grid, r, c + 1);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();

        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] > 0) {
                    long long islandSum = dfs(grid, i, j);

                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};