/*
Problem: Number of Students Unable to Eat Lunch
Link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
Difficulty: Easy
Topic: Array / Queue / Simulation / Greedy

Problem Statement:
The school cafeteria offers circular and square sandwiches.
Students are standing in a queue, each preferring one type of sandwich.

Rules:
- If the student at the front prefers the sandwich on top, they take it and leave.
- Otherwise, they move to the end of the queue.
- If no student wants the top sandwich, the process stops.

Return the number of students unable to eat.

Example:
students = [1,1,0,0]
sandwiches = [0,1,0,1]
Output: 0

Approach (Greedy Count – Optimal):
1. Count how many students prefer circular (0) and square (1) sandwiches.
2. Traverse the sandwiches stack from top to bottom:
   - If current sandwich is 0 and no student wants 0 → stop.
   - If current sandwich is 1 and no student wants 1 → stop.
   - Otherwise, decrement the corresponding count.
3. Remaining sandwiches = students unable to eat.

Why this works:
Queue rotation does not change preference counts.
Once no matching preference exists, no further progress is possible.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0;

        for (int s : students) {
            if (s == 0) count0++;
            else count1++;
        }

        for (int s : sandwiches) {
            if (s == 0) {
                if (count0 == 0) break;
                count0--;
            } else {
                if (count1 == 0) break;
                count1--;
            }
        }

        return count0 + count1;
    }
};