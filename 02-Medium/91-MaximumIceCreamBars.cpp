/*
Problem: Maximum Ice Cream Bars
Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/
Difficulty: Medium
Topic: Array / Greedy / Sorting

Problem Statement:
It is a hot summer day, and a boy wants to buy ice cream bars.

You are given:
- costs[i] = cost of the ith ice cream bar
- coins = number of coins available

The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars
he can buy with the given coins.

Example 1:
Input:
costs = [1,3,2,4,1]
coins = 7

Output:
4

Explanation:
Buy ice creams with costs:
1, 1, 2, 3

Total cost = 7
Number of bars = 4

Example 2:
Input:
costs = [10,6,8,7,7,8]
coins = 5

Output:
0

Explanation:
No ice cream can be purchased.

Example 3:
Input:
costs = [1,6,3,1,2,5]
coins = 20

Output:
6

Explanation:
All ice cream bars can be purchased.

--------------------------------------------------

Approach (Greedy + Sorting – Optimal):

Key Insight:
To maximize the number of ice cream bars,
always buy the cheapest bars first.

Why?
- Buying expensive bars early may prevent
  purchasing multiple cheaper bars later.
- Choosing the smallest costs first leaves
  maximum coins available for additional bars.

This is a classic Greedy strategy.

--------------------------------------------------

Steps:
1. Sort the costs array in ascending order.
2. Initialize count = 0.
3. Traverse the sorted array:
   - If current cost <= coins:
       buy it
       coins -= cost
       count++
   - Otherwise stop.
4. Return count.

--------------------------------------------------

Dry Run:

costs = [1,3,2,4,1]
coins = 7

After sorting:
[1,1,2,3,4]

Buy 1:
coins = 6
count = 1

Buy 1:
coins = 5
count = 2

Buy 2:
coins = 3
count = 3

Buy 3:
coins = 0
count = 4

Cannot buy 4

Answer = 4

--------------------------------------------------

Why it works:
- Sorting places the cheapest bars first.
- Every purchase uses the minimum possible coins.
- This leaves maximum budget for future purchases.
- Therefore, the total number of bars purchased
  is maximized.

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
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(), costs.end());

        int count = 0;

        for (int cost : costs) {

            if (cost > coins) {
                break;
            }

            coins -= cost;
            count++;
        }

        return count;
    }
};