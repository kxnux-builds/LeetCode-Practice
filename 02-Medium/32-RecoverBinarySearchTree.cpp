/*
Problem: Recover Binary Search Tree
Link: https://leetcode.com/problems/recover-binary-search-tree/description/
Difficulty: Medium
Topic: Tree / DFS / Inorder Traversal / BST

Problem Statement:
You are given the root of a binary search tree (BST) where **two nodes have been
swapped by mistake**. Recover the tree *without changing its structure*, restoring
it to a valid BST.

Example:
Input: root = [1,3,null,null,2]  
Output: [3,1,null,null,2]

Approach (Inorder Traversal to Detect Anomalies – Optimal):
1. In a valid BST, inorder traversal yields sorted values.
2. Perform inorder traversal:
   - Track previous visited node (`prev`).
   - If current value < prev value → record anomaly.
   - First anomaly → mark `first` = prev, `second` = current.
   - Second anomaly → update `second` = current.
3. After traversal, swap the values of `first` and `second` to fix the BST.

Time Complexity: O(n)  
Space Complexity: O(h) — recursion stack (h = tree height)
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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        inorder(root, prev, first, second);
        if (first && second) {
            swap(first->val, second->val);
        }
    }

private:
    void inorder(TreeNode* node, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
        if (!node) return;

        inorder(node->left, prev, first, second);

        if (prev && prev->val > node->val) {
            if (!first) {
                first = prev;
            }
            second = node;
        }
        prev = node;

        inorder(node->right, prev, first, second);
    }
};