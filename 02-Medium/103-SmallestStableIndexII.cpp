/*
    ============================================================
    Problem: Smallest Stable Index II
    LeetCode: 3904
    Link: https://leetcode.com/problems/smallest-stable-index-ii/description/

    Difficulty: Medium
    Topic: Array, Prefix Maximum, Suffix Minimum

    ============================================================
    Problem Statement:

    You are given an integer array nums of length n
    and an integer k.

    For every index i, define its instability score as:

        max(nums[0..i]) - min(nums[i..n-1])

    Where:

        max(nums[0..i])
        = maximum value from index 0 to i

        min(nums[i..n-1])
        = minimum value from index i to n-1

    An index i is called STABLE if:

        max(nums[0..i]) - min(nums[i..n-1]) <= k

    Return the SMALLEST stable index.

    If no stable index exists, return -1.

    ============================================================
    EXAMPLE 1:

    Input:
        nums = [5,0,1,4]
        k = 3

    Output:
        3

    Explanation:

        i = 0:
        max([5]) = 5
        min([5,0,1,4]) = 0

        score = 5 - 0 = 5

        5 > 3
        Not stable.


        i = 1:
        max([5,0]) = 5
        min([0,1,4]) = 0

        score = 5 - 0 = 5

        5 > 3
        Not stable.


        i = 2:
        max([5,0,1]) = 5
        min([1,4]) = 1

        score = 5 - 1 = 4

        4 > 3
        Not stable.


        i = 3:
        max([5,0,1,4]) = 5
        min([4]) = 4

        score = 5 - 4 = 1

        1 <= 3
        Stable!

        Answer = 3


    ============================================================
    EXAMPLE 2:

    Input:
        nums = [3,2,1]
        k = 1

    Output:
        -1

    Explanation:

        i = 0:
        max([3]) = 3
        min([3,2,1]) = 1
        score = 3 - 1 = 2


        i = 1:
        max([3,2]) = 3
        min([2,1]) = 1
        score = 3 - 1 = 2


        i = 2:
        max([3,2,1]) = 3
        min([1]) = 1
        score = 3 - 1 = 2


        None of the scores are <= 1.

        Answer = -1


    ============================================================
    EXAMPLE 3:

    Input:
        nums = [0]
        k = 0

    Output:
        0

    Explanation:

        max([0]) = 0
        min([0]) = 0

        score = 0 - 0 = 0

        0 <= 0

        Therefore index 0 is stable.

    ============================================================
    IMPORTANT OBSERVATION:

    For every index i, we need TWO values:

        1. Maximum from the LEFT
        2. Minimum from the RIGHT

    So we can use:

        Prefix Maximum
        +
        Suffix Minimum

    ------------------------------------------------------------
    Prefix Maximum:

        leftMax[i]
        = maximum value from nums[0] to nums[i]

    Example:

        nums = [5,0,1,4]

        leftMax:

        i = 0 -> 5
        i = 1 -> max(5,0) = 5
        i = 2 -> max(5,1) = 5
        i = 3 -> max(5,4) = 5

        leftMax = [5,5,5,5]


    ------------------------------------------------------------
    Suffix Minimum:

        rightMin[i]
        = minimum value from nums[i] to nums[n-1]

    Example:

        nums = [5,0,1,4]

        rightMin:

        i = 3 -> 4

        i = 2 -> min(1,4)
             = 1

        i = 1 -> min(0,1)
             = 0

        i = 0 -> min(5,0)
             = 0

        rightMin = [0,0,1,4]


    ============================================================
    APPROACH:

    STEP 1:
    Build the prefix maximum array.

    STEP 2:
    Build the suffix minimum array.

    STEP 3:
    Traverse every index from left to right.

    STEP 4:
    Calculate:

        instability =
            leftMax[i] - rightMin[i]

    STEP 5:
    If:

        instability <= k

    return i immediately.

    Since we check indices from 0 to n-1,
    the first valid index is automatically
    the SMALLEST stable index.

    STEP 6:
    If no index is stable, return -1.

    ============================================================
    DRY RUN:

    nums = [5,0,1,4]
    k = 3

    ------------------------------------------------------------
    Prefix Maximum:

        leftMax = [5,5,5,5]

    Suffix Minimum:

        rightMin = [0,0,1,4]


    ------------------------------------------------------------
    Index 0:

        leftMax[0] = 5
        rightMin[0] = 0

        instability = 5 - 0
                    = 5

        5 > 3

        Not stable.


    ------------------------------------------------------------
    Index 1:

        leftMax[1] = 5
        rightMin[1] = 0

        instability = 5 - 0
                    = 5

        5 > 3

        Not stable.


    ------------------------------------------------------------
    Index 2:

        leftMax[2] = 5
        rightMin[2] = 1

        instability = 5 - 1
                    = 4

        4 > 3

        Not stable.


    ------------------------------------------------------------
    Index 3:

        leftMax[3] = 5
        rightMin[3] = 4

        instability = 5 - 4
                    = 1

        1 <= 3

        STABLE!

        Return 3.

    ============================================================
    WHY THIS WORKS:

    For every index i:

        leftMax[i]
        gives exactly:

        max(nums[0..i])


    And:

        rightMin[i]
        gives exactly:

        min(nums[i..n-1])


    Therefore:

        leftMax[i] - rightMin[i]

    is exactly the instability score defined
    by the problem.

    Because we check indexes from left to right,
    the first index satisfying:

        instability <= k

    must be the smallest stable index.

    ============================================================
    WHY NOT BRUTE FORCE?

    A brute-force solution could calculate:

        max(nums[0..i])
        min(nums[i..n-1])

    separately for every i.

    That can take O(n) work for each index.

    For n = 100,000:

        O(n²)

    would be far too slow.

    Instead, prefix/suffix preprocessing lets us
    answer each index in O(1).

    Total = O(n).

    ============================================================
    COMPLEXITY:

    Building prefix maximum:
        O(n)

    Building suffix minimum:
        O(n)

    Checking all indices:
        O(n)

    Total Time:
        O(n)

    Extra Space:
        O(n)

    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        // ----------------------------------------------------
        // Step 1: Prefix Maximum
        // leftMax[i] = maximum value from 0 to i
        // ----------------------------------------------------

        vector<int> leftMax(n);

        leftMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }


        // ----------------------------------------------------
        // Step 2: Suffix Minimum
        // rightMin[i] = minimum value from i to n-1
        // ----------------------------------------------------

        vector<int> rightMin(n);

        rightMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }


        // ----------------------------------------------------
        // Step 3: Check every index
        // ----------------------------------------------------

        for (int i = 0; i < n; i++) {

            int instability = leftMax[i] - rightMin[i];

            // First stable index
            if (instability <= k) {
                return i;
            }
        }


        // No stable index found
        return -1;
    }
};