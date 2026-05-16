/*
Problem: Reverse Nodes in k-Group
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/
Difficulty: Hard
Topic: Linked List / Recursion

Problem Statement:
Given the head of a linked list, reverse the nodes of the list k at a time,
and return the modified list.

- k is a positive integer.
- If the number of nodes is not a multiple of k, then left-out nodes
  at the end should remain as they are.
- You may not alter the values in the nodes, only nodes themselves
  may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Constraints:
- The number of nodes in the list is n.
- 1 <= k <= n <= 5000
- 0 <= Node.val <= 1000

--------------------------------------------------

Approach (Iterative Reversal – Optimal):

Key Idea:
Reverse the linked list in groups of size k.

Steps:
1. Check whether there are at least k nodes available.
   - If not, return remaining list as it is.
2. Reverse exactly k nodes.
3. Recursively/process the remaining list.
4. Connect the reversed part with the result of next groups.

Why it works:
- Every group of k nodes is reversed independently.
- Remaining nodes (< k) stay unchanged.
- Each node is visited only once.

--------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1) iterative approach
(Recursive version uses O(n/k) recursion stack)

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if at least k nodes exist
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head;
            temp = temp->next;
        }

        // Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;

        int count = 0;

        while (curr && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        // Recursively reverse remaining groups
        if (nextNode) {
            head->next = reverseKGroup(nextNode, k);
        }

        // prev becomes new head after reversal
        return prev;
    }
};