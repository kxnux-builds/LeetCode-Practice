/*
Problem: Climbing Stairs
Link: https://leetcode.com/problems/climbing-stairs/description/
Difficulty: Easy
Topic: Dynamic Programming / Math

Problem Statement:
You are climbing a staircase. It takes n steps to reach the top.
Each time you can climb either 1 or 2 steps.
Return the number of distinct ways to climb to the top.

Approach:
1. This problem is similar to the Fibonacci sequence:
   - Ways(n) = Ways(n-1) + Ways(n-2)
2. Instead of using recursion or DP array, use two variables:
   - prev1 = ways to reach step (n-1)
   - prev2 = ways to reach step (n-2)
3. Iteratively compute up to n with O(1) extra space.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;  // base cases: 1 step -> 1 way, 2 steps -> 2 ways

        int prev2 = 1;  // ways for step 1
        int prev1 = 2;  // ways for step 2

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
