/*
Problem: Number of Substrings Containing All Three Characters
Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
Difficulty: Medium
Topic: String / Sliding Window / Two Pointers

Problem Statement:
Given a string s consisting only of the characters
'a', 'b', and 'c'.

Return the number of substrings containing at least
one occurrence of all three characters.

Example 1:
Input: s = "abcabc"
Output: 10

Explanation:
Some valid substrings are:
"abc", "abca", "abcab", "abcabc",
"bca", "bcab", "bcabc",
"cab", "cabc",
"abc"

Example 2:
Input: s = "aaacb"
Output: 3

Explanation:
Valid substrings are:
"aaacb", "aacb", "acb"

Example 3:
Input: s = "abc"
Output: 1

--------------------------------------------------

Approach (Sliding Window – Optimal):

Key Insight:
Maintain a sliding window that contains at least
one 'a', one 'b', and one 'c'.

Whenever the current window is valid:
- Every substring starting from the current left
  pointer and ending at the current right pointer
  or beyond is also valid.
- Therefore, add:
      (n - right)
to the answer.

Then shrink the window to find more valid substrings.

--------------------------------------------------

Steps:
1. Initialize two pointers:
      left = 0, right = 0
2. Maintain frequency of:
      'a', 'b', and 'c'
3. Expand the window by moving right.
4. While the window contains all three characters:
      - Add (n - right) to answer.
      - Remove s[left].
      - Move left forward.
5. Return answer.

--------------------------------------------------

Dry Run:

s = "abcabc"

right = 2
Window = "abc"

Contains all three.

Answer += 6 - 2 = 4

Valid substrings:
abc
abca
abcab
abcabc

Shrink window.

Continue similarly...

Final Answer = 10

--------------------------------------------------

Why it works:
- Every valid window contributes all substrings
  ending at or after the current right pointer.
- Sliding window ensures every character enters
  and leaves the window at most once.
- Thus the algorithm is linear.

--------------------------------------------------

Time Complexity: O(n)

- Each character is visited at most twice.

Space Complexity: O(1)

- Frequency array of size 3.

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {

        vector<int> freq(3, 0);

        int n = s.size();
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            freq[s[right] - 'a']++;

            while (freq[0] > 0 &&
                   freq[1] > 0 &&
                   freq[2] > 0) {

                ans += (n - right);

                freq[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};