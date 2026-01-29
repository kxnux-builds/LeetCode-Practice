/*
Problem: Masking Personal Information
Link: https://leetcode.com/problems/masking-personal-information/description/
Difficulty: Medium
Topic: Strings / Simulation

Problem Statement:
You are given a personal information string `s`, representing either an **email address** or a **phone number**.  
Return the **masked personal information** following the rules below:

1) **Email Address:**
   - Convert all letters to lowercase.
   - Keep the first and last characters of the name (before `'@'`).
   - Replace all middle characters of the name with exactly **5 asterisks `"*****"`**.
   - Keep the domain (after `'@'`) in lowercase.

   Example:
     Input:  "LeetCode@LeetCode.com"  
     Output: "l*****e@leetcode.com"  
     (First name becomes lowercase and middle replaced by five stars.) :contentReference[oaicite:0]{index=0}

2) **Phone Number:**
   - A phone number may contain digits `0–9` and characters from `{'+' , '-', '(', ')', ' '}`.
   - Remove all non-digit characters.
   - There are **10–13 digits** total.
       - Last **10 digits** → local number.
       - First **(0–3) digits** (if any) → country code.
   - Mask:
       - Always show only last **4 digits**.
       - Local part always formatted as `"***-***-XXXX"`.
       - If country code exists, prefix `+` plus asterisks for each country code digit, then `'-'`.

   Examples:
     "1(234)567-890" → "***-***-7890"  
     "86-(10)12345678" → "+**-***-***-5678" :contentReference[oaicite:1]{index=1}

Return the correctly masked string.

Time Complexity: O(n) — single pass  
Space Complexity: O(n) — building result
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maskPII(string s) {
        // If email (contains '@'), mask email
        auto atPos = s.find('@');
        if (atPos != string::npos) {
            // Lowercase everything
            for (char &c : s)
                c = tolower(c);

            // First part (before '@'): keep first and last, mask middle with "*****"
            string name = s.substr(0, atPos);
            string domain = s.substr(atPos); // includes '@'
            return name.substr(0, 1) + "*****" + name.substr(name.size() - 1) + domain;
        }

        // Otherwise phone number
        string digits;
        for (char c : s) {
            if (isdigit(c)) digits.push_back(c);
        }

        int total = digits.size(); // 10 to 13
        string last4 = digits.substr(total - 4);

        // Local always masked as ***-***-XXXX
        string masked = "***-***-" + last4;

        // Country code part
        int countryLen = total - 10;
        if (countryLen > 0) {
            masked = "+" + string(countryLen, '*') + "-" + masked;
        }

        return masked;
    }
};