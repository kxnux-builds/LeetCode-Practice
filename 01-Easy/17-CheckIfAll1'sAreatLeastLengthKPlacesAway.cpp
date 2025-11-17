/*
Problem: Check If All 1's Are at Least Length K Places Away
Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/
Difficulty: Easy
Topic: Array / Greedy

Problem Statement:
Given an array nums containing only 0s and 1s, return true if all 1s are at least k places apart.
Otherwise, return false.

Approach:
1. Track the index of the previous '1'. Initialize prev = -1.
2. Traverse the array:
   - When you find a '1':
       • If prev is not -1, check if the gap (i - prev - 1) < k.
         If yes → return false.
       • Update prev = i.
3. If no violations found, return true.

Time Complexity: O(n)     (single pass)
Space Complexity: O(1)    (constant memory)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (prev != -1 && (i - prev - 1) < k)
                    return false;
                prev = i;
            }
        }

        return true;
    }
};