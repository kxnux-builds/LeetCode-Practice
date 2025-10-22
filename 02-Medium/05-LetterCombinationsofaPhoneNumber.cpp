/*
Problem: Letter Combinations of a Phone Number
Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
Difficulty: Medium
Topic: Backtracking / String

Problem Statement:
Given a string containing digits from 2–9 inclusive, return all possible letter 
combinations that the number could represent. Return the answer in any order.

The mapping of digits to letters is as follows (just like on telephone buttons):
2 → "abc", 3 → "def", 4 → "ghi", 5 → "jkl",
6 → "mno", 7 → "pqrs", 8 → "tuv", 9 → "wxyz"

Approach:
1. Use a recursive backtracking approach.
2. Maintain a mapping from digits to letters.
3. At each step, choose one letter corresponding to the current digit and 
   move to the next digit recursively.
4. Stop when the current combination’s length equals the input length.

Time Complexity: O(4^n)  (each digit can map to up to 4 letters)
Space Complexity: O(n)   (recursion depth + combination string)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;

        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }

            string letters = mapping[digits[index] - '0'];
            for (char c : letters) {
                current.push_back(c);
                backtrack(index + 1);
                current.pop_back();
            }
        };

        backtrack(0);
        return result;
    }
};
