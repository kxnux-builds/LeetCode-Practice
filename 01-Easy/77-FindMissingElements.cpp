/*
Problem: Find Missing Elements
Link: https://leetcode.com/problems/find-missing-elements/description/
Difficulty: Easy
Topic: Array / Sorting / Hashing

Problem Statement:
You are given an array nums of distinct integers.

The array contains values in a certain range, but some
integers are missing.

Find and return all integers that are missing between
the minimum and maximum values of nums.

The answer can be returned in any order.

Example 1:
Input: nums = [1,4,2,5]
Output: [3]

Explanation:
Minimum = 1
Maximum = 5

Numbers in the range:
1, 2, 3, 4, 5

3 is missing.

Example 2:
Input: nums = [7,8,6,9]
Output: []

Explanation:
All numbers from 6 to 9 are present.

Example 3:
Input: nums = [10,5,7]
Output: [6,8,9]

Explanation:
Minimum = 5
Maximum = 10

Numbers in range:
5,6,7,8,9,10

Missing:
6,8,9

--------------------------------------------------

Approach (Sorting + Range Traversal – Optimal):

Key Insight:
After sorting the array, every missing number will
appear as a gap between two consecutive elements.

For example:

[5,7,10]

Missing:
6
8
9

We can simply check every number from the minimum
to the maximum and determine whether it exists.

Since the constraints are small, sorting provides
a simple and easy-to-understand solution.

--------------------------------------------------

Steps:
1. Sort the array.
2. Find:
      minimum = nums[0]
      maximum = nums[n - 1]
3. Traverse from minimum to maximum.
4. Keep checking the current array element.
5. If a number is not present, add it to the answer.
6. Return the missing elements.

--------------------------------------------------

Dry Run:

nums = [10,5,7]

After sorting:
[5,7,10]

Start from 5:

5 → present
6 → missing → add 6
7 → present
8 → missing → add 8
9 → missing → add 9
10 → present

Answer = [6,8,9]

--------------------------------------------------

Why it works:
- Sorting puts all existing values in increasing order.
- Every integer between the minimum and maximum
  should be present.
- If a value is skipped, it is a missing element.
- We check every value in the required range exactly once.

--------------------------------------------------

Time Complexity: O(n log n + k)

Where:
- n = number of elements
- k = number of values between minimum and maximum

Space Complexity: O(k)

- Output array stores the missing elements.

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> answer;

        int n = nums.size();

        for (int num = nums[0]; num <= nums[n - 1]; num++) {

            if (!binary_search(nums.begin(), nums.end(), num)) {
                answer.push_back(num);
            }
        }

        return answer;
    }
};