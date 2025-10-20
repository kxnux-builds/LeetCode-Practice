/*
Problem: Final Value of Variable After Performing Operations
Link: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/
Difficulty: Easy
Topic: Simulation / String

Problem Statement:
There is a programming language with only four operations and one variable X:

- "++X" and "X++" increments the value of X by 1.
- "--X" and "X--" decrements the value of X by 1.

Initially, the value of X is 0.

Given an array of strings operations containing a list of operations,
return the final value of X after performing all the operations.

Approach:
1. Initialize X = 0.
2. Traverse each string in the operations array.
3. If the operation contains '+' (i.e., "++X" or "X++"), increment X.
4. Else, decrement X.
5. Return X.

Time Complexity: O(n)  — where n is the number of operations
Space Complexity: O(1) — only one integer variable used
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (const auto &op : operations) {   // using reference to avoid copying strings
            if (op[1] == '+') X++;           // middle char '+' means increment
            else X--;                        // otherwise decrement
        }
        return X;
    }
};
