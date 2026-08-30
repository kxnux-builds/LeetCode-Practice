/*
Problem: Removing Minimum and Maximum From Array
Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/
Difficulty: Medium
Topic: Array / Greedy

Problem Statement:
You are given a 0-indexed array of distinct integers nums.

There is one minimum element and one maximum element
in the array.

You need to remove both the minimum and maximum elements.

A deletion can only be performed from:
- The front of the array
- The back of the array

Return the minimum number of deletions required.

Example 1:
Input:
nums = [2,10,7,5,4,1,8,6]

Output:
5

Explanation:
Minimum = 1, index = 5
Maximum = 10, index = 1

We can remove:
- 2 elements from the front
- 3 elements from the back

Total = 5

Example 2:
Input:
nums = [0,-4,19,1,8,-2,-3,5]

Output:
3

Explanation:
Minimum = -4, index = 1
Maximum = 19, index = 2

Remove the first 3 elements.

Total = 3

Example 3:
Input:
nums = [101]

Output:
1

Explanation:
The only element is both minimum and maximum.
One deletion is enough.

--------------------------------------------------

Approach (Greedy + Index Calculation – Optimal):

Key Insight:
First find the positions of the minimum and maximum.

Let:
- left = smaller index
- right = larger index

There are only 3 possible strategies:

1. Remove both from the front.
2. Remove both from the back.
3. Remove one from the front and one from the back.

Calculate all three and take the minimum.

--------------------------------------------------

Case 1: Both From Front

To remove the element at index right,
we must remove everything from index 0 to right.

Deletions:

right + 1

--------------------------------------------------

Case 2: Both From Back

To remove the element at index left,
we must remove everything from left to the end.

Deletions:

n - left

--------------------------------------------------

Case 3: One From Front + One From Back

Remove the smaller-index element from the front
and the larger-index element from the back.

Deletions:

(left + 1) + (n - right)

--------------------------------------------------

Steps:
1. Find the index of the minimum element.
2. Find the index of the maximum element.
3. Make sure:
      left < right
4. Calculate:
      fromFront = right + 1
      fromBack = n - left
      fromBoth = left + 1 + n - right
5. Return the minimum of these three values.

--------------------------------------------------

Dry Run:

nums = [2,10,7,5,4,1,8,6]

n = 8

Minimum = 1
minIndex = 5

Maximum = 10
maxIndex = 1

After ordering the indices:

left = 1
right = 5

Case 1:
Both from front

right + 1
= 5 + 1
= 6

Case 2:
Both from back

n - left
= 8 - 1
= 7

Case 3:
One from front + one from back

left + 1 + n - right
= 1 + 1 + 8 - 5
= 5

Answer:

min(6, 7, 5) = 5

--------------------------------------------------

Why it works:
- We can only delete elements from the two ends.
- Once the positions of minimum and maximum are known,
  there are only three optimal strategies to consider.
- We calculate the number of deletions for each strategy.
- The smallest value is therefore the minimum possible
  number of deletions.

--------------------------------------------------

Time Complexity: O(n)

- One traversal is enough to find the minimum
  and maximum positions.

Space Complexity: O(1)

- Only a few variables are used.

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find minimum and maximum indices
        for (int i = 0; i < n; i++) {

            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Make minIndex the smaller index
        if (minIndex > maxIndex) {
            swap(minIndex, maxIndex);
        }

        // Case 1: Remove both from the front
        int fromFront = maxIndex + 1;

        // Case 2: Remove both from the back
        int fromBack = n - minIndex;

        // Case 3: Remove one from each side
        int fromBoth = minIndex + 1 + n - maxIndex;

        return min({
            fromFront,
            fromBack,
            fromBoth
        });
    }
};