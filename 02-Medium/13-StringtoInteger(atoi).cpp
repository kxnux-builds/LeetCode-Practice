/*
Problem: String to Integer (atoi)
Link: https://leetcode.com/problems/string-to-integer-atoi/description/
Difficulty: Medium
Topic: String / Simulation

Problem Statement:
Implement the function `myAtoi(string s)` which converts a string to a 32-bit signed integer (similar to C/C++ `atoi`).  
The function should:
1. Discard leading whitespace.
2. Optional '+' or '-' sign.
3. Read digits until a non-digit character is encountered.
4. Clamp the result within the 32-bit signed integer range [-2^31, 2^31 - 1].

Approach:
1. Skip leading whitespaces.
2. Check for '+' or '-' sign.
3. Traverse each digit, updating the result.
4. Handle overflow by clamping to INT_MAX or INT_MIN.
5. Return the final integer.

Time Complexity: O(n) — traverse the string once
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ') i++;  // skip whitespaces

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (sign * result > INT_MAX) return INT_MAX;
            if (sign * result < INT_MIN) return INT_MIN;
            i++;
        }

        return (int)(sign * result);
    }
};
