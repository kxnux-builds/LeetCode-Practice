/*
Problem: Final Prices With a Special Discount in a Shop
Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
Difficulty: Easy
Topic: Array / Stack / Monotonic Stack

Problem Statement:
You are given an integer array prices where prices[i] is the price of the i-th item in a shop.
There is a special discount for items in the shop: if you buy the i-th item, then you will receive a discount equal to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i].  
If no such j exists, there is no discount for item i.

Return an integer array answer where answer[i] is the final price you pay for the i-th item of the shop (i.e. prices[i] minus discount, if any).

Example:
Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation:
- Item 0: price = 8, next smaller or equal is 4 → final price = 8 - 4 = 4  
- Item 1: price = 4, next smaller or equal is 2 → final price = 4 - 2 = 2  
- Item 2: price = 6, next smaller or equal is 2 → final price = 6 - 2 = 4  
- Items 3 and 4: no smaller/equal price after them → final price remains same [2,3]

Approach (Monotonic Stack – Optimal):
1. Use a stack to store indices of prices for which we are yet to find a discount.
2. Iterate through prices:
   - While stack is not empty AND current price ≤ price at index on top of stack:
       - Pop index prev, set answer[prev] = prices[prev] − current price   (found its discount)
   - Push current index onto stack.
3. After the loop, for any index left in stack → no discount found → answer[index] = prices[index].

Time Complexity: O(n) — each element is pushed/popped at most once  
Space Complexity: O(n) — stack plus result array  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                int prevIdx = st.top(); st.pop();
                result[prevIdx] = prices[prevIdx] - prices[i];
            }
            st.push(i);
        }

        // For elements with no discount
        while (!st.empty()) {
            int idx = st.top(); st.pop();
            result[idx] = prices[idx];
        }

        return result;
    }
};