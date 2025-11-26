/*
Problem: Repeated String Match
Link: https://leetcode.com/problems/repeated-string-match/description/
Difficulty: Medium
Topic: String / String Matching

Problem Statement:
Given two strings a and b, return the minimum number of times we must repeat a 
so that b becomes a substring of the repeated string. 
If impossible, return -1.

Example:
Input: a = "abcd", b = "cdabcdab"
Output: 3

Approach (Efficient Check Using Repetition Logic):
1. The repeated string must be at least as long as b.
2. So we repeat string a until its length ≥ length of b.
3. After reaching that length, check if b is a substring.
4. Also check one extra repetition because b may overlap across boundaries.
5. If found in either attempt, return repetition count.
6. Otherwise, return -1.

Time Complexity: O(n + m) average
Space Complexity: O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        // Repeat until repeated string length >= b length
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check current and one more repetition
        if (repeated.find(b) != string::npos) return count;

        repeated += a;
        if (repeated.find(b) != string::npos) return count + 1;

        return -1;
    }
};