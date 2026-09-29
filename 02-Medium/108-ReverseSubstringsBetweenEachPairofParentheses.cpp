/*
    ============================================================
    Problem: Reverse Substrings Between Each Pair of Parentheses

    Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description

    Difficulty: Medium
    ============================================================

    Problem:
    Given a string containing lowercase letters and parentheses,
    reverse the substring inside every pair of matching parentheses.

    The innermost parentheses are processed first.

    Example:
        Input:  "(u(love)i)"
        Output: "iloveu"

    ------------------------------------------------------------
    Approach: Stack + String
    ------------------------------------------------------------

    We use a stack to store the string that was built before
    entering a pair of parentheses.

    1. If we see '(':
       - Push the current string into the stack.
       - Start a new empty string.

    2. If we see a normal character:
       - Add it to the current string.

    3. If we see ')':
       - Reverse the current string.
       - Take the previous string from the stack.
       - Append the reversed string to it.
       - Remove the previous string from the stack.

    Why does this work?

    Because parentheses can be nested.

    Example:
        (u(love)i)

    The inner "(love)" is closed first, so it gets reversed first:

        love -> evol

    Then the outer substring is processed.

    ------------------------------------------------------------
    Time Complexity:
        O(n^2) worst case

    Space Complexity:
        O(n)
    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";

        for (char ch : s) {

            // Opening parenthesis
            if (ch == '(') {
                st.push(current);
                current = "";
            }

            // Closing parenthesis
            else if (ch == ')') {
                reverse(current.begin(), current.end());

                current = st.top() + current;
                st.pop();
            }

            // Normal character
            else {
                current += ch;
            }
        }

        return current;
    }
};