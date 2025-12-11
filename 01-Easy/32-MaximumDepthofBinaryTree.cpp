/*
Problem: Maximum Depth of Binary Tree
Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
Difficulty: Easy
Topic: Tree / Depth-First Search / Recursion

Problem Statement:
Given the root of a binary tree, return its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Approach (Recursion – Optimal):
1. If the current node is null, return 0.
2. Recursively compute the depth of left subtree.
3. Recursively compute the depth of right subtree.
4. Return the greater of the two depths plus 1 (for current node).

Time Complexity: O(n) — visit each node once  
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth  = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }
};