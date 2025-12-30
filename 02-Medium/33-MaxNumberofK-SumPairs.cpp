/*
Problem: Max Number of K-Sum Pairs
Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/description/
Difficulty: Medium
Topic: Array / Hash Map / Two-Pointers / Greedy

Problem Statement:
You are given an integer array `nums` and an integer `k`.  
In one operation, you can pick two numbers from the array whose sum equals `k`
and remove them from the array.

Return the **maximum number of such operations** you can perform.

Example:
Input: nums = [1,2,3,4], k = 5  
Output: 2  
Explanation: Pairs are (1,4) and (2,3).

Approach (Hash Map – Optimal):
1. Use a hash map to store frequency of numbers.
2. For each number `x` in `nums`:
   - Calculate `y = k − x`
   - If `y` exists in map with positive count:
       - Decrement count of `y`
       - Increase operations count
   - Else:
       - Increment count of `x`
3. Return the total operations count.

Time Complexity: O(n)  
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int ops = 0;

        for (int x : nums) {
            int need = k - x;
            if (freq[need] > 0) {
                ops++;
                freq[need]--;
            } else {
                freq[x]++;
            }
        }

        return ops;
    }
};