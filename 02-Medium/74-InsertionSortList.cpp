/*
Problem: Insertion Sort List
Link: https://leetcode.com/problems/insertion-sort-list/description/
Difficulty: Medium
Topic: Linked List / Sorting

Problem Statement:
Given the `head` of a **singly linked list**, sort the list using **insertion sort**
and return the sorted list's head. :contentReference[oaicite:0]{index=0}

Insertion Sort Algorithm:
1. Insertion sort iterates through the list one element at a time.
2. Each element is removed from the input list.
3. It is inserted into the correct position in a **sorted part of the list**.
4. This continues until all elements are processed. :contentReference[oaicite:1]{index=1}

Example 1:
Input: head = [4,2,1,3]  
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]  
Output: [-1,0,3,4,5]

Constraints:
1 <= number of nodes <= 5000  
-5000 <= Node.val <= 5000 :contentReference[oaicite:2]{index=2}

--------------------------------------------------

Approach (Insertion Sort on Linked List – Optimal):

Key Idea:
We maintain a **sorted list** and insert each node from the original list
into its correct position.

Steps:
1. Create a **dummy node** to simplify insertion.
2. Traverse the original linked list.
3. For each node:
   - Find the correct place in the sorted list.
   - Insert the node there.
4. Continue until all nodes are processed.

Why Dummy Node?
It simplifies edge cases like inserting at the beginning.

--------------------------------------------------

Time Complexity: O(n²)  
Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;

        while (curr) {
            ListNode* prev = dummy;

            // Find correct insertion point
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            ListNode* nextNode = curr->next;

            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy->next;
    }
};