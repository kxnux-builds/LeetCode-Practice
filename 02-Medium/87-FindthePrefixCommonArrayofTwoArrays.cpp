/*
Problem: Find the Prefix Common Array of Two Arrays
Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/
Difficulty: Medium
Topic: Array / Hashing / Counting

Problem Statement:
You are given two **0-indexed permutations** `A` and `B` of length `n`.

A prefix common array `C` is defined such that:
- C[i] = number of elements common in:
  - A[0...i]
  - B[0...i]

Return the array `C`.

Example 1:
Input: A = [1,3,2,4], B = [3,1,2,4]  
Output: [0,2,3,4]

Example 2:
Input: A = [2,3,1], B = [3,1,2]  
Output: [0,1,3]

--------------------------------------------------

Approach (Frequency Counting – Optimal):

Key Idea:
Track how many times each number appears while traversing both arrays.

When a number’s frequency becomes 2,
it means that number has appeared in both prefixes. ([algo.monster](https://algo.monster/liteproblems/2657?utm_source=chatgpt.com))

Steps:
1. Create frequency array/map
2. Traverse arrays simultaneously:
   - Increment frequency of A[i]
   - Increment frequency of B[i]
3. If any number frequency becomes 2:
   - increase common count
4. Store running common count in answer array

Why it works:
- Since A and B are permutations,
  each number appears exactly once in each array.

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(n)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> freq(n + 1, 0);
        vector<int> ans(n);

        int common = 0;

        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) {
                common++;
            }

            freq[B[i]]++;
            if (freq[B[i]] == 2) {
                common++;
            }

            ans[i] = common;
        }

        return ans;
    }
};