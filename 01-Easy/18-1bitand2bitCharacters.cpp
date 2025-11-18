/*
Problem: 1-bit and 2-bit Characters
Link: https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
Difficulty: Easy
Topic: Array / Simulation

Problem Statement:
We have an array bits where:
- '0' represents a 1-bit character
- '10' or '11' represents a 2-bit character

The array always ends with a single '0'.
Return true if the last character must be a 1-bit character, otherwise false.

Approach:
1. Traverse the array from left to right.
2. If the current bit is 1 → it is a 2-bit character, so skip 2 positions.
3. If the current bit is 0 → it's a 1-bit character, skip 1 position.
4. At the end, check if we land exactly on the last index.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        
        while (i < n - 1) {        // stop before the last bit
            if (bits[i] == 1)
                i += 2;           // 2-bit character
            else
                i += 1;           // 1-bit character
        }
        
        return i == n - 1;         // true if last character is 1-bit
    }
};