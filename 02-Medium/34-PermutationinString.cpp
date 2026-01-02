/*
Problem: Permutation in String
Link: https://leetcode.com/problems/permutation-in-string/description/
Difficulty: Medium
Topic: Strings / Sliding Window / Hashing

Problem Statement:
Given two strings `s1` and `s2`, return true if `s2` contains a **permutation** of `s1`.  
In other words, return true if one of s1’s permutations is a substring of s2.

Example:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Approach (Sliding Window with Frequency Counts):
1. If `s1.size() > s2.size()` → return false (impossible).
2. Use two frequency arrays of size 26: `freq1` for s1 and `freq2` for current window in s2.
3. Initialize `freq1` with counts from `s1`, and fill the first window (`0 to s1.size()−1`) in `s2`.
4. Slide the window one character at a time:
   - At each step, compare `freq1` and `freq2`.
   - If equal at any point → true.
   - Update `freq2`:
       * remove left character
       * add new right character
5. If no matching window found → false.

Time Complexity: O(n + m) → n = s1.size(), m = s2.size()  
Space Complexity: O(1) → fixed alphabet count (26)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        for (char c : s1) freq1[c - 'a']++;
        for (int i = 0; i < n1; i++) freq2[s2[i] - 'a']++;

        if (freq1 == freq2) return true;

        for (int i = n1; i < n2; i++) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - n1] - 'a']--;
            if (freq1 == freq2) return true;
        }

        return false;
    }
};