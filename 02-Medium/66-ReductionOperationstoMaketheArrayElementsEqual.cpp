/*
Problem: Reduction Operations to Make the Array Elements Equal
Link: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/
Difficulty: Medium
Topic: Array / Greedy / Sorting

Problem Statement:
Given an integer array `nums`, your goal is to make **all elements equal**.

In one operation:
1. Find the **largest element** in the array.
2. Find the **next largest value strictly smaller** than it.
3. Reduce the largest element to that next largest value.

Return *the number of operations required to make all elements equal*. :contentReference[oaicite:0]{index=0}

Example 1:
Input: nums = [5,1,3]  
Output: 3  

Explanation:
Step1: [5,1,3] → reduce 5 → 3 → [3,1,3]  
Step2: reduce 3 → 1 → [1,1,3]  
Step3: reduce 3 → 1 → [1,1,1]

Example 2:
Input: nums = [1,1,1]  
Output: 0  
Explanation: Already equal.

Example 3:
Input: nums = [1,1,2,2,3]  
Output: 4

Approach (Greedy + Sorting – Optimal):
Key Idea:
Each time we reduce a number, we move it down to the **next smaller distinct value**.

Steps:
1. Sort the array.
2. Traverse from index `1` to `n-1`.
3. Whenever `nums[i] != nums[i-1]`, it means we found a new larger value.
4. All elements from this position onward will need additional operations.
5. Accumulate operations using a counter.

Intuition:
Every time we encounter a **new distinct value**, all larger elements must be reduced one more step.

Time Complexity: O(n log n) (sorting)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int operations = 0;
        int steps = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                steps++; 
            }
            operations += steps;
        }

        return operations;
    }
};