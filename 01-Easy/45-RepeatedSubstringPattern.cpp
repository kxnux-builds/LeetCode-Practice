/*
Problem: Repeated Substring Pattern
Link: https://leetcode.com/problems/repeated-substring-pattern/description/
Difficulty: Easy
Topic: Strings / Simulation / Math

Problem Statement:
Given a string `s`, return `true` if it can be constructed by taking a substring of it
and appending multiple copies of the substring together. Otherwise, return `false`.

Example:
Input: s = "abab"  
Output: true  
Explanation: It is formed by repeating substring "ab".

Example:
Input: s = "aba"  
Output: false

Approach (String Trick – Optimal):
1. Let `t = s + s`.
2. Remove the **first** and the **last** character from `t` → call this `modified`.
3. If `s` occurs in `modified`, then `s` is made of a repeated substring.
4. Otherwise, it is not.

Why this works:
- Repeating `s` twice and removing edge characters produces all possible rotations
  of `s`. If `s` can be built from a smaller repeated substring, one of these
  rotations will match the original `s`.

Time Complexity: O(n²) in worst case  
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        string modified = t.substr(1, t.size() - 2);
        return modified.find(s) != string::npos;
    }
};