/*
Problem: Sort Vowels in a String
Link: https://leetcode.com/problems/sort-vowels-in-a-string/description/
Difficulty: Medium
Topic: String / Sorting

Problem Statement:
Given a string s, sort only the vowels ('a', 'e', 'i', 'o', 'u', both uppercase and lowercase) 
in non-decreasing order, while keeping all other characters in their original positions.

Approach:
1. Traverse the string and collect all vowels into a separate container.
2. Sort the vowels.
3. Replace the vowels in the string with the sorted ones in order.
4. Return the modified string.

Time Complexity: O(n log n)  — due to sorting the vowels
Space Complexity: O(n)       — for storing vowels separately
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        string vowels;
        unordered_set<char> vowelSet = {'a','e','i','o','u','A','E','I','O','U'};

        // Collect vowels from the string
        for (char c : s) {
            if (vowelSet.count(c))
                vowels.push_back(c);
        }

        // Sort the collected vowels
        sort(vowels.begin(), vowels.end());

        // Replace vowels in original string with sorted vowels
        int idx = 0;
        for (char &c : s) {
            if (vowelSet.count(c))
                c = vowels[idx++];
        }

        return s;
    }
};
