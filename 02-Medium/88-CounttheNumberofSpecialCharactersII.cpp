/*
Problem: Count the Number of Special Characters II
Link: https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/
Difficulty: Medium
Topic: String / Hashing

Problem Statement:
A character is called special if:
- It appears in lowercase form before its uppercase form.
- Both lowercase and uppercase versions exist in the string.

Return the number of special characters in the string.

Example 1:
Input: word = "aaAbcBC"
Output: 3

Explanation:
- 'a' appears before 'A'
- 'b' appears before 'B'
- 'c' appears before 'C'

Example 2:
Input: word = "abc"
Output: 0

Example 3:
Input: word = "AbBCab"
Output: 0

--------------------------------------------------

Approach (First & Last Occurrence Tracking – Optimal):

Key Insight:
For a character to be special:
1. Lowercase letter must exist
2. Uppercase letter must exist
3. Last occurrence of lowercase letter
   must appear BEFORE first occurrence
   of uppercase letter

Meaning:
lastLower[ch] < firstUpper[ch]

--------------------------------------------------

Steps:
1. Store:
   - last occurrence of lowercase letters
   - first occurrence of uppercase letters
2. Traverse all 26 letters
3. Check:
      lastLower[i] < firstUpper[i]
4. Count valid characters

--------------------------------------------------

Dry Run:

word = "aaAbcBC"

Lowercase last positions:
a -> 1
b -> 3
c -> 4

Uppercase first positions:
A -> 2
B -> 5
C -> 6

Checks:
1 < 2 → valid ('a')
3 < 5 → valid ('b')
4 < 6 → valid ('c')

Answer = 3

--------------------------------------------------

Why it works:
- Using last lowercase occurrence ensures
  every lowercase comes before uppercase.
- Using first uppercase occurrence ensures
  uppercase appears after lowercase.
- Efficiently checks condition in one pass.

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

        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, INT_MAX);

        int n = word.size();

        // Store occurrences
        for (int i = 0; i < n; i++) {

            char ch = word[i];

            if (islower(ch)) {
                lastLower[ch - 'a'] = i;
            }
            else {
                firstUpper[ch - 'A'] =
                    min(firstUpper[ch - 'A'], i);
            }
        }

        int special = 0;

        // Check valid special characters
        for (int i = 0; i < 26; i++) {

            if (lastLower[i] != -1 &&
                firstUpper[i] != INT_MAX &&
                lastLower[i] < firstUpper[i]) {

                special++;
            }
        }

        return special;
    }
};