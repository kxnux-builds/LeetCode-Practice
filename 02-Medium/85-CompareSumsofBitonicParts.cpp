/*
Problem: Compare Sums of Bitonic Parts
Link: https://leetcode.com/problems/compare-sums-of-bitonic-parts/description/
Difficulty: Medium
Topic: Array / Prefix Sum / Simulation

Problem Statement:
You are given an integer array `nums`.

Split the array into two parts:
1. Increasing part (strictly increasing sequence from start)
2. Decreasing part (strictly decreasing sequence after peak)

The array is guaranteed to be **bitonic**:
- strictly increasing up to a peak
- then strictly decreasing

Return:
- 1  → if sum of increasing part > sum of decreasing part
- -1 → if sum of increasing part < sum of decreasing part
- 0  → if both sums are equal

Example 1:
Input: nums = [1,3,5,4,2]  
Output: 1  

Example 2:
Input: nums = [1,2,3,2,1]  
Output: 0  

--------------------------------------------------

Approach (Single Pass – Optimal):

Key Idea:
Find the peak (maximum element), then compute:
- sum of left increasing part (including peak)
- sum of right decreasing part (excluding peak)

Steps:
1. Find peak index `p`
2. Compute:
   - leftSum = sum from 0 → p
   - rightSum = sum from p+1 → n-1
3. Compare both sums:
   - left > right → return 1
   - left < right → return -1
   - else → return 0

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareSums(vector<int>& nums) {
        int n = nums.size();

        // Step 1: find peak index
        int peak = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[peak]) {
                peak = i;
            }
        }

        // Step 2: compute sums
        int leftSum = 0, rightSum = 0;

        for (int i = 0; i <= peak; i++) {
            leftSum += nums[i];
        }

        for (int i = peak; i < n; i++) {
            rightSum += nums[i];
        }

        // Step 3: compare
        if (leftSum > rightSum) return 0;
        if (leftSum < rightSum) return -1;
        return -1;
    }
};