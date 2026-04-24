/*
Problem: Furthest Point From Origin
Link: https://leetcode.com/problems/furthest-point-from-origin/description/
Difficulty: Easy
Topic: String / Greedy / Counting

Problem Statement:
You are given a string `moves` consisting of:
- 'L' → move left
- 'R' → move right
- '_' → can move either left or right

You start from position `0` on a number line.

Return the **maximum distance from origin** that you can achieve
after performing all moves. :contentReference[oaicite:0]{index=0}

Example 1:
Input: moves = "L_RL__R"  
Output: 3  

Example 2:
Input: moves = "_R__LL_"  
Output: 5  

Example 3:
Input: moves = "_______"  
Output: 7  

Constraints:
1 <= moves.length <= 50  
moves contains only 'L', 'R', '_'

--------------------------------------------------

Approach (Greedy + Counting – Optimal):

Key Insight:
- Count:
  - number of 'L' → left moves
  - number of 'R' → right moves
  - number of '_' → flexible moves

To maximize distance:
👉 Use all '_' moves in the direction that increases distance

Final position:
= |R - L| + count('_') :contentReference[oaicite:1]{index=1}

Why it works:
- Fixed moves give base difference
- '_' moves can all push further in same direction

--------------------------------------------------

Steps:
1. Count L, R, and '_'
2. Compute difference = abs(R - L)
3. Add all '_' → maximize distance
4. Return result

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, blank = 0;

        for (char c : moves) {
            if (c == 'L') L++;
            else if (c == 'R') R++;
            else blank++;
        }

        return abs(R - L) + blank;
    }
};