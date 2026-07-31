/*
Problem: Minimum Number of Pushes to Type Word II
Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
Difficulty: Medium
Topic: String / Greedy / Sorting / Counting

Problem Statement:
You are given a string word consisting of lowercase
English letters.

You have a telephone keypad with 8 keys.
Each key can be assigned any number of distinct letters.

Typing a letter requires:
- 1 push if it is the first letter on its key.
- 2 pushes if it is the second letter.
- 3 pushes if it is the third letter.
- ...

You may assign letters to keys in any way.

Return the minimum total number of pushes required
to type the given word.

Example 1:
Input: word = "abcde"
Output: 5

Explanation:
Assign each letter to the first position
of different keys.

Each letter requires 1 push.

Total = 5

Example 2:
Input: word = "xyzxyzxyzxyz"

Output: 12

Explanation:
Letters:
x -> frequency = 4
y -> frequency = 4
z -> frequency = 4

Assign all three letters as the first letter
on different keys.

Total pushes = 4 + 4 + 4 = 12

--------------------------------------------------

Approach (Greedy + Frequency Sorting – Optimal):

Key Insight:
Letters with higher frequency should require
fewer pushes.

Since there are only 8 keys:

- First 8 most frequent letters
  require 1 push.

- Next 8 letters
  require 2 pushes.

- Next 8 letters
  require 3 pushes.

- Remaining letters
  require 4 pushes.

Sort frequencies in descending order
and assign pushes greedily.

--------------------------------------------------

Steps:
1. Count frequency of each letter.
2. Sort frequencies in descending order.
3. Traverse sorted frequencies:
   - i < 8       → 1 push
   - 8 ≤ i < 16  → 2 pushes
   - 16 ≤ i < 24 → 3 pushes
   - else        → 4 pushes
4. Add:
      frequency × pushes
5. Return total pushes.

--------------------------------------------------

Dry Run:

word = "aabbccc"

Frequencies:

c = 3
a = 2
b = 2

Sorted:
3 2 2

Assignments:

c → 1 push
Cost = 3 × 1 = 3

a → 1 push
Cost = 2 × 1 = 2

b → 1 push
Cost = 2 × 1 = 2

Total = 7

--------------------------------------------------

Why it works:
- Most frequently used letters contribute
  the most to the answer.
- Assigning them to positions requiring
  fewer pushes minimizes the total cost.
- Greedy assignment after sorting guarantees
  the minimum number of pushes.

--------------------------------------------------

Time Complexity: O(n)

- Counting frequencies: O(n)
- Sorting 26 frequencies: O(26 log 26) = O(1)

Overall: O(n)

Space Complexity: O(1)

- Frequency array of size 26.

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {

        vector<int> freq(26, 0);

        for (char ch : word) {
            freq[ch - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int pushes = 0;

        for (int i = 0; i < 26; i++) {

            if (freq[i] == 0) break;

            pushes += freq[i] * (i / 8 + 1);
        }

        return pushes;
    }
};