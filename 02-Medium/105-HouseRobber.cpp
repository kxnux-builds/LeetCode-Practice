/*
    ============================================================
    Problem: House Robber
    Link: https://leetcode.com/problems/house-robber/description/

    Difficulty: Medium
    Topic: Dynamic Programming, Array

    ============================================================
    Problem Statement:

    You are a professional robber planning to rob houses
    along a street.

    Each house contains some amount of money.

    However, you CANNOT rob two adjacent houses.

    If you rob two adjacent houses, the police will be alerted.

    Given an integer array nums where:

        nums[i] = amount of money in the i-th house

    Return the maximum amount of money you can rob
    without robbing two adjacent houses.

    ============================================================
    EXAMPLE 1:

    Input:
        nums = [1,2,3,1]

    Output:
        4

    Explanation:

        Rob house 1:
            1

        Rob house 3:
            3

        Total:
            1 + 3 = 4

        We cannot rob house 2 and house 3 together
        because they are adjacent.

    ============================================================
    EXAMPLE 2:

    Input:
        nums = [2,7,9,3,1]

    Output:
        12

    Explanation:

        Rob:

            2 + 9 + 1 = 12

        These houses are not adjacent.

    ============================================================
    KEY IDEA:

    At every house, we have TWO choices:

        1. ROB the current house
        2. SKIP the current house

    If we ROB the current house:

        We CANNOT rob the previous house.

    Therefore:

        rob current
        =
        nums[i] + best answer until i-2


    If we SKIP the current house:

        We can keep the best answer until i-1.

    Therefore:

        skip current
        =
        best answer until i-1


    So:

        dp[i] =
        max(
            dp[i-1],
            nums[i] + dp[i-2]
        )

    ============================================================
    DP DEFINITION:

    Let:

        dp[i] = maximum money we can rob
                from houses 0 to i.

    Then:

        dp[i-1]
        =
        maximum money without robbing house i


    And:

        nums[i] + dp[i-2]
        =
        rob house i,
        so we must skip house i-1.


    Therefore:

        dp[i] = max(dp[i-1],
                    nums[i] + dp[i-2])

    ============================================================
    BASE CASE:

    For one house:

        nums = [5]

        dp[0] = 5


    For two houses:

        nums = [2,7]

        We can rob only one of them.

        dp[1] = max(2,7)
             = 7

    ============================================================
    DRY RUN:

    nums = [2,7,9,3,1]


    ------------------------------------------------------------
    HOUSE 0:

        nums[0] = 2

        dp[0] = 2

        Best = 2


    ------------------------------------------------------------
    HOUSE 1:

        nums[1] = 7

        We can rob either:

            house 0 = 2

        or:

            house 1 = 7

        dp[1] = max(2,7)

             = 7


    ------------------------------------------------------------
    HOUSE 2:

        nums[2] = 9

        OPTION 1: Skip house 2

            dp[1] = 7


        OPTION 2: Rob house 2

            nums[2] + dp[0]

            = 9 + 2
            = 11


        Therefore:

            dp[2] = max(7,11)
                  = 11


    ------------------------------------------------------------
    HOUSE 3:

        nums[3] = 3

        OPTION 1: Skip house 3

            dp[2] = 11


        OPTION 2: Rob house 3

            nums[3] + dp[1]

            = 3 + 7
            = 10


        Therefore:

            dp[3] = max(11,10)
                  = 11


    ------------------------------------------------------------
    HOUSE 4:

        nums[4] = 1

        OPTION 1: Skip house 4

            dp[3] = 11


        OPTION 2: Rob house 4

            nums[4] + dp[2]

            = 1 + 11
            = 12


        Therefore:

            dp[4] = max(11,12)
                  = 12


    FINAL ANSWER:

        12


    ============================================================
    DP TABLE:

        House:     0    1    2    3    4
        Money:     2    7    9    3    1
        dp:        2    7   11   11   12


    ============================================================
    WHY THIS WORKS:

    At every house i, there are only two possibilities:

        CASE 1:
        Do NOT rob house i.

        Then our answer remains:

            dp[i-1]


        CASE 2:
        Rob house i.

        Then house i-1 cannot be robbed.

        Therefore:

            nums[i] + dp[i-2]


    We take the better option:

        dp[i] = max(
                    dp[i-1],
                    nums[i] + dp[i-2]
                )

    This considers every valid possibility without
    explicitly generating all combinations.

    ============================================================
    SPACE OPTIMIZATION:

    We technically need:

        dp[i-1]
        dp[i-2]

    We DON'T need the entire dp array.

    So instead of:

        dp[i-2] → prev2
        dp[i-1] → prev1

    we maintain only two variables.

    For each house:

        current = max(
            prev1,
            nums[i] + prev2
        )

    Then move forward:

        prev2 = prev1
        prev1 = current


    ============================================================
    DRY RUN OF OPTIMIZED VERSION:

    nums = [2,7,9,3,1]

    Initially:

        prev2 = 0
        prev1 = 0


    ------------------------------------------------------------
    i = 0

        current = max(
            0,
            2 + 0
        )

        current = 2

        prev2 = 0
        prev1 = 2


    ------------------------------------------------------------
    i = 1

        current = max(
            2,
            7 + 0
        )

        current = 7

        prev2 = 2
        prev1 = 7


    ------------------------------------------------------------
    i = 2

        current = max(
            7,
            9 + 2
        )

        current = 11

        prev2 = 7
        prev1 = 11


    ------------------------------------------------------------
    i = 3

        current = max(
            11,
            3 + 7
        )

        current = 11

        prev2 = 11
        prev1 = 11


    ------------------------------------------------------------
    i = 4

        current = max(
            11,
            1 + 11
        )

        current = 12

        prev2 = 11
        prev1 = 12


    Return:

        12


    ============================================================
    IMPORTANT PATTERN:

    Whenever you see:

        "Cannot choose two adjacent elements"

    think about:

        DP


    Typical recurrence:

        current =
        max(
            previous,
            current_value + previous_previous
        )

    This same pattern appears in many problems.

    ============================================================
    COMPLEXITY:

    Time Complexity:

        O(n)

    We visit every house exactly once.


    Space Complexity:

        O(1)

    We only maintain three variables:

        prev2
        prev1
        current

    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        int prev2 = 0;  // Best answer up to i-2
        int prev1 = 0;  // Best answer up to i-1

        for (int i = 0; i < nums.size(); i++) {

            // Option 1: Skip current house
            int skip = prev1;

            // Option 2: Rob current house
            int take = nums[i] + prev2;

            // Choose the better option
            int current = max(skip, take);

            // Move to next house
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};