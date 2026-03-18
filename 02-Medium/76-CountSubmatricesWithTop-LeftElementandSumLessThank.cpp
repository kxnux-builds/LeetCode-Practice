/*
Problem: Count Submatrices With Top-Left Element and Sum Less Than k
Link: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/
Difficulty: Medium
Topic: Matrix / Prefix Sum

Problem Statement:
You are given a 0-indexed integer matrix `grid` and an integer `k`.

Return the number of submatrices that:
1. Contain the **top-left element** (i.e., always start at (0,0))
2. Have a sum **less than or equal to `k`**

Example 1:
Input: grid = [[7,6,3],[6,6,1]], k = 18  
Output: 4  

Example 2:
Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20  
Output: 6  

--------------------------------------------------

Approach (2D Prefix Sum – Optimal):

Key Insight:
Since every valid submatrix must include (0,0),
each submatrix is defined only by its **bottom-right corner (i, j)**. :contentReference[oaicite:0]{index=0}

So we only need to compute sum from (0,0) → (i,j).

Steps:
1. Build prefix sum while traversing the grid.
2. Let `prefix[i][j]` = sum of submatrix (0,0) → (i,j)
3. If `prefix[i][j] <= k`, increment count.
4. Stop early in row if sum exceeds `k` (optimization).

Prefix Formula:
prefix[i][j] = grid[i][j]
             + prefix[i-1][j]
             + prefix[i][j-1]
             - prefix[i-1][j-1] :contentReference[oaicite:1]{index=1}

--------------------------------------------------

Time Complexity: O(m × n)  
Space Complexity: O(n) (optimized)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> colSum(n, 0);
        int count = 0;

        for (int i = 0; i < m; i++) {
            int rowPrefix = 0;

            for (int j = 0; j < n; j++) {
                rowPrefix += grid[i][j];     // row prefix sum
                colSum[j] += rowPrefix;      // full prefix sum (0,0 → i,j)

                if (colSum[j] <= k) {
                    count++;
                } else {
                    break; // further will only increase
                }
            }
        }

        return count;
    }
};