/*
    ============================================================
    Problem: Reverse Degree of a String
    Link: https://leetcode.com/problems/reverse-degree-of-a-string/description/

    Difficulty: Easy
    Topic: String, Simulation

    ============================================================
    Problem Statement:

    You are given a string s.

    Calculate its REVERSE DEGREE.

    The reverse degree is calculated as follows:

    For every character:

        1. Find its position in the REVERSED alphabet.

        2. Multiply that value by the character's
           position in the string.

        3. Add the result to the total.

    ------------------------------------------------------------
    Reversed Alphabet:

        Normal Alphabet:

        a = 1
        b = 2
        c = 3
        ...
        z = 26


        Reversed Alphabet:

        a = 26
        b = 25
        c = 24
        ...
        z = 1

    ------------------------------------------------------------
    String positions are 1-indexed:

        First character  -> position 1
        Second character -> position 2
        Third character  -> position 3
        ...

    ============================================================
    EXAMPLE 1:

    Input:

        s = "abc"

    Output:

        148

    Explanation:

        Character    Reverse Value    String Position    Product

            a             26                 1             26
            b             25                 2             50
            c             24                 3             72

        Total:

            26 + 50 + 72
            = 148

    ============================================================
    EXAMPLE 2:

    Input:

        s = "zaza"

    Output:

        160

    Explanation:

        Character    Reverse Value    Position    Product

            z              1              1          1
            a             26              2         52
            z              1              3          3
            a             26              4        104

        Total:

            1 + 52 + 3 + 104
            = 160

    ============================================================
    KEY OBSERVATION:

    We need the reversed alphabet position.

    Instead of creating a map:

        a -> 26
        b -> 25
        c -> 24
        ...
        z -> 1

    We can calculate it directly.

    ------------------------------------------------------------
    Normal position of a character:

        'a' -> 0
        'b' -> 1
        'c' -> 2
        ...
        'z' -> 25

    This is obtained using:

        s[i] - 'a'

    ------------------------------------------------------------
    Reversed position:

        26 - (s[i] - 'a')

    Check:

        For 'a':

            26 - ('a' - 'a')
            = 26 - 0
            = 26


        For 'b':

            26 - ('b' - 'a')
            = 26 - 1
            = 25


        For 'z':

            26 - ('z' - 'a')
            = 26 - 25
            = 1

    Perfect!

    ============================================================
    FORMULA:

    For character s[i]:

        reverseValue =
            26 - (s[i] - 'a')

    Its string position is:

        i + 1

    Therefore:

        contribution =
            reverseValue * (i + 1)

    Add every contribution:

        answer += contribution

    ============================================================
    APPROACH:

    STEP 1:

        Initialize:

            answer = 0


    STEP 2:

        Traverse the string from left to right.


    STEP 3:

        For every character s[i], calculate:

            reverseValue =
                26 - (s[i] - 'a')


    STEP 4:

        Calculate its contribution:

            reverseValue * (i + 1)


    STEP 5:

        Add it to answer.


    STEP 6:

        Return answer.

    ============================================================
    DRY RUN:

    Input:

        s = "abc"


    ------------------------------------------------------------
    i = 0

        character = 'a'

        Reverse alphabet value:

            26 - ('a' - 'a')
            = 26

        String position:

            i + 1
            = 1

        Contribution:

            26 * 1
            = 26

        answer:

            26


    ------------------------------------------------------------
    i = 1

        character = 'b'

        Reverse alphabet value:

            26 - ('b' - 'a')
            = 26 - 1
            = 25

        String position:

            2

        Contribution:

            25 * 2
            = 50

        answer:

            26 + 50
            = 76


    ------------------------------------------------------------
    i = 2

        character = 'c'

        Reverse alphabet value:

            26 - ('c' - 'a')
            = 26 - 2
            = 24

        String position:

            3

        Contribution:

            24 * 3
            = 72

        answer:

            76 + 72
            = 148


    FINAL ANSWER:

        148

    ============================================================
    ANOTHER DRY RUN:

    Input:

        s = "zaza"


    ------------------------------------------------------------
    i = 0

        'z'

        Reverse value:

            26 - 25
            = 1

        Position = 1

        Contribution:

            1 * 1
            = 1

        answer = 1


    ------------------------------------------------------------
    i = 1

        'a'

        Reverse value:

            26 - 0
            = 26

        Position = 2

        Contribution:

            26 * 2
            = 52

        answer:

            1 + 52
            = 53


    ------------------------------------------------------------
    i = 2

        'z'

        Reverse value:

            1

        Position = 3

        Contribution:

            1 * 3
            = 3

        answer:

            53 + 3
            = 56


    ------------------------------------------------------------
    i = 3

        'a'

        Reverse value:

            26

        Position = 4

        Contribution:

            26 * 4
            = 104

        answer:

            56 + 104
            = 160


    FINAL ANSWER:

        160

    ============================================================
    WHY THIS WORKS:

    The problem directly defines the reverse degree as:

        reverse alphabet position
        ×
        string position

    for every character.

    Our formula:

        26 - (s[i] - 'a')

    gives exactly the reversed alphabet position.

    And:

        i + 1

    gives the required 1-based string position.

    Therefore:

        answer +=
            (26 - (s[i] - 'a')) * (i + 1)

    calculates exactly the required reverse degree.

    ============================================================
    IMPORTANT C++ CONCEPT:

    Why does:

        s[i] - 'a'

    work?

    Characters have numeric ASCII values.

    For example:

        'a' = 97
        'b' = 98
        'c' = 99

    Therefore:

        'b' - 'a'
        = 98 - 97
        = 1


        'c' - 'a'
        = 99 - 97
        = 2


        'z' - 'a'
        = 122 - 97
        = 25

    So it gives the zero-based alphabet position.

    ============================================================
    COMMON MISTAKE:

    DO NOT use:

        i

    directly as the string position.

    Because C++ indexing starts from 0:

        i = 0 -> first character

    But the problem uses 1-based positions:

        first character -> 1

    Therefore use:

        i + 1

    Example:

        s = "abc"

        C++ index:
            0, 1, 2

        Problem position:
            1, 2, 3

    ============================================================
    COMPLEXITY:

    Time Complexity:

        O(n)

    We visit every character exactly once.


    Space Complexity:

        O(1)

    We only use a few integer variables.

    ============================================================
    FINAL FORMULA:

        answer +=
            (26 - (s[i] - 'a')) * (i + 1)

    This single formula is the main thing to remember.

    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {

        int answer = 0;

        // Traverse every character
        for (int i = 0; i < s.size(); i++) {

            // Position in reversed alphabet
            int reverseValue = 26 - (s[i] - 'a');

            // Add:
            // reversed alphabet value × 1-based position
            answer += reverseValue * (i + 1);
        }

        return answer;
    }
};