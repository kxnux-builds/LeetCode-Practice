/*
Problem: Binary Tree Zigzag Level Order Traversal
Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
Difficulty: Medium
Topic: Tree / Breadth-First Search / Queue / Zigzag Traversal

Problem Statement:
Given the root of a binary tree, return the *zigzag level order* traversal of its nodes’ values.  
(i.e., from left to right, then right to left for the next level and alternate).

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
  [20,9],
  [15,7]
]

Approach (BFS with Alternating Order):
1. If the root is null, return an empty vector.
2. Use a queue to perform BFS level by level.
3. Keep a boolean `leftToRight` to track direction.
4. For each level:
   - Traverse all nodes at the current level (`size = q.size()`).
   - Store values in a temporary vector.
   - If direction is right→left, reverse the level’s values.
   - Append this vector to result.
   - Toggle `leftToRight`.

Time Complexity: O(n) — each node visited once  
Space Complexity: O(n) — queue + result storage
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();

                // Determine position based on direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // After each level, flip direction
            leftToRight = !leftToRight;
            result.push_back(level);
        }

        return result;
    }
};