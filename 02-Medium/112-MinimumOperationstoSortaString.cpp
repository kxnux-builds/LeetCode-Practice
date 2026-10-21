/*
Problem: Minimum Operations to Sort a String
Link: https://leetcode.com/problems/minimum-operations-to-sort-a-string/description/
Difficulty: Medium
Topic: String / Greedy

Problem Statement:
You are given a string `s` consisting of lowercase English letters.

In one operation, you can select any substring of `s` that is
not the entire string and sort it in non-descending alphabetical
order.

Return the minimum number of operations required to make `s`
sorted in non-descending order.

If it is impossible to sort the string using these operations,
return -1.

Example 1:
Input: s = "dog"
Output: 1

Explanation:
Sort the substring "og" to get "go".

The string becomes:
"dgo"

Now the string is sorted, so the answer is 1.

Example 2:
Input: s = "card"
Output: 2

Explanation:
Operation 1:
Sort the substring "car" to get "acr".

The string becomes:
"acrd".

Operation 2:
Sort the substring "rd" to get "dr".

The string becomes:
"acdr".

The string is now sorted, so the answer is 2.

Example 3:
Input: s = "gf"
Output: -1

Explanation:
The only proper substrings have length 1.
Sorting a single character does not change the string.

Therefore, sorting "gf" is impossible.

Approach (Greedy):
1. If the string is already sorted, return 0.

2. Find the minimum character `mn` and maximum character `mx`.

3. If the minimum character appears at the beginning
   OR the maximum character appears at the end,
   return 1.

4. Otherwise, check whether:
   - The minimum character appears before the last position.
   - The maximum character appears after the first position.

   If both conditions are true, return 2.

5. If neither condition allows sorting in two operations,
   return 3 when the string has enough characters to make
   sorting possible; otherwise, return -1.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // If the string is already sorted, no operation is needed
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // A string of length 2 cannot be changed:
        // its only proper substrings have length 1
        if (n == 2) {
            return -1;
        }

        // Find the minimum and maximum characters
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // One operation is enough if the minimum is at the start
        // or the maximum is at the end
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // Check whether the minimum occurs before the last position
        // and the maximum occurs after the first position
        bool minBeforeLast = false;
        bool maxAfterFirst = false;

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && s[i] == mn) {
                minBeforeLast = true;
            }

            if (i > 0 && s[i] == mx) {
                maxAfterFirst = true;
            }
        }

        // Two operations are enough when both conditions hold
        if (minBeforeLast && maxAfterFirst) {
            return 2;
        }

        // Otherwise, three operations are sufficient for n >= 3
        return 3;
    }
};
