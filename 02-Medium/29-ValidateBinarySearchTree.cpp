/*
Problem: Validate Binary Search Tree
Link: https://leetcode.com/problems/validate-binary-search-tree/description/
Difficulty: Medium
Topic: Tree / DFS / Recursion / BST Properties

Problem Statement:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A **valid BST** is defined as:
- The left subtree of a node contains only nodes with keys **less than** the node’s key.
- The right subtree of a node contains only nodes with keys **greater than** the node’s key.
- Both left and right subtrees must also be valid BSTs.

Example:
Input: root = [2,1,3]
Output: true

Example:
Input: root = [5,1,4,null,null,3,6]
Output: false

Approach (DFS with Range Limits — Optimal):
1. Use recursion with `min` and `max` boundaries.
2. At each node:
   - Its value must be **strictly greater** than min bound.
   - Its value must be **strictly less** than max bound.
3. Propagate updated bounds:
   - Left child’s max → current node value
   - Right child’s min → current node value
4. If any node violates its bounds → false.
5. If entire tree satisfies BST properties → true.

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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

private:
    bool dfs(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;

        if (node->val <= minVal || node->val >= maxVal)
            return false;

        return dfs(node->left, minVal, node->val)
            && dfs(node->right, node->val, maxVal);
    }
};