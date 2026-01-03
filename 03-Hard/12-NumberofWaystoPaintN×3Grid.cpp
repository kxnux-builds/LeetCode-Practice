/*
Problem: Number of Ways to Paint N × 3 Grid
Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/
Difficulty: Hard
Topic: Dynamic Programming / Math

Problem Statement:
You have a grid of size `n x 3` and you want to paint each cell of the grid with
one of three colors: Red, Yellow, or Green.  
You must paint the grid so that no two adjacent cells (sharing a side either horizontally
or vertically) have the same color.

Given an integer `n` representing the number of rows, return the **number of valid
ways to paint the grid**. Since the answer can be large, return it modulo `10^9 + 7`.

Example:
Input: n = 1  
Output: 12  
Explanation: For one row, there are 12 valid ways to color 3 cells with 3 colors
so that adjacent cells differ.

Constraints:
- 1 ≤ n ≤ 5000

Approach (Pattern Classification + DP – Optimal):
Let’s classify all valid colorings of a 3-cell row (ignoring vertical adjacency for now):
- **Type A (All Different):** All three cells are different — 6 ways.
- **Type B (First and Third Same):** First and third cell same, middle different — 6 ways. :contentReference[oaicite:0]{index=0}

For each new row, the number of valid colorings depends on the previous row:
- From Type A:
  - Can transition to **Type A** in `3` ways
  - Can transition to **Type B** in `2` ways
- From Type B:
  - Can transition to **Type A** in `2` ways
  - Can transition to **Type B** in `2` ways :contentReference[oaicite:1]{index=1}

Define:
- `dpA` → number of ways up to current row ending in Type A
- `dpB` → number of ways up to current row ending in Type B

Transitions:
newA = (3dpA + 2dpB) % MOD
newB = (2dpA + 2dpB) % MOD

Initialize:
dpA = 6
dpB = 6
Answer = `(dpA + dpB) % MOD`.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;

        // dpA = type A (all 3 colors different), dpB = type B (1st & 3rd same)
        long long dpA = 6, dpB = 6;

        for (int i = 2; i <= n; i++) {
            long long newA = (3LL * dpA + 2LL * dpB) % MOD;
            long long newB = (2LL * dpA + 2LL * dpB) % MOD;
            dpA = newA;
            dpB = newB;
        }

        return (int)((dpA + dpB) % MOD);
    }
};
