/*
Problem: First Missing Positive
Link: https://leetcode.com/problems/first-missing-positive/description/
Difficulty: Hard
Topic: Array / Hashing / Indexing Trick

Problem Statement:
Given an unsorted integer array `nums`, return *the smallest missing positive integer*.

Example:
Input: nums = [3,4,-1,1]  
Output: 2  
Explanation: The smallest missing positive is 2.

Example:
Input: nums = [1,2,0]  
Output: 3

Approach (Index Placement / In-Place Hashing – Optimal):
1. The answer must be in the range `[1 … n+1]` where `n = nums.size()`.
2. Place each positive number `x` at index `x−1` if `1 ≤ x ≤ n` and it’s not already in the correct position.
3. After placement:
   - The first index `i` where `nums[i] != i+1` → return `i+1`.
4. If all positions are correct → return `n+1`.

Why this works:
- We use the array itself as a hash map to record presence of numbers 1 to `n`.
- Running in O(n) time with O(1) extra space.

Time Complexity: O(n)  
Space Complexity: O(1) — in-place
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // place nums[i] in correct position if possible
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // find first index where number is incorrect
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};