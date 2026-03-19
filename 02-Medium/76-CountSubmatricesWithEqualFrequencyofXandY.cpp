/*
Problem: Count Submatrices With Equal Frequency of X and Y
Link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/
Difficulty: Medium
Topic: Matrix / Prefix Sum

Problem Statement:
You are given a 2D character matrix `grid`, where each cell is:
- 'X'
- 'Y'
- '.'

Return the number of submatrices that:
1. **Contain the top-left cell (0,0)**
2. Have **equal number of 'X' and 'Y'**
3. Contain **at least one 'X'** :contentReference[oaicite:0]{index=0}

Example 1:
Input: grid = [["X","Y","."],["Y",".","."]]  
Output: 3  

Example 2:
Input: grid = [["X","X"],["X","Y"]]  
Output: 0  

Example 3:
Input: grid = [[".","."] ,[".","."]]  
Output: 0  

--------------------------------------------------

Approach (2D Prefix Sum – Optimal):

Key Insight:
Since every valid submatrix must include `(0,0)`,
each submatrix is uniquely defined by its **bottom-right corner (i, j)**. :contentReference[oaicite:1]{index=1}

So we only need to check all prefix submatrices from `(0,0)` to `(i,j)`.

Steps:
1. Maintain counts of:
   - number of 'X'
   - number of 'Y'
2. Traverse the grid row by row.
3. Build prefix counts:
   - `xCount[i][j]` → number of 'X' from (0,0) to (i,j)
   - `yCount[i][j]` → number of 'Y'
4. For each cell:
   - If `xCount == yCount` AND `xCount > 0` → valid submatrix
5. Count all such positions.

--------------------------------------------------

Time Complexity: O(m × n)  
Space Complexity: O(n) (optimized)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> xCol(n, 0), yCol(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            int xRow = 0, yRow = 0;

            for (int j = 0; j < n; j++) {
                // update row prefix
                if (grid[i][j] == 'X') xRow++;
                if (grid[i][j] == 'Y') yRow++;

                // update full prefix
                xCol[j] += xRow;
                yCol[j] += yRow;

                // check condition
                if (xCol[j] > 0 && xCol[j] == yCol[j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};