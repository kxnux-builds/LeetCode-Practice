/*
Problem: Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
Difficulty: Easy
Topic: Array / Greedy

Problem Statement:
You are given an array prices where prices[i] is the price of a given stock on the i-th day.
You want to maximize your profit by choosing a single day to buy one stock and 
a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.

Approach:
1. Initialize a variable minPrice to track the minimum price so far.
2. Traverse the array once.
3. For each price:
   - Update minPrice if a lower price is found.
   - Calculate potential profit = price - minPrice.
   - Track the maximum profit obtained so far.
4. Return the maximum profit.

Time Complexity: O(n)  — single pass through the array
Space Complexity: O(1) — constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};