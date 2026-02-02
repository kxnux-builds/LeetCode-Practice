/*
Problem: Product of Array Except Self
Link: https://leetcode.com/problems/product-of-array-except-self/description/
Difficulty: Medium
Topic: Array / Prefix & Suffix Product

Problem Statement:
Given an integer array `nums` of length `n`, return an array `answer` such that:
- `answer[i]` is equal to the **product of all the elements of nums except nums[i]**.
- You must solve it **without using division** and in **O(n)** time.

Example:
Input: nums = [1,2,3,4]  
Output: [24,12,8,6]  
Explanation:
- For i=0: product of [2,3,4] = 24
- For i=1: product of [1,3,4] = 12
- For i=2: product of [1,2,4] = 8
- For i=3: product of [1,2,3] = 6

Approach (Prefix & Suffix Products — Optimal):
1. Create an output array `answer` of size `n`, initialized to 1.
2. First loop (left → right):  
   - Compute the **prefix product** up to (but not including) index `i`.
   - Store it in `answer[i]`.
3. Second loop (right → left):
   - Maintain a running **suffix product**.
   - Multiply `answer[i]` by the suffix product for index `i`.
4. Final `answer` has the product of all elements except `nums[i]`.

Time Complexity: O(n)  
Space Complexity: O(1) extra space (excluding output array)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Step 1: prefix products
        long long prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: suffix products
        long long suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};