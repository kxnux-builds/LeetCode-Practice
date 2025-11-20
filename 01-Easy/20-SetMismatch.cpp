/*
Problem: Set Mismatch
Link: https://leetcode.com/problems/set-mismatch/description/
Difficulty: Easy
Topic: Array / Math / Hashing

Problem Statement:
You are given an integer array nums of length n, where the numbers are supposed 
to be from 1 to n. But:
- One number appears twice.
- One number is missing.

Return the number that is duplicated and the number that is missing.

Example:
Input: nums = [1,2,2,4]
Output: [2,3]

Approach (Most Optimized - O(n) time, O(1) extra space):
1. Use the array index as a marking mechanism.
2. For each number x in nums:
     - Let idx = abs(x) - 1.
     - If nums[idx] < 0 → this index was visited earlier → duplicate found.
     - Else mark visited: nums[idx] *= -1.
3. After marking, the index where value is still positive is the missing number.
4. Return {duplicate, missing}.

Time Complexity: O(n)
Space Complexity: O(1) (in-place marking)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1, missing = -1;

        for (int x : nums) {
            int idx = abs(x) - 1;

            if (nums[idx] < 0)
                duplicate = abs(x);    // already visited → duplicate
            else
                nums[idx] *= -1;       // mark visited
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missing = i + 1;       // index not visited
                break;
            }
        }

        return {duplicate, missing};
    }
};