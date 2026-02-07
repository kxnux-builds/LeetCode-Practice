/*
Problem: Find the Highest Altitude
Link: https://leetcode.com/problems/find-the-highest-altitude/description/
Difficulty: Easy
Topic: Array / Prefix Sum / Simulation

Problem Statement:
You are given an integer array `gain` representing the net gain in altitude
between successive points of a hike. The **altitude** starts at `0` at the first point.
Return the **highest altitude** of the entire hike.

Example:
Input: gain = [-5,1,5,0,-7]  
Output: 6  
Explanation:
Altitude path = [0, -5, -4, 1, 1, -6] → highest = 1  
(*Note:* The example above matches the typical pattern, though multiple altitude
arrays could be described; we simply compute based on cumulative sums.)

Approach (Prefix Sum – Optimal):
1. Initialize `currentAlt = 0` and `highest = 0`.
2. Iterate through `gain`:
   - For each `g` in `gain`:  
       `currentAlt += g`
   - Update `highest = max(highest, currentAlt)`
3. Return the `highest` altitude reached.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAlt = 0;
        int highest = 0;

        for (int g : gain) {
            currentAlt += g;
            highest = max(highest, currentAlt);
        }

        return highest;
    }
};