/*
Problem: Max Dot Product of Two Subsequences
Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/
Difficulty: Hard
Topic: Dynamic Programming / 2D DP / Subsequence

Problem Statement:
Given two integer arrays `nums1` and `nums2`, return the **maximum dot product** between **non-empty subsequences** of `nums1` and `nums2` with the same length.

The **dot product** of two sequences a and b of length k is:
    sum(a[i] * b[i]) for i from 0 to k−1

Example:
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Subsequences [2, −2] from nums1 and [3, −6] from nums2:
2×3 + (−2)×(−6) = 6 + 12 = 18

Approach (2D Dynamic Programming – Optimal):
1. Let `dp[i][j]` be the **maximum dot product** for subsequences using elements up to
   index `i−1` in `nums1` and `j−1` in `nums2`.
2. Transition:
   - Include both nums1[i−1] & nums2[j−1]:  
       `dp[i][j] = max(dp[i][j], max(dp[i−1][j−1], 0) + nums1[i−1] * nums2[j−1])`
   - Skip nums1’s element:  
       `dp[i][j] = max(dp[i][j], dp[i−1][j])`
   - Skip nums2’s element:  
       `dp[i][j] = max(dp[i][j], dp[i][j−1])`
3. Base case: `dp[i][0] = dp[0][j] = −∞` (no valid subsequence without both).
4. Return `dp[n][m]`.

Time Complexity: O(n × m)  
Space Complexity: O(n × m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // Initialize dp with very small values
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MIN / 2));

        long long ans = LLONG_MIN;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                long long prod = (long long)nums1[i - 1] * nums2[j - 1];

                // take both and add to previous subsequence or just this prod
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + prod);
                dp[i][j] = max(dp[i][j], prod);

                // skip nums1’s element or skip nums2’s element
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);

                ans = max(ans, dp[i][j]);
            }
        }

        return (int)ans;
    }
};