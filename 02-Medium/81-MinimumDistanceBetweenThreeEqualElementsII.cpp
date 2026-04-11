/*
Problem: Minimum Distance Between Three Equal Elements II
Link: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/
Difficulty: Medium
Topic: Array / Hash Table

Problem Statement:
You are given an integer array `nums`.

A tuple `(i, j, k)` is called **good** if:
- 0 ≤ i < j < k < nums.length
- nums[i] == nums[j] == nums[k]

The **distance** of such a tuple is:
abs(i - j) + abs(j - k) + abs(k - i)

Return the **minimum possible distance** among all good tuples,
or `-1` if no such tuple exists. :contentReference[oaicite:0]{index=0}

Example 1:
Input: nums = [1,2,1,1,3]  
Output: 6  

Example 2:
Input: nums = [1,1,2,3,2,1,2]  
Output: 8  

Example 3:
Input: nums = [1]  
Output: -1  

--------------------------------------------------

Approach (Hash Map + Greedy – Optimal):

Key Insight:
For indices i < j < k:

distance = (j - i) + (k - j) + (k - i)  
         = 2 * (k - i)

👉 So distance depends **only on first and last index**. :contentReference[oaicite:1]{index=1}

Therefore:
- We only need to find **3 occurrences of same number**
- And minimize `(k - i)`

Even better:
👉 Only check **consecutive triples** of indices for each number

--------------------------------------------------

Steps:
1. Store indices of each number using a hashmap
2. For each number:
   - If it appears ≥ 3 times:
     - Check every 3 consecutive indices:
       distance = 2 * (idx[k] - idx[i])
3. Track minimum distance
4. If no valid triple → return -1

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(n)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Process each value
        for (auto &it : mp) {
            vector<int>& idx = it.second;

            if (idx.size() >= 3) {
                for (int i = 0; i + 2 < idx.size(); i++) {
                    int dist = 2 * (idx[i + 2] - idx[i]);
                    ans = min(ans, dist);
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};