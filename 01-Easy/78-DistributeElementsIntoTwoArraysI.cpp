/*
Problem: Distribute Elements Into Two Arrays I
Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/
Difficulty: Easy
Topic: Array / Simulation

Problem Statement:
You are given a 1-indexed array nums of distinct integers.

You need to distribute the elements of nums into two arrays:
- arr1
- arr2

Rules:
1. Put nums[0] into arr1.
2. Put nums[1] into arr2.
3. For every remaining element nums[i]:
   - If the last element of arr1 is greater than
     the last element of arr2, put nums[i] into arr1.
   - Otherwise, put nums[i] into arr2.
4. Finally, concatenate arr1 followed by arr2.

Return the resulting array.

Example 1:
Input:
nums = [2,1,3]

Output:
[2,3,1]

Explanation:
arr1 = [2]
arr2 = [1]

For 3:
last(arr1) = 2
last(arr2) = 1

2 > 1, so 3 goes into arr1.

arr1 = [2,3]
arr2 = [1]

Result = [2,3,1]

Example 2:
Input:
nums = [5,4,3,8]

Output:
[5,3,4,8]

Explanation:
arr1 = [5]
arr2 = [4]

3:
5 > 4 → arr1

arr1 = [5,3]
arr2 = [4]

8:
3 > 4 is false → arr2

arr1 = [5,3]
arr2 = [4,8]

Result = [5,3,4,8]

--------------------------------------------------

Approach (Simulation – Optimal):

Key Insight:
We simply follow the given rules exactly.

Maintain two arrays:
- arr1
- arr2

For every element starting from index 2:
- Compare the last elements of arr1 and arr2.
- Put the current element into the appropriate array.

Finally:
answer = arr1 + arr2

--------------------------------------------------

Steps:
1. Create arr1 and arr2.
2. Put nums[0] into arr1.
3. Put nums[1] into arr2.
4. Traverse nums from index 2.
5. Compare:
      arr1.back() > arr2.back()
6. If true:
      push nums[i] into arr1
7. Otherwise:
      push nums[i] into arr2
8. Concatenate arr2 after arr1.
9. Return the result.

--------------------------------------------------

Dry Run:

nums = [5,4,3,8]

Initial:
arr1 = [5]
arr2 = [4]

i = 2:
nums[i] = 3

5 > 4 → true

arr1 = [5,3]

i = 3:
nums[i] = 8

3 > 4 → false

arr2 = [4,8]

Final:
arr1 = [5,3]
arr2 = [4,8]

Answer:
[5,3,4,8]

--------------------------------------------------

Why it works:
- The problem gives an exact rule for distributing
  every element.
- We simulate that rule from left to right.
- Comparing the last elements ensures that each
  element is placed exactly where required.
- Finally, concatenating arr1 and arr2 gives
  the required result.

--------------------------------------------------

Time Complexity: O(n)

- Every element is processed once.
- Concatenating the arrays also takes O(n).

Space Complexity: O(n)

- Two arrays and the final result are required.

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {

            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        // Concatenate arr2 after arr1
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};