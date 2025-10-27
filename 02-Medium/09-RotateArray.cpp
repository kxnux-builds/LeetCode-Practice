/*
Problem: Rotate Array
Link: https://leetcode.com/problems/rotate-array/description/
Difficulty: Medium
Topic: Array / In-place / Math

Problem Statement:
Given an integer array nums, rotate the array to the right by k steps, 
where k is non-negative.

Approach:
1. Use the reverse approach to rotate the array in-place:
   a. Reverse the entire array.
   b. Reverse the first k elements.
   c. Reverse the remaining n-k elements.
2. This effectively rotates the array to the right by k positions.

Time Complexity: O(n)  — each element is reversed at most twice
Space Complexity: O(1) — in-place rotation
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // handle k > n

        // Helper lambda to reverse a subarray
        auto reverseSubarray = [&](int start, int end) {
            while (start < end) {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
        };

        // Step 1: reverse entire array
        reverseSubarray(0, n - 1);

        // Step 2: reverse first k elements
        reverseSubarray(0, k - 1);

        // Step 3: reverse remaining elements
        reverseSubarray(k, n - 1);
    }
};
