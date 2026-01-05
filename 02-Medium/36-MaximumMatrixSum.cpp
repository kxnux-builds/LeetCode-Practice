/*
Problem: Maximum Matrix Sum
Link: https://leetcode.com/problems/maximum-matrix-sum/description/
Difficulty: Medium
Topic: Matrix / Greedy / Math

Problem Statement:
You are given an `n x n` integer matrix. You can perform the following operation any number of times:
- Choose any two **adjacent** elements (sharing a border) and multiply both of them by -1.

Your goal is to **maximize the sum** of all the elements in the matrix after applying the operations.

Example:
Input: matrix = [[1,-1],[-1,1]]  
Output: 4  
Explanation: By flipping adjacent signs you can make all values positive.

Example:
Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]  
Output: 16  
Explanation: With optimal flips, maximize total sum of absolute values.

Approach (Greedy Parity of Negatives):
1. Compute:
   - `totalSum` = sum of absolute values of all elements.
   - `negCount` = how many elements are negative.
   - `minAbs` = smallest absolute value in the entire matrix.
2. If `negCount` is **even**, you can flip signs to make all values effectively positive → answer = `totalSum`.
3. If `negCount` is **odd**, one element must stay negative → subtract `2 * minAbs` from the sum.
4. Return the final value.

Key Idea:
- Flipping two adjacent signs changes neither the count nor the parity of negative numbers.
- Thus we can always pair up negatives except at most one if the count is odd.
- To maximize sum, keep the smallest absolute value negative in that case. :contentReference[oaicite:0]{index=0}

Time Complexity: O(n²)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negCount = 0;
        int n = matrix.size();
        int minAbs = INT_MAX;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = matrix[i][j];
                if (val < 0) negCount++;
                totalSum += llabs(val);
                minAbs = min(minAbs, (int)llabs(val));
            }
        }

        if (negCount % 2 != 0) {
            totalSum -= 2LL * minAbs;
        }

        return totalSum;
    }
};