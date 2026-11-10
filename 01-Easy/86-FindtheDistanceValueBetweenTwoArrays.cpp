/*
Problem: Find the Distance Value Between Two Arrays
Link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/
Difficulty: Easy
Topic: Array / Sorting / Binary Search

Problem Statement:
You are given two integer arrays arr1 and arr2, and an integer d.

An element arr1[i] is considered valid if there is no element
arr2[j] such that:

|arr1[i] - arr2[j]| <= d

Return the number of valid elements in arr1.

Example 1:
Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2

Example 2:
Input: arr1 = [1,4,2,3],
       arr2 = [-4,-3,6,10,20,30], d = 3
Output: 2

Example 3:
Input: arr1 = [2,1,100,3],
       arr2 = [-5,-2,10,-3,7], d = 6
Output: 1

Explanation:
For every element in arr1, check whether its absolute difference
with every element in arr2 is greater than d.

Approach (Brute Force):
1. Traverse every element of arr1.
2. For each element, check its difference with every element of arr2.
3. If any difference is <= d, mark the element as invalid.
4. Otherwise, increase the answer.
5. Return the final count.

Time Complexity: O(n * m)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for (int num1 : arr1) {
            bool valid = true;

            for (int num2 : arr2) {
                if (abs(num1 - num2) <= d) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                count++;
            }
        }

        return count;
    }
};