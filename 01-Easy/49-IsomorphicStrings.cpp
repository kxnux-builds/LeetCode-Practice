/*
Problem: Isomorphic Strings
Link: https://leetcode.com/problems/isomorphic-strings/description/
Difficulty: Easy
Topic: Strings / Hash Map / Mapping

Problem Statement:
Given two strings `s` and `t`, determine if they are **isomorphic**.

Two strings are isomorphic if the characters in `s` can be replaced to get `t`,
such that:
  • All occurrences of a character must be replaced with the same character.
  • No two characters may map to the same character.
  • The order of characters is preserved.

Example:
Input: s = "egg", t = "add"  
Output: true

Example:
Input: s = "foo", t = "bar"  
Output: false

Example:
Input: s = "paper", t = "title"  
Output: true

Approach (Two-Way Hash Mapping – Optimal):
1. Ensure both strings have the **same length**; otherwise return `false`.
2. Use two maps/arrays:
   - `mapST` to map chars from `s` → `t`
   - `mapTS` to map chars from `t` → `s`
3. Iterate through the characters:
   - If `s[i]` has an existing mapping, ensure it matches `t[i]`.
   - If `t[i]` has an existing mapping, ensure it matches `s[i]`.
   - If mappings conflict → return `false`.
   - Otherwise store the new mapping in both maps.
4. If no conflicts found → return `true`.

Time Complexity: O(n)  
Space Complexity: O(1) — limited alphabet
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<char> mapST(256, 0);
        vector<char> mapTS(256, 0);

        for (int i = 0; i < s.size(); ++i) {
            char cs = s[i], ct = t[i];

            // s → t
            if (mapST[cs] == 0 && mapTS[ct] == 0) {
                mapST[cs] = ct;
                mapTS[ct] = cs;
            } else {
                // check existing mapping
                if (mapST[cs] != ct || mapTS[ct] != cs)
                    return false;
            }
        }
        return true;
    }
};