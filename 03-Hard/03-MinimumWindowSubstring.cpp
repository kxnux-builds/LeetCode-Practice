/*
Problem: Minimum Window Substring
Link: https://leetcode.com/problems/minimum-window-substring/description/
Difficulty: Hard
Topic: String / Sliding Window / Hash Map

Problem Statement:
Given two strings s and t, return the minimum window in s which contains all 
the characters of t. If no such window exists, return an empty string "".

Approach:
1. Use a hash map to count characters in t.
2. Use two pointers (left, right) to maintain a sliding window over s.
3. Expand the window by moving right until all characters of t are covered.
4. Shrink the window from left to minimize its length while still covering t.
5. Keep track of the minimum window found.

Time Complexity: O(n + m) — n = s.size(), m = t.size()
Space Complexity: O(1) — character count maps are fixed size (ASCII)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> tCount;
        for (char c : t) tCount[c]++;

        unordered_map<char, int> windowCount;
        int required = tCount.size();
        int formed = 0;

        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;

        while (right < s.size()) {
            char c = s[right];
            windowCount[c]++;

            if (tCount.count(c) && windowCount[c] == tCount[c])
                formed++;

            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                windowCount[leftChar]--;
                if (tCount.count(leftChar) && windowCount[leftChar] < tCount[leftChar])
                    formed--;

                left++;
            }

            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};