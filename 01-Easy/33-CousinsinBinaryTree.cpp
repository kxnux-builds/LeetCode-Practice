/*
Problem: Cousins in Binary Tree
Link: https://leetcode.com/problems/cousins-in-binary-tree/description/
Difficulty: Easy
Topic: Tree / Breadth-First Search / DFS

Problem Statement:
In a binary tree, the root node is at depth 0.
Two nodes of a binary tree are **cousins** if they have the same depth
but have different parents.

Given the root of a binary tree with unique values, and the values x and y of two
different nodes in the tree, return true if the nodes corresponding to the values
x and y are cousins, or false otherwise.

Example:
Input: root = [1,2,3,4], x = 4, y = 3  
Output: false  
Explanation: Node 4 is depth 2, node 3 is depth 1.

Approach (BFS – Level Order Traversal with Parent Tracking):
1. Use a queue to perform BFS.
2. For each level:
   - Track parent and depth for x and y when found.
   - If both found at same level with different parents → true.
   - If one found but not the other at this level → false.
3. Continue until queue empties.
4. If not both found → false.

Time Complexity: O(n)  
Space Complexity: O(n) (queue)
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            bool foundX = false, foundY = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();

                if (node->val == x) foundX = true;
                if (node->val == y) foundY = true;

                if (node->left && node->right) {
                    int leftVal = node->left->val;
                    int rightVal = node->right->val;
                    // same parent → not cousins
                    if ((leftVal == x && rightVal == y) ||
                        (leftVal == y && rightVal == x)) {
                        return false;
                    }
                }

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (foundX && foundY) return true;
            if (foundX || foundY) return false;
        }

        return false;
    }
};