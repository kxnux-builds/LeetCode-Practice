/*
Problem: Implement Queue using Stacks
Link: https://leetcode.com/problems/implement-queue-using-stacks/description/
Difficulty: Easy
Topic: Stack / Design / Amortized Analysis

Problem Statement:
Implement a first-in-first-out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue:
push, pop, peek, and empty.

Example:
Input:
["MyQueue","push","push","peek","pop","empty"]
[[],[1],[2],[],[],[]]
Output:
[null,null,null,1,1,false]

Approach (Two Stacks – Amortized O(1)):
1. Use two stacks:
   - `inStack`  → used for push operations
   - `outStack` → used for pop and peek operations
2. Push:
   - Always push elements into `inStack`.
3. Pop / Peek:
   - If `outStack` is empty, transfer all elements from `inStack` to `outStack`
     (this reverses order and maintains FIFO).
   - Pop or peek from `outStack`.
4. Empty:
   - Queue is empty if both stacks are empty.

Why this works:
Each element is moved at most once from `inStack` to `outStack`,
giving amortized O(1) time per operation.

Time Complexity:
- push: O(1)
- pop / peek: Amortized O(1)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty())
            transfer();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        if (outStack.empty())
            transfer();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};