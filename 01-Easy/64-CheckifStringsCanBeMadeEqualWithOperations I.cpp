/*
Problem: Check if Strings Can Be Made Equal With Operations I
Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/
Difficulty: Easy
Topic: String / Simulation

Problem Statement:
You are given two strings `s1` and `s2` of equal length (length = 4).

In one operation, you can choose two indices `i` and `j` such that:
- `j - i = 2`
and swap `s1[i]` with `s1[j]`.

Return `true` if you can make `s1` equal to `s2` using any number of operations,
otherwise return `false`.

Example 1:
Input: s1 = "abcd", s2 = "cdab"  
Output: true  

Example 2:
Input: s1 = "abcd", s2 = "dacb"  
Output: false  

--------------------------------------------------

Approach (Grouping Indices – Optimal):

Key Idea:
Allowed swaps:
- index 0 ↔ 2
- index 1 ↔ 3

So we can freely rearrange:
- characters at even indices (0, 2)
- characters at odd indices (1, 3)

Steps:
1. Extract characters from:
   - even positions → (0, 2)
   - odd positions → (1, 3)
2. Sort both groups for `s1` and `s2`
3. Compare:
   - even groups must match
   - odd groups must match
4. If both match → return true

--------------------------------------------------

Time Complexity: O(1) (fixed size = 4)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string even1 = "", odd1 = "";
        string even2 = "", odd2 = "";

        // Separate characters by index parity
        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0) {
                even1 += s1[i];
                even2 += s2[i];
            } else {
                odd1 += s1[i];
                odd2 += s2[i];
            }
        }

        // Sort and compare
        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());
        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());

        return (even1 == even2 && odd1 == odd2);
    }
};