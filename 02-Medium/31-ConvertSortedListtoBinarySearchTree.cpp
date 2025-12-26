/*
Problem: Convert Sorted List to Binary Search Tree
Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
Difficulty: Medium
Topic: Linked List / Tree / Recursion / Two Pointers

Problem Statement:
Given the head of a **sorted singly-linked list** where elements are in ascending
order, convert it to a **height-balanced binary search tree (BST)**.

A height-balanced binary tree is defined as a binary tree in which the depth of
the two subtrees of every node never differs by more than one.

Example:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]

Approach (In-Order Simulation – Optimal):
1. Count the length of the linked list.
2. Use recursion to simulate in-order traversal:
   - Recursively build left subtree with half of the nodes.
   - Use the current list node as the tree root.
   - Move the list pointer forward.
   - Recursively build right subtree.
3. The sorted order of the list ensures BST property.
4. This uses only forward list traversal.

Time Complexity: O(n)  
Space Complexity: O(h) — recursion stack (h ≈ log n)
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

/* Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        return build(head, 0, n - 1);
    }

private:
    int getLength(ListNode* head) {
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        return count;
    }

    TreeNode* build(ListNode*& head, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        
        // Build left subtree
        TreeNode* leftChild = build(head, left, mid - 1);

        // Current root
        TreeNode* root = new TreeNode(head->val);
        head = head->next;

        // Build right subtree
        root->right = build(head, mid + 1, right);
        root->left  = leftChild;

        return root;
    }
};