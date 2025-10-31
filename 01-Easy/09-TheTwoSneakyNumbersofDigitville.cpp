/*
Problem: The Two Sneaky Numbers of Digitville
Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/
Difficulty: Easy
Topic: Array / Hash Map

Problem Statement:
In Digitville, every number is unique except for two sneaky numbers that appear twice.  
Given an array nums containing n + 2 integers, where exactly two numbers appear twice 
and all others appear once, return the two sneaky numbers in any order.

Approach:
1. Use a hash map (unordered_map) to count occurrences of each number.
2. Traverse the array:
   - Increment count for each number.
   - If a number’s count becomes 2, add it to the result.
3. Return the result containing the two sneaky numbers.

Time Complexity: O(n)    — single pass through the array
Space Complexity: O(n)   — for storing counts in hash map
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> result;

        for (int num : nums) {
            count[num]++;
            if (count[num] == 2) {
                result.push_back(num);
            }
        }

        return result;
    }
};
