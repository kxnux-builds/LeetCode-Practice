/*
Problem: Maximum Sum BST in Binary Tree
Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
Difficulty: Hard
Topic: Tree / DFS / BST / Recursion

Problem Statement:
Given the `root` of a binary tree, return the **maximum sum** of all values of any subtree of this tree that is also a valid Binary Search Tree (BST).

A subtree is a BST if:
- The left subtree contains only nodes with keys *less than* the current node’s value.
- The right subtree contains only nodes with keys *greater than* the current node’s value.
- Both left and right subtrees must themselves be valid BSTs.

Example:
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]  
Output: 20  
Explanation: The subtree rooted at 3 is a BST with sum 20.

Approach (Post-order DFS with BST Validation & Accumulation):
1. Define a helper that returns for each subtree:
   - `isBST`: whether the subtree is a valid BST.
   - `minVal`: minimum value in this subtree.
   - `maxVal`: maximum value in this subtree.
   - `sum`: sum of all nodes in this subtree.
2. For null nodes → treat as BST with min = +∞, max = −∞, sum = 0.
3. For each node:
   - Recurse left and right.
   - If left and right are BSTs **and** `left.maxVal < node->val < right.minVal`:
       - This subtree is BST, compute its sum and update global max.
       - Return updated stats up the recursion.
   - Otherwise → mark subtree invalid (not BST).
4. Finally return the global maximum sum (non-BST subtrees contribute 0).

Time Complexity: O(n) — each node visited once  
Space Complexity: O(h) — recursion stack (h = tree height) :contentReference[oaicite:0]{index=0}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        dfs(root);
        return maxSum;
    }

private:
    int maxSum;

    struct Info {
        bool isBST;
        long minVal;
        long maxVal;
        long sum;
    };

    Info dfs(TreeNode* node) {
        if (!node) {
            return {true, LONG_MAX, LONG_MIN, 0};
        }

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        Info curr;
        // Check if current subtree is BST
        if (left.isBST && right.isBST &&
            left.maxVal < node->val && node->val < right.minVal) {
            curr.isBST = true;
            curr.sum = left.sum + right.sum + node->val;
            // Update global maximum
            maxSum = max(maxSum, (int)curr.sum);

            curr.minVal = min(left.minVal, (long)node->val);
            curr.maxVal = max(right.maxVal, (long)node->val);
        } else {
            curr.isBST = false;
            // Values don’t matter when not BST
            curr.sum = 0;
            curr.minVal = LONG_MAX;
            curr.maxVal = LONG_MIN;
        }

        return curr;
    }
};