/*
Problem: Smallest Subsequence of Distinct Characters
Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/
Difficulty: Medium
Topic: Stack / Greedy / String

Problem Statement:
Given a string `s`, return *the lexicographically smallest subsequence* of `s`  
that contains **all the distinct characters of `s` exactly once**.

Example:
Input: s = "cbacdcbc"  
Output: "acdb"

Explanation:
- The distinct characters in `s` are `{a, b, c, d}`.
- Among all subsequences that contain each distinct letter exactly once, `"acdb"`  
  is the lexicographically smallest.

Approach (Greedy + Monotonic Stack):
1. Count the **frequency** of each character in the string.
2. Use a **stack** to build the result subsequence:
   - Maintain a boolean `inStack[26]` to avoid duplicates.
   - Traverse each character `c` in `s`:
     - Decrement its frequency (used up for current position).
     - If already in stack → skip.
     - Otherwise, while:
         - stack not empty,
         - top character > current character (lexicographically),
         - and the character at the top still appears later (freq > 0),
       pop from stack (to get smaller lexicographic result).
     - Push current character and mark it in stack.
3. Result is the stack content (in order).

Time Complexity: O(n)  
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> inStack(26, false);

        // Count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }

        stack<char> st;

        for (char c : s) {
            int idx = c - 'a';
            freq[idx]--;  // using one frequency of c

            // skip if already in stack
            if (inStack[idx]) continue;

            // Greedily pop bigger chars if they appear later
            while (!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[idx] = true;
        }

        // Form result from stack
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};