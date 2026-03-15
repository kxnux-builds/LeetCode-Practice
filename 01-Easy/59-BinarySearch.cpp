/*
Problem: Binary Search
Link: https://leetcode.com/problems/binary-search/description/
Difficulty: Easy
Topic: Array / Binary Search

Problem Statement:
Given a **sorted array of integers** `nums` (sorted in ascending order)
and an integer `target`, return the **index of `target`** if it exists
in the array. Otherwise return `-1`. :contentReference[oaicite:0]{index=0}

You must write an algorithm with **O(log n)** runtime complexity. :contentReference[oaicite:1]{index=1}

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9  
Output: 4  
Explanation: 9 exists in nums and its index is 4.

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2  
Output: -1  
Explanation: 2 does not exist in nums.

Constraints:
1 <= nums.length <= 10^4  
-10^4 < nums[i], target < 10^4  
All integers in `nums` are unique and sorted in ascending order. :contentReference[oaicite:2]{index=2}

--------------------------------------------------

Approach (Classic Binary Search – Optimal):

Key Idea:
Because the array is **sorted**, we can repeatedly divide the search
space in half.

Steps:
1. Initialize two pointers:
   - `left = 0`
   - `right = n - 1`
2. While `left <= right`:
   - Compute `mid = left + (right - left) / 2`
3. Compare `nums[mid]` with `target`:
   - If equal → return `mid`
   - If `nums[mid] < target` → search right half (`left = mid + 1`)
   - If `nums[mid] > target` → search left half (`right = mid - 1`)
4. If loop finishes without finding target → return `-1`.

Intuition:
Binary search **cuts the search space in half each step**, giving
logarithmic time complexity. :contentReference[oaicite:3]{index=3}

--------------------------------------------------

Time Complexity: O(log n)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};