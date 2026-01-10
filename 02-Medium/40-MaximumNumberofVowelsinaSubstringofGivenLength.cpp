/*
Problem: Maximum Number of Vowels in a Substring of Given Length
Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
Difficulty: Medium
Topic: Strings / Sliding Window / Counting

Problem Statement:
Given a string `s` and an integer `k`, return *the maximum number of vowel letters*
in any substring of `s` with length `k`.

Vowel letters in English are **'a', 'e', 'i', 'o', and 'u'**.

Example:
Input: s = "abciiidef", k = 3  
Output: 3  
Explanation: The substring "iii" has 3 vowels.

Approach (Sliding Window – Optimal):
1. Use a sliding window of size `k` over the string.
2. Maintain a count of vowels in the current window.
3. As the window moves right:
   - Add the vowel contribution of the new right character.
   - Subtract the vowel contribution of the left character that goes out.
4. Track the maximum vowel count seen.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [&](char c) {
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
                   c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
        };

        int n = s.size();
        int current = 0;
        int maxCount = 0;

        // initial window
        for (int i = 0; i < k && i < n; i++) {
            if (isVowel(s[i])) current++;
        }
        maxCount = current;

        // slide window
        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) current++;
            if (isVowel(s[i - k])) current--;
            maxCount = max(maxCount, current);
        }

        return maxCount;
    }
};