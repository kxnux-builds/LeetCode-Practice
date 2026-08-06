/*
Problem: Smallest Divisible Digit Product I
Link: https://leetcode.com/problems/smallest-divisible-digit-product-i/description/
Difficulty: Easy
Topic: Math / Simulation

Problem Statement:
You are given two integers:
- n
- t

Starting from n, find the smallest integer x such that:
- x >= n
- The product of the digits of x is divisible by t.

Return x.

Example 1:
Input: n = 10, t = 2
Output: 10

Explanation:
Product of digits of 10:
1 × 0 = 0

0 is divisible by 2.

Hence, answer = 10.

Example 2:
Input: n = 15, t = 3
Output: 16

Explanation:
15:
1 × 5 = 5 (not divisible by 3)

16:
1 × 6 = 6

6 is divisible by 3.

Hence, answer = 16.

--------------------------------------------------

Approach (Brute Force + Simulation – Optimal):

Key Insight:
Starting from n:
- Compute the product of digits.
- Check if it is divisible by t.
- If not, move to the next number.

Since the constraints are small,
a simple simulation is sufficient.

--------------------------------------------------

Steps:
1. Start with x = n.
2. Compute the product of digits of x.
3. If:
      product % t == 0
   return x.
4. Otherwise:
      x++
5. Repeat until a valid number is found.

--------------------------------------------------

Dry Run:

n = 15
t = 3

x = 15

Digits:
1, 5

Product = 5

5 % 3 != 0

x = 16

Digits:
1, 6

Product = 6

6 % 3 == 0

Answer = 16

--------------------------------------------------

Why it works:
- Every number greater than or equal to n
  is checked in increasing order.
- The first number satisfying the condition
  is the smallest valid answer.
- Digit product is computed independently
  for each candidate.

--------------------------------------------------

Time Complexity: O(k × d)

Where:
- k = numbers checked until the answer
- d = number of digits in the number

Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitProduct(int num) {

        int product = 1;

        while (num > 0) {

            product *= (num % 10);
            num /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {

        int x = n;

        while (true) {

            if (digitProduct(x) % t == 0) {
                return x;
            }

            x++;
        }
    }
};