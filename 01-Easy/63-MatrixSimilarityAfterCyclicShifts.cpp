/*
Problem: Matrix Similarity After Cyclic Shifts
Link: https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/description/
Difficulty: Easy
Topic: Matrix / Simulation

Problem Statement:
You are given a 2D integer matrix `mat` of size `m x n` and an integer `k`.

- For each row:
  - If the row index is **even**, shift the row to the **right** by `k` positions.
  - If the row index is **odd**, shift the row to the **left** by `k` positions.

Return `true` if the matrix remains **unchanged after performing these shifts**,
otherwise return `false`.

Note:
- Shifts are **cyclic** (wrap around).
- `k` can be larger than `n`, so use `k % n`.

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 3  
Output: true  
Explanation: Shifting by 3 (equal to row length) keeps rows unchanged.

Example 2:
Input: mat = [[1,2],[3,4]], k = 1  
Output: false  

--------------------------------------------------

Approach (Simulation with Modulo – Optimal):

Key Idea:
Instead of actually shifting the row, compute where each element
would come from after shifting.

Steps:
1. Let `shift = k % n`
2. For each row `i`:
   - For each column `j`:
     - If `i` is even (right shift):
       original index = (j - shift + n) % n
     - If `i` is odd (left shift):
       original index = (j + shift) % n
3. Compare with original matrix:
   - If any mismatch → return false
4. If all match → return true

--------------------------------------------------

Time Complexity: O(m × n)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        int shift = k % n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int originalIndex;

                if (i % 2 == 0) {
                    // right shift
                    originalIndex = (j - shift + n) % n;
                } else {
                    // left shift
                    originalIndex = (j + shift) % n;
                }

                if (mat[i][j] != mat[i][originalIndex]) {
                    return false;
                }
            }
        }

        return true;
    }
};