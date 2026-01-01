/*
Problem: Split Array Largest Sum
Link: https://leetcode.com/problems/split-array-largest-sum/description/
Difficulty: Hard
Topic: Array / Binary Search / Greedy

Problem Statement:
Given an array `nums` and an integer `m`, split the array into **m non-empty
continuous subarrays** such that the **largest sum among these subarrays** is minimized.
Return this minimized largest sum.

Example:
Input: nums = [7,2,5,10,8], m = 2  
Output: 18  
Explanation:  
There are 4 ways to split into two subarrays:
1) [7] and [2,5,10,8] → max sum = 25  
2) [7,2] and [5,10,8] → max sum = 23  
3) [7,2,5] and [10,8] → max sum = 18  
4) [7,2,5,10] and [8] → max sum = 22  
The best split minimizes the largest sum → 18.

Approach (Binary Search on Answer + Greedy Check):
1. The answer must be between:
   - `left = max(nums)` → no split can reduce the largest element
   - `right = sum(nums)` → whole array as one segment
2. Do binary search on this range:
   - mid = (left + right) / 2 (candidate largest sum limit)
   - Check if it is possible to split into **≤ m** subarrays with each sum ≤ mid:
       - Greedily accumulate subarray sums
       - If current sum + num > mid → start new subarray
       - Count subarrays → must be ≤ m
3. If greedy check passes → try smaller sum (right = mid)
   else → increase sum (left = mid + 1)
4. Return left (minimum largest sum achieving ≤ m splits)

Time Complexity: O(n * log(sum(nums)))  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (int x : nums) {
            left = max(left, (long long)x);
            right += x;
        }

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canSplit(nums, m, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return (int)left;
    }

private:
    bool canSplit(vector<int>& nums, int m, long long maxSum) {
        long long curr = 0;
        int count = 1;

        for (int x : nums) {
            if (curr + x <= maxSum) {
                curr += x;
            } else {
                curr = x;
                count++;
                if (count > m) return false;
            }
        }

        return true;
    }
};