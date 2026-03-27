/*
Problem: Move Zeroes
Link: https://leetcode.com/problems/move-zeroes/
Difficulty: Easy
Topic: Array / Two Pointers

Problem Statement:
Given an integer array `nums`, move all `0`s to the **end** of the array
while maintaining the **relative order of the non-zero elements**.

Example 1:
Input: nums = [0,1,0,3,12]  
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]  
Output: [0]

Constraints:
1 <= nums.length <= 10^4  
-2^31 <= nums[i] <= 2^31 - 1

--------------------------------------------------

Approach (Two Pointers – Optimal):

Key Idea:
Use a pointer `j` to track the position where the next **non-zero**
element should be placed.

Steps:
1. Initialize `j = 0`
2. Traverse array with index `i`:
   - If `nums[i] != 0`:
     - Swap `nums[i]` with `nums[j]`
     - Increment `j`
3. All non-zero elements shift to front, zeros move to end.

Why it works:
- Maintains order of non-zero elements
- Moves zeros automatically to the back

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // position for next non-zero

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};