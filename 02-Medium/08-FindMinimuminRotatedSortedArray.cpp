/*
Problem: Find Minimum in Rotated Sorted Array
Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
Difficulty: Medium
Topic: Binary Search / Array

Problem Statement:
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
The array contains no duplicate elements.

Given the sorted rotated array nums, return the minimum element of this array.

Approach:
1. Use binary search to find the minimum element.
2. Compare nums[mid] with nums[right]:
   - If nums[mid] < nums[right], the minimum lies in the left part (including mid).
   - Else, the minimum lies in the right part.
3. Continue until left == right, which gives the minimum element.

Time Complexity: O(log n)
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
                right = mid; // minimum in left part (including mid)
            } 
            else {
                left = mid + 1; // minimum in right part
            }
        }

        return nums[left];
    }
};
