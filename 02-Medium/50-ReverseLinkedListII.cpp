/*
Problem: Reverse Linked List II
Link: https://leetcode.com/problems/reverse-linked-list-ii/description/
Difficulty: Medium
Topic: Linked List / Two Pointers / In-Place Reversal

Problem Statement:
Given the head of a singly linked list and two integers `left` and `right`
(1-indexed), reverse the nodes of the list from position `left` to position `right`,
and return the *modified list*.

Example:
Input: head = [1,2,3,4,5], left = 2, right = 4  
Output: [1,4,3,2,5]  
Explanation: Only sublist from position 2 to 4 is reversed.

Approach (Iterative In-Place Reversal):
1. Create a dummy node before the head to simplify edge cases.
2. Traverse to the node **just before** the `left`-th node (`prev`).
3. Reverse the sublist from `left` to `right` using standard pointer reversal:
   - For each node in the range, take it out and insert it after `prev`.
4. Reconnect the reversed sublist back to the rest of the list.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

/* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Move prev to the node before "left"
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // Now prev->next is the start of the sublist to reverse
        ListNode* curr = prev->next;

        // Step 2: Reverse sublist [left, right]
        for (int i = 0; i < right - left; ++i) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};