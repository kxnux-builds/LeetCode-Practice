/*
Problem: Flatten a Multilevel Doubly Linked List
Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
Difficulty: Medium
Topic: Linked List / Depth-First Search / Stack

Problem Statement:
You are given a **multilevel doubly linked list** where in addition to
the `next` and `prev` pointers, a node may have a `child` pointer
that may point to a separate doubly linked list (possibly with its own children).

Flatten the list so that all the nodes appear in a single-level,
doubly linked list. The child lists should be inserted between the node
and its next node. After flattening, all `child` pointers should be set to `nullptr`.

Example:
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]  
Output: [1,2,3,7,8,11,12,9,10,4,5,6]

Explanation: The child list starting at 7 is inserted between 3 and 4,
and child of 8 heading to [11,12] is inserted between 8 and 9.

Approach (DFS + Stack – Optimal):
1. Use a stack to track following nodes when traversing child lists.
2. Start from the head and process nodes sequentially:
   – If the current node has a `child`:
     • If `next` exists, push it to stack (to reconnect later).
     • Connect the current’s `child` as `next`, and set `child->prev`.
     • Set current’s `child` to `nullptr`.
   – If there is no next and the stack is not empty:
     • Pop from stack and attach as `next` with correct `prev`.
3. Continue until all nodes are processed.
4. Return the flattened head.

Time Complexity: O(n) — each node visited once  
Space Complexity: O(n) — due to stack in worst case
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node in multilevel doubly linked list.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    
    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        
        stack<Node*> st;
        Node* curr = head;
        
        while (curr) {
            // If there's a child, process it
            if (curr->child) {
                // If next exists, push to stack
                if (curr->next) {
                    st.push(curr->next);
                }
                
                // Connect child as next
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
            }
            
            // If no next but still nodes in stack
            if (!curr->next && !st.empty()) {
                Node* topNode = st.top();
                st.pop();
                curr->next = topNode;
                topNode->prev = curr;
            }
            
            curr = curr->next;
        }
        
        return head;
    }
};