/*
Problem: Search in Rotated Sorted Array
Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
Difficulty: Medium
Topic: Binary Search / Array

Problem Statement:
There is an integer array nums sorted in ascending order (with distinct values).
The array was rotated at some unknown pivot index k (0 ≤ k < nums.length),
so that the resulting array is:
    [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
Given the array nums and an integer target, return the index of target if it is
in nums, or -1 if it is not in nums.

Approach:
1. Use a modified binary search.
2. At each step, determine whether the left half or right half of the array is sorted.
3. Check if the target lies within the sorted half:
   - If yes, narrow the search to that half.
   - Otherwise, search the other half.
4. Continue until left > right.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // Check if left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } 
            // Otherwise, right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};