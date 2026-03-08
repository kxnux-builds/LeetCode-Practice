/*
Problem: Find Unique Binary String
Link: https://leetcode.com/problems/find-unique-binary-string/description/
Difficulty: Medium
Topic: Array / String / Math

Problem Statement:
Given an array of strings `nums` containing `n` unique binary strings,
each string has length `n`.

Return a **binary string of length `n` that does NOT appear in `nums`**.
If there are multiple answers, you may return any of them. :contentReference[oaicite:0]{index=0}

Example 1:
Input: nums = ["01","10"]  
Output: "11"  
Explanation: "11" does not exist in nums. "00" is also valid.

Example 2:
Input: nums = ["00","01"]  
Output: "11"  
Explanation: "11" does not exist in nums. "10" is also valid.

Example 3:
Input: nums = ["111","011","001"]  
Output: "101"  

Constraints:
n == nums.length  
1 <= n <= 16  
nums[i].length == n  
nums[i] contains only '0' or '1'  
All strings are unique. :contentReference[oaicite:1]{index=1}

--------------------------------------------------

Approach (Cantor's Diagonal Trick – Optimal):

Key Idea:
Construct a new binary string by **flipping the i-th bit of the i-th string**.

Steps:
1. Traverse the array.
2. For each string `nums[i]`, check the character at index `i`.
3. Flip the bit:
   - '0' → '1'
   - '1' → '0'
4. Append the flipped bit to the result.

Why it Works:
The constructed string will differ from the `i-th` string at position `i`,
so it **cannot be equal to any string in the array**.  
Thus, it is guaranteed to be unique. :contentReference[oaicite:2]{index=2}

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";

        for (int i = 0; i < n; i++) {
            if (nums[i][i] == '0')
                result += '1';
            else
                result += '0';
        }

        return result;
    }
};