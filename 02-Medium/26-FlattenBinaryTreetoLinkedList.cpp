/*
Problem: Flatten Binary Tree to Linked List
Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
Difficulty: Medium
Topic: Binary Tree / DFS / Recursion

Problem Statement:
Given the root of a binary tree, flatten the tree into a linked list in-place.
The linked list should follow the same order as a preorder traversal.
After flattening:
- Left child of every node should be NULL
- Right child points to the next node in preorder sequence

Approach:
1. Use a recursive DFS approach.
2. Recursively flatten the left and right subtrees.
3. If a left subtree exists:
   - Store the right subtree temporarily.
   - Move the left subtree to the right.
   - Set left child to NULL.
   - Attach the previously stored right subtree to the end of the new right subtree.
4. Return the tail node of the flattened subtree to help connect nodes properly.

Time Complexity: O(n)
- Each node is visited once.

Space Complexity: O(h)
- Recursive call stack where h is the height of the tree.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* flattenTree(TreeNode* root) {
        if (!root) return NULL;

        TreeNode* leftTail = flattenTree(root->left);
        TreeNode* rightTail = flattenTree(root->right);

        if (root->left) {
            TreeNode* tempRight = root->right;
            root->right = root->left;
            root->left = NULL;

            leftTail->right = tempRight;
        }

        if (rightTail) return rightTail;
        if (leftTail) return leftTail;
        return root;
    }

    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};