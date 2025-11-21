/*
Problem: Time Needed to Buy Tickets
Link: https://leetcode.com/problems/time-needed-to-buy-tickets/description/
Difficulty: Easy
Topic: Queue / Simulation

Problem Statement:
You are given an array tickets where tickets[i] is the number of tickets 
person i wants to buy. People stand in a queue from left to right.
Each second:
    - The person at the front buys 1 ticket.
    - If they still need more tickets, they go to the back of the line.
Find the total time required for person k to finish buying all their tickets.

Example:
Input: tickets = [2,3,2], k = 2
Output: 6

Approach (Optimized Counting Logic):
Key Observation:
Every person i in front of person k will buy:
    min(tickets[i], tickets[k]) tickets.

Every person after k will buy:
    min(tickets[i], tickets[k] - 1) tickets.
(because after the kth person buys the final ticket, the queue stops)

Algorithm:
1. Let target = tickets[k].
2. Loop through all i:
     - If i ≤ k: time += min(tickets[i], target)
     - Else:     time += min(tickets[i], target - 1)
3. Return time.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int target = tickets[k];
        int time = 0;

        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k)
                time += min(tickets[i], target);
            else
                time += min(tickets[i], target - 1);
        }

        return time;
    }
};