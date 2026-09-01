/*
Problem: Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence/description/
Difficulty: Medium
Topic: Array / Hashing / Hash Set

Problem Statement:
Given an unsorted array of integers nums,
return the length of the longest consecutive
elements sequence.

A consecutive sequence means:
- Each number is exactly 1 greater than the previous number.
- The elements do NOT need to be next to each other
  in the original array.

The solution must run in O(n) time.

Example 1:
Input:
nums = [100,4,200,1,3,2]

Output:
4

Explanation:
The longest consecutive sequence is:

[1,2,3,4]

Length = 4

Example 2:
Input:
nums = [0,3,7,2,5,8,4,6,0,1]

Output:
9

Explanation:
The longest consecutive sequence is:

[0,1,2,3,4,5,6,7,8]

Length = 9

Example 3:
Input:
nums = [1,0,1,2]

Output:
3

Explanation:
The longest consecutive sequence is:

[0,1,2]

Length = 3

Duplicate values do not increase the length.

--------------------------------------------------

Approach (Hash Set – Optimal):

Key Insight:
We need to quickly check whether a number exists.

An unordered_set gives average O(1) lookup.

But there is one important optimization:

Only start building a sequence if:

    num - 1 does NOT exist

Why?

If num - 1 exists, then num is not the beginning
of a consecutive sequence.

For example:

[1,2,3,4]

Only 1 is the starting point.

2 has 1 before it.
3 has 2 before it.
4 has 3 before it.

So we only start counting from 1.

--------------------------------------------------

Steps:
1. Put every number into an unordered_set.
2. Initialize:
      longest = 0
3. Traverse every number in the set.
4. Check:
      if (num - 1) does not exist
   then num is the beginning of a sequence.
5. Start counting:
      num + 1
      num + 2
      num + 3
      ...
6. Stop when the next number does not exist.
7. Update:
      longest = max(longest, currentLength)
8. Return longest.

--------------------------------------------------

Dry Run:

nums = [100,4,200,1,3,2]

Set:
{100,4,200,1,3,2}

Check 100:
99 does not exist.

100 is a sequence start.

100 → 101 not found

Length = 1

longest = 1


Check 4:
3 exists.

So 4 is NOT a sequence start.
Skip it.


Check 200:
199 does not exist.

200 → 201 not found

Length = 1


Check 1:
0 does not exist.

1 is a sequence start.

1 → 2 → 3 → 4

Length = 4

longest = 4


Check 3:
2 exists.

Skip.


Check 2:
1 exists.

Skip.

Final Answer = 4

--------------------------------------------------

Why it works:
- Every number is stored in the Hash Set.
- We only start counting from the beginning
  of a sequence.
- This prevents repeatedly counting the same
  sequence.
- Every number is involved in the consecutive
  expansion at most once in the overall process.

Therefore, the solution runs in O(n) average time.

--------------------------------------------------

Important Pattern:

For consecutive sequence problems:

1. Use Hash Set.
2. Find the START of a sequence:

      num - 1 not present

3. Expand forward:

      num + 1
      num + 2
      num + 3
      ...

This is a very important DSA pattern.

--------------------------------------------------

Time Complexity: O(n)

- Building the Hash Set: O(n)
- Checking sequence starts: O(n)
- Each consecutive element is processed
  efficiently using O(1) average lookup.

Overall: O(n) average.

Space Complexity: O(n)

- Hash Set stores the elements.

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Store all numbers for O(1) average lookup
        unordered_set<int> st(
            nums.begin(),
            nums.end()
        );

        int longest = 0;

        // Traverse every unique number
        for (int num : st) {

            // Check if num is the start
            // of a consecutive sequence
            if (st.find(num - 1) == st.end()) {

                int currentNum = num;
                int currentLength = 1;

                // Expand the sequence
                while (st.find(currentNum + 1) != st.end()) {

                    currentNum++;
                    currentLength++;
                }

                // Update longest sequence
                longest = max(
                    longest,
                    currentLength
                );
            }
        }

        return longest;
    }
};