/*
Problem: Maximum Element After Decreasing and Rearranging
Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/
Difficulty: Medium
Topic: Array / Greedy / Sorting

Problem Statement:
You are given an array arr of positive integers.

You may perform the following operations any number of times:
1. Rearrange the elements in any order.
2. Decrease the value of any element to any smaller positive integer.

After performing the operations, the array must satisfy:
- The first element is equal to 1.
- The absolute difference between every pair of adjacent elements
  is at most 1.

Return the maximum possible value of the largest element
in the array.

Example 1:
Input: arr = [2,2,1,2,1]
Output: 2

Explanation:
One possible valid array:
[1,2,2,2,2]

Maximum element = 2

Example 2:
Input: arr = [100,1,1000]
Output: 3

Explanation:
One possible valid array:
[1,2,3]

Maximum element = 3

Example 3:
Input: arr = [1,2,3,4,5]
Output: 5

Explanation:
The array already satisfies the conditions.

--------------------------------------------------

Approach (Greedy + Sorting – Optimal):

Key Insight:
To maximize the largest element:
- Sort the array.
- Make the first element equal to 1.
- For every next element:
    It can be at most previous + 1.

If the current value is larger than previous + 1,
decrease it to previous + 1.

This keeps the array valid while maximizing
every element.

--------------------------------------------------

Steps:
1. Sort the array.
2. Set arr[0] = 1.
3. Traverse from index 1:
   - arr[i] = min(arr[i], arr[i-1] + 1)
4. Return the last element.

--------------------------------------------------

Dry Run:

arr = [100,1,1000]

After sorting:
[1,100,1000]

arr[0] = 1

i = 1:
min(100,2) = 2

Array:
[1,2,1000]

i = 2:
min(1000,3) = 3

Array:
[1,2,3]

Answer = 3

--------------------------------------------------

Why it works:
- Sorting arranges numbers in increasing order.
- Every element is made as large as possible
  while ensuring the adjacent difference
  does not exceed 1.
- Since we only decrease values,
  this greedy approach always produces
  the maximum possible largest element.

--------------------------------------------------

Time Complexity: O(n log n)

- Sorting dominates the complexity.

Space Complexity: O(1)

(Ignoring sorting's internal space)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        return arr.back();
    }
};