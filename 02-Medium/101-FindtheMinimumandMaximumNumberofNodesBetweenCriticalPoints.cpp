/*
Problem: Find the Minimum and Maximum Number of Nodes Between Critical Points
Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
Difficulty: Medium
Topic: Linked List / Two Pointers / Traversal

Problem Statement:
A critical point in a linked list is a node that is either:
- A local maximum
- A local minimum

A node is a local maximum if its value is strictly greater
than both its previous and next nodes.

A node is a local minimum if its value is strictly smaller
than both its previous and next nodes.

The first and last nodes cannot be critical points because
they do not have both a previous and next node.

Return:
[minDistance, maxDistance]

Where:
- minDistance = minimum distance between any two critical points.
- maxDistance = maximum distance between any two critical points.

If there are fewer than two critical points, return [-1, -1].

Example 1:
Input:
head = [5,3,1,2,5,1,2]

Output:
[1,3]

Explanation:

Critical points:
- 1 → local minimum
- 5 → local maximum
- 1 → local minimum

Their positions are:
2, 4, 5

Minimum distance:
5 - 4 = 1

Maximum distance:
5 - 2 = 3

Answer = [1,3]

Example 2:
Input:
head = [1,3,2,2,3,2,2,2,7]

Output:
[3,3]

Explanation:
There are two critical points.

Their positions:
1 and 4

Distance:
4 - 1 = 3

Therefore:
minDistance = 3
maxDistance = 3

--------------------------------------------------

Approach (Single Traversal – Optimal):

Key Insight:
We do not need to store all critical points.

We only need three pieces of information:

1. firstCritical
   → index of the first critical point.

2. lastCritical
   → index of the most recently found critical point.

3. minDistance
   → minimum distance between two consecutive
      critical points.

When we find a new critical point at index i:

Minimum distance:
    i - lastCritical

Maximum distance:
    i - firstCritical

This allows us to solve the problem in one traversal.

--------------------------------------------------

How to Identify a Critical Point:

For three consecutive nodes:

previous → current → next

Current is a critical point if:

Local Maximum:
current > previous && current > next

OR

Local Minimum:
current < previous && current < next

In short:

current > max(previous, next)

OR

current < min(previous, next)

--------------------------------------------------

Steps:
1. Start with:
      firstCritical = -1
      lastCritical = -1
      minDistance = INT_MAX

2. Traverse the linked list while current node
   has both previous and next nodes.

3. Check whether current is a critical point.

4. If it is the first critical point:
      firstCritical = index
      lastCritical = index

5. Otherwise:
      minDistance = min(
          minDistance,
          index - lastCritical
      )

      lastCritical = index

6. After traversal:
   If fewer than two critical points exist:
      return {-1, -1}

7. Otherwise:
      maxDistance = lastCritical - firstCritical

8. Return:
      {minDistance, maxDistance}

--------------------------------------------------

Dry Run:

Linked List:

5 → 3 → 1 → 2 → 5 → 1 → 2

Index:

0   1   2   3   4   5   6

Check index 1:
3 is not critical.

Check index 2:
1 < 3 and 1 < 2

So index 2 is a local minimum.

firstCritical = 2
lastCritical = 2

Check index 3:
2 is not critical.

Check index 4:
5 > 2 and 5 > 1

So index 4 is a local maximum.

Distance:
4 - 2 = 2

minDistance = 2
lastCritical = 4

Check index 5:
1 < 5 and 1 < 2

So index 5 is a local minimum.

Distance:
5 - 4 = 1

minDistance = 1
lastCritical = 5

Maximum distance:

5 - 2 = 3

Answer:

[1,3]

--------------------------------------------------

Why it works:
- Every node is checked exactly once.
- Only the previous, current, and next nodes
  are needed to identify a critical point.
- The distance between consecutive critical points
  gives the minimum distance.
- The distance between the first and last critical
  points gives the maximum distance.
- Therefore, there is no need to store all critical
  point positions.

--------------------------------------------------

Time Complexity: O(n)

- Every node is visited once.

Space Complexity: O(1)

- Only a few variables are maintained.

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int firstCritical = -1;
        int lastCritical = -1;

        int minDistance = INT_MAX;

        int index = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != NULL) {

            ListNode* nextNode = curr->next;

            // Check whether curr is a critical point
            bool isCritical =
                (curr->val > prev->val &&
                 curr->val > nextNode->val)
                ||
                (curr->val < prev->val &&
                 curr->val < nextNode->val);

            if (isCritical) {

                // First critical point
                if (firstCritical == -1) {

                    firstCritical = index;
                    lastCritical = index;
                }

                // Another critical point
                else {

                    // Minimum distance between
                    // consecutive critical points
                    minDistance = min(
                        minDistance,
                        index - lastCritical
                    );

                    lastCritical = index;
                }
            }

            prev = curr;
            curr = nextNode;
            index++;
        }

        // Fewer than two critical points
        if (firstCritical == lastCritical) {
            return {-1, -1};
        }

        // Distance between first and last
        // critical points
        int maxDistance =
            lastCritical - firstCritical;

        return {
            minDistance,
            maxDistance
        };
    }
};