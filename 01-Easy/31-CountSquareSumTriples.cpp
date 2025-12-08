/*
Problem: Count Square Sum Triples
Link: https://leetcode.com/problems/count-square-sum-triples/description/
Difficulty: Easy
Topic: Math / Enumeration / Loops

Problem Statement:
A square triple (a, b, c) is a triple where a, b, and c are integers and a² + b² = c².  
Given an integer n, return the number of square triples such that 1 ≤ a, b, c ≤ n.

Example 1:
Input: n = 5  
Output: 2  
Explanation: The square triples are (3,4,5) and (4,3,5).

Example 2:
Input: n = 10  
Output: 4  
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).

Constraints:
- 1 ≤ n ≤ 250

Approach (Enumerate a and b, compute c via sqrt — O(n²) optimal for given constraints):
1. Initialize counter = 0.
2. Loop a from 1 to n.  
3. Loop b from 1 to n.  
4. Compute x = a*a + b*b.  
   - Compute c = integer square root of x (e.g. via `int c = sqrt(x)`).
   - If c ≤ n and c*c == x → valid triple → increment counter.
5. Return counter.

Time Complexity: O(n²) — double loop over a and b  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) {
                int sumSq = a * a + b * b;
                int c = (int) sqrt(sumSq);
                if (c <= n && c * c == sumSq) {
                    count++;
                }
            }
        }
        return count;
    }
};