/*
Problem: Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/description/
Difficulty: Easy
Topic: String / Hash Map

Problem Statement:
Given a Roman numeral string s, convert it to an integer.  
Roman numerals are represented by the symbols I, V, X, L, C, D, and M.  

Approach:
1. Create a mapping of Roman numerals to their integer values.
2. Traverse the string from left to right:
   - If the current value < next value, subtract current from total.
   - Otherwise, add current to total.
3. Return the accumulated total.

Time Complexity: O(n) — traverse the string once
Space Complexity: O(1) — only fixed-size map used
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && mp[s[i]] < mp[s[i + 1]]) {
                total -= mp[s[i]];
            } else {
                total += mp[s[i]];
            }
        }
        return total;
    }
};