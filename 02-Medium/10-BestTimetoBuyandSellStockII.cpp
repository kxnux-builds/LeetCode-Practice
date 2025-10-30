/*
Problem: Best Time to Buy and Sell Stock II
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
Difficulty: Medium
Topic: Array / Greedy

Problem Statement:
You are given an integer array prices where prices[i] is the price of a given stock on the i-th day.
On each day, you may decide to buy and/or sell the stock.
You can hold at most one share of the stock at a time.
However, you can buy it and sell it multiple times (one after another).
Return the maximum profit you can achieve.

Approach:
1. Use a Greedy approach.
2. Whenever prices[i] > prices[i - 1], it means a profit opportunity.
3. Sum up all such positive differences to get the maximum profit.
4. This simulates multiple buy-sell transactions where you buy before a rise and sell at the peak.

Time Complexity: O(n)   — single traversal of prices array
Space Complexity: O(1)  — constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
