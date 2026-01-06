/*
Problem: Maximum Subarray
Link: https://leetcode.com/problems/maximum-subarray/description/
Difficulty: Medium
Topic: Array / Dynamic Programming / Kadane’s Algorithm

Problem Statement:
Given an integer array `nums`, find the **contiguous subarray** (containing at least one number)
which has the largest sum and return *its sum*.

Example:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]  
Output: 6  
Explanation:
The subarray `[4,-1,2,1]` has the largest sum = 6.

Approach (Kadane’s Algorithm – Optimal):
1. Track the current running sum (`currentSum`) and the maximum sum found (`maxSum`).
2. For each element `x`:
   - Update `currentSum = max(x, currentSum + x)`
     (start new subarray at x if currentSum becomes worse).
   - Update `maxSum = max(maxSum, currentSum)`.
3. Return `maxSum`.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};