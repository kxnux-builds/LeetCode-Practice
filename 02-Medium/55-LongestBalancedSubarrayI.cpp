/*
Problem: Longest Balanced Subarray I
Link: https://leetcode.com/problems/longest-balanced-subarray-i/description/
Difficulty: Medium
Topic: Array / Brute Force / Hash Set / Distinct Counts

Problem Statement:
You are given an integer array `nums`.  
A subarray is called **balanced** if the number of **distinct even numbers** in the subarray
is equal to the number of **distinct odd numbers**.  

Return the length of the **longest** balanced subarray.

Example 1:
Input: nums = [2,5,4,3]
Output: 4
Explanation: The longest balanced subarray is `[2,5,4,3]`.
It has distinct even = {2,4} and distinct odd = {5,3} → 2 = 2. :contentReference[oaicite:0]{index=0}

Example 2:
Input: nums = [3,2,2,5,4]
Output: 5
Explanation: The balanced subarray `[3,2,2,5,4]` has distinct evens {2,4} 
and distinct odds {3,5} → 2 = 2. :contentReference[oaicite:1]{index=1}

Example 3:
Input: nums = [1,2,3,2]
Output: 3
Explanation: One balanced subarray is `[2,3,2]`: even distinct {2}, odd distinct {3}. :contentReference[oaicite:2]{index=2}

Constraints:
- 1 <= nums.length <= 1500  
- 1 <= nums[i] <= 10^5 :contentReference[oaicite:3]{index=3}

Approach (Brute Force + Hashing – Suitable for n ≤ 1500):
1. Enumerate all subarrays by fixing start index `i` and end index `j`.
2. Use two hash sets to track the **distinct even** and **distinct odd** values currently in the subarray.
3. For each subarray:
   - If count of distinct evens == count of distinct odds → update the answer as `j − i + 1`.
4. Return the maximum found.

Time Complexity: O(n²) — double loop & set operations  
Space Complexity: O(n) — for hash sets per subarray
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> evens;
            unordered_set<int> odds;

            for (int j = i; j < n; ++j) {
                int x = nums[j];
                if (x % 2 == 0) {
                    evens.insert(x);
                } else {
                    odds.insert(x);
                }

                if (evens.size() == odds.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};