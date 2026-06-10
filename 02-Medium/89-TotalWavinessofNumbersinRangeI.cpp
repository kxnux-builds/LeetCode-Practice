/*
Problem: Total Waviness of Numbers in Range I
Link: https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/
Difficulty: Medium
Topic: Math / Simulation / Enumeration

Problem Statement:
You are given two integers num1 and num2 representing
an inclusive range [num1, num2].

The waviness of a number is defined as the total count
of its peaks and valleys.

A digit is:
- Peak   -> greater than both adjacent digits
- Valley -> smaller than both adjacent digits

Rules:
- First and last digits cannot be peaks or valleys.
- Numbers with fewer than 3 digits have waviness = 0.

Return the total sum of waviness for all numbers
in the range [num1, num2]. :contentReference[oaicite:0]{index=0}

Example 1:
Input: num1 = 120, num2 = 130
Output: 3

Explanation:
120 -> 1 peak
121 -> 1 peak
130 -> 1 peak
Total = 3

Example 2:
Input: num1 = 198, num2 = 202
Output: 3

Example 3:
Input: num1 = 4848, num2 = 4848
Output: 2

--------------------------------------------------

Approach (Brute Force Simulation – Optimal for Constraints):

Key Insight:
Constraints are small:

1 <= num1 <= num2 <= 10^5

So we can:
- Check every number in the range.
- Compute its waviness individually.
- Add all waviness values.

For a number:
1. Extract its digits.
2. Ignore first and last digit.
3. Check every middle digit:
   - Peak:
       digit > left && digit > right
   - Valley:
       digit < left && digit < right
4. Count valid peaks/valleys.

--------------------------------------------------

Steps:
1. Create helper function waviness(x).
2. Convert number into digits.
3. If digits < 3:
      return 0.
4. Traverse middle digits:
      count peaks and valleys.
5. For every number from num1 to num2:
      answer += waviness(number)
6. Return answer.

--------------------------------------------------

Dry Run:

num1 = 120
num2 = 122

120:
Digits = [1,2,0]

2 > 1 and 2 > 0
Peak found

Waviness = 1

121:
Digits = [1,2,1]

2 > 1 and 2 > 1
Peak found

Waviness = 1

122:
Digits = [1,2,2]

2 is not peak
2 is not valley

Waviness = 0

Total = 2

--------------------------------------------------

Why it works:
- Every middle digit is checked exactly once.
- A digit contributes only if it is strictly
  greater or smaller than both neighbors.
- Summing the waviness of each number gives
  the required total waviness of the range.

--------------------------------------------------

Time Complexity:
O((num2 - num1 + 1) * log(num2))

Space Complexity:
O(log(num2))

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int getWaviness(int x) {

        vector<int> digits;

        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }

        int n = digits.size();

        if (n < 3) {
            return 0;
        }

        int waviness = 0;

        for (int i = 1; i < n - 1; i++) {

            bool peak =
                digits[i] > digits[i - 1] &&
                digits[i] > digits[i + 1];

            bool valley =
                digits[i] < digits[i - 1] &&
                digits[i] < digits[i + 1];

            if (peak || valley) {
                waviness++;
            }
        }

        return waviness;
    }

    int totalWaviness(int num1, int num2) {

        int answer = 0;

        for (int x = num1; x <= num2; x++) {
            answer += getWaviness(x);
        }

        return answer;
    }
};