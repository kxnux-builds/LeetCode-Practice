/*
Problem: Maximal Rectangle
Link: https://leetcode.com/problems/maximal-rectangle/description/
Difficulty: Hard
Topic: Matrix / DP / Stack / Histogram

Problem Statement:
Given a 2D binary matrix filled with '0's and '1's, find the largest rectangle 
containing only '1's and return its area.

Example:
Input: matrix = [
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
Explanation: The largest rectangle has area 6.

Approach (Optimized using Histogram + Monotonic Stack):
1. Treat each row as the base of a histogram:
   - For each column, maintain a height of consecutive '1's up to current row.
2. For each row, calculate the largest rectangle area in the histogram using the
   monotonic stack approach (same as LeetCode 84).
3. Keep track of the maximum area found across all rows.

Time Complexity: O(rows * cols)
Space Complexity: O(cols) — stack for each row histogram
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (auto &row : matrix) {
            for (int j = 0; j < n; j++) {
                heights[j] = row[j] == '1' ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()]; st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }

        return maxArea;
    }
};