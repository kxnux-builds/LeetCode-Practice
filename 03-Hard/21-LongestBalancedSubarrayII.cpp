/*
Problem: Longest Balanced Subarray II  
Link: https://leetcode.com/problems/longest-balanced-subarray-ii/description/
Difficulty: Hard
Topic: Array / Hashing / Prefix + Map

Problem Statement:
You are given an integer array `nums`.  
A subarray is called **balanced** if the number of distinct even numbers
in the subarray is **equal** to the number of distinct odd numbers.  
Return the **length** of the longest balanced subarray.

Example 1:
Input: nums = [2,5,4,3]  
Output: 4  
Explanation: Subarray [2,5,4,3] has distinct evens {2,4} and distinct odds {5,3} → 2 = 2. :contentReference[oaicite:0]{index=0}

Example 2:
Input: nums = [3,2,2,5,4]  
Output: 5  
Explanation: Subarray [3,2,2,5,4] has distinct evens {2,4} and distinct odds {3,5} → 2 = 2. :contentReference[oaicite:1]{index=1}

Example 3:
Input: nums = [1,2,3,2]  
Output: 3  
Explanation: Subarray [2,3,2] has distinct evens {2} and distinct odds {3} → 1 = 1. :contentReference[oaicite:2]{index=2}

Constraints:
- 1 ≤ nums.length ≤ 10⁵  
- 1 ≤ nums[i] ≤ 10⁵ :contentReference[oaicite:3]{index=3}

Approach (Prefix + Tracking Last Occurrences – Optimal):
The key insight is to treat changes in distinct counts
as a **balance**, and map the current balance to the earliest index
where it occurred:

1. Use a prefix balance and two maps `lastEven`/`lastOdd` to record
   the **last index** where each value was seen.
2. Also maintain a prefix index map `balanceIndex` that stores the
   **earliest index** at which a given balance was encountered.
3. As you scan `nums`, update distinct counts only when a number
   is seen **for the first time** in the current prefix.
4. Compute a **balance = distinctEven − distinctOdd**.
5. If this balance has been seen before at index `prevIdx`, then
   `i − prevIdx` is a balanced subarray length; update the answer.
6. Use the map to keep earliest occurrences of each balance.

This transforms the distinct-set requirement into a **prefix balance
problem** + hashing.

Time Complexity: O(n) on average  
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        // Stores earliest position at which a given balance appeared
        unordered_map<int, int> balanceIndex;
        balanceIndex[0] = -1;

        unordered_map<int, int> lastEven, lastOdd;

        int balance = 0; // distinctEven - distinctOdd
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];

            // If this value contributes newly to either set
            if (val % 2 == 0) {
                // if it's new even distinct
                if (!lastEven.count(val)) {
                    balance++;
                }
                lastEven[val] = i;
            } else {
                // if it's new odd distinct
                if (!lastOdd.count(val)) {
                    balance--;
                }
                lastOdd[val] = i;
            }

            // If this balance seen before, possible answer
            if (balanceIndex.count(balance)) {
                ans = max(ans, i - balanceIndex[balance]);
            } else {
                // first time seeing this balance
                balanceIndex[balance] = i;
            }
        }

        return ans;
    }
};