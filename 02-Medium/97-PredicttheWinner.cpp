/*
Problem: Predict the Winner
Link: https://leetcode.com/problems/predict-the-winner/description/
Difficulty: Medium
Topic: Dynamic Programming / Recursion / Game Theory

Problem Statement:
You are given an integer array nums.

Two players take turns picking a number from either
the beginning or the end of the array.

Rules:
- Player 1 starts first.
- Both players play optimally.
- Each picked number is added to the player's score.

Return true if Player 1 can win the game or tie.
Otherwise, return false.

Example 1:
Input: nums = [1,5,2]
Output: false

Explanation:
Player 1 can choose:
- 1 → Player 2 chooses 5 → Player 1 gets 2
  Score:
  Player 1 = 3
  Player 2 = 5

- 2 → Player 2 chooses 5 → Player 1 gets 1
  Score:
  Player 1 = 3
  Player 2 = 5

Player 1 loses.

Example 2:
Input: nums = [1,5,233,7]
Output: true

Explanation:
Player 1 chooses 1.
Player 2 chooses 5.
Player 1 chooses 233.

Player 1 wins.

--------------------------------------------------

Approach (Dynamic Programming + Minimax – Optimal):

Key Insight:
Instead of storing each player's score separately,
store the maximum score difference that the current
player can achieve over the opponent.

Let:

dp[i][j]

= maximum score difference the current player
can obtain from subarray nums[i...j].

Choices:

1. Pick left element

nums[i] - dp[i+1][j]

2. Pick right element

nums[j] - dp[i][j-1]

Take the maximum of both choices.

If the final score difference is non-negative,
Player 1 can win or tie.

--------------------------------------------------

Steps:
1. Create DP table.
2. Base case:
      dp[i][i] = nums[i]
3. Fill table by increasing subarray length.
4. Transition:
      dp[i][j] =
      max(
          nums[i] - dp[i+1][j],
          nums[j] - dp[i][j-1]
      )
5. If dp[0][n-1] >= 0:
      return true
   else:
      return false

--------------------------------------------------

Dry Run:

nums = [1,5,2]

Base:

dp[0][0] = 1
dp[1][1] = 5
dp[2][2] = 2

Length = 2

dp[0][1]
= max(1-5,5-1)
= 4

dp[1][2]
= max(5-2,2-5)
= 3

Length = 3

dp[0][2]
= max(1-3,2-4)
= -2

-2 < 0

Answer = false

--------------------------------------------------

Why it works:
- dp[i][j] represents the maximum advantage
  the current player can gain over the opponent.
- Both players always choose the optimal move.
- A non-negative final difference means
  Player 1 can at least tie, which counts as a win.

--------------------------------------------------

Time Complexity: O(n²)

- DP table has n² states.

Space Complexity: O(n²)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                dp[i][j] = max(
                    nums[i] - dp[i + 1][j],
                    nums[j] - dp[i][j - 1]
                );
            }
        }

        return dp[0][n - 1] >= 0;
    }
};