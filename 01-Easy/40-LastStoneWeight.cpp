/*
Problem: Last Stone Weight
Link: https://leetcode.com/problems/last-stone-weight/description/
Difficulty: Easy
Topic: Heap / Greedy / Priority Queue

Problem Statement:
You are given an array `stones` where `stones[i]` is the weight of the ith stone.  
On each turn, choose the **two heaviest stones** and smash them together:
- If the stones have equal weight, both stones are destroyed.
- If the stones have different weights, the smaller stone is destroyed and the larger
  stone’s weight is reduced by the smaller stone’s weight.
Continue until at most one stone remains.  
Return *the weight of the last remaining stone*.  
If no stones remain, return 0.

Example:
Input: stones = [2,7,4,1,8,1]  
Output: 1  
Explanation:
- Smash 8 & 7 → new stone = 1 → stones = [2,4,1,1,1]
- Smash 4 & 2 → new stone = 2 → stones = [2,1,1,1]
- Smash 2 & 1 → new stone = 1 → stones = [1,1,1]
- Smash 1 & 1 → both destroyed → stones = [1]
- Result = 1

Approach (Max Heap / Priority Queue – Optimal):
1. Use a max heap (priority queue) to always extract the two largest stones.
2. Push all initial stones into the max heap.
3. While heap size ≥ 2:
   - Pop the top two weights.
   - If they aren’t equal, push back their difference.
4. If the heap is non-empty → answer = top; otherwise 0.

Time Complexity: O(n log n)  
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int w : stones) {
            pq.push(w);
        }

        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if (a != b) {
                pq.push(a - b);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};