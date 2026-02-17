/*
Problem: Binary Watch
Link: https://leetcode.com/problems/binary-watch/description/
Difficulty: Easy
Topic: Bit Manipulation / Brute Force / Simulation

Problem Statement:
A binary watch has 4 LEDs to represent the hours (0-11) and 6 LEDs to represent the minutes (0-59). 
Each LED represents either a 0 or a 1 in binary, with the least significant bit on the right.

Given an integer `turnedOn` representing the number of LEDs that are currently on,
return *all possible times* the watch could represent. You can return the answer in any order.

- Hours should not contain a leading zero (e.g., "01:00" is invalid).
- Minutes must be two digits with leading zeros if needed (e.g., "10:02" not "10:2"). :contentReference[oaicite:0]{index=0}

Example:
Input: turnedOn = 1  
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

Example:
Input: turnedOn = 9  
Output: []

Approach (Brute Force – Optimal Here):
1. There are at most **12 hours × 60 minutes = 720 possible times**.
2. Loop through all valid hour values (0-11) and minute values (0-59).
3. For each hour and minute:
   - Compute the number of set bits (`1`s) in the hour and in the minute.
   - If the total equals `turnedOn`, format the time string properly (`hour:minute` with 2-digit minutes).
   - Add it to the result list.
4. Return the result.

Time Complexity: O(1) — Constant 720 combinations.  
Space Complexity: O(1) — Only output list uses extra space. :contentReference[oaicite:1]{index=1}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> times;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                // Count set bits in hour + minute
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    // Format time string
                    string time = to_string(h) + ":";
                    if (m < 10) time += "0"; // ensure 2-digit minutes
                    time += to_string(m);
                    times.push_back(time);
                }
            }
        }
        return times;
    }
};