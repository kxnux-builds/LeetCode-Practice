/*
Problem: Map of Highest Peak
Link: https://leetcode.com/problems/map-of-highest-peak/description/
Difficulty: Medium
Topic: Matrix / Graph / Breadth-First Search (BFS)

Problem Statement:
You are given an m x n matrix `isWater`.

- If isWater[i][j] == 1, the cell represents water.
- If isWater[i][j] == 0, the cell represents land.

You must assign a non-negative height to every cell such that:

1. Every water cell has height 0.
2. The absolute difference between the heights of any two
   adjacent cells is at most 1.
3. The maximum height in the matrix is as large as possible.

Two cells are adjacent if they share a side:
up, down, left, or right.

Return an m x n matrix `height` containing the assigned heights.

Example 1:
Input:
isWater = [[0, 1],
           [0, 0]]

Output:
[[1, 0],
 [2, 1]]

Explanation:
The water cell has height 0.
Its adjacent land cells can have height 1.
The bottom-left cell can have height 2.

Example 2:
Input:
isWater = [[0, 0, 1],
           [1, 0, 0],
           [0, 0, 0]]

Output:
[[1, 1, 0],
 [0, 1, 1],
 [1, 2, 2]]

Explanation:
Every water cell has height 0.
Land cells receive heights based on their distance
from the nearest water cell.

Approach (Multi-Source BFS):
1. Create a matrix `height` of size m x n and initialize
   every cell to -1, meaning it has not been visited.

2. Create a queue to perform BFS.

3. Traverse the entire `isWater` matrix:
   - If a cell contains water (value 1):
       Set its height to 0.
       Push its coordinates into the queue.

4. While the queue is not empty:
   - Remove the front cell from the queue.
   - Check its four neighboring cells:
       up, down, left, and right.
   - If a neighbor is inside the grid and its height is -1:
       Set its height to the current height + 1.
       Push the neighbor into the queue.

5. Return the `height` matrix.

Why Multi-Source BFS?
All water cells are starting points with height 0.

BFS explores cells level by level, so each land cell receives
the shortest distance to its nearest water cell.

This produces the maximum possible valid heights.

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        // -1 means the cell has not been visited
        vector<vector<int>> height(m, vector<int>(n, -1));

        // Queue stores the coordinates of cells
        queue<pair<int, int>> q;

        // Add all water cells as starting points
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Perform multi-source BFS
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // Visit all four neighboring cells
            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                // Check whether the neighbor is inside the grid
                if (newRow >= 0 && newRow < m &&
                    newCol >= 0 && newCol < n) {

                    // Process only unvisited cells
                    if (height[newRow][newCol] == -1) {

                        // Neighbor's height is one greater
                        height[newRow][newCol] =
                            height[row][col] + 1;

                        // Add the neighbor to the queue
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        return height;
    }
};