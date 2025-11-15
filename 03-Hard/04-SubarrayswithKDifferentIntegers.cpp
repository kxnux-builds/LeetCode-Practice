/*
Problem: Subarrays with K Different Integers
Link: https://leetcode.com/problems/subarrays-with-k-different-integers/description/
Difficulty: Hard
Topic: Sliding Window / HashMap / Two Pointers

Problem Statement:
Given an integer array nums and an integer k, return the number of subarrays with exactly 
k different integers.

Approach (Sliding Window + Inclusion-Exclusion):
1. Define a helper function `atMost(k)` that returns the number of subarrays with at most k distinct integers.
2. Number of subarrays with exactly k distinct integers:
   exactlyK = atMost(k) - atMost(k-1)
3. `atMost(k)`:
   - Use a sliding window [left, right] and a hashmap to count frequency of numbers in the window.
   - Expand `right`, include nums[right] in count.
   - If distinct count > k, shrink from left until distinct count ≤ k.
   - Add window size (right-left+1) to result for each step.
4. Return exactlyK.

Time Complexity: O(n)  
Space Complexity: O(n) — hashmap to count frequency
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int res = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (count[nums[right]] == 0) k--;
            count[nums[right]]++;

            while (k < 0) {
                count[nums[left]]--;
                if (count[nums[left]] == 0) k++;
                left++;
            }

            res += right - left + 1;
        }
        return res;
    }
};