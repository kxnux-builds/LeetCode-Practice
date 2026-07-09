/*
Problem: Concatenate Non-Zero Digits and Multiply by Sum I
Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/
Difficulty: Easy
Topic: Math / Simulation / String

Problem Statement:
You are given an integer n.

Perform the following operations:
1. Extract all non-zero digits of n.
2. Concatenate these digits in their original order
   to form a new integer x.
3. Compute the sum of all non-zero digits.
4. Return:
      x × (sum of non-zero digits)

Example 1:
Input: n = 1052
Output: 378

Explanation:
Non-zero digits:
1, 5, 2

Concatenated number:
152

Sum of digits:
1 + 5 + 2 = 8

Answer:
152 × 8 = 1216

Example 2:
Input: n = 9004
Output: 52

Explanation:
Non-zero digits:
9, 4

Concatenated number:
94

Sum:
9 + 4 = 13

Answer:
94 × 13 = 1222

--------------------------------------------------

Approach (Simulation – Optimal):

Key Insight:
Traverse every digit of the number once.

For each digit:
- Ignore if it is 0.
- Otherwise:
   - Append it to the concatenated number.
   - Add it to the running sum.

Finally:
Answer = concatenatedNumber × digitSum

--------------------------------------------------

Steps:
1. Convert n into a string.
2. Initialize:
      concat = 0
      sum = 0
3. Traverse each character:
   - Convert to digit.
   - Ignore 0.
   - concat = concat * 10 + digit
   - sum += digit
4. Return concat × sum.

--------------------------------------------------

Dry Run:

n = 1052

Digits:
1 0 5 2

Digit = 1
concat = 1
sum = 1

Digit = 0
Ignore

Digit = 5
concat = 15
sum = 6

Digit = 2
concat = 152
sum = 8

Answer:
152 × 8 = 1216

--------------------------------------------------

Why it works:
- Every digit is processed exactly once.
- Non-zero digits are preserved in their
  original order.
- Simultaneously computes both the
  concatenated number and the digit sum.

--------------------------------------------------

Time Complexity: O(d)

Where:
d = number of digits in n

Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int concatSum(int n) {

        string s = to_string(n);

        int concat = 0;
        int sum = 0;

        for (char ch : s) {

            int digit = ch - '0';

            if (digit == 0)
                continue;

            concat = concat * 10 + digit;
            sum += digit;
        }

        return concat * sum;
    }
};