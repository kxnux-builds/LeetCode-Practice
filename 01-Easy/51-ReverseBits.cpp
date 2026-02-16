/*
Problem: Reverse Bits
Link: https://leetcode.com/problems/reverse-bits/description/
Difficulty: Easy
Topic: Bit Manipulation / Math

Problem Statement:
Given a 32-bit unsigned integer `n`, reverse its bits and return the resulting unsigned integer.

Example:
Input:  n = 00000010100101000001111010011100
Output:       00111001011110000010100101000000
Explanation: The reversed binary represents 964176192.

Example:
Input:  n = 11111111111111111111111111111101
Output:   10111111111111111111111111111111
Explanation: The reversed binary represents 3221225471.

Approach (Bit-by-Bit Reversal – Optimal):
1. Initialize `result = 0`.
2. Iterate exactly 32 times (since integer is 32-bit).
3. In each iteration:
   - Left shift `result` to make space for next bit.
   - Extract last bit of `n` using `(n & 1)`.
   - Add extracted bit to `result`.
   - Right shift `n` to process next bit.
4. After 32 iterations, `result` contains reversed bits.

Time Complexity: O(1)   // Always 32 iterations
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++) {
            result <<= 1;        // Make space
            result |= (n & 1);   // Add last bit of n
            n >>= 1;             // Shift n to right
        }

        return result;
    }
};