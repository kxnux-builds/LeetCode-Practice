/*
Problem: Largest Rectangle in Histogram
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
Difficulty: Hard
Topic: Stack / Monotonic Stack / Array

Problem Statement:
Given an array heights representing the histogram's bar heights where the 
width of each bar is 1, return the area of the largest rectangle that can be 
formed in the histogram.

Example:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The largest rectangle has area 10 (bars of height 5 and 6).

Approach (Optimized Stack-based):
1. Use a monotonic increasing stack to store indices of bars.
2. Loop through all bars:
    - While current bar < bar at stack top:
        - Pop top, calculate rectangle area with height = popped bar.
        - Width = current index - index of new stack top - 1.
        - Update max area.
3. After the loop, process remaining stack in the same way.
4. Return the maximum area.

Time Complexity: O(n)
Space Complexity: O(n) — stack for indices
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);  // Sentinel to pop all remaining bars
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }

        return maxArea;
    }
};