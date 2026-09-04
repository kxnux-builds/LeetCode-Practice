/*
    Problem: Smallest Stable Index I
    LeetCode: 3903
    Link: https://leetcode.com/problems/smallest-stable-index-i/description/

    Difficulty: Easy
    Topic: Array, Prefix Maximum, Suffix Minimum

    ============================================================
    Problem Statement:

    You are given an integer array nums of length n
    and an integer k.

    For every index i:

        instability score =
        max(nums[0..i]) - min(nums[i..n-1])

    An index i is called STABLE if:

        instability score <= k

    Return the SMALLEST stable index.

    If no stable index exists, return -1.

    ============================================================
    Example 1:

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

        i = 1:
        max([5,0]) = 5
        min([0,1,4]) = 0
        score = 5 - 0 = 5

        i = 2:
        max([5,0,1]) = 5
        min([1,4]) = 1
        score = 5 - 1 = 4

        i = 3:
        max([5,0,1,4]) = 5
        min([4]) = 4
        score = 5 - 4 = 1

        Since 1 <= 3,
        index 3 is stable.

        Answer = 3


    Example 2:

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

        None of them has score <= 1.

        Answer = -1


    Example 3:

    Input:
        nums = [0]
        k = 0

    Output:
        0

    Explanation:

        max([0]) = 0
        min([0]) = 0

        score = 0 - 0 = 0

        Since 0 <= 0,
        index 0 is stable.

    ============================================================
    APPROACH: Suffix Minimum + Prefix Maximum

    The formula contains two things:

        1. max(nums[0..i])
        2. min(nums[i..n-1])

    We need to calculate these efficiently.

    ------------------------------------------------------------
    STEP 1: Build suffix minimum array

    Let:

        right[i] = minimum value from nums[i] to nums[n-1]

    Example:

        nums = [5,0,1,4]

        right[3] = 4

        right[2] = min(nums[2], right[3])
                 = min(1,4)
                 = 1

        right[1] = min(0,1)
                 = 0

        right[0] = min(5,0)
                 = 0

        Therefore:

        right = [0,0,1,4]


    ------------------------------------------------------------
    STEP 2: Maintain prefix maximum

    While scanning from left to right, keep:

        leftMax = maximum value from nums[0] to nums[i]

    Example:

        nums = [5,0,1,4]

        i = 0:
        leftMax = 5

        i = 1:
        leftMax = max(5,0) = 5

        i = 2:
        leftMax = max(5,1) = 5

        i = 3:
        leftMax = max(5,4) = 5


    ------------------------------------------------------------
    STEP 3: Calculate instability score

    At every index:

        score = leftMax - right[i]

    If:

        score <= k

    then i is stable.

    Since we scan from left to right,
    the FIRST valid index is automatically the
    smallest stable index.

    ============================================================
    DRY RUN:

    nums = [5,0,1,4]
    k = 3

    Suffix minimum:

        right = [0,0,1,4]


    Now scan from left:

    ------------------------------------------------------------
    i = 0

        leftMax = max(-infinity, 5)
                 = 5

        score = 5 - right[0]
              = 5 - 0
              = 5

        5 > 3

        Not stable.


    ------------------------------------------------------------
    i = 1

        leftMax = max(5,0)
                 = 5

        score = 5 - right[1]
              = 5 - 0
              = 5

        5 > 3

        Not stable.


    ------------------------------------------------------------
    i = 2

        leftMax = max(5,1)
                 = 5

        score = 5 - right[2]
              = 5 - 1
              = 4

        4 > 3

        Not stable.


    ------------------------------------------------------------
    i = 3

        leftMax = max(5,4)
                 = 5

        score = 5 - right[3]
              = 5 - 4
              = 1

        1 <= 3

        Stable!

        Return 3.

    ============================================================
    WHY THIS WORKS:

    For every index i, we need:

        maximum of the prefix [0...i]

    and:

        minimum of the suffix [i...n-1]

    The suffix minimum array gives us the second value
    in O(1) time for every index.

    At the same time, leftMax gives us the first value
    while scanning.

    Therefore each index is processed only once.

    ============================================================
    COMPLEXITY:

    Building suffix minimum:
        O(n)

    Scanning the array:
        O(n)

    Total:
        O(n)

    Space:
        O(n)

    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        // right[i] = minimum value from index i to n-1
        vector<int> right(n);

        // Last element is the minimum of itself
        right[n - 1] = nums[n - 1];

        // Build suffix minimum array
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], nums[i]);
        }

        // Maximum value from nums[0] to nums[i]
        int leftMax = 0;

        // Check every index from left to right
        for (int i = 0; i < n; i++) {

            // Update prefix maximum
            leftMax = max(leftMax, nums[i]);

            // Calculate instability score
            int score = leftMax - right[i];

            // First stable index
            if (score <= k) {
                return i;
            }
        }

        // No stable index exists
        return -1;
    }
};