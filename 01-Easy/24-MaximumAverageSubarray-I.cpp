/*
Problem: Maximum Average Subarray I
Link: https://leetcode.com/problems/maximum-average-subarray-i/description/
Difficulty: Easy
Topic: Array / Sliding Window

Problem Statement:
Given an integer array nums and an integer k, return the maximum average value 
of any contiguous subarray of length k.

Example:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
Maximum average subarray = [12, -5, -6, 50] 
Its sum is 51 → 51/4 = 12.75

Approach (Sliding Window – Optimal):
1. Compute the sum of the first window of size k.
2. Slide the window across the array:
   - Add the new element.
   - Subtract the outgoing element.
   - Update the maximum sum.
3. Return max_sum / k.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long windowSum = 0;

        // initial window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        long long maxSum = windowSum;

        // slide the window
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};