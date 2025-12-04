/*
Problem: Remove Duplicates from Sorted List
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
Difficulty: Easy
Topic: Linked List

Problem Statement:
Given the head of a sorted linked list, delete all duplicates such that each element
appears only once. Return the modified list.

Example:
Input:
head = [1,1,2,3,3]
Output: [1,2,3]

Approach (Iterative – Optimal):
1. Use a pointer curr starting at the head.
2. While curr is not null:
   - Compare curr->val with curr->next->val.
   - If equal, skip the next node (curr->next = curr->next->next).
   - Otherwise, move curr forward.
3. Return the head after removing all duplicates.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next; // Skip duplicate
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};