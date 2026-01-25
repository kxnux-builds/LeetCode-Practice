/*
Problem: Minimum Difference Between Highest and Lowest of K Scores
Link: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
Difficulty: Easy
Topic: Array / Sorting / Sliding Window / Greedy

Problem Statement:
You are given an integer array `nums` and an integer `k`.  
Pick `k` scores from `nums` such that the **difference between the highest and lowest** score in the selected group is minimized.  
Return *the minimum possible difference*.

Example:
Input: nums = [90, 80, 75, 60, 120], k = 3  
Output: 15  
Explanation: Pick scores [75, 80, 90] → difference = 90 − 75 = 15.

Approach (Sorting + Sliding Window – Optimal):
1. Sort `nums` in ascending order.
2. Use a sliding window of size `k` over sorted `nums`.
   - For each window `[i … i+k−1]`, compute difference = `nums[i+k−1] − nums[i]`.
3. Track and return the minimum difference.

Time Complexity: O(n log n) — sorting  
Space Complexity: O(1) — no extra data structures
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i + k - 1 < n; i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans == INT_MAX ? 0 : ans;
    }
};