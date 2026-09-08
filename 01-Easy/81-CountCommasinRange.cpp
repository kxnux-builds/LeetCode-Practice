/*
    ============================================================
    Problem: Count Commas in Range
    Link: https://leetcode.com/problems/count-commas-in-range/description/

    Difficulty: Easy
    Topic: Math, Observation

    ============================================================
    Problem Statement:

    You are given an integer n.

    Consider all integers from:

        1 to n

    Write every number using standard number formatting.

    For example:

        999      -> 999
        1000     -> 1,000
        1001     -> 1,001
        10000    -> 10,000

    A comma is inserted after every three digits
    from the right.

    Return the TOTAL number of commas used when writing
    all integers from 1 to n.

    Constraints:

        1 <= n <= 10^5

    ============================================================
    EXAMPLE 1:

    Input:
        n = 1002

    Output:
        3

    Explanation:

        1,000 -> 1 comma
        1,001 -> 1 comma
        1,002 -> 1 comma

        All numbers from 1 to 999 have no commas.

        Total = 3


    ============================================================
    EXAMPLE 2:

    Input:
        n = 998

    Output:
        0

    Explanation:

        Every number from 1 to 998 has at most 3 digits.

        Therefore, none of them needs a comma.

        Answer = 0

    ============================================================
    KEY OBSERVATION:

    The FIRST number that requires a comma is:

        1,000

    Therefore:

        1 to 999
            -> 0 commas

        1,000 to n
            -> 1 comma each

    Because the constraint is:

        n <= 100,000

    every number in our range can have AT MOST ONE comma.

    So the problem becomes:

        How many numbers are there from 1000 to n?

    ------------------------------------------------------------
    Count of numbers from 1000 to n:

        n - 1000 + 1

    Simplify:

        n - 999

    Therefore:

        if n < 1000:
            answer = 0

        otherwise:
            answer = n - 999

    ============================================================
    APPROACH:

    We can combine both cases using:

        max(0, n - 999)

    Why?

    Case 1:
        n < 1000

        n - 999 is negative.

        max(0, negative) = 0

    Case 2:
        n >= 1000

        n - 999 is positive.

        max(0, n - 999) = n - 999

    ============================================================
    DRY RUN 1:

    n = 1002

    Numbers containing commas:

        1000
        1001
        1002

    Count:

        1002 - 999
        = 3

    Answer:

        3


    ============================================================
    DRY RUN 2:

    n = 998

        n - 999
        = 998 - 999
        = -1

    We cannot have a negative number of commas.

    Therefore:

        max(0, -1)
        = 0

    Answer = 0


    ============================================================
    DRY RUN 3:

    n = 1000

    Only:

        1,000

    contains a comma.

    Count:

        1000 - 999
        = 1

    Answer = 1


    ============================================================
    WHY THIS WORKS:

    Every number from 1 to 999 contains no comma.

    Every number from 1000 to n contains exactly one comma
    because n <= 100,000.

    Therefore, the total number of commas is simply the
    number of integers in the range:

        [1000, n]

    The number of integers in an inclusive range [a, b] is:

        b - a + 1

    So:

        n - 1000 + 1
        = n - 999

    For n < 1000, the answer must be 0.

    Hence:

        max(0, n - 999)

    ============================================================
    ALTERNATIVE WAY TO THINK:

    Don't count commas one number at a time.

    Instead, ask:

        "At what number does the first comma appear?"

    Answer:

        1000

    So every number after 999 contributes exactly
    one comma.

    This is a classic example of an:

        OBSERVATION / MATH

    problem.

    ============================================================
    COMPLEXITY:

    Time Complexity:
        O(1)

    Space Complexity:
        O(1)

    No loop.
    No array.
    No string conversion.
    No extra data structure.

    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCommas(int n) {

        return max(0, n - 999);
    }
};