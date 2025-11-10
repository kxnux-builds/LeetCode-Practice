/*
Problem: Reverse String
Link: https://leetcode.com/problems/reverse-string/description/
Difficulty: Easy
Topic: Two Pointers / String

Problem Statement:
Write a function that reverses a string. The input string is given as an array of characters `s`.
You must do this by modifying the input array in-place with O(1) extra memory.

Approach:
1. Use two pointers — one at the start (left) and one at the end (right).
2. Swap the characters at these two positions.
3. Move the pointers toward each other until they meet or cross.
4. Since modifications are in-place, no extra array is used.

Time Complexity: O(n)   — each element visited once
Space Complexity: O(1)  — in-place operation
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};
