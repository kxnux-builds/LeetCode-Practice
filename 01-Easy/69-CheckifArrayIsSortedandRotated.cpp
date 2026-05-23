/*
Problem: Check if Array Is Sorted and Rotated
Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
Difficulty: Easy
Topic: Array

Problem Statement:
Given an array nums, return true if the array was originally sorted
in non-decreasing order, then rotated some number of positions.
Otherwise, return false.

There may be duplicates in the array.

An array A rotated by x positions results in:
A[x], A[x+1], ..., A[n-1], A[0], A[1], ..., A[x-1]

Example 1:
Input: nums = [3,4,5,1,2]
Output: true

Example 2:
Input: nums = [2,1,3,4]
Output: false

Example 3:
Input: nums = [1,2,3]
Output: true

--------------------------------------------------

Approach (Counting Break Points – Optimal):

Key Insight:
A sorted and rotated array can have at most ONE place where:
nums[i] > nums[(i+1) % n]

Why?
- In a perfectly sorted array:
  nums[i] <= nums[i+1]
- After rotation:
  only one decreasing point exists
  (the rotation pivot)

If more than one such break exists,
the array cannot be sorted and rotated.

--------------------------------------------------

Steps:
1. Traverse the array
2. Compare:
      nums[i] > nums[(i+1) % n]
3. Count such break points
4. If breaks > 1:
      return false
5. Otherwise:
      return true

--------------------------------------------------

Dry Run:

nums = [3,4,5,1,2]

3 < 4  → OK
4 < 5  → OK
5 > 1  → break = 1
1 < 2  → OK
2 < 3  → OK (circular check)

Total breaks = 1
Answer = true

--------------------------------------------------

Why it works:
- A sorted rotated array has only one transition
  from larger → smaller element.
- Circular comparison handles rotation naturally.
- More than one break means array order
  is violated multiple times.

--------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int breaks = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                breaks++;
            }
        }

        return breaks <= 1;
    }
};