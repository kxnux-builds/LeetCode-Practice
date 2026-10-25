/*
Problem: Number of Closed Islands
Link: https://leetcode.com/problems/number-of-closed-islands/description/
Difficulty: Medium
Topic: DFS / Matrix / Graph / Flood Fill

Problem Statement:
You are given a 2D grid containing:
- 0 representing land.
- 1 representing water.

An island is a group of land cells (0s) connected in four
directions: up, down, left, and right.

A closed island is an island completely surrounded by water.
This means none of its land cells can touch the boundary
of the grid.

Return the total number of closed islands in the grid.

Example 1:
Input:
grid = [
    [1,1,1,1,1,1,1,0],
    [1,0,0,0,0,1,1,0],
    [1,0,1,0,1,1,1,0],
    [1,0,0,0,0,1,0,1],
    [1,1,1,1,1,1,1,0]
]

Output: 2

Explanation:
There are three separate land regions, but one region touches
the boundary of the grid.

Therefore, only two islands are closed.

Example 2:
Input:
grid = [
    [0,0,1,0,0],
    [0,1,0,1,0],
    [0,1,1,1,0]
]

Output: 1

Explanation:
The land regions connected to the boundary are not closed.
Only one island is completely surrounded by water.

Approach (DFS + Flood Fill):
1. Traverse every cell in the grid.
2. Whenever we find an unvisited land cell (grid[i][j] == 0),
   start a DFS from that cell.
3. During DFS:
   - Mark the current land cell as visited by changing it to 1.
   - Check all four neighboring cells.
   - If any cell in the island touches the boundary, the island
     is not closed.
   - Continue exploring every connected land cell.
4. After exploring the entire island:
   - If the island does not touch the boundary, increase
     the closed-island count.
5. Return the total count.

Important:
We must explore the entire island even after discovering that
it touches the boundary. Otherwise, some land cells might remain
unvisited and be counted again as separate islands.

Time Complexity: O(m * n)
Space Complexity: O(m * n) in the worst case due to recursion.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;

    // DFS returns true if the connected island is closed
    bool dfs(vector<vector<int>>& grid, int r, int c) {

        // If we move outside the grid, this island is not closed
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }

        // Water or an already visited cell
        if (grid[r][c] == 1) {
            return true;
        }

        // Mark the current land cell as visited
        grid[r][c] = 1;

        // Explore all four directions
        bool up = dfs(grid, r - 1, c);
        bool down = dfs(grid, r + 1, c);
        bool left = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);

        // The island is closed only if every direction is closed
        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int count = 0;

        // Visit every cell in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                // Start DFS for every unvisited land cell
                if (grid[i][j] == 0) {

                    // Count the island only if it is completely closed
                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};