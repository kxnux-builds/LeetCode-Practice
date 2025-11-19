/*
Problem: Keep Multiplying Found Values by Two
Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/
Difficulty: Easy
Topic: Array / Hash Set / Simulation

Problem Statement:
You are given an array nums and an integer original.
While original is found in nums, multiply original by 2.
Return the final value of original.

Approach:
1. Insert all elements of nums into an unordered_set for O(1) lookups.
2. While original exists in the set, multiply it by 2.
3. Once it's not found, return it.

Time Complexity: O(n) for building the set + O(k) checks  
Space Complexity: O(n) for the set
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st(nums.begin(), nums.end());

        while (st.count(original))
            original *= 2;

        return original;
    }
};