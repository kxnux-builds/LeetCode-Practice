/*
Problem: Ways to Make a Fair Array
Link: https://leetcode.com/problems/ways-to-make-a-fair-array/description/
Difficulty: Medium
Topic: Array / Prefix Sum / Simulation

Problem Statement:
You are given a 0-indexed integer array `nums`.  
An array is called **fair** if the sum of the elements at **even** indices equals the sum of the elements at **odd** indices.

Return *the number of ways* to delete **exactly one element** from the array such that the resulting array is fair.

Example 1:
Input: nums = [2,1,6,4]  
Output: 1  
Explanation:
After removing index 1 (1), the array becomes [2,6,4]:
Even sum = 2 + 4 = 6  
Odd sum = 6  
Counts as fair.

Example 2:
Input: nums = [1,1,1]  
Output: 3  
Explanation:
Removing any one yields a fair array.

Example 3:
Input: nums = [1,2,3]  
Output: 0  
Explanation:
No deletion results in fair sums.

Approach (Two Prefix Sums – Optimal):
Let:
- `totalEven`  = sum of values at even indices
- `totalOdd`   = sum of values at odd indices

We scan the array once while keeping running left sums:
- `leftEven`, `leftOdd` → sums before current index  
- `rightEven`, `rightOdd` → remaining sums after current index

If we delete index `i`, then:
- Indices after `i` will **flip parity** (even ↔ odd)
- So new sums become:
  - `newEven = leftEven + rightOdd`
  - `newOdd  = leftOdd  + rightEven`

We count if `newEven == newOdd`.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        
        // Compute total even and odd sums
        int totalEven = 0, totalOdd = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) totalEven += nums[i];
            else totalOdd += nums[i];
        }
        
        int leftEven = 0, leftOdd = 0;
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            // Remove current from totals
            if (i % 2 == 0) totalEven -= nums[i];
            else totalOdd -= nums[i];
            
            // New sums after deleting nums[i]:
            // right part flips parity
            int newEven = leftEven + totalOdd;
            int newOdd  = leftOdd  + totalEven;
            
            if (newEven == newOdd) ++result;
            
            // Add current to left sums
            if (i % 2 == 0) leftEven += nums[i];
            else leftOdd += nums[i];
        }
        
        return result;
    }
};