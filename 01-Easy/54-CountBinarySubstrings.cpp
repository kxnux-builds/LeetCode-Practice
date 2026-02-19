/*
Problem: Count Binary Substrings
Link: https://leetcode.com/problems/count-binary-substrings/description/
Difficulty: Easy
Topic: Strings / Greedy / Counting

Problem Statement:
Given a binary string `s`, return *the number of non-empty substrings* that have the following properties:

- The substring has the same number of `0`s and `1`s.
- All the `0`s and all the `1`s in the substring are grouped consecutively.
  (i.e., all 0s are together and all 1s are together).

You don’t need to return the substrings themselves, only count how many valid ones exist.

Example:
Input: s = "00110011"  
Output: 6  
Explanation:
Valid substrings:  
"0011", "01", "1100", "10", "0011", "01"

Example:
Input: s = "10101"  
Output: 4  
Explanation:
Valid substrings: "10", "01", "10", "01"

Approach (Group Counts – Optimal):
1. Traverse the string and group **consecutive identical bits**,
   storing the length of each group.
2. For each pair of adjacent groups, add `min(prevGroup, currGroup)`
   to the answer — this counts how many valid substrings can be formed
   with those two groups.
3. Return the total count.

Intuition:
A valid substring must take some prefix of a group of `0`s followed by an equal
length prefix of a group of `1`s (or vice-versa). So the number of choices
between two adjacent groups is limited by the smaller group size.

Time Complexity: O(n)  
Space Complexity: O(1) — only a few integer counters used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevCount = 0;
        int currCount = 1;
        int result = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                currCount++;
            } else {
                // Completed a group, add valid pairs
                result += min(prevCount, currCount);
                prevCount = currCount;
                currCount = 1;
            }
        }

        // Final group transition
        result += min(prevCount, currCount);
        return result;
    }
};