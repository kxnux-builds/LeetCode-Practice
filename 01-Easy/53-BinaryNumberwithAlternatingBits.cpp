/*
Problem: Binary Number with Alternating Bits
Link: https://leetcode.com/problems/binary-number-with-alternating-bits/description/
Difficulty: Easy
Topic: Bit Manipulation / Simulation / Math

Problem Statement:
Given a positive integer `n`, check whether its binary representation has **alternating bits**.
That is, no two adjacent bits are the same (e.g., 101010...).

Return `true` if the bits alternate, otherwise return `false`.

Example:
Input: n = 5  
Output: true  
Explanation: Binary of 5 is `101`, which has alternating bits.

Example:
Input: n = 7  
Output: false  
Explanation: Binary of 7 is `111`, which does not alternate.

Example:
Input: n = 11  
Output: false  
Explanation: Binary of 11 is `1011`, adjacent `1`s at the end.

Approach (Bitwise Check – Optimal):
1. Track the **last bit** seen while iterating through the bits of `n`.
2. For each bit from least significant to most:
   - Extract current bit with `(n & 1)`.
   - If it equals the last bit, return `false`.
   - Otherwise update last bit and shift `n` right by 1.
3. If no adjacent matches found → return `true`.

Time Complexity: O(log n) — proportional to number of bits in `n`.  
Space Complexity: O(1) — uses only a few variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastBit = n & 1;
        n >>= 1;

        while (n > 0) {
            int currBit = n & 1;
            if (currBit == lastBit) {
                return false;
            }
            lastBit = currBit;
            n >>= 1;
        }

        return true;
    }
};