/*
Problem: Construct the Minimum Bitwise Array II
Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/
Difficulty: Medium
Topic: Array / Bit Manipulation

Problem Statement:
You are given an array `nums` consisting of `n` prime integers.  
You need to construct an array `ans` of length `n`, such that for each index `i`,  
the bitwise OR of `ans[i]` and `ans[i] + 1` equals `nums[i]`, i.e.,
    ans[i] | (ans[i] + 1) == nums[i]

Additionally, you must minimize each value of `ans[i]`.  
If there is no such value that satisfies the condition for an index, set `ans[i] = -1`.

Example:
Input: nums = [2,3,5,7]  
Output: [-1,1,4,3]

Example:
Input: nums = [11,13,31]  
Output: [9,12,15]

Key Insight:
For any integer `x`, the operation `a | (a + 1)` produces a number with all bits set
up to and including the first zero bit in `a`. To find the minimal `a` such that
`a | (a + 1) == num`, locate the **rightmost 0 bit** in `num` and flip the **1 bit
immediately below** it to 0.  
If `num == 2` (the only even prime), this is impossible → answer is `-1`. :contentReference[oaicite:0]{index=0}

Time Complexity: O(n × log M)  
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            // If num == 2 (even prime), no valid answer
            if (x == 2) {
                ans[i] = -1;
                continue;
            }

            int result = -1;
            // Find the first 0 bit from LSB upward
            for (int bit = 1; bit < 32; ++bit) {
                // Check if the current `bit` of x is 0
                if (((x >> bit) & 1) == 0) {
                    // Flip the bit just below to 0 and keep others same
                    result = x ^ (1 << (bit - 1));
                    break;
                }
            }
            ans[i] = result;
        }

        return ans;
    }
};