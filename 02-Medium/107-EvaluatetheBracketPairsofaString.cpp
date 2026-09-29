/*
    ============================================================
    Problem: Evaluate the Bracket Pairs of a String

    Link: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/

    Difficulty: Medium
    Topic: String, Hash Map, Simulation

    ============================================================
    Problem Statement:

    You are given:

        1. A string s
        2. A list of knowledge pairs

    Each knowledge pair has:

        [key, value]

    The string s contains some keys inside brackets.

    Example:

        s = "hi(name)"

        knowledge = [["name", "bob"]]

    Then:

        (name)

    should be replaced with:

        bob

    If a key inside brackets does NOT exist in knowledge,
    replace it with:

        "?"

    Return the resulting string.

    ============================================================
    EXAMPLE 1:

    Input:

        s = "(name)is(age)yearsold"

        knowledge = [
            ["name","bob"],
            ["age","two"]
        ]

    Output:

        "bobistwoyearsold"

    Explanation:

        (name) -> bob
        (age)  -> two

        Therefore:

        "(name)is(age)yearsold"

                    ↓

        "bobistwoyearsold"

    ============================================================
    EXAMPLE 2:

    Input:

        s = "hi(name)"

        knowledge = [
            ["a","b"]
        ]

    Output:

        "hi?"

    Explanation:

        The key "name" does not exist.

        Therefore:

            (name) -> ?

    Result:

        "hi?"

    ============================================================
    EXAMPLE 3:

    Input:

        s = "(a)(a)(a)"

        knowledge = [
            ["a","b"]
        ]

    Output:

        "bbb"

    Explanation:

        Every occurrence of (a) is replaced by "b".

    ============================================================
    KEY OBSERVATION:

    There are TWO separate tasks:

        1. Quickly find the value of a key.
        2. Detect the key inside brackets.

    ------------------------------------------------------------
    TASK 1: Store knowledge in a Hash Map

    Suppose:

        knowledge = [
            ["name","bob"],
            ["age","two"]
        ]

    Store:

        mp["name"] = "bob"
        mp["age"]  = "two"

    Now we can find any key in O(1) average time.

    ------------------------------------------------------------
    TASK 2: Parse the string

    Scan s from left to right.

    If current character is NOT '(':

        Add it directly to answer.

    If current character IS '(':

        Start collecting characters until ')'.

        Those characters form the key.

        Example:

            "(name)"

             ↑    ↑
             |    |
           start  end

        key = "name"

        Then look for "name" in the map.

    ============================================================
    APPROACH:

    STEP 1:

    Create:

        unordered_map<string, string> mp


    STEP 2:

    Insert every knowledge pair:

        mp[key] = value


    STEP 3:

    Initialize:

        string answer = ""


    STEP 4:

    Traverse the string using index i.

    ------------------------------------------------------------
    CASE 1:

        s[i] != '('

    Then this is a normal character.

    Add it:

        answer += s[i]

    Move:

        i++


    ------------------------------------------------------------
    CASE 2:

        s[i] == '('

    We found the beginning of a key.

    Move inside the brackets:

        i++

    Create:

        string key = ""


    Keep adding characters until:

        s[i] == ')'


    Now we have the complete key.

    ------------------------------------------------------------
    STEP 5:

    Search the key in the map.

    If found:

        answer += mp[key]

    Otherwise:

        answer += "?"

    ------------------------------------------------------------
    STEP 6:

    Skip the closing ')'
    and continue scanning.

    ============================================================
    DRY RUN:

    s = "(name)is(age)yearsold"

    knowledge:

        name -> bob
        age  -> two


    Hash Map:

        mp["name"] = "bob"
        mp["age"]  = "two"


    ------------------------------------------------------------
    i = 0

        s[i] = '('

        Start reading key.

        key = "name"


        Search:

            mp["name"]

        Found!

        Add:

            "bob"

        answer:

            "bob"


    ------------------------------------------------------------
    Next characters:

        "is"

    They are normal characters.

        answer:

            "bobis"


    ------------------------------------------------------------
    Next:

        "(age)"

    Extract:

        key = "age"


    Search:

        mp["age"]

    Found:

        "two"


    Add:

        "two"


    answer:

        "bobistwo"


    ------------------------------------------------------------
    Remaining:

        "yearsold"

    Add normally.

    Final:

        "bobistwoyearsold"

    ============================================================
    DRY RUN FOR UNKNOWN KEY:

    s = "hi(name)"

    knowledge:

        a -> b


    ------------------------------------------------------------
    Characters:

        h
        i

    Add:

        "hi"


    ------------------------------------------------------------
    Encounter:

        (name)

    Extract:

        key = "name"


    Search:

        mp.find("name")

    Not found.

    Therefore:

        answer += "?"


    Final:

        "hi?"

    ============================================================
    WHY USE unordered_map?

    We need to repeatedly ask:

        "Does this key exist?"

    and:

        "What value belongs to this key?"

    An unordered_map provides average:

        O(1)

    lookup time.

    Without a hash map, we would need to search the
    entire knowledge list for every key.

    That could be much slower.

    ============================================================
    IMPORTANT C++ CONCEPT:

    We use:

        mp.find(key)

    instead of:

        mp[key]

    for checking whether the key exists.

    Why?

    Because:

        mp[key]

    can create a new entry if the key doesn't exist.

    With:

        mp.find(key)

    we can safely check.

    Example:

        if (mp.find(key) != mp.end())

            // key exists

        else

            // key doesn't exist

    ============================================================
    POINTER / ITERATOR IDEA:

    This condition:

        mp.find(key) != mp.end()

    means:

        "The key was found."

    While:

        mp.find(key) == mp.end()

    means:

        "The key does not exist."

    ============================================================
    APPROACH SUMMARY:

    1. Store all knowledge pairs in unordered_map.

    2. Scan string from left to right.

    3. Normal character:
           Add directly.

    4. '(':
           Extract everything until ')'.

    5. Search extracted key.

    6. If found:
           Add corresponding value.

       Otherwise:
           Add '?'.

    7. Return answer.

    ============================================================
    WHY THIS WORKS:

    Every bracket pair represents exactly one key.

    We extract that key and look up its value.

    Every normal character is copied unchanged.

    Therefore, after processing the entire string,
    answer contains exactly the required transformed string.

    ============================================================
    COMPLEXITY:

    Let:

        n = length of s
        m = total size of knowledge strings

    Building the hash map:

        O(m) approximately


    Scanning s:

        O(n) approximately


    Hash-map lookup:

        O(1) average


    Total:

        O(n + m) average

    Space:

        O(m + n)

    The map stores the knowledge pairs,
    and answer stores the resulting string.

    ============================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        // ----------------------------------------------------
        // Step 1: Store knowledge in a hash map
        // ----------------------------------------------------

        unordered_map<string, string> mp;

        for (auto& pair : knowledge) {

            string key = pair[0];
            string value = pair[1];

            mp[key] = value;
        }


        // ----------------------------------------------------
        // Step 2: Build the answer
        // ----------------------------------------------------

        string answer = "";

        int i = 0;

        while (i < s.size()) {

            // ------------------------------------------------
            // Normal character
            // ------------------------------------------------

            if (s[i] != '(') {

                answer += s[i];

                i++;
            }

            // ------------------------------------------------
            // We found a bracket pair
            // ------------------------------------------------

            else {

                // Skip '('
                i++;

                string key = "";

                // Read characters until ')'
                while (s[i] != ')') {

                    key += s[i];

                    i++;
                }

                // ------------------------------------------------
                // Check whether key exists
                // ------------------------------------------------

                if (mp.find(key) != mp.end()) {

                    // Key exists
                    answer += mp[key];

                } else {

                    // Key does not exist
                    answer += "?";
                }

                // Skip ')'
                i++;
            }
        }

        return answer;
    }
};