/*
Problem: Sort Colors
Link: https://leetcode.com/problems/sort-colors/description/
Difficulty: Medium
Topic: Array / Two Pointers / Dutch National Flag Algorithm

Problem Statement:
Given an array nums with n objects colored:
0 → red
1 → white
2 → blue

Sort them in-place so that objects of the same color are adjacent,
with the colors in order: 0s, then 1s, then 2s.

Example:
Input:
nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Approach (Dutch National Flag – Optimal):
1. Use three pointers:
   - low → boundary for 0
   - mid → current index
   - high → boundary for 2
2. Traverse while mid <= high:
   - If nums[mid] == 0 → swap with nums[low], low++, mid++
   - If nums[mid] == 1 → mid++
   - If nums[mid] == 2 → swap with nums[high], high--
3. This sorts the array in a single pass.

Time Complexity: O(n)
Space Complexity: O(1) — in-place sorting
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};