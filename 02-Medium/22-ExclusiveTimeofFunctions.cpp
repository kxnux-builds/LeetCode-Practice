/*
Problem: Exclusive Time of Functions
Link: https://leetcode.com/problems/exclusive-time-of-functions/description/
Difficulty: Medium
Topic: Stack / Simulation / String Parsing

Problem Statement:
On a single-threaded CPU, a program executes n functions, each with a unique ID from 0 to n−1.
Function calls are logged in a list of strings logs, where each log is formatted as:
    "{function_id}:{“start” | “end”}:{timestamp}"

- "start" means the function starts at the beginning of that timestamp.
- "end" means the function ends at the end of that timestamp.
Functions can call other functions (including recursively).  
When a function call starts, its ID is pushed onto the call stack; when it ends, it is popped.  
Only the function at the top of the stack is actively executing at any time.

Return an array of size n, where the i-th element is the **exclusive time** of function i  
— i.e. total time spent executing function i, **excluding** time spent in functions called by i (nested calls).

Example:
Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]  
Output: [3,4]

Explanation:
- Function 0 runs from time 0 to 1 (2 units), then is paused when function 1 starts at time 2.
- Function 1 runs from time 2 to 5 (4 units), then ends.
- Function 0 resumes at time 6 and ends at 6 (1 unit).
So, exclusive time: func 0 → 2 + 1 = 3, func 1 → 4.

Approach (Stack-based Simulation – Optimal):
1. Use a stack to keep track of currently running functions (by ID).  
2. Maintain a variable `prev_time` to record the previous processed timestamp.  
3. Iterate through each log (in order):
   - Parse `id`, `type` (start/end), `time`.  
   - If it's a "start":
       - If stack is not empty, add to `ans[stack.top()]` the time difference `time - prev_time`.  
       - Push current `id` on stack.  
       - Update `prev_time = time`.  
   - If it's an "end":
       - Pop the top `id`.  
       - Add to `ans[id]` the time difference `time - prev_time + 1`.  // +1 because end timestamp is inclusive  
       - Update `prev_time = time + 1`.  

Time Complexity: O(m) where m = logs.size()  
Space Complexity: O(n) for stack + ans array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prev_time = 0;

        for (auto &log : logs) {
            // parse log
            int id = 0;
            int pos1 = log.find(':');
            id = stoi(log.substr(0, pos1));
            int pos2 = log.find(':', pos1 + 1);
            string type = log.substr(pos1 + 1, pos2 - pos1 - 1);
            int time = stoi(log.substr(pos2 + 1));

            if (type == "start") {
                if (!st.empty()) {
                    ans[st.top()] += time - prev_time;
                }
                st.push(id);
                prev_time = time;
            } else { // "end"
                ans[st.top()] += time - prev_time + 1;
                st.pop();
                prev_time = time + 1;
            }
        }

        return ans;
    }
};