/*
Problem: Rotating the Box
Link: https://leetcode.com/problems/rotating-the-box/description/
Difficulty: Medium
Topic: Matrix / Simulation

Problem Statement:
You are given an `m x n` matrix `box` representing a box of stones:
- '#' → stone
- '*' → obstacle
- '.' → empty space

The box is rotated **90 degrees clockwise**, and gravity then pulls
the stones **downwards**.

Return the resulting matrix after rotation and gravity.

Example 1:
Input:
box = [["#",".","#"]]
Output:
[["."],
 ["#"],
 ["#"]]

Example 2:
Input:
box = [["#",".","*","."],
       ["#","#","*","."]]

Output:
[["#","."],
 ["#","#"],
 ["*","*"],
 [".","."]]

--------------------------------------------------

Approach (Simulate Gravity + Rotate – Optimal):

Key Idea:
1. First simulate gravity in each row:
   - Stones fall to the **right** until blocked by:
     - obstacle '*'
     - another stone '#'
2. Then rotate the matrix 90° clockwise

--------------------------------------------------

Steps:
1. For each row:
   - Traverse from right → left
   - Track position `empty` where next stone can fall
   - If obstacle '*' → reset `empty`
   - If stone '#' → move it to `empty` position
2. Create new matrix of size `n x m`
3. Rotate:
   new[j][m-1-i] = box[i][j]

--------------------------------------------------

Time Complexity: O(m × n)  
Space Complexity: O(m × n)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // Step 1: simulate gravity (stones fall right)
        for (int i = 0; i < m; i++) {
            int empty = n - 1;

            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    empty = j - 1; // reset after obstacle
                }
                else if (box[i][j] == '#') {
                    swap(box[i][j], box[i][empty]);
                    empty--;
                }
            }
        }

        // Step 2: rotate 90° clockwise
        vector<vector<char>> res(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - 1 - i] = box[i][j];
            }
        }

        return res;
    }
};