/*
Problem: Shortest Distance to Target String in a Circular Array
Link: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/
Difficulty: Easy
Topic: Array / String / Simulation

Problem Statement:
You are given a **circular array** of strings `words` and a string `target`.

- The array is circular → after last element comes first
- From index `i`, you can move:
  - right → (i + 1) % n
  - left  → (i - 1 + n) % n

Starting from `startIndex`, return the **minimum number of steps**
needed to reach any index where `words[i] == target`.

If target does not exist → return `-1`. :contentReference[oaicite:0]{index=0}

Example 1:
Input: words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1  
Output: 1  

Example 2:
Input: words = ["a","b","leetcode"], target = "leetcode", startIndex = 0  
Output: 1  

Example 3:
Input: words = ["i","eat","leetcode"], target = "ate", startIndex = 0  
Output: -1  

--------------------------------------------------

Approach (Circular Distance Calculation – Optimal):

Key Idea:
For any index `i` where `words[i] == target`, we have two ways:
- Move directly → distance = abs(i - startIndex)
- Wrap around → distance = n - abs(i - startIndex)

So final distance:
👉 min(abs(i - startIndex), n - abs(i - startIndex)) :contentReference[oaicite:1]{index=1}

Steps:
1. Traverse all indices
2. If `words[i] == target`:
   - Compute circular distance
   - Take minimum
3. If no occurrence → return -1

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                int circularDist = min(dist, n - dist);
                ans = min(ans, circularDist);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};