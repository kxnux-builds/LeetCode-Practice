/*
Problem: Find Minimum in Rotated Sorted Array II
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
Difficulty: Hard
Topic: Binary Search / Array

Problem Statement:
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
The array may contain duplicates.

Given the sorted rotated array nums, return the minimum element of this array.

You must decrease the overall runtime complexity as much as possible.

Approach:
1. Use a modified binary search to handle rotation and duplicates.
2. Compare nums[mid] with nums[right]:
   - If nums[mid] < nums[right]: minimum lies in the left half (including mid).
   - If nums[mid] > nums[right]: minimum lies in the right half.
   - If nums[mid] == nums[right]: cannot determine; reduce right by one.
3. Continue until left == right, where nums[left] is the minimum.

Time Complexity: O(log n) in average case, O(n) in worst case (due to duplicates)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid; // minimum is in the left part (including mid)
            } 
            else if (nums[mid] > nums[right]) {
                left = mid + 1; // minimum is in the right part
            } 
            else {
                right--; // nums[mid] == nums[right], shrink right
            }
        }

        return nums[left];
    }
};