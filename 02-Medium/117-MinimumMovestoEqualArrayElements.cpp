/*
Problem: Minimum Moves to Equal Array Elements
Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
Difficulty: Medium
Topic: Array / Math

Problem Statement:
You are given an integer array nums.

In one move, you can increment n - 1 elements of the array by 1.

Return the minimum number of moves required to make all
array elements equal.

Example 1:
Input: nums = [1,2,3]
Output: 3

Explanation:
[1,2,3] => [2,3,3] => [3,4,3] => [4,4,4]

Example 2:
Input: nums = [1,1,1]
Output: 0

Approach (Mathematics):
1. Instead of incrementing n-1 elements, think of decrementing
   the remaining one element by 1.
2. To make all elements equal with minimum moves, reduce every
   element to the minimum element.
3. Find the minimum element and calculate the sum of differences.
4. The answer is:

   sum(nums) - (minimum * n)

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minimum = INT_MAX;
        long long sum = 0;

        for (int num : nums) {
            minimum = min(minimum, num);
            sum += num;
        }

        return sum - (long long)minimum * nums.size();
    }
};