/*
Problem: Guess Number Higher or Lower
Link: https://leetcode.com/problems/guess-number-higher-or-lower/description/
Difficulty: Easy
Topic: Binary Search / Interactive

Problem Statement:
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked 
is higher or lower than your guess.

You call a predefined API int guess(int num), which returns:
-1 if my number is lower than your guess (num is high)
 1 if my number is higher than your guess (num is low)
 0 if your guess is correct

Return the number that I picked.

Approach:
1. Use Binary Search between 1 and n.
2. For each mid:
   - If guess(mid) == 0, return mid (correct guess).
   - If guess(mid) == -1, move the right pointer left.
   - If guess(mid) == 1, move the left pointer right.
3. Continue until you find the correct number.

Time Complexity: O(log n)  — binary search over range [1, n]
Space Complexity: O(1)     — constant extra space
*/

// The guess API is defined for you.
// int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);

            if (res == 0) 
                return mid;            // Correct guess
            else if (res < 0) 
                right = mid - 1;       // My number is lower
            else 
                left = mid + 1;        // My number is higher
        }

        return -1; // Should never reach here
    }
};
