/*
Problem: Construct Target Array With Multiple Sums
Link: https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/
Difficulty: Hard
Topic: Greedy / Heap / Simulation / Math

Problem Statement:
Given an array `target` of **positive integers**, return `true` if you can
construct the `target` array starting from an array of all **1’s** (same length)
by repeatedly applying this procedure:

- At each step, choose any index `i` and set:
      arr[i] = sum(arr)

where `sum(arr)` is the sum of all elements in the current array.

Return `false` if it is **impossible** to construct `target` this way.

Example:
Input: target = [9,3,5]
Output: true  
Explanation:
Start with [1,1,1]:
  Step 1: sum = 3 → update index 0 → becomes [3,1,1]
  Step 2: sum = 5 → update index 0 → becomes [5,1,1]
  Step 3: sum = 7 → update index 2 → becomes [5,1,7]
  Step 4: sum = 13 → update index 0 → becomes [13,1,7]
Finally target can be achieved.

Approach (Greedy with Max Heap – Optimal):
This problem is best solved **in reverse**:
1. Compare `target` with the start array `[1,1,...,1]`.
2. At each step, **replace** the largest number `x` in the current array
   with `x % (sum − x)`:
   - Because in the forward process, `x` was formed by adding all other
     elements in the array to some previous value.
   - So reverse step = `prevVal = x − (sum − x) = x % (sum − x)`.
3. Repeat until:
   - The largest element becomes 1 → return `true`.
   - The new value becomes **0 or negative** → impossible → return `false`.

Use a **max heap** for efficient access to the largest element.

Time Complexity: O(n log n) amortized  
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long total = 0;
        priority_queue<long long> pq;

        for (long long x : target) {
            total += x;
            pq.push(x);
        }

        while (true) {
            long long x = pq.top(); pq.pop();
            long long rest = total - x;

            // If x was formed from all 1s (or rest == 1)
            if (x == 1 || rest == 1) return true;

            // Cannot reduce further
            if (rest == 0 || x < rest) return false;

            long long newVal = x % rest;

            // If mod result 0 or no change → impossible
            if (newVal == 0 || newVal == x) return false;

            total = rest + newVal;
            pq.push(newVal);
        }

        return true;
    }
};