/*
Problem: Happy Number
Link: https://leetcode.com/problems/happy-number/description/
Difficulty: Easy
Topic: Hash Set / Math / Two Pointers

Problem Statement:
Write an algorithm to determine if a number n is a “happy number”.
A number is happy if repeatedly replacing it with the sum of the squares of its digits
eventually becomes 1. If it loops endlessly in a cycle that does not include 1,
then the number is not happy.

Example:
Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1  → happy

Approach (Floyd’s Cycle Detection – Optimized):
1. Define a function to compute the sum of squares of digits.
2. Use slow and fast pointers:
   - slow = f(slow)
   - fast = f(f(fast))
3. If fast becomes 1 → number is happy.
4. If slow == fast (cycle detected) and not 1 → not happy.

Why Floyd's Algorithm?
- O(1) extra space (better than using a set)
- Detects cycles efficiently.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;

        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));

            if (fast == 1) return true;
        } while (slow != fast);

        return slow == 1;
    }

private:
    int digitSquareSum(int x) {
        int sum = 0;
        while (x > 0) {
            int d = x % 10;
            sum += d * d;
            x /= 10;
        }
        return sum;
    }
};