/*
Problem: Calculate Money in Leetcode Bank
Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/
Difficulty: Easy
Topic: Math / Simulation

Problem Statement:
Hercy wants to save money for his first car. 
He deposits money every day according to the following rules:

1. On the first Monday, he deposits $1, and each day of that week, he deposits 
   $1 more than the previous day (so $1, $2, $3, ..., $7).
2. Every following Monday, he deposits $1 more than the previous Monday.
   (So the first day of week 2, he deposits $2, and then $3, $4, ..., $8 for that week.)
3. Return the total amount of money he will have after n days.

Approach:
1. Each full week (7 days) forms an arithmetic progression:
   - Sum of one week = 7 * first_day + 21
     (because 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 → 7*first_day + 21)
2. Calculate the total for all full weeks.
3. Add the remaining days of the last incomplete week.

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        // Total from complete weeks
        int total = weeks * (28 + (weeks - 1) * 7 / 2);

        // Add remaining days (in the next week's sequence)
        int start = weeks + 1;
        for (int i = 0; i < days; ++i)
            total += start + i;

        return total;
    }
};
