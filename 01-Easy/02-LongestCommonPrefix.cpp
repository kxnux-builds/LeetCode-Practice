/*
Problem: Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/description/
Difficulty: Easy
Topic: String / Array

Problem Statement:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Approach:
1. If the input array is empty, return "".
2. Take the first string as a reference prefix.
3. Compare each character of the prefix with corresponding characters in all other strings.
4. Truncate the prefix when a mismatch is found.
5. Continue until the prefix matches all strings.

Time Complexity: O(n * m)  (n = number of strings, m = length of prefix)
Space Complexity: O(1) extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
            {
                j++;
            }
            prefix = prefix.substr(0, j);
            if (prefix.empty())
                return "";
        }
        return prefix;
    }
};