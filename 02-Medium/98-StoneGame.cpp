/*
Problem: Stone Game
Link: https://leetcode.com/problems/stone-game/description/
Difficulty: Medium
Topic: Dynamic Programming / Game Theory / Recursion

Problem Statement:
Alice and Bob are playing a game with an even number
of piles arranged in a row.

Rules:
- Alice and Bob take turns.
- Alice starts first.
- On each turn, a player removes the entire pile
  from either the beginning or the end.
- The player with more stones wins.

It is guaranteed that:
- The total number of stones is odd.
- There are no ties.
- Both players play optimally.

Return true if Alice wins the game.

Example 1:
Input: piles = [5,3,4,5]
Output: true

Explanation:
Alice can choose the rightmost pile (5).

Remaining:
[5,3,4]

Whatever Bob chooses,
Alice can always obtain more stones.

Alice wins.

Example 2:
Input: piles = [3,7,2,3]
Output: true

--------------------------------------------------

Approach (Game Theory):

Key Insight:
For this problem, the answer is always true.

Why?

- The number of piles is even.
- Alice moves first.
- Alice can choose either:
    • all even-indexed piles
    • all odd-indexed piles

Before the game starts,
Alice compares the total stones in:

- Even-indexed piles
- Odd-indexed piles

She chooses the group with the larger sum.

No matter how Bob plays,
Alice can always force herself to pick
every pile from the chosen parity.

Since:
- Total stones are odd.
- A tie is impossible.

Alice always ends with more stones.

--------------------------------------------------

Steps:
1. Observe the number of piles is even.
2. Alice selects the parity
   (even or odd indices) having more stones.
3. She always forces that strategy.
4. Therefore, Alice always wins.

--------------------------------------------------

Dry Run:

piles = [5,3,4,5]

Even-indexed piles:
5 + 4 = 9

Odd-indexed piles:
3 + 5 = 8

Alice chooses even-indexed piles.

She guarantees collecting:
5 and 4

Total = 9

Bob gets:
3 and 5

Total = 8

Alice wins.

--------------------------------------------------

Why it works:
- Alice has the first move.
- With an even number of piles,
  she can always control the parity
  of the piles she picks.
- Choosing the larger parity sum
  guarantees victory.
- Hence, the answer is always true.

--------------------------------------------------

Time Complexity: O(1)

Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};