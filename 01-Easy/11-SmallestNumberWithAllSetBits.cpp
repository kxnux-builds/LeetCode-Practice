/*
Problem: Smallest Number With All Set Bits
Link: https://leetcode.com/problems/smallest-number-with-all-set-bits/description/
Difficulty: Easy
Topic: Bit Manipulation / Math

Problem Statement:
You are given a positive integer n. Return the smallest number x such that:
1. x has all bits set to 1 (in binary form), and
2. x is greater than or equal to n.

Example:
Input: n = 5
Binary of 5 = 101
Smallest number >= 5 with all bits set = 111 (which is 7)
Output: 7

Approach:
1. If n is already a power of two minus one (e.g., 1, 3, 7, 15), return n.
2. Otherwise, find the position of the most significant bit (MSB) set in n.
3. Create a number with all bits set up to that position using (1 << bits) - 1.
4. If that number is still < n, increase the bit length by 1 and recompute.

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int bits = 0;
        int temp = n;

        // Count bits required to represent n
        while (temp > 0) {
            bits++;
            temp >>= 1;
        }

        // Create a number with all bits set for the counted length
        int result = (1 << bits) - 1;

        // If it's still smaller than n, increase bit length
        if (result < n)
            result = (1 << (bits + 1)) - 1;

        return result;
    }
};