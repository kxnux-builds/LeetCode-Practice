/*
Problem: Construct the Minimum Bitwise Array I
Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/
Difficulty: Easy
Topic: Array / Bit Manipulation

Problem Statement:
You are given an array `nums` consisting of `n` prime integers.  
You need to construct an array `ans` of length `n` such that, for each index `i`,  
the bitwise OR of `ans[i]` and `ans[i] + 1` is equal to `nums[i]`, i.e.,
    ans[i] | (ans[i] + 1) == nums[i]

Additionally, each `ans[i]` should be **minimized**.  
If it is not possible to find such a value for `ans[i]` that satisfies the condition,  
then set `ans[i] = -1`.

Example 1:
Input: nums = [2,3,5,7]  
Output: [-1,1,4,3]  
Explanation:
- For 2: no value x exists such that x | (x+1) == 2 → ans = -1  
- For 3: 1 | 2 = 3 → ans = 1  
- For 5: 4 | 5 = 5 → ans = 4  
- For 7: 3 | 4 = 7 → ans = 3

Example 2:
Input: nums = [11,13,31]  
Output: [9,12,15]  
Explanation:
- 9 | 10 = 11  
- 12 | 13 = 13  
- 15 | 16 = 31

Key Insight:
For any integer `x`, `(x | (x+1))` sets the **lowest zero bit in `x` to 1** along with all less significant bits in `(x+1)`.  
Thus, to solve `a | (a+1) == num`, we need to **flip the zero bit in `num` immediately after its trailing ones** back to zero in `a`.  
If `num` is `2` (the only even prime), no such `a` exists because `(a | (a+1))` is always odd. :contentReference[oaicite:0]{index=0}

Time Complexity: O(n × log M) per bit scanning  
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
            // Find the first 0 bit (from LSB) after at least one 1 bit
            int result = -1;
            for (int bit = 1; bit < 31; bit++) {
                // Check if the bit at position `bit` is zero
                if (((x >> bit) & 1) == 0) {
                    // Construct candidate by flipping the bit just below
                    result = x ^ (1 << (bit - 1));
                    break;
                }
            }
            ans[i] = result;
        }

        return ans;
    }
};