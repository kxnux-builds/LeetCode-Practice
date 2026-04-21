/*
Problem: Maximum Distance Between a Pair of Values
Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/
Difficulty: Medium
Topic: Array / Two Pointers / Binary Search

Problem Statement:
You are given two **non-increasing** (sorted in descending order) arrays
`nums1` and `nums2`.

A pair of indices `(i, j)` is valid if:
1. i <= j
2. nums1[i] <= nums2[j]

The **distance** of the pair is `j - i`.

Return the **maximum distance** among all valid pairs.
If no valid pair exists, return `0`. :contentReference[oaicite:0]{index=0}

Example 1:
Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]  
Output: 2  

Example 2:
Input: nums1 = [2,2,2], nums2 = [10,10,1]  
Output: 1  

Example 3:
Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]  
Output: 2  

Constraints:
1 <= nums1.length, nums2.length <= 10^5  
Both arrays are non-increasing :contentReference[oaicite:1]{index=1}

--------------------------------------------------

Approach (Two Pointers – Optimal):

Key Insight:
Since both arrays are **sorted in non-increasing order**, we can
use two pointers to efficiently find valid pairs. :contentReference[oaicite:2]{index=2}

Steps:
1. Initialize two pointers:
   - i = 0 (for nums1)
   - j = 0 (for nums2)
2. While i < n1 and j < n2:
   - If nums1[i] > nums2[j]:
       → increase i (need smaller nums1 value)
   - Else:
       → valid pair → update answer = max(ans, j - i)
       → increase j (try to maximize distance)
3. Return the maximum distance found

Why it works:
- `j` always moves forward → ensures maximum distance
- `i` only moves when condition fails

--------------------------------------------------

Time Complexity: O(n + m)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int ans = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] > nums2[j]) {
                i++; // move i to satisfy condition
            } else {
                ans = max(ans, j - i);
                j++; // expand j to maximize distance
            }
        }

        return ans;
    }
};