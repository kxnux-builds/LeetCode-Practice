/*
Problem: Words Within Two Edits of Dictionary
Link: https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/
Difficulty: Medium
Topic: Array / String / Simulation

Problem Statement:
You are given two string arrays `queries` and `dictionary`.
All words have the **same length**.

In one edit, you can change any one character of a word.

Return all words from `queries` that can be transformed into
any word in `dictionary` using **at most two edits**.

The answer should be returned in the same order as `queries`. :contentReference[oaicite:0]{index=0}

Example 1:
Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]  
Output: ["word","note","wood"]

Example 2:
Input: queries = ["yes"], dictionary = ["not"]  
Output: []

--------------------------------------------------

Approach (Brute Force Comparison – Optimal):

Key Insight:
Since all words have equal length and only **replacement operations**
are allowed, the number of edits = number of positions where characters differ. :contentReference[oaicite:1]{index=1}

So:
👉 Count mismatched characters between two strings  
👉 If mismatches ≤ 2 → valid word

Steps:
1. For each word `q` in queries:
2. Compare with each word `d` in dictionary:
   - Count differing characters
   - If differences ≤ 2 → add `q` to result and break
3. Return result list

--------------------------------------------------

Time Complexity: O(q × d × n)  
Space Complexity: O(1) (excluding output)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for (auto &q : queries) {
            for (auto &d : dictionary) {
                int diff = 0;

                for (int i = 0; i < q.size(); i++) {
                    if (q[i] != d[i]) diff++;
                    if (diff > 2) break;
                }

                if (diff <= 2) {
                    result.push_back(q);
                    break;
                }
            }
        }

        return result;
    }
};