/*
Problem: Backspace String Compare
Link: https://leetcode.com/problems/backspace-string-compare/description/
Difficulty: Easy
Topic: String / Stack / Two Pointers

Problem Statement:
Given two strings s and t, return true if they are equal when both are typed into empty text editors.  
'#' means a backspace character. Note that after backspacing an empty text, the text will continue empty.

Approach:
1. Use two pointers starting from the end of each string.
2. Track backspaces for each string and skip characters accordingly.
3. Compare characters from the end to the start.
4. If all characters match, return true; otherwise, return false.

Time Complexity: O(n + m) — n = s.size(), m = t.size()
Space Complexity: O(1) — only counters used, no extra stacks
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') { skipS++; i--; }
                else if (skipS > 0) { skipS--; i--; }
                else break;
            }

            while (j >= 0) {
                if (t[j] == '#') { skipT++; j--; }
                else if (skipT > 0) { skipT--; j--; }
                else break;
            }

            char chS = (i >= 0) ? s[i] : '\0';
            char chT = (j >= 0) ? t[j] : '\0';
            if (chS != chT) return false;

            i--; j--;
        }

        return true;
    }
};