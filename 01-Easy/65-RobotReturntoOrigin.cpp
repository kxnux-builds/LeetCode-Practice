/*
Problem: Robot Return to Origin
Link: https://leetcode.com/problems/robot-return-to-origin/description/
Difficulty: Easy
Topic: String / Simulation

Problem Statement:
There is a robot starting at position `(0, 0)` on a 2D plane.

You are given a string `moves` where each character represents a move:
- 'U' → move up
- 'D' → move down
- 'L' → move left
- 'R' → move right

Return `true` if the robot returns to the **origin (0,0)** after all moves,
otherwise return `false`. :contentReference[oaicite:0]{index=0}

Example 1:
Input: moves = "UD"  
Output: true  

Example 2:
Input: moves = "LL"  
Output: false  

Constraints:
1 <= moves.length <= 2 * 10^4  
moves consists only of 'U', 'D', 'L', 'R'

--------------------------------------------------

Approach (Simulation / Coordinate Tracking – Optimal):

Key Idea:
Track the robot's position using coordinates `(x, y)`.

- 'R' → x++
- 'L' → x--
- 'U' → y++
- 'D' → y--

If after all moves:
- x == 0 AND y == 0 → robot is back at origin

Alternative Insight:
Number of 'L' must equal 'R'  
Number of 'U' must equal 'D' :contentReference[oaicite:1]{index=1}

Steps:
1. Initialize x = 0, y = 0
2. Traverse the string:
   - Update coordinates based on move
3. Check if x == 0 && y == 0

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;

        for (char c : moves) {
            if (c == 'U') y++;
            else if (c == 'D') y--;
            else if (c == 'L') x--;
            else if (c == 'R') x++;
        }

        return (x == 0 && y == 0);
    }
};