/*
Problem: Sort Integers by The Number of 1 Bits
Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/
Difficulty: Easy
Topic: Sorting / Bit Manipulation

Problem Statement:
Given an integer array `arr`, sort the array in **ascending order** by:
1. The number of `1` bits in the binary representation of each number.
2. If two numbers have the same number of `1` bits, sort by **numeric value**.

Return the sorted array.

Example:
Input: arr = [0,1,2,3,4,5,6,7,8]  
Output: [0,1,2,4,8,3,5,6,7]  
Explanation:
Binary representations:
0 → 0 bits  
1 → 1 bit  
2 (10) → 1 bit  
3 (11) → 2 bits  
4 (100) → 1 bit  
5 (101) → 2 bits  
6 (110) → 2 bits  
7 (111) → 3 bits  
8 (1000) → 1 bit

Example:
Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]  
Output: [1,2,4,8,16,32,64,128,256,512,1024]  
Explanation: All have 1 bit; sorted numerically.

Approach (Custom Sort using Bit Count – Optimal):
1. Define a comparator that:
   - First compares the number of set bits (`__builtin_popcount`).
   - Then compares values if bit counts are equal.
2. Sort the array using this comparator.
3. Return the result.

Time Complexity: O(n log n) → due to sorting  
Space Complexity: O(log n) → sorting stack overhead
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);
            if (ca == cb) return a < b;
            return ca < cb;
        });
        return arr;
    }
};