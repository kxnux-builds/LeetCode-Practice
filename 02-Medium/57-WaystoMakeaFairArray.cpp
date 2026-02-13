/*
Problem: Ways to Make a Fair Array
Link: https://leetcode.com/problems/ways-to-make-a-fair-array/description/
Difficulty: Medium
Topic: Array / Prefix Sums / Simulation

Problem Statement:
You are given a **0-indexed** integer array `nums`.  
An array is **fair** if the sum of the **even-indexed** elements equals the sum of the **odd-indexed** elements.

Return *the number of ways to remove exactly one index* from the array so that
the resulting array (after the removal) is fair.

Example:
Input: nums = [2,1,6,4]  
Output: 1  
Explanation:
After removing index 1 (`nums[1]=1`), the new array becomes [2,6,4].
Even indices → 2 + 4 = 6  
Odd indices → 6  
They are equal.

Approach (Prefix Sums – Optimal):
1. Compute the **total sums** of even and odd positions:  
   - `evenSum` = sum of nums at even indices  
   - `oddSum` = sum of nums at odd indices  
2. Maintain two running prefix sums as we remove each index:
   - `leftEven`, `leftOdd`: sums of even/odd indices before the current index
   - `rightEven`, `rightOdd`: sums after the current index
3. After removing `nums[i]`:
   - Subsequent elements shift index parity → flip between right sums.
4. At each index `i`, compute:
   - newEvenSum = leftEven + rightOdd (shifted)
   - newOddSum  = leftOdd  + rightEven
5. If they match → this removal makes the array fair → increment answer.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        // total sums for even and odd positions
        long long evenSum = 0, oddSum = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) evenSum += nums[i];
            else            oddSum += nums[i];
        }

        long long leftEven = 0, leftOdd = 0;
        int ways = 0;

        for (int i = 0; i < n; ++i) {
            // remove nums[i]
            // subtract from totals to get right sums
            if (i % 2 == 0) evenSum -= nums[i];
            else            oddSum -= nums[i];

            // after removal:
            // right part swaps parity → old even becomes odd and vice versa
            long long newEvenSum = leftEven + oddSum;
            long long newOddSum  = leftOdd  + evenSum;

            if (newEvenSum == newOddSum) {
                ways++;
            }

            // add nums[i] back into left prefix sums
            if (i % 2 == 0) leftEven += nums[i];
            else            leftOdd  += nums[i];
        }

        return ways;
    }
};