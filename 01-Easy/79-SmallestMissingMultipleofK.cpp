/*
Problem: Smallest Missing Multiple of K
Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/description/
Difficulty: Easy
Topic: Array / Hashing / Simulation

Problem Statement:
You are given an integer array nums and an integer k.

A positive multiple of k is any positive integer
that is divisible by k.

Return the smallest positive multiple of k
that is missing from nums.

Example 1:
Input:
nums = [8,2,3,4,6]
k = 2

Output:
10

Explanation:
Positive multiples of 2 are:

2, 4, 6, 8, 10, 12, ...

In nums:
2 → present
4 → present
6 → present
8 → present
10 → missing

Therefore, answer = 10

Example 2:
Input:
nums = [1,4,7,10,15]
k = 5

Output:
5

Explanation:
Positive multiples of 5 are:

5, 10, 15, 20, ...

5 is not present in nums.

Therefore, answer = 5

--------------------------------------------------

Approach (Hash Set + Simulation – Optimal):

Key Insight:
All possible answers are positive multiples of k.

So we:
1. Store all elements of nums in a Hash Set.
2. Start from k.
3. Check whether the current multiple exists.
4. If it exists, move to the next multiple.
5. If it does not exist, return it.

--------------------------------------------------

Steps:
1. Create an unordered_set.
2. Insert every element of nums into the set.
3. Start:
      multiple = k
4. While multiple exists in the set:
      multiple += k
5. Return multiple.

--------------------------------------------------

Dry Run:

nums = [8,2,3,4,6]
k = 2

Set:
{8,2,3,4,6}

multiple = 2
2 is present → continue

multiple = 4
4 is present → continue

multiple = 6
6 is present → continue

multiple = 8
8 is present → continue

multiple = 10
10 is NOT present

Answer = 10

--------------------------------------------------

Why it works:
- Every valid answer must be a positive multiple of k.
- We check multiples in increasing order:
      k, 2k, 3k, 4k, ...
- Therefore, the first multiple not found in nums
  is automatically the smallest missing multiple.

--------------------------------------------------

Important Pattern:

When a problem asks for the:

"Smallest missing X"

and X follows a predictable sequence:

1. Store existing values in a Hash Set.
2. Generate candidates in increasing order.
3. Return the first candidate that is missing.

Here:

Candidates:
k, 2k, 3k, 4k, ...

--------------------------------------------------

Time Complexity: O(n)

- Building the Hash Set: O(n)
- Checking multiples: O(n) in the worst case,
  because there are at most n present multiples
  before finding a missing one.

Overall: O(n)

Space Complexity: O(n)

- Hash Set stores the elements of nums.

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;

        // Store all elements
        for (int num : nums) {
            st.insert(num);
        }

        // Start with the first positive multiple of k
        int multiple = k;

        // Find the first missing multiple
        while (st.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};