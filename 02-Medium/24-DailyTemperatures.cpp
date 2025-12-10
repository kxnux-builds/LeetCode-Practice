/*
Problem: Daily Temperatures
Link: https://leetcode.com/problems/daily-temperatures/description/
Difficulty: Medium
Topic: Array / Stack / Monotonic Stack

Problem Statement:
Given an integer array temperatures representing the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.  
If there is no future day for which this is possible, put 0 instead.

Example:
Input: temperatures = [73,74,75,71,69,72,76,73]  
Output: [1,1,4,2,1,1,0,0]

Approach (Monotonic Stack – Optimal):
1. Use a stack to store indices of days whose warmer day hasn't been found yet.
2. Iterate through temperatures with index i:
   - While stack is not empty AND temperatures[i] > temperatures[stack.top()]:
       - Let prev = stack.top(), stack.pop().
       - answer[prev] = i - prev.
   - Push i onto stack.
3. For any indices still in stack → no warmer day → answer = 0 (default).

Time Complexity: O(n) — each element pushed/popped once  
Space Complexity: O(n) — stack + answer array  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;  // will store indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev = st.top(); st.pop();
                answer[prev] = i - prev;
            }
            st.push(i);
        }

        return answer;
    }
};