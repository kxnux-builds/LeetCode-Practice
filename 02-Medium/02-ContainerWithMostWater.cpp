/*
Problem: Container With Most Water
Link: https://leetcode.com/problems/container-with-most-water/description/
Difficulty: Medium
Topic: Two Pointers / Greedy

Problem Statement:
You are given an integer array height of length n. There are n vertical lines where 
the i-th line has a height of height[i]. Find two lines that together with the x-axis 
form a container that holds the most water. Return the maximum amount of water a 
container can store.

Approach:
1. Use two pointers: one at the beginning (left) and one at the end (right).
2. Calculate the water area as: width * min(height[left], height[right]).
3. Move the pointer pointing to the smaller height because it limits the container.
4. Repeat until left < right.

Time Complexity: O(n)    (single pass with two pointers)
Space Complexity: O(1)   (constant extra space)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int water = min(height[left], height[right]) * width;
            maxWater = max(maxWater, water);

            // Move the pointer at the smaller height
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxWater;
    }
};
