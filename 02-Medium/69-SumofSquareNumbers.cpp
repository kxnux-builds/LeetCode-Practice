/*
Problem: Sum of Square Numbers
Link: https://leetcode.com/problems/sum-of-square-numbers/description/
Difficulty: Medium
Topic: Math / Two Pointers

Problem Statement:
Given a non-negative integer `c`, determine whether there exist two integers `a` and `b`
such that:

a² + b² = c

Return `true` if such integers exist, otherwise return `false`. :contentReference[oaicite:0]{index=0}

Example 1:
Input: c = 5  
Output: true  
Explanation: 1² + 2² = 5

Example 2:
Input: c = 3  
Output: false

Example 3:
Input: c = 4  
Output: true  
Explanation: 0² + 2² = 4

Constraints:
0 <= c <= 2³¹ − 1 :contentReference[oaicite:1]{index=1}

--------------------------------------------------

Approach (Two Pointers – Optimal):

Key Idea:
We want to check if there exist integers `a` and `b` such that:

a² + b² = c

Steps:
1. Set `left = 0`
2. Set `right = sqrt(c)`
3. While `left <= right`:
   - Compute `sum = left² + right²`
   - If `sum == c` → return true
   - If `sum < c` → increase `left`
   - If `sum > c` → decrease `right`
4. If no pair found, return false.

Intuition:
- `a²` increases when `a` increases.
- `b²` decreases when `b` decreases.
- Using two pointers lets us efficiently search all valid pairs without brute force. :contentReference[oaicite:2]{index=2}

--------------------------------------------------

Time Complexity: O(√c)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);

        while (left <= right) {
            long long sum = left * left + right * right;

            if (sum == c) {
                return true;
            }
            else if (sum < c) {
                left++;
            }
            else {
                right--;
            }
        }

        return false;
    }
};