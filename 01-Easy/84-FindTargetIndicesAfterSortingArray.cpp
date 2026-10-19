/*
Problem: Find Target Indices After Sorting Array
Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/description/
Difficulty: Easy
Topic: Array / Sorting / Binary Search

Problem Statement:
You are given a 0-indexed integer array `nums` and an integer
`target`.

Return a list of the indices where `target` appears in the array
after sorting `nums` in non-decreasing order.

If `target` does not exist in `nums`, return an empty list.

Example 1:
Input: nums = [1, 2, 5, 2, 3], target = 2
Output: [1, 2]

Explanation:
After sorting:
nums = [1, 2, 2, 3, 5]

The target 2 appears at indices 1 and 2.

Example 2:
Input: nums = [1, 2, 5, 2, 3], target = 3
Output: [3]

Explanation:
After sorting:
nums = [1, 2, 2, 3, 5]

The target 3 appears at index 3.

Example 3:
Input: nums = [1, 2, 5, 2, 3], target = 5
Output: [4]

Explanation:
After sorting:
nums = [1, 2, 2, 3, 5]

The target 5 appears at index 4.

Approach (Sorting + Linear Search):
1. Sort the array `nums` in non-decreasing order.
2. Create an empty vector `result` to store the target indices.
3. Traverse the sorted array using index `i`.
4. If `nums[i] == target`, add index `i` to `result`.
5. Return `result`.

Because the array is sorted, all occurrences of the target
appear next to each other.

Time Complexity: O(n log n)
Space Complexity: O(log n) auxiliary space for sorting on typical
implementations, excluding the output vector.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        // Sort the array in non-decreasing order
        sort(nums.begin(), nums.end());

        // Store all indices where the target appears
        vector<int> result;

        // Traverse the sorted array
        for (int i = 0; i < nums.size(); i++) {

            // Check whether the current element is the target
            if (nums[i] == target) {
                result.push_back(i);
            }
        }

        return result;
    }
};