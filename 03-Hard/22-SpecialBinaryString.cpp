/*
Problem: Special Binary String
Link: https://leetcode.com/problems/special-binary-string/description/
Difficulty: Hard
Topic: Recursion / Greedy / String

Problem Statement:
A **special binary string** is a binary string with two properties:
1. The number of `1`s is equal to the number of `0`s.
2. Every prefix has at least as many `1`s as `0`s.

You are given a special binary string `s`.  
A **move** consists of selecting two consecutive, non-empty, special substrings of `s` and swapping them.  
Two strings are consecutive if the last character of the first is immediately before the first character of the second.

Return *the lexicographically largest string possible* after applying any number of such moves.

Example:
Input:  s = "11011000"  
Output:     "11100100"  
Explanation: By swapping special substrings "10" and "1100", we can form the largest possible result. :contentReference[oaicite:0]{index=0}

Example:
Input:  s = "10"  
Output:    "10"  
This is already the only valid special string. :contentReference[oaicite:1]{index=1}

Approach (Recursive Greedy + Sort – Optimal):
The lexicographically largest special string can be built by:
1. Splitting `s` into consecutive special substrings by scanning with a balance counter (`1` increases, `0` decreases); every time balance reaches `0`, a special substring ends.
2. Recursively transforming the *inside* (without the outer `1` … `0`) of each special substring to its largest form.
3. Sorting all these special substrings in **descending lexicographic order**.
4. Concatenating them to produce the result.

The idea relies on:
- A special binary string is analogous to a valid parentheses sequence.
- You can independently optimize each primitive segment and then order them greedily to maximize the result. :contentReference[oaicite:2]{index=2}

Time Complexity: O(n²) — worst-case sorting & recursive concatenation.  
Space Complexity: O(n) — recursion and temporary storage.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) return "";

        vector<string> parts;
        int balance = 0, start = 0;

        // 1. Split into primitive special substrings
        for (int i = 0; i < s.size(); i++) {
            balance += (s[i] == '1' ? 1 : -1);
            if (balance == 0) {
                // Recursively solve the inside (strip outer 1 and 0)
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // 2. Sort parts in descending lexicographic order
        sort(parts.begin(), parts.end(), greater<string>());

        // 3. Concatenate
        string result;
        for (auto &p : parts) {
            result += p;
        }
        return result;
    }
};