/*
Problem: Flip Square Submatrix Vertically
Link: https://leetcode.com/problems/flip-square-submatrix-vertically/description
Difficulty: Easy
Topic: Matrix / Simulation / Two Pointers

Problem Statement:
You are given an `m x n` integer matrix `grid`, and three integers `x`, `y`, and `k`.

- `(x, y)` represents the **top-left corner** of a square submatrix
- `k` represents the **size (k × k)** of the submatrix

Your task is to **flip the submatrix vertically**, i.e.,
reverse the order of its rows while keeping columns unchanged. :contentReference[oaicite:0]{index=0}

Return the updated matrix.

Example 1:
Input:
grid = [[1,2,3,4],
        [5,6,7,8],
        [9,10,11,12],
        [13,14,15,16]],
x = 1, y = 0, k = 3

Output:
[[1,2,3,4],
 [13,14,15,8],
 [9,10,11,12],
 [5,6,7,16]]

Example 2:
Input:
grid = [[3,4,2,3],
        [2,3,4,2]],
x = 0, y = 2, k = 2

Output:
[[3,4,4,2],
 [2,3,2,3]]

--------------------------------------------------

Approach (Row Swapping – Optimal):

Key Idea:
To flip vertically → **reverse rows inside the k×k submatrix**.

Steps:
1. Identify rows from `x` to `x + k - 1`.
2. Use two pointers:
   - `top = x`
   - `bottom = x + k - 1`
3. While `top < bottom`:
   - Swap entire rows within column range `[y, y + k - 1]`
   - Move `top++` and `bottom--`
4. Only half of the rows are processed.

Intuition:
- First row ↔ last row  
- Second row ↔ second last row  
- Continue until center reached :contentReference[oaicite:1]{index=1}

--------------------------------------------------

Time Complexity: O(k²)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int top = x;
        int bottom = x + k - 1;

        while (top < bottom) {
            for (int j = y; j < y + k; j++) {
                swap(grid[top][j], grid[bottom][j]);
            }
            top++;
            bottom--;
        }

        return grid;
    }
};