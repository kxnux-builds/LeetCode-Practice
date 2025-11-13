/*
Problem: Maximum Number of Operations to Move Ones to the End
Link: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/
Difficulty: Medium
Topic: String / Greedy

Problem Statement:
You are given a binary string s. In one operation, you may choose an index i such that s[i] = '0',
and there is a '1' somewhere to the right of index i. Then you can move that '1' to position i by
shifting all characters between i and that '1' one step to the right.
Return the maximum number of operations you can perform.

Approach:
1. Traverse the string from left to right.
2. Count the number of '1's seen so far as you go (ones).
3. Whenever you encounter a '0' which is the last character or is followed by a '1', you can perform
   an operation for each previously counted '1' (because each of those can be moved into this zero position).
4. Sum up these counts to get the answer.

Time Complexity: O(n)  — single pass through the string s. :contentReference[oaicite:0]{index=0}  
Space Complexity: O(1)  — only counters used, no extra data structures
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxOperations(string s) {
        long long ans = 0;
        long long ones = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ones++;
            } else {
                // we have a '0' – check if at end or next is '1'
                if (i + 1 == n || s[i + 1] == '1') {
                    ans += ones;
                }
            }
        }
        return ans;
    }
};