/*
Problem: Binary Tree Level Order Traversal
Link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/
Difficulty: Medium
Topic: Tree / Breadth-First Search / Queue

Problem Statement:
Given the root of a binary tree, return the level order traversal of its nodes' values.  
(i.e., from left to right, level by level).

Example:
Input:
    3
   / \
  9  20
     / \
    15  7

Output:
[
  [3],
  [9,20],
  [15,7]
]

Approach (BFS using Queue – Optimal):
1. If root is null → return empty vector.
2. Initialize a queue and push the root.
3. While queue is not empty:
     - Let size = queue.size() (number of nodes at current level).
     - Initialize a vector to store this level’s values.
     - For i in [0..size):
         - Pop front node.
         - Add node->val to level’s vector.
         - If left child exists → push to queue.
         - If right child exists → push to queue.
     - Append level vector to result.
4. Return result.

Time Complexity: O(n) — each node visited once  
Space Complexity: O(n) — queue storage + result storage  
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            level.reserve(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
        }

        return result;
    }
};