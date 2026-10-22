/*
Problem: Unique Paths
Link: https://leetcode.com/problems/unique-paths/description/
Difficulty: Medium
Topic: Dynamic Programming / Math / Combinatorics

Problem Statement:
There is a robot located at the top-left corner of an m x n grid.

The robot wants to reach the bottom-right corner of the grid.

The robot can move only:
1. Right
2. Down

Return the total number of possible unique paths that the robot
can take to reach the bottom-right corner.

Example 1:
Input: m = 3, n = 7
Output: 28

Explanation:
The robot starts at the top-left corner and must reach the
bottom-right corner.

It can move only right or down.

There are 28 different possible paths.

Example 2:
Input: m = 3, n = 2
Output: 3

Explanation:
The possible paths are:

1. Right -> Down -> Down
2. Down -> Right -> Down
3. Down -> Down -> Right

Therefore, the answer is 3.

Approach (Dynamic Programming):
1. Create a 2D DP array `dp` of size m x n.
2. Define:
       dp[i][j] = number of unique paths to reach cell (i, j).

3. Initialize the first row and first column with 1:
   - The robot can reach any cell in the first row using
     only right moves.
   - The robot can reach any cell in the first column using
     only down moves.

4. Traverse the remaining cells:
   - The robot can reach a cell from the cell above it.
   - The robot can also reach it from the cell to its left.

   Therefore:
       dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

5. Return dp[m - 1][n - 1].

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

        // dp[i][j] = number of unique paths to reach cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // Calculate the number of paths for each cell
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                // Paths from above + paths from the left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // Return the number of paths to the bottom-right corner
        return dp[m - 1][n - 1];
    }
};