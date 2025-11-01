/*
Problem: Generate Parentheses
Link: https://leetcode.com/problems/generate-parentheses/description/
Difficulty: Medium
Topic: Backtracking / Recursion / String

Problem Statement:
Given n pairs of parentheses, write a function to generate all combinations of 
well-formed parentheses.

Approach:
1. Use backtracking to build the string step-by-step.
2. Keep track of:
   - open: number of '(' used so far
   - close: number of ')' used so far
3. Add '(' if open < n.
4. Add ')' if close < open (to maintain validity).
5. When the current string length reaches 2 * n, store it in the result list.

Time Complexity: O(4^n / √n)  — number of valid parentheses combinations (Catalan number)
Space Complexity: O(n)        — recursion stack depth
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;

        function<void(int, int)> backtrack = [&](int open, int close) {
            if (current.size() == 2 * n) {
                result.push_back(current);
                return;
            }

            if (open < n) {
                current.push_back('(');
                backtrack(open + 1, close);
                current.pop_back();
            }

            if (close < open) {
                current.push_back(')');
                backtrack(open, close + 1);
                current.pop_back();
            }
        };

        backtrack(0, 0);
        return result;
    }
};
