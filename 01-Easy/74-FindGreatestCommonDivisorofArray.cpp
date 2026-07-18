/*
Problem: Find Greatest Common Divisor of Array
Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/
Difficulty: Easy
Topic: Array / Math / GCD

Problem Statement:
You are given an integer array nums.

Return the greatest common divisor (GCD) of the
smallest number and the largest number in nums.

The GCD of two numbers is the largest positive integer
that divides both numbers without leaving a remainder.

Example 1:
Input: nums = [2,5,6,9,10]
Output: 2

Explanation:
Smallest number = 2
Largest number = 10

GCD(2,10) = 2

Example 2:
Input: nums = [7,5,6,8,3]
Output: 1

Explanation:
Smallest number = 3
Largest number = 8

GCD(3,8) = 1

Example 3:
Input: nums = [3,3]
Output: 3

Explanation:
Smallest number = 3
Largest number = 3

GCD(3,3) = 3

--------------------------------------------------

Approach (Find Min & Max + Euclidean Algorithm – Optimal):

Key Insight:
The problem only asks for the GCD of:
- Smallest element
- Largest element

So:
1. Find the minimum value.
2. Find the maximum value.
3. Compute their GCD using the Euclidean Algorithm.

--------------------------------------------------

Steps:
1. Find:
   - minimum element
   - maximum element
2. Compute:
      gcd(minimum, maximum)
3. Return the result.

--------------------------------------------------

Dry Run:

nums = [2,5,6,9,10]

Minimum = 2
Maximum = 10

GCD(2,10)

10 % 2 = 0

Answer = 2

--------------------------------------------------

Why it works:
- The problem explicitly requires the GCD of
  the smallest and largest elements only.
- Euclidean Algorithm efficiently computes
  the GCD in logarithmic time.

--------------------------------------------------

Time Complexity: O(n)

- Finding minimum and maximum takes O(n).
- GCD computation takes O(log(maxValue)).

Overall: O(n)

Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {

        int minimum = *min_element(nums.begin(), nums.end());
        int maximum = *max_element(nums.begin(), nums.end());

        return __gcd(minimum, maximum);
    }
};