/*
Problem: Number of Zero-Filled Subarrays
Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
Difficulty: Medium
Topic: Array / Counting / Math

Problem Statement:
Given an integer array nums, return the number of **zero-filled subarrays**.
A zero-filled subarray is a contiguous sequence of one or more 0’s in nums.

Example:
Input: nums = [1,0,0,0,1,0,0]
Output: 6  
Explanation: Zero-filled subarrays are:
[0], [0], [0], [0,0], [0,0], [0,0,0]

Approach (Optimal Counting Consecutive Zeros):
1. Traverse the array.
2. Keep a running count of consecutive zeros.
3. For each zero encountered:
     - Increment count
     - Add count to answer (because each new zero extends all previous zero subarrays and creates new ones).
4. If a non-zero is encountered → reset count to 0.
5. Return the total answer.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                count++;
                ans += count;
            } else {
                count = 0;
            }
        }
        return ans;
    }
};