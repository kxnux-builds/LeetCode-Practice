/*
Problem: Count the Number of Special Characters I
Link: https://leetcode.com/problems/count-the-number-of-special-characters-i/description/
Difficulty: Easy
Topic: String / Hashing

Problem Statement:
A character is called special if:
- It appears in lowercase form.
- It also appears in uppercase form.

Return the number of special characters in the string.

Example 1:
Input: word = "aaAbcBC"
Output: 3

Explanation:
- 'a' and 'A' both exist
- 'b' and 'B' both exist
- 'c' and 'C' both exist

So, answer = 3

Example 2:
Input: word = "abc"
Output: 0

Explanation:
No uppercase versions exist.

Example 3:
Input: word = "abBCab"
Output: 1

Explanation:
Only 'b' and 'B' both exist.

--------------------------------------------------

Approach (Presence Tracking – Optimal):

Key Insight:
A character is special if:
- lowercase letter exists
- uppercase letter exists

For each letter from 'a' to 'z',
check whether both versions are present.

--------------------------------------------------

Steps:
1. Create two arrays:
   - lower[26]
   - upper[26]
2. Traverse the string:
   - Mark lowercase occurrences
   - Mark uppercase occurrences
3. Check all 26 letters:
   - If both lower[i] and upper[i] exist,
     increase answer.
4. Return count.

--------------------------------------------------

Dry Run:

word = "aaAbcBC"

Lowercase present:
a, b, c

Uppercase present:
A, B, C

Checks:
a & A → valid
b & B → valid
c & C → valid

Answer = 3

--------------------------------------------------

Why it works:
- We only need presence information,
  not positions.
- Each character is processed once.
- Constant-size arrays make the solution efficient.

--------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<bool> lower(26, false);
        vector<bool> upper(26, false);

        for (char ch : word) {

            if (islower(ch)) {
                lower[ch - 'a'] = true;
            }
            else {
                upper[ch - 'A'] = true;
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) {
                count++;
            }
        }

        return count;
    }
};