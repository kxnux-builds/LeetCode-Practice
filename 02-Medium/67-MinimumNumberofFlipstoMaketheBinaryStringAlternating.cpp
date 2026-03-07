/*
Problem: Minimum Number of Flips to Make the Binary String Alternating
Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/
Difficulty: Medium
Topic: String / Sliding Window / Greedy

Problem Statement:
You are given a binary string `s`.

You can perform two types of operations:
1. Remove the first character of the string and append it to the end (rotation).
2. Flip any character (`0` → `1` or `1` → `0`).

Return the **minimum number of flip operations (type-2)** required to make the string alternating.  
A binary string is alternating if **no two adjacent characters are the same**. :contentReference[oaicite:0]{index=0}

Examples of alternating strings:
"010", "1010"

Example 1:
Input: s = "111000"  
Output: 2  

Explanation:
Rotate twice → "100011"  
Flip two characters → "101010"

Example 2:
Input: s = "010"  
Output: 0  
Explanation: Already alternating.

Example 3:
Input: s = "1110"  
Output: 1  

Approach (Sliding Window + Pattern Matching – Optimal):

Key Idea:
An alternating string can only have **two patterns**:
1. "010101..."
2. "101010..."

Because rotation is allowed, we must consider **all rotations of the string**.

Optimization Trick:
Instead of generating rotations, we **double the string**:

s = s + s

Then use a **sliding window of size n** to check every rotation.

Steps:
1. Create two target patterns of length `2n`
   - alt1 = "010101..."
   - alt2 = "101010..."
2. Slide a window of size `n`.
3. Count mismatches with both patterns.
4. Maintain the minimum flips.

Time Complexity: O(n)  
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string s2 = s + s;

        string alt1 = "", alt2 = "";
        for (int i = 0; i < 2 * n; i++) {
            alt1 += (i % 2 ? '1' : '0');
            alt2 += (i % 2 ? '0' : '1');
        }

        int diff1 = 0, diff2 = 0;
        int left = 0;
        int ans = INT_MAX;

        for (int right = 0; right < 2 * n; right++) {
            if (s2[right] != alt1[right]) diff1++;
            if (s2[right] != alt2[right]) diff2++;

            if (right - left + 1 > n) {
                if (s2[left] != alt1[left]) diff1--;
                if (s2[left] != alt2[left]) diff2--;
                left++;
            }

            if (right - left + 1 == n) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};