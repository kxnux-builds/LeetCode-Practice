/*
Problem: Minimum Add to Make Parentheses Valid
Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
Difficulty: Medium
Topic: String / Greedy / Stack

Problem Statement:
Given a parentheses string `s` consisting only of '(' and ')',
return the minimum number of parentheses we must add to make
the string valid.

A parentheses string is valid if:
1. Every opening parenthesis '(' has a matching closing parenthesis ')'.
2. Every closing parenthesis ')' has a matching opening parenthesis '('.
3. Parentheses are correctly ordered.

Example 1:
Input: s = "())"
Output: 1

Explanation:
Add one '(' at the beginning or end to make the string valid.

Example 2:
Input: s = "((("
Output: 3

Explanation:
Three closing parentheses ')' are needed to match the
three opening parentheses.

Example 3:
Input: s = "()))(("
Output: 4

Explanation:
We need two opening parentheses to match the extra closing
parentheses and two closing parentheses to match the extra
opening parentheses.

Approach (Greedy):
1. Initialize two variables:
   - `open`: counts unmatched opening parentheses.
   - `additions`: counts parentheses that must be added.

2. Traverse every character in `s`:
   - If the character is '(':
       Increase `open` because we have an unmatched opening parenthesis.
   - If the character is ')':
       - If `open > 0`, match it with an existing '(' by decreasing `open`.
       - Otherwise, we need to add an opening parenthesis,
         so increase `additions`.

3. After processing the string, any remaining unmatched opening
   parentheses need closing parentheses.

4. Return:
       additions + open

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int additions = 0;

        for (char c : s) {

            // Count unmatched opening parentheses
            if (c == '(') {
                open++;
            }

            // Match a closing parenthesis or add an opening one
            else {
                if (open > 0) {
                    open--;
                } else {
                    additions++;
                }
            }
        }

        // Remaining opening parentheses need closing parentheses
        return additions + open;
    }
};