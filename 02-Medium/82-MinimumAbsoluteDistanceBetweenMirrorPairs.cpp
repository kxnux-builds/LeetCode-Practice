/*
Problem: Minimum Absolute Distance Between Mirror Pairs
Link: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/
Difficulty: Medium
Topic: Array / Hash Table / Math

Problem Statement:
You are given an integer array `nums`.

A **mirror pair** is a pair of indices `(i, j)` such that:
- 0 ≤ i < j < nums.length
- reverse(nums[i]) == nums[j]

Where `reverse(x)` means reversing the digits of `x`
(e.g., reverse(120) = 21). :contentReference[oaicite:0]{index=0}

Return the **minimum absolute distance** between indices of any mirror pair:
abs(i - j)

If no such pair exists, return `-1`. :contentReference[oaicite:1]{index=1}

Example 1:
Input: nums = [12,21,45,33,54]  
Output: 1  

Example 2:
Input: nums = [120,21]  
Output: 1  

Example 3:
Input: nums = [21,120]  
Output: -1  

--------------------------------------------------

Approach (Hash Map + Reverse – Optimal):

Key Insight:
While scanning from left → right:
- We want to know if a previous number’s **reverse**
  matches current number.

Instead of searching backward (O(n²)),
we store reversed values in a hash map.

Steps:
1. Use a map `pos` → stores last index of reversed numbers
2. Traverse array:
   - If current number exists in map → valid mirror pair found
   - Update answer = min(ans, i - pos[current])
3. Store reverse(nums[i]) → i in map
4. If no pair found → return -1

Why it works:
- We only check valid mirror matches in O(1)
- Ensures minimum distance automatically by tracking latest index

--------------------------------------------------

Time Complexity: O(n × log M)  
Space Complexity: O(n)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNum(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + (x % 10);
            x /= 10;
        }
        return y;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> pos;
        int n = nums.size();
        int ans = n + 1;

        for (int i = 0; i < n; i++) {
            if (pos.count(nums[i])) {
                ans = min(ans, i - pos[nums[i]]);
            }
            pos[reverseNum(nums[i])] = i;
        }

        return (ans > n) ? -1 : ans;
    }
};