/*
Problem: 3 Sum
Link: https://leetcode.com/problems/3sum/description/
Difficulty: Medium
Topic: Array / Two Pointers / Sorting

Problem Statement:
Given an integer array nums, return all unique triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, j != k and nums[i] + nums[j] + nums[k] == 0.

Approach:
1. Sort the array to simplify avoiding duplicates.
2. Fix the first element (nums[i]) and use two pointers (left, right) for the remaining two elements.
3. Move the pointers based on the sum:
   - If sum < 0, move left pointer forward.
   - If sum > 0, move right pointer backward.
   - If sum == 0, add triplet to result and skip duplicates.
4. Repeat for all i from 0 to n-3.

Time Complexity: O(n^2)  (two nested loops: i + left-right scan)
Space Complexity: O(1) extra space (excluding result storage)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates for first element
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;   // skip duplicates
                    while(left < right && nums[right] == nums[right-1]) right--; // skip duplicates
                    left++;
                    right--;
                } else if(sum < 0) left++;
                else right--;
            }
        }
        return res;
    }
};
