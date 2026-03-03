/*
Problem: Gas Station
Link: https://leetcode.com/problems/gas-station/description/
Difficulty: Medium
Topic: Greedy / Array

Problem Statement:
There are `n` gas stations along a circular route. You are given two integer arrays:
- `gas[i]` — the amount of gas at station `i`
- `cost[i]` — the cost of gas needed to travel from station `i` to `(i+1)`

You have a car with an **unlimited gas tank**. You begin the journey with an empty tank.
Return *the starting gas station’s index* if you can travel around the circuit once in the 
clockwise direction, otherwise return `-1`.

It's guaranteed that if there exists a solution, it is unique.

Example 1:
Input: gas  = [1,2,3,4,5]
       cost = [3,4,5,1,2]
Output: 3  
Explanation: Starting at index 3 (gas 4):
tank = 4 → cost 1 → tank = 3
… completes full circle.

Example 2:
Input: gas  = [2,3,4]
       cost = [3,4,3]
Output: -1  
Explanation: Cannot complete the circuit from any starting station.

Approach (Greedy – Optimal):
1. If the **total gas < total cost**, no solution → return `-1`.
2. Otherwise, keep a `tank` tracking net fuel from your current start.
3. Iterate stations from `0` to `n−1`:
   - Add `gas[i] − cost[i]` to `tank`.
   - If `tank` drops below zero → current start fails:
     • Set `start = i + 1`
     • Reset `tank = 0`
4. The valid start index is the only solution.

Intuition:
If you cannot reach station `i+1` from your current start, any station
between start and `i` also cannot be a valid start.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        long long totalGas = 0, totalCost = 0;
        for (int i = 0; i < n; ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        // If not enough gas overall
        if (totalGas < totalCost) return -1;

        long long tank = 0;
        int start = 0;
        for (int i = 0; i < n; ++i) {
            tank += (gas[i] - cost[i]);
            if (tank < 0) {
                // Cannot start from current range
                start = i + 1;
                tank = 0;
            }
        }
        return start;
    }
};