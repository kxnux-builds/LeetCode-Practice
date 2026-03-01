/*
Problem: Partitioning Into Minimum Number Of Deci-Binary Numbers
Link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/
Difficulty: Medium
Topic: Greedy / Math / Strings

Problem Statement:
A **deci-binary number** is a decimal number where each digit is either `0` or `1`,
and it does not contain leading zeros (except for the number zero itself).

Given a string `n` that represents a **positive decimal integer**, return *the minimum
number of deci-binary numbers needed such that the sum of those deci-binary numbers equals `n`*.

Example 1:
Input: n = "32"  
Output: 3  
Explanation:  
We can represent 32 as:
  32 = 10 + 11 + 11 → (3 deci-binary numbers)

Example 2:
Input: n = "82734"  
Output: 8  
Explanation:
The maximum digit in `n` is 8, which tells us we need at least 8 deci-binary numbers.

Example 3:
Input: n = "27346209830709182346"  
Output: 9

Approach (Greedy Observation – Optimal):
1. To form the decimal number `n` by summing deci-binary numbers, each digit of `n` (at any position)
   can only be contributed by the same position digits (0 or 1) of the deci-binary numbers.
2. So each deci-binary number contributes **at most 1 per position**.
3. The minimum number of deci-binary numbers required is therefore equal to
   the **maximum digit** present in the string `n`.

Intuition:
To sum up to a digit `d` at any position using only 1s and 0s from deci-binary numbers,
you need at least `d` ones in that column → so the answer is `maxDigit`.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (char c : n) {
            ans = max(ans, c - '0');
        }
        return ans;
    }
};