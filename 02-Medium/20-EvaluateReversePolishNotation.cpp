/*
Problem: Evaluate Reverse Polish Notation
Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
Difficulty: Medium
Topic: Stack / Math

Problem Statement:
You are given an array of strings tokens representing an arithmetic expression 
in Reverse Polish Notation (RPN). Evaluate the expression and return the result.

Valid operators: +, -, *, /
Each operand may be an integer.
Division should truncate toward zero.

Example:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: (2 + 1) * 3 = 9

Approach (Using Stack):
1. Use a stack to store operands.
2. Traverse each token:
   - If it's a number: push onto stack.
   - If it's an operator:
       - Pop top two numbers (b = top, a = second top)
       - Compute a op b
       - Push result back to stack.
3. At the end, the stack contains exactly one element (the answer).

Time Complexity: O(n)
Space Complexity: O(n) — stack for operands
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& t : tokens) {
            if (isOperator(t)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(apply(a, b, t));
            } else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }

private:
    bool isOperator(const string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int apply(int a, int b, const string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        return a / b;   // truncates toward zero
    }
};