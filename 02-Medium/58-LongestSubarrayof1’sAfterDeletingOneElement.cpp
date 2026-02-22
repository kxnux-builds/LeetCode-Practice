/*
Problem: Longest Subarray of 1’s After Deleting One Element
Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
Difficulty: Medium
Topic: Array / Sliding Window / Greedy

Problem Statement:
Given a binary array `nums`, you must delete **exactly one element** from it.
Return *the length of the longest subarray containing only `1`s* in the resulting array.

Note:
- You must delete one element (could be `0` or `1`).
- The resulting subarray should contain only `1`s to be counted.

Example 1:
Input: nums = [1,1,0,1]  
Output: 3  
Explanation: Delete the `0` → subarray of three `1`s.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]  
Output: 5  
Explanation: Delete a zero between sequences to combine them.

Example 3:
Input: nums = [1,1,1]  
Output: 2  
Explanation: Must delete one element → longest all-1s = 2.

Approach (Sliding Window – Optimal):
We use a sliding window that allows at most **one zero inside**:
1. Expand right pointer `r`.
2. Track count of zeros in window.
3. If more than one zero → shrink left pointer `l` until zeros ≤ 1.
4. Update best length as `(r − l)` (since we must delete exactly one element).

Intuition:
By allowing at most one zero in the window, that zero can be “deleted,” effectively
combining adjacent 1’s runs. The window length minus 1 zero gives the count of 1’s.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, zeros = 0, ans = 0;
        
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) zeros++;
            
            while (zeros > 1) {
                if (nums[l] == 0) zeros--;
                l++;
            }
            
            // window length minus 1 zero gives number of 1s
            ans = max(ans, r - l);
        }
        
        return ans;
    }
};