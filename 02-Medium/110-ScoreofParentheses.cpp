/*
Problem: Score of Parentheses
Link: https://leetcode.com/problems/score-of-parentheses/description/
Difficulty: Medium
Topic: Stack / String

Problem Statement:
Given a balanced parentheses string `s`, return its score.

The score is calculated using these rules:
1. "()" has a score of 1.
2. AB has a score of A + B, where A and B are balanced parentheses strings.
3. (A) has a score of 2 * A, where A is a balanced parentheses string.

Example:
Input: s = "()()"
Output: 2

Explanation:
"()" has a score of 1.
"()" has a score of 1.

Total score = 1 + 1 = 2.

Example 2:
Input: s = "(())"
Output: 2

Explanation:
"()" has a score of 1.
"(())" doubles the inner score.

Total score = 2 * 1 = 2.

Example 3:
Input: s = "(()(()))"
Output: 6

Explanation:
The innermost "()" has a score of 1.
"(()())" has a score of 1 + 2 = 3.
The outer parentheses double the inner score.

Final score = 6.

Approach (Stack):
1. Create a stack to store the scores of nested parentheses.
2. Initialize the stack with 0 to represent the outermost level.
3. Traverse every character in the string:
   - If the character is '(':
       Push 0 onto the stack to start a new level.
   - If the character is ')':
       Pop the score of the current level.
       - If the score is 0, the pair is "()", so its score is 1.
       - Otherwise, its score is 2 * score.
       Add this value to the score of the previous level.
4. After processing the string, the top of the stack contains
   the total score.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;

        // Initial score for the outermost level
        st.push(0);

        for (char c : s) {

            // Opening parenthesis: start a new level
            if (c == '(') {
                st.push(0);
            }

            // Closing parenthesis: calculate the current score
            else {
                int innerScore = st.top();
                st.pop();

                // "()" scores 1; "(A)" scores 2 * score(A)
                int currentScore = max(1, 2 * innerScore);

                // Add the current score to the previous level
                st.top() += currentScore;
            }
        }

        return st.top();
    }
};