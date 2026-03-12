/*
Problem: Subsets
Link: https://leetcode.com/problems/subsets/description/
Difficulty: Medium
Topic: Array / Backtracking / Recursion

Problem Statement:
Given an integer array `nums` of **unique elements**, return **all possible subsets**
(the power set).

The solution set must **not contain duplicate subsets**.  
You may return the subsets in any order. :contentReference[oaicite:0]{index=0}

Example 1:
Input: nums = [1,2,3]  
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]  
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10  
-10 <= nums[i] <= 10  
All elements of `nums` are unique. :contentReference[oaicite:1]{index=1}

--------------------------------------------------

Approach (Backtracking – Optimal):

Key Idea:
For every element in the array we have **two choices**:
1. Include the element in the subset
2. Exclude the element

This naturally forms a **recursion tree**, where each branch represents
a possible subset. :contentReference[oaicite:2]{index=2}

Steps:
1. Start with an empty subset.
2. Add the current subset to the result.
3. Iterate through remaining elements.
4. Include the element and recursively explore further subsets.
5. Backtrack by removing the element and continue exploring.

This generates all **2ⁿ possible subsets**.

--------------------------------------------------

Time Complexity: O(2ⁿ × n)  
Space Complexity: O(n)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int start, vector<int>& curr) {
        result.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);            // include
            backtrack(nums, i + 1, curr);       // recurse
            curr.pop_back();                    // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(nums, 0, curr);
        return result;
    }
};