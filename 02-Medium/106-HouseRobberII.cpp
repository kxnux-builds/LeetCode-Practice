/*
    ============================================================
    Problem: House Robber II
    LeetCode: 213

    Link:
    https://leetcode.com/problems/house-robber-ii/description/

    Difficulty: Medium
    Topic: Dynamic Programming, Array

    ============================================================
    Problem Statement:

    You are a professional robber planning to rob houses.

    Each house contains some amount of money.

    However, you CANNOT rob two adjacent houses.

    The important difference from House Robber I is:

        The houses are arranged in a CIRCLE.

    Therefore:

        First house and last house are also adjacent.

    Return the maximum amount of money you can rob
    without alerting the police.

    ============================================================
    EXAMPLE 1:

    Input:
        nums = [2,3,2]

    Output:
        3

    Explanation:

        Houses are arranged in a circle:

             2
           /   \
          2 --- 3

        We cannot rob the first and last house together
        because they are adjacent.

        Best choice:

            Rob house with 3

        Answer = 3


    ============================================================
    EXAMPLE 2:

    Input:
        nums = [1,2,3,1]

    Output:
        4

    Explanation:

        Rob:

            1 + 3 = 4

        These houses are not adjacent.

    ============================================================
    EXAMPLE 3:

    Input:
        nums = [1,2,3]

    Output:
        3

    Explanation:

        Since the houses form a circle, we cannot rob
        both the first and last house.

        Best choice:

            3

        Answer = 3

    ============================================================
    THE MAIN PROBLEM:

    In House Robber I, the houses were in a straight line:

        1 -- 2 -- 3 -- 4

    We used:

        dp[i] = max(
            dp[i-1],
            nums[i] + dp[i-2]
        )


    But here we have:

        1 -- 2 -- 3 -- 4
        |           |
        --------------
            circle

    So:

        house 0 and house n-1

    are also adjacent.

    Therefore, we cannot rob both.

    ============================================================
    KEY OBSERVATION:

    Since the FIRST and LAST houses cannot both be robbed,
    there are only TWO possibilities:

        CASE 1:
        Don't rob the LAST house.

        Use:

            nums[0 ... n-2]


        CASE 2:
        Don't rob the FIRST house.

        Use:

            nums[1 ... n-1]


    Then solve each case as a normal House Robber problem.

    Finally:

        answer =
        max(case 1, case 2)

    ============================================================
    VISUAL:

    Original:

        [ 2, 3, 2, 3, 5 ]

         ↑           ↑
       first       last

       These two are adjacent.


    CASE 1:
    Exclude LAST:

        [ 2, 3, 2, 3 ]

        Solve normally.


    CASE 2:
    Exclude FIRST:

        [ 3, 2, 3, 5 ]

        Solve normally.


    Take the maximum.

    ============================================================
    WHY TWO CASES ARE ENOUGH:

    Suppose an optimal solution exists.

    It is impossible for that solution to contain BOTH:

        nums[0]

    and:

        nums[n-1]

    because they are adjacent.

    Therefore, at least one of them must be excluded.

    So every valid optimal solution belongs to:

        Case 1 → exclude last

    OR:

        Case 2 → exclude first

    By solving both cases, we cannot miss the optimal answer.

    ============================================================
    LINEAR HOUSE ROBBER:

    We already know how to solve:

        [2,7,9,3,1]

    At each house:

        OPTION 1:
        Skip current house.

            previous answer


        OPTION 2:
        Rob current house.

            current money + answer from two houses back


    Therefore:

        current =
            max(
                previous,
                previousPrevious + money
            )

    We only need two variables.

    ============================================================
    DRY RUN:

    nums = [2,3,2]


    ------------------------------------------------------------
    CASE 1:
    Exclude last house.

        [2,3]


    House 2:

        best = 2


    House 3:

        max(2,3)
        = 3


    Case 1 = 3


    ------------------------------------------------------------
    CASE 2:
    Exclude first house.

        [3,2]


    House 3:

        best = 3


    House 2:

        max(3,2)
        = 3


    Case 2 = 3


    ------------------------------------------------------------
    FINAL:

        max(3,3)

        = 3

    Answer = 3

    ============================================================
    ANOTHER DRY RUN:

    nums = [1,2,3,1]


    ------------------------------------------------------------
    CASE 1:
    Exclude last house.

        [1,2,3]


    Linear House Robber:

        i = 0:

            best = 1


        i = 1:

            max(1,2)
            = 2


        i = 2:

            max(
                2,
                1 + 3
            )

            = max(2,4)
            = 4


    Case 1 = 4


    ------------------------------------------------------------
    CASE 2:
    Exclude first house.

        [2,3,1]


    i = 0:

        best = 2


    i = 1:

        max(2,3)
        = 3


    i = 2:

        max(
            3,
            2 + 1
        )

        = 3


    Case 2 = 3


    ------------------------------------------------------------
    FINAL:

        max(4,3)
        = 4

    Answer = 4

    ============================================================
    EDGE CASE:

    Only ONE house:

        nums = [5]

    There is no other house adjacent to it.

    So we can simply rob it.

        Answer = 5


    This is why we handle:

        nums.size() == 1

    separately.

    ============================================================
    EDGE CASE:

    TWO HOUSES:

        nums = [2,7]

    Since they are adjacent, we can only rob one.

    Answer:

        max(2,7)
        = 7


    Our two cases become:

        Case 1:
        [2]

        Case 2:
        [7]

        max(2,7)
        = 7

    So the same approach works.

    ============================================================
    APPROACH STEPS:

    1. If there is only one house,
       return nums[0].

    2. Solve the first linear case:

           nums[0 ... n-2]

       This means:
           Exclude the last house.


    3. Solve the second linear case:

           nums[1 ... n-1]

       This means:
           Exclude the first house.


    4. Return:

           max(case1, case2)


    ============================================================
    CODE STRUCTURE:

        robRange(nums, start, end)

    solves the normal House Robber problem
    between indices:

        start ... end


    Then:

        robRange(nums, 0, n-2)

    handles Case 1.


    And:

        robRange(nums, 1, n-1)

    handles Case 2.

    ============================================================
    WHY THIS WORKS:

    The only new difficulty compared with House Robber I
    is that the first and last houses are adjacent.

    We remove that conflict by considering two possibilities:

        Don't use the first house
        OR
        Don't use the last house

    After removing one endpoint, the remaining houses form
    a normal straight line.

    Then the standard House Robber DP solves each case.

    Taking the maximum gives the globally optimal answer.

    ============================================================
    COMPLEXITY:

    First linear pass:
        O(n)

    Second linear pass:
        O(n)

    Total:

        O(n)

    Space:

        O(1)

    We only use a few variables inside the helper.

    ============================================================
    IMPORTANT DP PATTERN:

    House Robber I:

        Linear array

        dp[i] =
        max(
            dp[i-1],
            nums[i] + dp[i-2]
        )


    House Robber II:

        Circular array

        Split into:

            [0 ... n-2]

        and:

            [1 ... n-1]

        Then apply House Robber I.

    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Normal House Robber for a linear range
    int robRange(vector<int>& nums, int start, int end) {

        int prev2 = 0;  // Best answer up to i-2
        int prev1 = 0;  // Best answer up to i-1

        for (int i = start; i <= end; i++) {

            // Option 1: Skip current house
            int skip = prev1;

            // Option 2: Rob current house
            int take = nums[i] + prev2;

            // Choose the better option
            int current = max(skip, take);

            // Move forward
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }


    int rob(vector<int>& nums) {

        int n = nums.size();

        // Edge case: only one house
        if (n == 1) {
            return nums[0];
        }


        // CASE 1:
        // Rob from house 0 to n-2
        // Exclude the last house
        int case1 = robRange(nums, 0, n - 2);


        // CASE 2:
        // Rob from house 1 to n-1
        // Exclude the first house
        int case2 = robRange(nums, 1, n - 1);


        // Take the better case
        return max(case1, case2);
    }
};