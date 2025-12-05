/*
Problem: Count Partitions with Even Sum Difference
Link: https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/
Difficulty: Easy
Topic: Array / Prefix Sum / Math

Problem Statement:
You are given an integer array nums of length n. A partition is defined as an index i
(0 ≤ i < n-1), splitting the array into two non-empty subarrays:
  - Left subarray: nums[0..i]
  - Right subarray: nums[i+1..n-1]

Return the number of partitions where the difference between the sum of the left and right subarrays is even.

Example:
Input: nums = [10,10,3,7,6]
Output: 4
Explanation:
Possible partitions (i = 0,1,2,3):
  i = 0 → left = [10], right = [10,3,7,6] → difference = 10 − 26 = -16 (even)
  i = 1 → left = [10,10], right = [3,7,6] → difference = 20 − 16 = 4 (even)
  i = 2 → left = [10,10,3], right = [7,6] → difference = 23 − 13 = 10 (even)
  i = 3 → left = [10,10,3,7], right = [6] → difference = 30 − 6 = 24 (even)

Constraints:
- 2 ≤ n = nums.length ≤ 100  
- 1 ≤ nums[i] ≤ 100

Approach (Optimal – Use total sum parity insight):
Key insight: Let total = sum(nums), and at a partition at i let left = sum of nums[0..i], right = total − left.
Then difference = left − right = 2*left − total. Since 2*left is always even, the difference is even ⇔ total is even.  
Thus:
- If total sum is even → **every** partition (there are n − 1 possible) will have even difference.  
- If total sum is odd → **no** partition yields even difference.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        if (total % 2 != 0) return 0;
        return nums.size() - 1;
    }
};