/*
Problem: Can Place Flowers
Link: https://leetcode.com/problems/can-place-flowers/description/
Difficulty: Easy
Topic: Greedy / Array

Problem Statement:
You are given an integer array flowerbed representing a flowerbed, where flowerbed[i] is:
- 0 → empty
- 1 → already planted

Flowers cannot be planted in adjacent plots.

You are also given an integer n.
Return true if n new flowers can be planted in the flowerbed without violating the rule.

Example:
Input:
flowerbed = [1,0,0,0,1], n = 1
Output: true

Approach (Greedy – Optimal):
1. Traverse the flowerbed.
2. For each index i, check 3 conditions:
   - flowerbed[i] == 0
   - (i == 0 or flowerbed[i-1] == 0)
   - (i == flowerbed.size()-1 or flowerbed[i+1] == 0)
3. If all conditions satisfy, plant a flower (set flowerbed[i] = 1) and decrement n.
4. If n becomes 0 at any point, return true.
5. After traversal, return n <= 0.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();

        for (int i = 0; i < m && n > 0; i++) {
            if (flowerbed[i] == 0) {
                bool left  = (i == 0 || flowerbed[i - 1] == 0);
                bool right = (i == m - 1 || flowerbed[i + 1] == 0);

                if (left && right) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }

        return n <= 0;
    }
};