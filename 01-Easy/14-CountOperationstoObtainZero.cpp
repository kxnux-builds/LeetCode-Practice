/*
Problem: Count Operations to Obtain Zero
Link: https://leetcode.com/problems/count-operations-to-obtain-zero/description/
Difficulty: Easy
Topic: Math / Simulation

Problem Statement:
You are given two non-negative integers num1 and num2.  
In one operation, you:
- If num1 >= num2, subtract num2 from num1.
- Otherwise, subtract num1 from num2.  

Return the number of operations required to reduce either num1 or num2 to zero.

Approach:
1. Initialize a counter to 0.
2. Loop until either num1 or num2 becomes 0:
   - Subtract the smaller number from the larger.
   - Increment the operation counter.
3. Return the counter.

Time Complexity: O(max(num1, num2))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            count++;
        }
        return count;
    }
};