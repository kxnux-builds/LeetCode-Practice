/*
Problem: Remove Invalid Parentheses
Link: https://leetcode.com/problems/remove-invalid-parentheses/description/
Difficulty: Hard
Topic: String / Backtracking / DFS

Problem Statement:
Given a string `s` containing parentheses and lowercase English
letters, remove the minimum number of invalid parentheses to
make the input string valid.

Return all possible results.

The answer can be returned in any order.

Example 1:
Input: s = "()())()"

Output: ["(())()", "()()()"]

Explanation:
Removing one ')' produces "(())()".
Removing the other extra ')' produces "()()()".

Both results are valid and require removing only one parenthesis.

Example 2:
Input: s = "(a)())()"

Output: ["(a())()", "(a)()()"]

Explanation:
We remove one invalid closing parenthesis.
The letters must remain in their original order.

Example 3:
Input: s = ")("

Output: [""]

Explanation:
Both parentheses are invalid, so we remove both.
The resulting string is empty.

Approach (Backtracking + DFS):
1. Count the minimum number of opening and closing parentheses
   that must be removed.

   - `leftRemove`: unmatched opening parentheses that must go.
   - `rightRemove`: unmatched closing parentheses that must go.

2. Use DFS to explore the possible choices:
   - Keep the current character.
   - If it is a parenthesis and removals are still needed,
     try removing it.

3. Track the number of opening and closing parentheses kept:
   - `leftCount`: opening parentheses kept.
   - `rightCount`: closing parentheses kept.

4. A closing parenthesis can be kept only when:
       rightCount < leftCount

   This prevents an invalid prefix such as ")(".

5. When the entire string has been processed:
   - Accept the result only if both removal counts are zero.
   - Store valid results in an unordered_set to avoid duplicates.

6. Convert the set into a vector and return it.

Time Complexity:
Exponential in the worst case; commonly expressed as O(n * 2^n),
where n is the length of the string.

Space Complexity:
O(n) auxiliary recursion depth, excluding the space required
to store all valid results.

Note:
The problem can have exponentially many candidate strings and
outputs, so its total time and space usage can also be exponential.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> resultSet;

    void dfs(string& s, int index, int leftCount, int rightCount,
             int leftRemove, int rightRemove, string current) {

        // Processed the entire string
        if (index == s.size()) {

            // Accept only if all required removals were used
            if (leftRemove == 0 && rightRemove == 0) {
                resultSet.insert(current);
            }

            return;
        }

        char c = s[index];

        // Option 1: Remove the current opening parenthesis
        if (c == '(' && leftRemove > 0) {
            dfs(s, index + 1, leftCount, rightCount,
                leftRemove - 1, rightRemove, current);
        }

        // Option 2: Remove the current closing parenthesis
        if (c == ')' && rightRemove > 0) {
            dfs(s, index + 1, leftCount, rightCount,
                leftRemove, rightRemove - 1, current);
        }

        // Option 3: Keep the current character
        if (c != '(' && c != ')') {
            current.push_back(c);

            dfs(s, index + 1, leftCount, rightCount,
                leftRemove, rightRemove, current);
        }
        else if (c == '(') {
            current.push_back(c);

            dfs(s, index + 1, leftCount + 1, rightCount,
                leftRemove, rightRemove, current);
        }
        else if (c == ')' && rightCount < leftCount) {
            current.push_back(c);

            dfs(s, index + 1, leftCount, rightCount + 1,
                leftRemove, rightRemove, current);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;

        // Calculate the minimum removals required
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        // Explore all valid choices with the minimum removals
        dfs(s, 0, 0, 0, leftRemove, rightRemove, "");

        // Convert the set of unique results into a vector
        vector<string> answer(resultSet.begin(), resultSet.end());

        return answer;
    }
};