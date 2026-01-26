/*
Problem: Smallest Range Covering Elements from K Lists
Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
Difficulty: Hard
Topic: Heap / Sliding Window / Two Pointers

Problem Statement:
You are given `k` sorted lists of integers.  
Find the **smallest range [l, r]** such that **each of the k lists contributes at least one number** within this range.

If multiple ranges have the same length, return the one with the smallest `l`.

Example:
Input: nums = [[4,10,15,24,26],
               [0,9,12,20],
               [5,18,22,30]]
Output: [20,24]

Explanation:
The range [20,24] includes:
- 24 from first list
- 20 from second list
- 22 from third list

Approach (Min Heap + Tracking Maximum – Optimal):
1. Use a **min-heap** to always extract the smallest current element among lists.
2. Track the **current maximum value** among chosen elements.
3. Initially, push the first element of each list into the heap.
4. At each step:
   - Pop the smallest element from the heap.
   - Update the answer range if (max − min) is smaller.
   - Push the next element from the same list into the heap.
5. Stop when any list runs out of elements (cannot cover all lists anymore).

Why this works:
- Heap ensures smallest element is always known.
- Max tracking ensures valid range covers all lists.
- Each element is processed once.

Time Complexity: O(N log K)
Space Complexity: O(K)
Where:
- N = total number of elements
- K = number of lists
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        // minHeap stores {value, list_index, element_index}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<>
        > minHeap;

        int currentMax = INT_MIN;

        // Initialize heap with first element of each list
        for (int i = 0; i < k; i++) {
            minHeap.emplace(nums[i][0], i, 0);
            currentMax = max(currentMax, nums[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while (true) {
            auto [val, listIdx, elemIdx] = minHeap.top();
            minHeap.pop();

            // Update best range
            if (currentMax - val < rangeEnd - rangeStart) {
                rangeStart = val;
                rangeEnd = currentMax;
            }

            // Move to next element in the same list
            if (elemIdx + 1 == nums[listIdx].size()) {
                break; // one list exhausted
            }

            int nextVal = nums[listIdx][elemIdx + 1];
            minHeap.emplace(nextVal, listIdx, elemIdx + 1);
            currentMax = max(currentMax, nextVal);
        }

        return {rangeStart, rangeEnd};
    }
};