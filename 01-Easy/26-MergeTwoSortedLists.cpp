/*
Problem: Merge Two Sorted Lists
Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
Difficulty: Easy
Topic: Linked List / Two Pointers

Problem Statement:
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list and return the head of the merged list.

Example:
Input:
list1 = [1,2,4]
list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Approach (Two Pointer Merge – Optimal):
1. Create a dummy node to simplify pointer operations.
2. Use two pointers p1 and p2 to traverse list1 and list2.
3. At each step, attach the smaller node to the merged list.
4. When one list becomes empty, attach the remaining list.
5. Return dummy->next as the merged head.

Time Complexity: O(n + m)
Space Complexity: O(1) — in-place merging
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        tail->next = list1 ? list1 : list2;

        return dummy->next;
    }
};