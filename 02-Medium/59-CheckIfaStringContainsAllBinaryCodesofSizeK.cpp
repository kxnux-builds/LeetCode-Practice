/*
Problem: Check If a String Contains All Binary Codes of Size K
Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/
Difficulty: Medium
Topic: Strings / Hashing / Bit Manipulation

Problem Statement:
Given a binary string `s` and an integer `k`, return `true` *if every binary code* of length `k` 
exists as a substring of `s`. Otherwise, return `false`.

Example 1:
Input: s = "00110110", k = 2  
Output: true  
Explanation: The binary codes of length 2 are: "00", "01", "10", "11", all of which appear.

Example 2:
Input: s = "0110", k = 1  
Output: true  
Explanation: The binary codes of length 1 are: "0", "1".

Example 3:
Input: s = "0110", k = 2  
Output: false  
Explanation: Missing "00", so not all codes appear.

Approach (Hash Set + Sliding Window – Optimal):
1. If `k > s.length()`, it’s impossible to contain all codes → return `false`.
2. Maintain a hash set to store all unique substrings of length `k`.
3. Slide a window of length `k` across `s`:
   - At each position, extract the substring `s[i..i+k-1]` and insert into the set.
4. There are at most `2^k` different binary codes of length `k`.
   If set size reaches `2^k`, return `true`.
5. After scanning, check if set size == `2^k`.

Time Complexity: O(n)  
Space Complexity: O(2^k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        
        unordered_set<string> codes;
        int need = 1 << k; // total unique codes of length k
        
        for (int i = 0; i + k <= s.size(); ++i) {
            codes.insert(s.substr(i, k));
            if (codes.size() == need) return true;
        }
        
        return codes.size() == need;
    }
};