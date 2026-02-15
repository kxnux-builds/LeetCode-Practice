/*
Problem: Add Binary
Link: https://leetcode.com/problems/add-binary/description/
Difficulty: Easy
Topic: Strings / Simulation / Math

Problem Statement:
Given two binary strings `a` and `b`, return *their sum* as a binary string.

Example:
Input: a = "11", b = "1"  
Output: "100"

Example:
Input: a = "1010", b = "1011"  
Output: "10101"

Approach (Two-Pointer Addition – Optimal):
1. Use two pointers starting from the **end** of each string.
2. Maintain a carry (`0` or `1`) as you add corresponding digits.
3. For each position:
   - Add the digit from string `a` (if available).
   - Add the digit from string `b` (if available).
   - Add carry.
   - Append the result bit `(sum % 2)` to answer.
   - Update carry `= sum / 2`.
4. After processing both strings, if `carry` remains → append it.
5. Reverse the answer string and return.

Time Complexity: O(max(n, m))  
Space Complexity: O(max(n, m))  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += (a[i--] - '0');
            if (j >= 0) sum += (b[j--] - '0');

            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};