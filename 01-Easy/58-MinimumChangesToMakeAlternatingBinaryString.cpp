/*
Problem: Minimum Changes To Make Alternating Binary String
Link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/
Difficulty: Easy
Topic: String / Greedy

Problem Statement:
You are given a binary string `s` consisting only of `'0'` and `'1'`.

In one operation, you can change any character:
- `'0'` → `'1'`
- `'1'` → `'0'`

A string is called **alternating** if no two adjacent characters are the same.
Examples of alternating strings: `"0101"`, `"1010"`.

Return *the minimum number of operations needed to make `s` alternating*. :contentReference[oaicite:0]{index=0}

Example 1:
Input: s = "0100"  
Output: 1  
Explanation:
Change the last character → "0101".

Example 2:
Input: s = "10"  
Output: 0  
Explanation:
Already alternating.

Example 3:
Input: s = "1111"  
Output: 2  
Explanation:
Possible alternating strings: "0101" or "1010". :contentReference[oaicite:1]{index=1}

Approach (Greedy / Pattern Check – Optimal):
There are only **two possible alternating patterns**:
1. Starting with `'0'` → `"010101..."`.
2. Starting with `'1'` → `"101010..."`.

Steps:
1. Traverse the string.
2. Count mismatches if the pattern starts with `'0'`.
3. The number of mismatches for pattern starting with `'1'`
   will be `n - mismatch`.
4. Return the minimum of the two counts.

Intuition:
We simply check which alternating pattern requires fewer flips.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int mismatch = 0;

        // Assume pattern starts with '0'
        for (int i = 0; i < n; i++) {
            char expected = (i % 2 == 0) ? '0' : '1';
            if (s[i] != expected) {
                mismatch++;
            }
        }

        // Compare with pattern starting with '1'
        return min(mismatch, n - mismatch);
    }
};