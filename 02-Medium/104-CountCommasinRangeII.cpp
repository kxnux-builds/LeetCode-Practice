/*
    ============================================================
    Problem: Count Commas in Range II
    Link: https://leetcode.com/problems/count-commas-in-range-ii/description/

    Difficulty: Medium
    Topic: Math, Counting, Observation

    ============================================================
    Problem Statement:

    You are given an integer n.

    Consider every integer from:

        1 to n

    Write each number using standard number formatting.

    A comma is inserted after every three digits
    from the right.

    Examples:

        123        -> 123
        1,234      -> 1 comma
        12,345     -> 1 comma
        123,456    -> 1 comma
        1,234,567  -> 2 commas

    Return the TOTAL number of commas used when writing
    all integers from 1 to n.

    ------------------------------------------------------------
    IMPORTANT CONSTRAINT:

        1 <= n <= 10^15

    Because n can be extremely large, we cannot loop
    from 1 to n.

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

        Total = 3


    ============================================================
    EXAMPLE 2:

    Input:
        n = 998

    Output:
        0

    Explanation:

        Every number from 1 to 998 has at most 3 digits.

        Therefore, no commas are used.

        Answer = 0


    ============================================================
    KEY OBSERVATION:

    Look at the ranges:

        1 to 999
            -> 0 commas

        1,000 to 999,999
            -> 1 comma

        1,000,000 to 999,999,999
            -> 2 commas

        1,000,000,000 to 999,999,999,999
            -> 3 commas

        1,000,000,000,000 to ...
            -> 4 commas


    Instead of counting commas for every number,
    count each comma POSITION separately.

    ------------------------------------------------------------
    FIRST COMMA:

    A number gets its first comma at:

        1,000

    Every number from 1,000 to n contains this comma.

    Number of such numbers:

        n - 1000 + 1

        = n - 999


    ------------------------------------------------------------
    SECOND COMMA:

    A number gets its second comma at:

        1,000,000

    Every number from 1,000,000 to n contains
    this second comma.

    Number of such numbers:

        n - 1,000,000 + 1

        = n - 999,999


    ------------------------------------------------------------
    THIRD COMMA:

    A number gets its third comma at:

        1,000,000,000

    Number of numbers containing this comma:

        n - 1,000,000,000 + 1


    ------------------------------------------------------------
    PATTERN:

    Comma thresholds are:

        1,000
        1,000,000
        1,000,000,000
        1,000,000,000,000
        1,000,000,000,000,000
        ...

    Each threshold is:

        previous threshold * 1000


    ============================================================
    MAIN IDEA:

    Start:

        x = 1000

    While:

        x <= n

    Every number from x to n contains one additional comma.

    Therefore:

        contribution = n - x + 1

    Add this to the answer.

    Then move to the next comma threshold:

        x = x * 1000


    ============================================================
    FORMULA:

    For every:

        x = 1000, 1,000,000, 1,000,000,000, ...

    if:

        x <= n

    then:

        answer += n - x + 1


    ============================================================
    DRY RUN:

    Let's take:

        n = 1,234,567


    ------------------------------------------------------------
    STEP 1:

        x = 1,000

    Numbers from 1,000 to 1,234,567
    contain the FIRST comma.

    Count:

        1,234,567 - 1,000 + 1
        = 1,233,568

    answer:

        1,233,568


    ------------------------------------------------------------
    STEP 2:

        x = 1,000 * 1000

        x = 1,000,000

    Numbers from 1,000,000 to 1,234,567
    contain the SECOND comma.

    Count:

        1,234,567 - 1,000,000 + 1
        = 234,568

    answer:

        1,233,568 + 234,568
        = 1,468,136


    ------------------------------------------------------------
    STEP 3:

        x = 1,000,000 * 1000

        x = 1,000,000,000

    But:

        1,000,000,000 > 1,234,567

    Stop.

    Final answer:

        1,468,136


    ============================================================
    ANOTHER SIMPLE EXAMPLE:

    n = 2,000,000


    First comma:

        x = 1,000

        contribution:
        2,000,000 - 1,000 + 1
        = 1,999,001


    Second comma:

        x = 1,000,000

        contribution:
        2,000,000 - 1,000,000 + 1
        = 1,000,001


    Third threshold:

        x = 1,000,000,000

        x > n

        Stop.


    Total:

        1,999,001 + 1,000,001
        = 2,999,002


    ============================================================
    WHY DOES THIS WORK?

    Consider:

        1,234,567

    It contains TWO commas:

        1,234,567
         ^   ^

    Instead of treating those two commas as one unit,
    we count them independently.

    First comma:
        Every number >= 1,000 has it.

    Second comma:
        Every number >= 1,000,000 has it.

    Therefore:

        Total commas
        =
        numbers >= 1,000
        +
        numbers >= 1,000,000
        +
        numbers >= 1,000,000,000
        + ...

    This counts every comma exactly once.


    ============================================================
    WHY PART II IS DIFFERENT FROM PART I:

    Part I:

        n <= 10^5

    So:

        max(0, n - 999)

    was enough because every number could have
    at most ONE comma.


    Part II:

        n <= 10^15

    Now a number can have multiple commas.

    Example:

        1,234,567,890,123,456

    contains FOUR commas.

    Therefore, we must count:

        1st comma
        2nd comma
        3rd comma
        4th comma

    separately.


    ============================================================
    WHY USE long long?

    n can be as large as:

        10^15

    which is much larger than the safe range of
    a normal 32-bit int.

    So we use:

        long long

    for:

        n
        x
        answer


    ============================================================
    APPROACH STEPS:

    1. Initialize:

           answer = 0

    2. Start the first comma threshold:

           x = 1000

    3. While x <= n:

           answer += n - x + 1

    4. Move to the next comma threshold:

           x *= 1000

    5. Return answer.


    ============================================================
    COMPLEXITY:

    The threshold grows by 1000 every iteration:

        1000
        1,000,000
        1,000,000,000
        1,000,000,000,000
        1,000,000,000,000,000

    Therefore, there are only O(log n) iterations.

    Time Complexity:

        O(log n)

    Space Complexity:

        O(1)

    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {

        long long answer = 0;

        // First number that contains a comma
        long long x = 1000;

        // Check every comma threshold
        while (x <= n) {

            // Every number from x to n
            // contains this additional comma
            answer += n - x + 1;

            // Move to the next comma position
            x *= 1000;
        }

        return answer;
    }
};