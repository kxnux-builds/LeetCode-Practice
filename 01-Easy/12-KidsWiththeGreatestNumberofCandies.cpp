/*
Problem: Kids With the Greatest Number of Candies
Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/
Difficulty: Easy
Topic: Array / Greedy

Problem Statement:
Given the array candies and an integer extraCandies, where candies[i] represents 
the number of candies the i-th kid has, return a boolean array answer of length n 
where answer[i] is true if, after giving the i-th kid all extraCandies, they have 
the greatest number of candies among all kids.

Approach:
1. Find the maximum number of candies any kid currently has.
2. Iterate over the array:
   - If candies[i] + extraCandies >= maximum, mark true.
   - Otherwise, mark false.
3. Return the boolean array.

Time Complexity: O(n)  — single pass to find max + single pass to build result
Space Complexity: O(n) — for the answer array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(), candies.end());
        vector<bool> ans;

        for (int candy : candies) {
            ans.push_back(candy + extraCandies >= maxi);
        }

        return ans;
    }
};
