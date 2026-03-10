/*
Problem: Sort an Array
Link: https://leetcode.com/problems/sort-an-array/description/
Difficulty: Medium
Topic: Array / Sorting / Divide and Conquer

Problem Statement:
Given an integer array `nums`, sort the array in **ascending order** and return it.

You must solve the problem **without using built-in sorting functions** and
achieve a time complexity of **O(n log n)** with minimal extra space. :contentReference[oaicite:0]{index=0}

Example 1:
Input: nums = [5,2,3,1]  
Output: [1,2,3,5]

Example 2:
Input: nums = [5,1,1,2,0,0]  
Output: [0,0,1,1,2,5]

Constraints:
1 <= nums.length <= 5 * 10⁴  
-5 * 10⁴ <= nums[i] <= 5 * 10⁴ :contentReference[oaicite:1]{index=1}

--------------------------------------------------

Approach (Merge Sort – Optimal):

Key Idea:
Merge Sort is a **divide-and-conquer sorting algorithm** that divides the array
into smaller halves, sorts them recursively, and merges them back together.  
It guarantees **O(n log n)** time complexity, which satisfies the problem requirement. :contentReference[oaicite:2]{index=2}

Steps:
1. Divide the array into two halves.
2. Recursively sort the left half.
3. Recursively sort the right half.
4. Merge the two sorted halves into a single sorted array.

Intuition:
Instead of sorting the whole array directly, we repeatedly break it into
smaller subarrays until each part is already sorted (size = 1),
then merge them in sorted order.

--------------------------------------------------

Time Complexity: O(n log n)  
Space Complexity: O(n)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};