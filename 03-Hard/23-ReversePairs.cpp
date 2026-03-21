/*
Problem: Reverse Pairs
Link: https://leetcode.com/problems/reverse-pairs/description
Difficulty: Hard
Topic: Array / Divide and Conquer / Merge Sort

Problem Statement:
Given an integer array `nums`, return the number of **reverse pairs** in the array.

A reverse pair is defined as a pair `(i, j)` such that:
- 0 ≤ i < j < nums.length
- nums[i] > 2 * nums[j] :contentReference[oaicite:0]{index=0}

Example 1:
Input: nums = [1,3,2,3,1]  
Output: 2  

Example 2:
Input: nums = [2,4,3,5,1]  
Output: 3  

Constraints:
1 <= nums.length <= 5 * 10^4  
-2^31 <= nums[i] <= 2^31 - 1 :contentReference[oaicite:1]{index=1}

--------------------------------------------------

Approach (Merge Sort + Counting – Optimal):

Key Idea:
Brute force (checking all pairs) takes O(n²) → too slow.

Instead, use **Merge Sort**:
- While merging two sorted halves, count valid reverse pairs.

Steps:
1. Divide array into two halves.
2. Recursively count reverse pairs in left and right halves.
3. While merging:
   - For each element in left half, count elements in right half such that:
     nums[i] > 2 * nums[j]
   - Use two pointers (j only moves forward).
4. Merge the two sorted halves.

Why it works:
Since both halves are sorted, we can efficiently count pairs
without checking all combinations. :contentReference[oaicite:2]{index=2}

--------------------------------------------------

Time Complexity: O(n log n)  
Space Complexity: O(n)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = 0;

        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);

        // Count reverse pairs
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int i = left, k = mid + 1;

        while (i <= mid && k <= right) {
            if (nums[i] <= nums[k]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[k++]);
            }
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (k <= right) temp.push_back(nums[k++]);

        for (int p = 0; p < temp.size(); p++) {
            nums[left + p] = temp[p];
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};