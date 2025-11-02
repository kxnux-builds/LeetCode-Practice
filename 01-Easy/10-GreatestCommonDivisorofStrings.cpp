/*
Problem: Greatest Common Divisor of Strings
Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
Difficulty: Easy
Topic: String / Math

Problem Statement:
For two strings str1 and str2, we say str1 divides str2 if and only if 
str2 = str1 + str1 + ... + str1 (one or more times).

Given two strings str1 and str2, return the largest string x such that 
x divides both str1 and str2.

Approach:
1. If str1 + str2 != str2 + str1, then no common divisor string exists → return "".
2. Otherwise, the answer is the substring of length gcd(len(str1), len(str2)).
3. Use __gcd() from C++ STL to compute the GCD of lengths.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If they cannot form each other by repetition, no GCD string exists
        if (str1 + str2 != str2 + str1) 
            return "";

        // Greatest common divisor of lengths
        int g = __gcd(str1.size(), str2.size());

        // Return prefix of length g
        return str1.substr(0, g);
    }
};