/*
Problem: Trapping Rain Water
Link: https://leetcode.com/problems/trapping-rain-water/description/
Difficulty: Hard
Topic: Array / Two Pointers / Dynamic Programming / Stack

Problem Statement:
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Approach:
1. Use two pointers: left at 0 and right at n - 1.
2. Track maximum heights on both sides using leftMax and rightMax.
3. If height[left] is smaller:
   - If height[left] < leftMax, water can be trapped (leftMax - height[left]).
   - Otherwise, update leftMax.
   - Move left pointer forward.
4. Else, process the right pointer similarly using rightMax.
5. Continue until left < right.

Time Complexity: O(n)    (single pass with two pointers)
Space Complexity: O(1)   (constant extra space)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0, water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < leftMax)
                    water += leftMax - height[left];
                else
                    leftMax = height[left];
                left++;
            } else {
                if (height[right] < rightMax)
                    water += rightMax - height[right];
                else
                    rightMax = height[right];
                right--;
            }
        }
        return water;
    }
};
