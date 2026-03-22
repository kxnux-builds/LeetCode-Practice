/*
Problem: Determine Whether Matrix Can Be Obtained By Rotation
Link: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/descripton/
Difficulty: Easy
Topic: Matrix / Simulation

Problem Statement:
Given two `n x n` binary matrices `mat` and `target`, return `true`
if it is possible to make `mat` equal to `target` by rotating `mat`
in **90-degree increments**, otherwise return `false`. :contentReference[oaicite:0]{index=0}

You can rotate the matrix:
- 0 times (no change)
- 1 time (90°)
- 2 times (180°)
- 3 times (270°)

Example 1:
Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]  
Output: true  

Example 2:
Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]  
Output: false  

Example 3:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]  
Output: true  

--------------------------------------------------

Approach (Simulation + Rotation – Optimal):

Key Idea:
A matrix can be rotated at most **4 times** (after 4 rotations it returns to original). :contentReference[oaicite:1]{index=1}

Steps:
1. Repeat 4 times:
   - Check if `mat == target`
   - If yes → return true
   - Otherwise rotate `mat` by 90°
2. If no match found → return false

Matrix Rotation Trick:
To rotate matrix 90° clockwise:
1. **Transpose** the matrix
2. **Reverse each row**

--------------------------------------------------

Time Complexity: O(n²)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();

        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};