/*
Problem: Merge k Sorted Lists
Link: https://leetcode.com/problems/merge-k-sorted-lists/description/
Difficulty: Hard
Topic: Linked List / Divide & Conquer / Heap

Problem Statement:
You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example:
Input:
lists = [[1,4,5],[1,3,4],[2,6]]
Output:
[1,1,2,3,4,4,5,6]

Approach (Min-Heap / Priority Queue – Optimal):
1. Use a **min-heap** that always keeps the smallest current node among all lists.
2. Push the head of each non-empty list into the heap.
3. Repeatedly extract the smallest node and add it to the merged list.
4. If the extracted node has a next node, push it into the heap.
5. Continue until the heap is empty.

Why this works:
- The heap always gives the smallest available element.
- At most `k` elements are in the heap at any time.

Time Complexity: O(N log k), where N = total number of nodes  
Space Complexity: O(k)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap storing (node value, node pointer)
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Push heads of all non-empty lists
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();

            tail->next = cur;
            tail = tail->next;

            if (cur->next) {
                pq.push(cur->next);
            }
        }

        return dummy.next;
    }

private:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        }
    };
};