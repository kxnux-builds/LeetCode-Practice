/*
Problem: Divide an Array Into Subarrays With Minimum Cost I  
Link: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/  
Difficulty: Easy  
Topic: Array / Greedy / Brute Force / Optimization

Problem Statement:
You are given an integer array `nums` of length `n`.  
You need to divide `nums` into **3 disjoint contiguous subarrays**, and the cost
of a subarray is defined as the value of its **first element**.

Return *the minimum possible sum* of the costs of the 3 subarrays.

Example 1:
Input: nums = [1,2,3,12]  
Output: 6  
Explanation: Divide as [1], [2], [3,12].  
Costs = 1 + 2 + 3 = 6.

Example 2:
Input: nums = [5,4,3]  
Output: 12  
Explanation: The only division into three non-empty subarrays is [5],[4],[3] → 5+4+3.

Example 3:
Input: nums = [10,3,1,1]  
Output: 12  
Explanation: One optimal split is [10,3],[1],[1] → 10+1+1 = 12.

Approach (Greedy + Two Smallest Values):
- The **first subarray always starts at index 0**, so its cost is always `nums[0]`. :contentReference[oaicite:0]{index=0}
- We then need to pick **two more starting indices** `i` and `j` where `1 ≤ i < j < n`.
- The cost of the second subarray is `nums[i]`; the cost of the third is `nums[j]`.
- To minimize `nums[0] + nums[i] + nums[j]`, we can simply choose the **two smallest** values in `nums[1..n-1]`.
  - That’s because, no matter how we split contiguously, the next two first elements must be
    chosen from positions ≥1, and smaller values minimize total cost. :contentReference[oaicite:1]{index=1}

Time Complexity: O(n) — single pass to find smallest values  
Space Complexity: O(1) — constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // nums[0] always contributes
        int total = nums[0];

        // find the two smallest in nums[1..]
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }

        total += min1 + min2;
        return total;
    }
};