/*
Problem: Four Divisors
Link: https://leetcode.com/problems/four-divisors/description/
Difficulty: Medium
Topic: Math / Number Theory / Divisors

Problem Statement:
Given an integer array `nums`, return *the sum of all divisors* of integers
in the array that have **exactly four divisors**.
If an integer does not have exactly four divisors, it contributes 0 to the result.

Example:
Input: nums = [21, 4, 7]
Output: 32
Explanation:
21 has divisors [1,3,7,21] → sum = 32  
4 has divisors [1,2,4] → only 3 divisors → ignore  
7 has divisors [1,7] → only 2 divisors → ignore

Approach (Efficient Divisor Enumeration):
1. For every number `x` in `nums`:
   - Try all possible divisors up to `sqrt(x)`.
   - For each divisor `d`:
       * If `d * d == x`, count only once.
       * Else if `x % d == 0`, count both `d` and `x/d`.
   - Collect all divisors found.
2. If exactly **four divisors** are found → add their sum to the answer.
3. Otherwise → ignore.

Why this works:
- Divisors come in pairs `(d, x/d)`.
- Checking up to `sqrt(x)` ensures we find all divisors efficiently.

Time Complexity: O(n * sqrt(max(nums)))  
Space Complexity: O(1) — excluding input/output
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long result = 0;

        for (int x : nums) {
            vector<int> divs;
            int root = sqrt(x);

            for (int d = 1; d <= root; d++) {
                if (x % d == 0) {
                    int other = x / d;
                    if (d == other) {
                        divs.push_back(d);
                    } else {
                        divs.push_back(d);
                        divs.push_back(other);
                    }
                }
                if (divs.size() > 4) break;  // early stop
            }

            if (divs.size() == 4) {
                result += divs[0] + divs[1] + divs[2] + divs[3];
            }
        }

        return result;
    }
};
