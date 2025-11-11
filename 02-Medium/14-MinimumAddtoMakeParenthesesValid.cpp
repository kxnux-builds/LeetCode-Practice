/*
Problem: Minimum Add to Make Parentheses Valid
Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
Difficulty: Medium
Topic: Stack / String / Counting

Problem Statement:
A parentheses string is valid if and only if:
1. It is the empty string,
2. It can be written as AB (A concatenated with B), where A and B are valid strings, or
3. It can be written as (A), where A is a valid string.

Given a parentheses string s, return the minimum number of parentheses you must add 
to make the resulting string valid.

Approach:
1. Maintain a counter `balance` to track unmatched '(' parentheses.
2. For each character:
   - If '(', increment balance.
   - If ')':
       - If balance > 0, decrement (we found a match).
       - Else, increment a separate counter `insertions` (we need an extra '(').
3. Final answer = `balance` (unmatched '(') + `insertions` (unmatched ')').

Time Complexity: O(n)   — single pass over the string
Space Complexity: O(1)  — constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0, insertions = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            } else {
                if (balance > 0) {
                    balance--;
                } else {
                    insertions++;
                }
            }
        }
        return balance + insertions;
    }
};