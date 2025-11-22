/*
Problem: How Many Numbers Are Smaller Than the Current Number
Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/
Difficulty: Easy
Topic: Array / Counting / Sorting

Problem Statement:
Given an array nums, for each nums[i], find how many numbers in the array are
strictly smaller than it. Return the answer as an array.

Example:
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]

Approach (Optimized: Sorting + Index Mapping):
1. Make a copy of nums and sort it.
2. For every distinct number in the sorted array, store its first index 
   (which represents how many numbers are smaller than it).
3. For each original element nums[i], directly lookup its value in the map.
4. Construct and return the result.

Time Complexity: O(n log n) — sorting  
Space Complexity: O(n) — map to store first indices
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> firstIndex;
        for (int i = 0; i < sorted.size(); i++) {
            if (!firstIndex.count(sorted[i])) {
                firstIndex[sorted[i]] = i;   // first occurrence = count of smaller numbers
            }
        }

        vector<int> ans;
        ans.reserve(nums.size());

        for (int x : nums) {
            ans.push_back(firstIndex[x]);
        }

        return ans;
    }
};