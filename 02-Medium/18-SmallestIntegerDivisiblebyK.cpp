/*
Problem: Smallest Integer Divisible by K
Link: https://leetcode.com/problems/smallest-integer-divisible-by-k/description/
Difficulty: Medium
Topic: Math / Modular Arithmetic / Simulation

Problem Statement:
Given an integer K, return the length of the smallest positive integer 
consisting only of the digit '1' that is divisible by K.

If no such integer exists, return -1.

Important Observations:
1. If K is divisible by 2 or 5 → No number consisting of only '1's can be divisible.
2. We never need to construct the entire number (it grows exponentially).
   Use modular arithmetic:
     - Start with num = 1
     - At each step: num = (num * 10 + 1) % K
     - If num becomes 0 → we found the answer.

3. The maximum repetitions needed is K (Pigeonhole Principle).
   After K iterations, cycle repeats → no answer.

Time Complexity: O(K)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;

        int rem = 1;
        for (int len = 1; len <= K; len++) {
            if (rem % K == 0) return len;
            rem = (rem * 10 + 1) % K;
        }

        return -1;
    }
};