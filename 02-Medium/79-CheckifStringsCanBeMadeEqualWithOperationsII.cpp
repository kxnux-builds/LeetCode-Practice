/*
Problem: Check if Strings Can Be Made Equal With Operations II
Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/
Difficulty: Medium
Topic: String / Hashing / Sorting

Problem Statement:
You are given two strings `s1` and `s2` of equal length.

You can perform the following operation any number of times:
- Choose two indices `i` and `j` such that:
  - `i < j`
  - `(j - i)` is **even**
- Swap the characters at those indices.

Return `true` if you can make `s1` equal to `s2`, otherwise return `false`. :contentReference[oaicite:0]{index=0}

Example 1:
Input: s1 = "abcdba", s2 = "cabdab"  
Output: true  

Example 2:
Input: s1 = "abe", s2 = "bea"  
Output: false  

Constraints:
1 <= n <= 10^5  
s1.length == s2.length  
Strings consist of lowercase English letters  

--------------------------------------------------

Approach (Parity Grouping + Counting – Optimal):

Key Insight:
Since `(j - i)` must be even, we can only swap:
- even index ↔ even index
- odd index ↔ odd index

So the string splits into **two independent groups**:
1. Even indices
2. Odd indices :contentReference[oaicite:1]{index=1}

We can freely rearrange characters within each group.

Steps:
1. Count frequency of characters at:
   - even indices in `s1` and `s2`
   - odd indices in `s1` and `s2`
2. Compare:
   - even counts must match
   - odd counts must match
3. If both match → return true

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(1) (26 letters)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even1(26, 0), odd1(26, 0);
        vector<int> even2(26, 0), odd2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) {
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            } else {
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
        }

        return (even1 == even2 && odd1 == odd2);
    }
};