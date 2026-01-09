/*
Problem: Product of Array Except Self
Link: https://leetcode.com/problems/product-of-array-except-self/
Difficulty: Medium
Topic: Array / Prefix & Suffix Product

Problem Statement:
Given an integer array `nums` of length `n`, return an array `answer` such that:
- `answer[i]` is the product of all the elements of `nums` except `nums[i]`.
- The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.
- **You must write an algorithm that runs in O(n) time and without using the division operation.**

Example:
Input: nums = [1,2,3,4]  
Output: [24,12,8,6]

Approach (Prefix & Suffix Products – Optimal):
1. Construct an output array with prefix products:
   - `prefix[i]` = product of all elements before index `i`.
2. Construct suffix products on the fly while combining:
   - Traverse from right to left.
   - Maintain a running suffix product.
   - Multiply `prefix[i]` by current suffix product.
3. This yields the result in O(n) time and O(1) extra space (excluding the output array).

Time Complexity: O(n)  
Space Complexity: O(1) — excluding output
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // prefix product
        long long prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // suffix product
        long long suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};