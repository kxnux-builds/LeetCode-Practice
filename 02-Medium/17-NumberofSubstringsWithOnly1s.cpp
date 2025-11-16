/*
Problem: Number of Substrings With Only 1s
Link: https://leetcode.com/problems/number-of-substrings-with-only-1s/description/
Difficulty: Medium
Topic: String / Math / Counting

Problem Statement:
Given a binary string s, return the number of substrings that contain only '1's.

For every consecutive group of '1's of length L:
    Number of substrings = L * (L + 1) / 2

Example:
s = "0110111"
Consecutive 1s groups = [2, 3]
Total = (2*3)/2 + (3*4)/2 = 3 + 6 = 9

Approach:
1. Traverse the string.
2. Count the length of consecutive '1's.
3. Whenever a '0' is encountered or end is reached:
   - Add L*(L+1)/2 to answer.
   - Reset count to 0.
4. Return the final sum.

Time Complexity: O(n)      (single pass)
Space Complexity: O(1)     (just counters)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        long long count = 0;
        long long mod = 1e9 + 7;

        for (char c : s) {
            if (c == '1') {
                count++;
            } else {
                ans = (ans + (count * (count + 1)) / 2) % mod;
                count = 0;
            }
        }

        ans = (ans + (count * (count + 1)) / 2) % mod;
        return ans;
    }
};
