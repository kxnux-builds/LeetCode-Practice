/*
Problem: Minimum Distance to the Target Element
Link: https://leetcode.com/problems/minimum-distance-to-the-target-element/description/
Difficulty: Easy
Topic: Array / Simulation

Problem Statement:
Given an integer array `nums` (0-indexed), an integer `target`,
and an integer `start`, find an index `i` such that:

- nums[i] == target
- abs(i - start) is **minimum**

Return the minimum distance `abs(i - start)`.

It is guaranteed that `target` exists in the array. :contentReference[oaicite:0]{index=0}

Example 1:
Input: nums = [1,2,3,4,5], target = 5, start = 3  
Output: 1  

Example 2:
Input: nums = [1], target = 1, start = 0  
Output: 0  

Example 3:
Input: nums = [1,1,1,1,1], target = 1, start = 0  
Output: 0  

Constraints:
1 <= nums.length <= 1000  
1 <= nums[i] <= 10^4  
0 <= start < nums.length  

--------------------------------------------------

Approach (Linear Scan – Optimal):

Key Idea:
We only care about indices where `nums[i] == target`.
For each such index, compute distance from `start`
and take the minimum. :contentReference[oaicite:1]{index=1}

Steps:
1. Initialize `ans = n` (maximum possible distance)
2. Traverse the array:
   - If `nums[i] == target`:
     - Compute `abs(i - start)`
     - Update `ans = min(ans, distance)`
3. Return `ans`

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }

        return ans;
    }
};