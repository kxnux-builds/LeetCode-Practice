/*
Problem: Sort List
Link: https://leetcode.com/problems/sort-list/description/
Difficulty: Medium
Topic: Linked List / Divide & Conquer / Merge Sort

Problem Statement:
Given the head of a linked list, return the list after sorting it in **ascending order**.
You must sort the list **in O(n log n)** time and use **constant extra space** (no copying to an array).

Example:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Approach (Merge Sort on Linked List – Optimal):
1. Find the middle of the list using slow and fast pointers.
2. Split the list into two halves.
3. Recursively sort each half.
4. Merge the two sorted halves.

Time Complexity: O(n log n)  
Space Complexity: O(log n) recursion stack
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // 1. Split list into two halves
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;

        // 2. Recursively sort both halves
        left  = sortList(left);
        right = sortList(right);

        // 3. Merge sorted lists
        return merge(left, right);
    }

private:
    // Find midpoint (slow/fast)
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = (l1 ? l1 : l2);
        return dummy.next;
    }
};