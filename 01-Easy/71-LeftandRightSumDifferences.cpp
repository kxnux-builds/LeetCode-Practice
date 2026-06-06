/*
Problem: Left and Right Sum Differences
Link: https://leetcode.com/problems/left-and-right-sum-differences/description/
Difficulty: Easy
Topic: Array / Prefix Sum

Problem Statement:
Given a 0-indexed integer array nums of length n,
find an array answer of length n where:

answer[i] = |leftSum[i] - rightSum[i]|

Where:
- leftSum[i] = sum of elements to the left of index i
- rightSum[i] = sum of elements to the right of index i

Return the array answer.

Example 1:
Input: nums = [10,4,8,3]
Output: [15,1,11,22]

Explanation:
i = 0:
leftSum = 0
rightSum = 4 + 8 + 3 = 15
answer[0] = |0 - 15| = 15

i = 1:
leftSum = 10
rightSum = 8 + 3 = 11
answer[1] = |10 - 11| = 1

i = 2:
leftSum = 10 + 4 = 14
rightSum = 3
answer[2] = |14 - 3| = 11

i = 3:
leftSum = 10 + 4 + 8 = 22
rightSum = 0
answer[3] = |22 - 0| = 22

Example 2:
Input: nums = [1]
Output: [0]

--------------------------------------------------

Approach (Running Left & Right Sum – Optimal):

Key Insight:
Instead of computing left and right sums separately
for every index, maintain:

- totalSum = sum of all elements
- leftSum = running sum of elements on the left

For each index:
rightSum = totalSum - leftSum - nums[i]

Then:
answer[i] = abs(leftSum - rightSum)

--------------------------------------------------

Steps:
1. Compute totalSum of the array.
2. Initialize leftSum = 0.
3. Traverse the array:
   - rightSum = totalSum - leftSum - nums[i]
   - answer[i] = abs(leftSum - rightSum)
   - Update leftSum += nums[i]
4. Return answer.

--------------------------------------------------

Dry Run:

nums = [10,4,8,3]

totalSum = 25

i = 0:
leftSum = 0
rightSum = 25 - 0 - 10 = 15
answer = 15

i = 1:
leftSum = 10
rightSum = 25 - 10 - 4 = 11
answer = 1

i = 2:
leftSum = 14
rightSum = 25 - 14 - 8 = 3
answer = 11

i = 3:
leftSum = 22
rightSum = 25 - 22 - 3 = 0
answer = 22

Result = [15,1,11,22]

--------------------------------------------------

Why it works:
- leftSum stores sum of elements before i.
- rightSum is derived using totalSum.
- Each element is processed only once.
- No extra prefix/suffix arrays are needed.

--------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)
(Excluding the output array)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();

        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        vector<int> answer(n);
        int leftSum = 0;

        for (int i = 0; i < n; i++) {

            int rightSum = totalSum - leftSum - nums[i];

            answer[i] = abs(leftSum - rightSum);

            leftSum += nums[i];
        }

        return answer;
    }
};