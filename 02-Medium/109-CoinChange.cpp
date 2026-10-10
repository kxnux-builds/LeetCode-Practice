/*
Problem: Coin Change
Link: https://leetcode.com/problems/coin-change/description/
Difficulty: Medium
Topic: Dynamic Programming / Array

Problem Statement:
You are given an integer array `coins` representing different
coin denominations and an integer `amount` representing a total
amount of money.

Return the fewest number of coins needed to make up that amount.

If the amount cannot be made using any combination of the coins,
return -1.

You may use each coin an unlimited number of times.

Example:
Input: coins = [1, 2, 5], amount = 11
Output: 3

Explanation:
11 = 5 + 5 + 1
The minimum number of coins required is 3.

Approach (Dynamic Programming):
1. Create a DP array `dp` of size `amount + 1`.
2. Initialize every element with `amount + 1`, representing
   an initially unreachable amount.
3. Set `dp[0] = 0`, because zero coins are needed to make amount 0.
4. Traverse every amount `i` from 1 to `amount`:
   - Traverse every coin in `coins`.
   - If `coin <= i`, update:
       dp[i] = min(dp[i], 1 + dp[i - coin])
   - This means using one coin and adding the minimum number
     of coins needed for the remaining amount.
5. If `dp[amount]` is still `amount + 1`, return -1.
6. Otherwise, return `dp[amount]`.

Time Complexity: O(amount * n), where n is the number of coins.
Space Complexity: O(amount)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = minimum coins needed to make amount i
        vector<int> dp(amount + 1, amount + 1);

        // Base case: zero coins are needed for amount zero
        dp[0] = 0;

        // Calculate the minimum coins for every amount
        for (int i = 1; i <= amount; i++) {

            // Try every available coin
            for (int coin : coins) {

                // Use the coin only if it does not exceed i
                if (coin <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If the amount cannot be formed, return -1
        if (dp[amount] == amount + 1) {
            return -1;
        }

        return dp[amount];
    }
};