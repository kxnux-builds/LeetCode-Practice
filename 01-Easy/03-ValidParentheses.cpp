/*
Problem: Valid Parentheses
Link: https://leetcode.com/problems/valid-parentheses/description/
Difficulty: Easy
Topic: String

Problem Statement:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
- Open brackets are closed by the same type of brackets.
- Open brackets are closed in the correct order.

Approach:
1. Use a string as a manual stack to track opening brackets.
2. Traverse the string:
   - If the current character is an opening bracket, push it into the string.
   - If it is a closing bracket, check if it matches the last pushed opening bracket.
3. If all brackets match correctly and stack becomes empty, return true.

Time Complexity: O(n)
Space Complexity: O(n) in worst case
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string stk; // using string as stack
        for (char c : s) {
            if (c=='(' || c=='{' || c=='[') {
                stk.push_back(c);
            } else {
                if (stk.empty()) return false;
                char top = stk.back();
                stk.pop_back();
                if ((c==')' && top!='(') || (c=='}' && top!='{') || (c==']' && top!='['))
                    return false;
            }
        }
        return stk.empty();
    }
};
