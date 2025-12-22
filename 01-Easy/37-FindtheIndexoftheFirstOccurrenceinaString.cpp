/*
Problem: Find the Index of the First Occurrence in a String
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
Difficulty: Medium
Topic: Strings / String Matching

Problem Statement:
Given two strings `haystack` and `needle`, return *the index of the first
occurrence* of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

Example:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0

Input: haystack = "leetcode", needle = "leeto"
Output: -1

Approach (KMP – Optimal String Matching):
1. Preprocess `needle` to build a LPS (Longest Prefix-Suffix) array.
2. Use two pointers to traverse `haystack` and `needle`.
3. If chars match: advance both pointers.
4. If mismatch:
   - If `j > 0`, roll back using LPS.
   - If `j == 0`, advance `i` in `haystack`.
5. If `j` reaches `needle.size()`, a match is found → return `i − j`.

Time Complexity: O(n + m)  
Space Complexity: O(m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return 0;

        // Build LPS (longest prefix-suffix) array for needle
        vector<int> lps(m, 0);
        buildLPS(needle, lps);

        int i = 0, j = 0;  // i → haystack, j → needle
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++; j++;
                if (j == m) return i - j;
            } else {
                if (j > 0) j = lps[j - 1];
                else i++;
            }
        }

        return -1;
    }

private:
    void buildLPS(const string &pattern, vector<int> &lps) {
        int len = 0;
        int i = 1;
        int m = pattern.size();

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};