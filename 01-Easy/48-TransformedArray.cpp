/*
Problem: Transformed Array
Link: https://leetcode.com/problems/transformed-array/description/
Difficulty: Easy
Topic: Array / Simulation / Circular Array

Problem Statement:
You are given an integer array `nums` that represents a **circular array**.  
Create and return a new array `result` of the same size following these rules:

For each index `i` (where `0 <= i < nums.length`):

  • If `nums[i] > 0`:  
    Move `nums[i]` steps to the **right** (wrapping around) from index `i`,  
    and set `result[i]` to the value at the landing index.

  • If `nums[i] < 0`:  
    Move `abs(nums[i])` steps to the **left** (wrapping around) from index `i`,  
    and set `result[i]` to the value at the landing index.

  • If `nums[i] == 0`:  
    Set `result[i] = nums[i]` (stays 0).

Because the array is circular:
  - Moving past the last element wraps back to the beginning.
  - Moving before the first element wraps to the end.

Example 1:
Input: nums = [3, -2, 1, 1]  
Output: [1,1,1,3]  
Explanation:
- i=0: Move 3 right → index (0+3)%4 = 3 → value 1  
- i=1: Move 2 left → index (1−2)%4 = 3 → value 1  
- i=2: Move 1 right → index (2+1)%4 = 3 → value 1  
- i=3: Move 1 right → index (3+1)%4 = 0 → value 3

Example 2:
Input: nums = [-1, 4, -1]  
Output: [-1,-1,4]  
Explanation:
- i=0: Move 1 left → index (0−1)%3 = 2 → value −1  
- i=1: Move 4 right → index (1+4)%3 = 2 → value −1  
- i=2: Move 1 left → index (2−1)%3 = 1 → value 4 :contentReference[oaicite:0]{index=0}

Approach (Modular Arithmetic – Optimal):
1. Let `n = nums.size()`.
2. For each `i`, compute the target index:
     - `newIndex = ((i + nums[i]) % n + n) % n`  
       → ensures wrap-around and handles negative moves.
3. Set `result[i] = nums[newIndex]`.
4. Return `result`.

Time Complexity: O(n)  
Space Complexity: O(n) — for the result array :contentReference[oaicite:1]{index=1}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                // Compute circular new index
                int newIndex = ((i + nums[i]) % n + n) % n;
                result[i] = nums[newIndex];
            }
        }

        return result;
    }
};