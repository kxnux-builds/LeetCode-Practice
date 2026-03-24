/*
Problem: Combination Sum
Link: https://leetcode.com/problems/combination-sum/description/
Difficulty: Medium
Topic: Array / Backtracking / Recursion

Problem Statement:
Given an array of **distinct integers** `candidates` and an integer `target`,
return a list of all **unique combinations** of `candidates` where the chosen
numbers sum to `target`.

You may choose the same number from `candidates` **unlimited times**.

The solution set must **not contain duplicate combinations**. ([leetcode.doocs.org](https://leetcode.doocs.org/en/lc/39/?utm_source=chatgpt.com))

Example 1:
Input: candidates = [2,3,6,7], target = 7  
Output: [[2,2,3],[7]]

Example 2:
Input: candidates = [2,3,5], target = 8  
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1  
Output: []

Constraints:
1 <= candidates.length <= 30  
2 <= candidates[i] <= 40  
All elements are distinct  
1 <= target <= 40

--------------------------------------------------

Approach (Backtracking – Optimal):

Key Idea:
At each step, we have two choices:
1. **Pick the current number** (stay at same index since reuse allowed)
2. **Skip the current number** (move to next index)

We explore all valid combinations using recursion.

Steps:
1. Start from index `0`.
2. If `target == 0` → valid combination found → store it.
3. If `target < 0` → stop (invalid path).
4. For each index:
   - Include `candidates[i]`
   - Recurse with reduced target
   - Backtrack (remove last element)
5. Move to next index to avoid duplicates.

--------------------------------------------------

Time Complexity: Exponential (≈ O(2^n))  
Space Complexity: O(target) (recursion stack)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);                 // choose
            backtrack(candidates, target - candidates[i], i, curr); // reuse allowed
            curr.pop_back();                               // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates, target, 0, curr);
        return result;
    }
};