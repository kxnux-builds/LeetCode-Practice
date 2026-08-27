/*
Problem: Lexicographically Smallest Permutation Greater Than Target
Link: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
Difficulty: Medium
Topic: String / Greedy / Backtracking / Permutation

Problem Statement:
You are given two strings:
- s
- target

You need to rearrange all characters of s to form a permutation
that is lexicographically strictly greater than target.

Return the lexicographically smallest permutation of s
that is greater than target.

If no such permutation exists, return an empty string.

Example 1:
Input:
s = "abc"
target = "abb"

Output:
"abc"

Explanation:
Possible permutations:
abc, acb, bac, bca, cab, cba

The smallest permutation greater than "abb" is "abc".

Example 2:
Input:
s = "abc"
target = "cba"

Output:
""

Explanation:
"cba" is already the largest possible permutation,
so no permutation is strictly greater.

--------------------------------------------------

Approach (Greedy + Backtracking – Optimal):

Key Insight:
We want the smallest permutation that is greater than target.

Process target from left to right.

At each position:
1. Try to place the smallest available character
   that is greater than target[i].
2. If we place a greater character:
      The remaining characters should be placed
      in ascending order.
3. If we place the same character:
      Continue comparing the next position.
4. If the current path cannot produce a valid answer,
   backtrack and try a larger character at an
   earlier position.

Because we need the lexicographically smallest answer,
we always try characters in ascending order.

--------------------------------------------------

Steps:
1. Count the frequency of every character in s.
2. Traverse target from left to right.
3. At each position:
   - Try to use the same character if available.
   - If a larger character is available:
       • Place it.
       • Put all remaining characters in sorted order.
       • This gives the smallest possible answer for
         this prefix.
4. If the same-character path fails,
   backtrack to the previous position.
5. If no larger character can be selected at any position,
   return "".

--------------------------------------------------

Dry Run:

s = "abc"
target = "abb"

Frequency:
a = 1
b = 1
c = 1

Position 0:
target[0] = 'a'

Use 'a':
prefix = "a"

Position 1:
target[1] = 'b'

Use 'b':
prefix = "ab"

Position 2:
target[2] = 'b'

'b' is unavailable.

Try next larger character:
'c'

prefix = "abc"

Remaining characters = none.

"abc" > "abb"

Answer = "abc"

--------------------------------------------------

Another Example:

s = "abc"
target = "cba"

Position 0:
target[0] = 'c'

No character greater than 'c'.

There is also no way to make the prefix greater
at any later position because the first character
cannot exceed 'c'.

Answer = ""

--------------------------------------------------

Why it works:
- We keep the prefix equal to target as long as possible.
- At the first position where we make the answer larger,
  we choose the smallest possible larger character.
- Once the answer is already greater than target,
  the remaining characters are placed in ascending order
  to make the complete permutation as small as possible.
- Backtracking guarantees that all possible prefixes
  are considered when the equal path cannot succeed.

--------------------------------------------------

Time Complexity: O(n × 26)

Where:
n = length of s

Since there are only 26 lowercase letters,
this is effectively O(n).

Space Complexity: O(n)

- Result string
- Recursion/backtracking stack

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solve(int pos,
               string& target,
               vector<int>& freq,
               string& ans) {

        int n = target.size();

        // We successfully matched the entire target.
        // We need a STRICTLY greater permutation.
        return false;
    }

    string lexicographicallySmallestPermutation(
        string s,
        string target) {

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string ans;

        /*
        Try to keep the prefix equal to target.
        If that is impossible, backtrack and make
        the earliest possible position larger.
        */

        for (int i = 0; i < target.size(); i++) {

            int current = target[i] - 'a';

            // First try to match target[i].
            if (freq[current] > 0) {

                freq[current]--;

                ans.push_back(target[i]);
            }
            else {

                // Cannot continue with an equal prefix.
                // Find the smallest character greater
                // than target[i].
                for (int ch = current + 1; ch < 26; ch++) {

                    if (freq[ch] > 0) {

                        ans.push_back(char('a' + ch));
                        freq[ch]--;

                        // Remaining characters in sorted order.
                        for (int c = 0; c < 26; c++) {
                            while (freq[c] > 0) {
                                ans.push_back(char('a' + c));
                                freq[c]--;
                            }
                        }

                        return ans;
                    }
                }

                /*
                No larger character is available here.

                We need to backtrack to an earlier position
                and replace one of the previously matched
                characters with the smallest possible
                character greater than target[i].
                */

                while (!ans.empty()) {

                    int last = ans.back() - 'a';

                    ans.pop_back();
                    freq[last]++;

                    i--;

                    int targetChar = target[i] - 'a';

                    for (int ch = targetChar + 1; ch < 26; ch++) {

                        if (freq[ch] > 0) {

                            ans.push_back(char('a' + ch));
                            freq[ch]--;

                            // Fill the rest in ascending order.
                            for (int c = 0; c < 26; c++) {
                                while (freq[c] > 0) {
                                    ans.push_back(char('a' + c));
                                    freq[c]--;
                                }
                            }

                            return ans;
                        }
                    }
                }

                return "";
            }
        }

        /*
        We matched target exactly.

        The answer must be STRICTLY greater,
        so backtrack and increase the rightmost
        possible position.
        */

        while (!ans.empty()) {

            int last = ans.back() - 'a';

            ans.pop_back();
            freq[last]++;

            int pos = ans.size();

            if (pos >= target.size())
                continue;

            int targetChar = target[pos] - 'a';

            for (int ch = targetChar + 1; ch < 26; ch++) {

                if (freq[ch] > 0) {

                    ans.push_back(char('a' + ch));
                    freq[ch]--;

                    // Remaining characters in ascending order.
                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            ans.push_back(char('a' + c));
                            freq[c]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};