/*
Problem: Prime Number of Set Bits in Binary Representation
Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/
Difficulty: Easy
Topic: Bit Manipulation / Simulation / Math

Problem Statement:
Given two integers `left` and `right`, return the **count of numbers** in the inclusive range `[left, right]` 
whose binary representations have a number of set bits (`1`s) that is **a prime number**.

Example:
Input: left = 6, right = 10  
Output: 4  
Explanation:  
6  -> binary `110`  -> 2 set bits → 2 is prime  
7  -> binary `111`  -> 3 set bits → 3 is prime  
8  -> binary `1000` -> 1 set bit  → 1 is not prime  
9  -> binary `1001` -> 2 set bits → 2 is prime  
10 -> binary `1010` -> 2 set bits → 2 is prime  
Total = 4

Example:
Input: left = 10, right = 15  
Output: 5

Approach (Bit Count + Prime Lookup – Optimal):
1. Precompute a **small set of prime values** up to `32` (since max bits ≤ 32 for typical 32-bit ints).
2. For each integer `x` from `left` to `right`:
   - Count the number of set bits using `__builtin_popcount(x)`.
   - Check if that count exists in the prime set.
3. Increment the answer when true.

Time Complexity: O(N) where N = `right - left + 1`  
Space Complexity: O(1) — only a fixed prime lookup set

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Set of primes up to 32
        unordered_set<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        
        int result = 0;
        for (int x = left; x <= right; x++) {
            int bits = __builtin_popcount(x);
            if (prime.count(bits)) {
                result++;
            }
        }
        return result;
    }
};