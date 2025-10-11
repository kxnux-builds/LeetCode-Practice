/*
Problem: Two Sum
Link: https://leetcode.com/problems/two-sum/description/
Difficulty: Easy
Topic: Array / HashMap

Problem Statement:
Given an array of integers nums and an integer target, return indices of the two numbers
such that they add up to target.

Approach:
1. Use an unordered_map (hashmap) to store number -> index.
2. Traverse the array, for each number check if (target - nums[i]) exists in the map.
3. If exists, return indices. Otherwise, add the current number to the map.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.count(target-nums[i])) return {mp[target-nums[i]], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};