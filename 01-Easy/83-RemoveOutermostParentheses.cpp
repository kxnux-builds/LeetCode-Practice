/*
Problem: Remove Outermost Parentheses
Link: https://leetcode.com/problems/remove-outermost-parentheses/description/
Difficulty: Easy
Topic: String / Stack

Problem Statement:
A valid parentheses string is either:
1. An empty string "".
2. AB, where A and B are valid parentheses strings.
3. (A), where A is a valid parentheses string.

A valid parentheses string is called primitive if it cannot be
split into two non-empty valid parentheses strings.

Given a valid parentheses string `s`, divide it into primitive
strings and remove the outermost parentheses from each primitive.

Return the resulting string.

Example 1:
Input: s = "(()())(())"

Output: "()()()"

Explanation:
The primitive strings are:
"(()())" and "(())"

After removing the outermost parentheses:
"()()" and "()"

Combining them gives:
"()()()"

Example 2:
Input: s = "(()())(())(()(()))"

Output: "()()()()(())"

Example 3:
Input: s = "()()"

Output: ""

Explanation:
The primitive strings are:
"()" and "()"

Removing the outermost parentheses from each leaves:
"" and ""

The final answer is an empty string.

Approach (Greedy + Parentheses Depth):
1. Initialize:
   - `depth = 0` to track the current nesting depth.
   - `result = ""` to store the answer.

2. Traverse each character `c` in `s`:

   If `c == '('`:
   - If `depth > 0`, append '(' to the result.
   - Increase `depth` by 1.

   If `c == ')'`:
   - Decrease `depth` by 1.
   - If `depth > 0`, append ')' to the result.

3. Why does this work?
   - An opening parenthesis is outermost when depth is 0
     before processing it.
   - A closing parenthesis is outermost when depth becomes 0
     after processing it.
   - We skip these outermost parentheses and keep all inner ones.

4. Return `result`.

Time Complexity: O(n)
Space Complexity: O(n), excluding the input string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;

        for (char c : s) {

            // Opening parenthesis
            if (c == '(') {

                // Keep it only if it is not outermost
                if (depth > 0) {
                    result += c;
                }

                depth++;
            }

            // Closing parenthesis
            else {

                depth--;

                // Keep it only if it is not outermost
                if (depth > 0) {
                    result += c;
                }
            }
        }

        return result;
    }
};