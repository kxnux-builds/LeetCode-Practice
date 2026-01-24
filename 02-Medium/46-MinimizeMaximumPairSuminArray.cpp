/*
Problem: Minimize Maximum Pair Sum in Array
Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/
Difficulty: Medium
Topic: Array / Greedy / Sorting / Two Pointers

Problem Statement:
You are given a **0-indexed** integer array `nums` of **even length**.
Pair the elements of `nums` into `n / 2` pairs such that:
- Each element is in exactly one pair.

The **pair sum** is the sum of the two elements in the pair.
Return the **minimum possible value** of the **maximum** pair sum after optimally pairing elements.

Example:
Input: nums = [3,5,2,3]  
Output: 7  
Explanation:
Optimal pairing → (5,2) and (3,3) → maximum pair sum = 7.

Approach (Greedy with Sorting):
1. Sort the array in ascending order.
2. To minimize the largest pair sum, pair the **smallest** with the **largest**, the
   **second smallest** with the **second largest**, and so on.
3. For each pair `(nums[i], nums[n−1−i])`, compute the sum and track the maximum among them.
4. Return that maximum.

Why this works:
- Pairing smallest with largest balances sums.
- Any other pairing increases the largest pair sum.

Time Complexity: O(n log n)  
Space Complexity: O(1) — ignoring output
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxSum = 0;
        for (int i = 0; i < n / 2; ++i) {
            maxSum = max(maxSum, nums[i] + nums[n - 1 - i]);
        }
        return maxSum;
    }
};