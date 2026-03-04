/*
Problem: Continuous Subarray Sum
Link: https://leetcode.com/problems/continuous-subarray-sum/description/
Difficulty: Medium
Topic: Array / Prefix Sum / Hash Table / Math

Problem Statement:
Given an integer array `nums` and an integer `k`, return `true` *if `nums` has a continuous subarray of size at least two such that*:
- The sum of the subarray is a multiple of `k` (i.e., sum % k == 0).

Otherwise, return `false`.

Example 1:
Input: nums = [23,2,4,6,7], k = 6  
Output: true  
Explanation: [2,4] sums to 6.

Example 2:
Input: nums = [23,2,6,4,7], k = 6  
Output: true  
Explanation: [23,2,6,4,7] sums to 42.

Example 3:
Input: nums = [23,2,6,4,7], k = 13  
Output: false

Approach (Prefix Sum + Modulo Map – Optimal):
1. Compute running prefix sum modulo `k` (`prefixMod = sum % k`).
2. Use a hash map to store the **earliest index** where a given prefixMod was seen.
   - Initialize `map[0] = -1` to handle subarrays from index 0.
3. For each index `i`:
   - If `mod` already exists in map and `(i − prevIndex) > 1`, return `true`.
   - Otherwise, record `mod` with current index if not seen before.
4. If no valid subarray found, return `false`.

Key Idea:
Two prefix sums with the same modulo `k` → their subarray difference is divisible by `k`.

Time Complexity: O(n)  
Space Complexity: O(min(n, k))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen[0] = -1; // to handle subarray from index 0

        long long prefixSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            int mod = (k != 0) ? (prefixSum % k) : prefixSum;

            if (seen.find(mod) != seen.end()) {
                if (i - seen[mod] > 1) return true;
            } else {
                // store only first occurrence
                seen[mod] = i;
            }
        }
        return false;
    }
};