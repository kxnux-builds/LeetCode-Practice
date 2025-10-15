/*
Problem: 4 Sum
Link: https://leetcode.com/problems/4sum/description/
Difficulty: Medium
Topic: Array / Two Pointers / Sorting

Problem Statement:
Given an array nums of n integers and an integer target, return all unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:
- a, b, c, and d are all different indices
- nums[a] + nums[b] + nums[c] + nums[d] == target

Approach:
1. Sort the array to handle duplicates easily.
2. Use two nested loops (i, j) to fix the first two elements.
3. Apply two pointers (left, right) to find the remaining two elements.
4. Skip duplicates for nums[i], nums[j], nums[left], and nums[right] to avoid repetition.

Time Complexity: O(n^3)  (two loops + two-pointer scan)
Space Complexity: O(1) extra space (excluding result storage)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for first number

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates for second number

                long long target2 = (long long)target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum = nums[left] + nums[right];

                    if (sum == target2) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) left++;   // Skip duplicates
                        while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates

                        left++;
                        right--;
                    }
                    else if (sum < target2) left++;
                    else right--;
                }
            }
        }
        return res;
    }
};
