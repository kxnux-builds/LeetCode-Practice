/*
Problem: Permutations
Link: https://leetcode.com/problems/permutations/description/
Difficulty: Medium
Topic: Backtracking / Recursion / Array

Problem Statement:
Given an array nums of distinct integers, return all the possible 
permutations. You can return the answer in any order.

Approach:
1. Use a recursive backtracking approach with in-place swapping.
2. Fix one element at each index by swapping it with all possible choices.
3. Recurse for the next index.
4. When all positions are fixed (index == nums.size()), store the permutation.
5. Backtrack by swapping the elements back to restore the array.

Time Complexity: O(n × n!)   
- There are n! permutations, and copying each takes O(n).

Space Complexity: O(1) extra space   
- The recursion stack uses O(n) but no additional data structures.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); ++i) {
            swap(nums[i], nums[ind]);          // fix one element at 'ind'
            solve(nums, ind + 1, ans);         // recurse for remaining
            swap(nums[i], nums[ind]);          // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};