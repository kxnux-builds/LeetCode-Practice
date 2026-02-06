/*
Problem: Minimum Removals to Balance Array
Link: https://leetcode.com/problems/minimum-removals-to-balance-array/description/
Difficulty: Medium
Topic: Array / Sorting / Two Pointers / Sliding Window

Problem Statement:
You are given an integer array `nums` and an integer `k`.  
An array is considered **balanced** if the value of its maximum element is at most
`k` times the minimum element.

You may remove any number of elements from `nums` without making it empty.  
Return the **minimum number of elements to remove** so that the remaining array is balanced.

Note: An array of size 1 is considered balanced because the condition always holds true.

Example:
Input: nums = [2,1,5], k = 2  
Output: 1  
Explanation:
- Remove `5` → remaining `[1,2]`, max = 2, min = 1, and 2 ≤ 1 × 2 → balanced.

Example:
Input: nums = [1,6,2,9], k = 3  
Output: 2  
Explanation:
- Remove 1 and 9 → remaining `[2,6]`, max = 6 ≤ 2 × 3 → balanced.

Approach (Sort + Two Pointers / Sliding Window – Optimal):
1. First sort `nums` in ascending order.
2. Use a **sliding window** with two pointers (`l`, `r`):
   - Expand `r` while `nums[r] ≤ nums[l] × k` (still balanced).
   - If the condition breaks, increase `l`.
3. At each step, the window `[l … r]` represents a balanced subarray.
4. Track the **maximum length** of such a balanced subarray.
5. Minimum removals = `n − maxLen` (we keep the largest balanced subset).

Time Complexity: O(n log n)  
Space Complexity: O(1)

This transforms the removal problem into finding the **largest balanced subarray** we can keep. :contentReference[oaicite:0]{index=0}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxKeep = 1;
        int l = 0;
        
        for (int r = 0; r < n; ++r) {
            // Move left pointer until the window is balanced
            while ((long long)nums[r] > (long long)nums[l] * k) {
                l++;
            }
            maxKeep = max(maxKeep, r - l + 1);
        }
        
        // Remove all others
        return n - maxKeep;
    }
};