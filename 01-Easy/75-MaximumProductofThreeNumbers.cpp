/*
Problem: Maximum Product of Three Numbers
Link: https://leetcode.com/problems/maximum-product-of-three-numbers/description/
Difficulty: Easy
Topic: Array / Math / Sorting

Problem Statement:
Given an integer array nums, return the maximum product
that can be obtained by multiplying any three numbers.

Example 1:
Input: nums = [1,2,3]
Output: 6

Explanation:
Maximum product = 1 × 2 × 3 = 6

Example 2:
Input: nums = [1,2,3,4]
Output: 24

Explanation:
Maximum product = 2 × 3 × 4 = 24

Example 3:
Input: nums = [-1,-2,-3]
Output: -6

Explanation:
Maximum product = -1 × -2 × -3 = -6

--------------------------------------------------

Approach (Sorting + Greedy – Optimal):

Key Insight:
After sorting the array, there are only two possible
ways to obtain the maximum product:

1. Product of the three largest numbers.
2. Product of the two smallest numbers
   (possibly large negative values)
   and the largest number.

Why?
- Two negative numbers multiply to form
  a positive number.
- If their absolute values are large,
  they may produce a larger product than
  using the three largest positive numbers.

Answer =
max(last3Product, first2Last1Product)

--------------------------------------------------

Steps:
1. Sort the array.
2. Compute:
   - product1 = largest × secondLargest × thirdLargest
   - product2 = smallest × secondSmallest × largest
3. Return the maximum of both products.

--------------------------------------------------

Dry Run:

nums = [-10,-10,5,2]

After sorting:
[-10,-10,2,5]

product1
= -10 × 2 × 5
= -100

product2
= -10 × -10 × 5
= 500

Answer = 500

--------------------------------------------------

Why it works:
- Sorting places the smallest and largest
  numbers at known positions.
- The maximum product can only come from:
  • the three largest numbers, or
  • the two smallest (most negative) numbers
    together with the largest positive number.
- Checking both possibilities guarantees
  the optimal answer.

--------------------------------------------------

Time Complexity: O(n log n)

- Sorting dominates the complexity.

Space Complexity: O(1)

(Ignoring sorting's internal space)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];

        int product2 = nums[0] * nums[1] * nums[n - 1];

        return max(product1, product2);
    }
};