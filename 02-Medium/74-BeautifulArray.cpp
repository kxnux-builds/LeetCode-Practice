/*
Problem: Beautiful Array
Link: https://leetcode.com/problems/beautiful-array/description/
Difficulty: Medium
Topic: Array / Divide and Conquer / Math

Problem Statement:
An array `nums` of length `n` is called **beautiful** if:

1. `nums` is a **permutation of integers from 1 to n**.
2. For every `0 ≤ i < j < n`, there is **no index `k` (i < k < j)** such that:
   
   2 * nums[k] == nums[i] + nums[j]

This means the middle element cannot be the **average of two surrounding elements**
(i.e., no arithmetic progression inside the array). :contentReference[oaicite:0]{index=0}

Given an integer `n`, return **any beautiful array of length `n`**.
It is guaranteed that at least one valid answer exists. :contentReference[oaicite:1]{index=1}

Example 1:
Input: n = 4  
Output: [2,1,4,3]

Example 2:
Input: n = 5  
Output: [3,1,2,5,4]

Constraints:
1 <= n <= 1000

--------------------------------------------------

Approach (Divide & Conquer – Optimal):

Key Idea:
If we separate numbers into **odd and even groups**, they cannot form
an arithmetic progression with each other.

Observation:
If `A` is a beautiful array, then:
- `[2*x - 1 for x in A]` → produces valid **odd numbers**
- `[2*x for x in A]` → produces valid **even numbers**

Algorithm:
1. Recursively build beautiful arrays for smaller sizes.
2. Generate:
   - odd numbers from the left half
   - even numbers from the right half
3. Combine them to form the final array.

Steps:
1. Base case: if `n == 1` → return `[1]`
2. Recursively compute:
   - `beautifulArray((n + 1) / 2)` for odds
   - `beautifulArray(n / 2)` for evens
3. Transform:
   - odds → `2*x - 1`
   - evens → `2*x`
4. Concatenate both arrays.

This guarantees the condition `2*nums[k] != nums[i] + nums[j]`. :contentReference[oaicite:2]{index=2}

--------------------------------------------------

Time Complexity: O(n)  
Space Complexity: O(n)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};

        vector<int> result;

        // Generate odd part
        vector<int> odd = beautifulArray((n + 1) / 2);
        for (int x : odd) {
            result.push_back(2 * x - 1);
        }

        // Generate even part
        vector<int> even = beautifulArray(n / 2);
        for (int x : even) {
            result.push_back(2 * x);
        }

        return result;
    }
};