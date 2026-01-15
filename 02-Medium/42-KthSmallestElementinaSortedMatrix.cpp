/*
Problem: Kth Smallest Element in a Sorted Matrix
Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
Difficulty: Medium
Topic: Binary Search / Heap / Matrix

Problem Statement:
You are given an `n x n` matrix where each row and column is sorted in **ascending order**.
Return the **kth smallest element** in the matrix (not necessarily distinct).

Example:
Input:
matrix = [
  [ 1,  5,  9],
  [10, 11, 13],
  [12, 13, 15]
],
k = 8  
Output: 13

Approach (Binary Search on Value Range – Optimal):
1. Use binary search on the **value range** instead of indices:
   - Let `left = smallest element` (matrix[0][0]),
   - Let `right = largest element` (matrix[n−1][n−1]).
2. For each `mid = (left + right) // 2`, count how many elements in the matrix are **≤ mid**.
   - Since rows and columns are sorted, we can do this in O(n) per row by scanning from the bottom-left.
3. If `count ≥ k`: shrink `right = mid`.
   Else: `left = mid + 1`.
4. Return `left` when binary search completes.

Time Complexity: O(n * log(max−min))  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countLessEqual(matrix, mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

private:
    int countLessEqual(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int i = n - 1, j = 0;  // start bottom-left
        int count = 0;

        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                count += (i + 1);
                j++;
            } else {
                i--;
            }
        }

        return count;
    }
};