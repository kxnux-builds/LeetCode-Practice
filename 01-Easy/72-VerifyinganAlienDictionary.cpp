/*
Problem: Verifying an Alien Dictionary
Link: https://leetcode.com/problems/verifying-an-alien-dictionary/description/
Difficulty: Easy
Topic: String / Hash Table / Sorting

Problem Statement:
In an alien language, surprisingly, they also use
English lowercase letters, but in a different order.

You are given:
- words -> a list of words written in the alien language
- order -> a string of length 26 representing the order
           of the alien alphabet

Return true if and only if the given words are sorted
lexicographically according to the alien alphabet.

Example 1:
Input:
words = ["hello","leetcode"]
order = "hlabcdefgijkmnopqrstuvwxyz"

Output:
true

Explanation:
'h' comes before 'l' in the alien alphabet,
so "hello" < "leetcode".

Example 2:
Input:
words = ["word","world","row"]
order = "worldabcefghijkmnpqstuvxyz"

Output:
false

Explanation:
Comparing "word" and "world":
'd' comes after 'l' in alien order,
so words are not sorted.

Example 3:
Input:
words = ["apple","app"]
order = "abcdefghijklmnopqrstuvwxyz"

Output:
false

Explanation:
A longer word cannot come before its prefix.

--------------------------------------------------

Approach (Character Ranking + Pairwise Comparison):

Key Insight:
Instead of comparing characters using normal
English order, assign each character its rank
according to the alien alphabet.

Then compare every adjacent pair of words
just like dictionary ordering.

--------------------------------------------------

Steps:
1. Create rank array of size 26.
   - rank[ch] = position of ch in order.
2. Compare every adjacent pair:
      words[i] and words[i + 1]
3. Find first differing character.
4. If rank of first word's character
   is greater than second word's character:
      return false.
5. If all compared characters are equal:
   - shorter word must come first.
6. If every pair is valid:
      return true.

--------------------------------------------------

Dry Run:

words = ["hello","leetcode"]

order = "hlabcdefgijkmnopqrstuvwxyz"

Ranks:
h = 0
l = 1

Compare:
"hello"
"leetcode"

First differing characters:
h vs l

rank(h) < rank(l)

Valid ordering

Answer = true

--------------------------------------------------

Why it works:
- Alien ordering is converted into numeric ranks.
- Lexicographical comparison depends only on
  the first differing character.
- Prefix cases are handled separately.
- Every adjacent pair must satisfy ordering.

--------------------------------------------------

Time Complexity: O(total characters in words)
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        vector<int> rank(26);

        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {

            string& a = words[i];
            string& b = words[i + 1];

            int len = min(a.size(), b.size());
            bool differentFound = false;

            for (int j = 0; j < len; j++) {

                if (a[j] != b[j]) {

                    if (rank[a[j] - 'a'] >
                        rank[b[j] - 'a']) {
                        return false;
                    }

                    differentFound = true;
                    break;
                }
            }

            // Prefix case
            if (!differentFound && a.size() > b.size()) {
                return false;
            }
        }

        return true;
    }
};