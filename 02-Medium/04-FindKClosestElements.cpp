/*
Problem: Find K Closest Elements
Link: https://leetcode.com/problems/find-k-closest-elements/description/
Difficulty: Medium
Topic: Binary Search / Two Pointers

Problem Statement:
Given a sorted integer array arr, two integers k and x, return the k closest 
integers to x in the array. The result should also be sorted in ascending order.

Approach:
1. Use binary search to find the possible starting point.
2. Then expand using two pointers or directly apply binary search on window.
3. Return the subarray of size k.

Time Complexity: O(log n + k)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int left = 0, right = arr.size() - k;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (x - arr[mid] > arr[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }

        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
