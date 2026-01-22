/*
Problem: Minimum Pair Removal to Sort Array I
Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/
Difficulty: Easy
Topic: Array / Simulation / Greedy

Problem Statement:
You are given an integer array `nums`. You can perform the following operation any number
of times:
  * Select the **adjacent pair with the minimum sum** in `nums`. If multiple such pairs
    exist, choose the **leftmost** one.
  * Replace this pair with their sum (reducing the array length by 1).

Return the **minimum number of operations** needed to make the array **non-decreasing**
(i.e., each element ≥ the previous).

Example:
Input: nums = [5,2,3,1]  
Output: 2  
Explanation:
  - The adjacent pair with min sum is (3,1) → sum = 4 → array becomes [5,2,4].
  - Now min adjacent sum is (2,4) → sum = 6 → array becomes [5,6].
  - The array is now non-decreasing.

Example:
Input: nums = [1,2,2]  
Output: 0  
Explanation: The array is already non-decreasing. :contentReference[oaicite:0]{index=0}

Approach (Simulation – Direct Greedy):
Since `nums.length <= 50`, we can directly simulate the process:
1. While the array is not non-decreasing:
   - Find the **leftmost adjacent pair** with the minimum sum.
   - Replace that pair with the sum (overwrite left element, erase right).
   - Increment the operation count.
2. When the array becomes non-decreasing, return the count.

Time Complexity: O(n²) per simulation (worst case).  
Space Complexity: O(1) extra (in-place modifications). :contentReference[oaicite:1]{index=1}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        // Helper to check if array is non-decreasing
        auto isNonDecreasing = [&](const vector<int>& arr) {
            for (int i = 1; i < arr.size(); i++) {
                if (arr[i - 1] > arr[i]) return false;
            }
            return true;
        };

        // Simulate until sorted
        while (!isNonDecreasing(nums)) {
            int bestIdx = 0;
            int minSum = nums[0] + nums[1];

            // Find leftmost adjacent pair with minimum sum
            for (int i = 1; i + 1 < nums.size(); ++i) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    bestIdx = i;
                }
            }

            // Replace the pair at bestIdx with its sum
            nums[bestIdx] = minSum;
            nums.erase(nums.begin() + bestIdx + 1);
            ops++;
        }

        return ops;
    }
};