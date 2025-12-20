/*
Problem: Delete Columns to Make Sorted
Link: https://leetcode.com/problems/delete-columns-to-make-sorted/description/
Difficulty: Easy
Topic: Array / Strings

Problem Statement:
You are given an array of strings `strs` where each string is of the same length.
We may choose any number of columns and delete them.

Return the *minimum number of columns* that you must delete
so that each remaining column is sorted in **non-decreasing** order
(top to bottom).

Example:
Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation:
Column 0 → 'c','d','g' (sorted)
Column 1 → 'b','a','h' (not sorted → delete)
Column 2 → 'a','f','i' (sorted)

Approach (Greedy Column Check):
1. Initialize a count for deleted columns.
2. For each column index `j` from 0 to length-1:
   - Check if characters in that column over all rows are sorted:
     - Compare strs[i][j] with strs[i−1][j]
   - If any row has a smaller char than the previous → this column is unsorted.
     - Increment delete count.
3. Return delete count.

Time Complexity: O(m * n) — m rows, n columns  
Space Complexity: O(1) — constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int deletes = 0;

        for (int j = 0; j < cols; j++) {
            for (int i = 1; i < rows; i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    deletes++;
                    break;
                }
            }
        }

        return deletes;
    }
};