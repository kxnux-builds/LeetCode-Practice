/*
Problem: Smallest Subsequence of Distinct Characters
Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/
Difficulty: Medium
Topic: String / Stack / Greedy

Problem Statement:
Given a string s, return the lexicographically smallest
subsequence of s that contains all the distinct characters
of s exactly once.

A subsequence is formed by deleting zero or more characters
without changing the relative order of the remaining characters.

Example 1:
Input: s = "bcabc"
Output: "abc"

Explanation:
The distinct characters are {a, b, c}.
The lexicographically smallest subsequence is "abc".

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Explanation:
The distinct characters are {a, b, c, d}.
The lexicographically smallest subsequence is "acdb".

--------------------------------------------------

Approach (Greedy + Monotonic Stack – Optimal):

Key Insight:
We want:
- Every distinct character exactly once.
- Lexicographically smallest subsequence.

Maintain:
- lastIndex[ch] = last occurrence of each character.
- visited[ch] = whether character is already in the stack.
- A stack (implemented as a string) to build the answer.

While processing each character:
- If it's already included, skip it.
- Otherwise, remove larger characters from the top of
  the stack if they appear again later.
- Push the current character.

--------------------------------------------------

Steps:
1. Store the last occurrence of every character.
2. Initialize:
   - visited array
   - empty stack (string)
3. Traverse the string:
   - Skip if character already exists in stack.
   - While:
       stack is not empty
       current character < stack top
       stack top appears later
     Pop the stack.
   - Push current character.
4. Return the stack as the answer.

--------------------------------------------------

Dry Run:

s = "bcabc"

Last Occurrence:
b → 3
c → 4
a → 2

Process:

b → "b"

c → "bc"

a:
a < c and c appears later → pop c
a < b and b appears later → pop b
Push a

Stack = "a"

b → "ab"

c → "abc"

Answer = "abc"

--------------------------------------------------

Why it works:
- The stack always maintains the smallest
  possible lexicographical order.
- Characters are removed only if they can be
  added again later.
- Each distinct character is included exactly once.

--------------------------------------------------

Time Complexity: O(n)

- Every character is pushed and popped
  at most once.

Space Complexity: O(1)

- Stack and arrays of fixed size (26 letters).

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> lastIndex(26);

        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> visited(26, false);
        string st;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (visited[ch - 'a']) {
                continue;
            }

            while (!st.empty() &&
                   ch < st.back() &&
                   lastIndex[st.back() - 'a'] > i) {

                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return st;
    }
};