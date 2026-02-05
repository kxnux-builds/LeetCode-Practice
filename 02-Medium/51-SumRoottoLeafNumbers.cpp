/*
Problem: Sum Root to Leaf Numbers
Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
Difficulty: Medium
Topic: Tree / DFS / Recursion

Problem Statement:
You are given the root of a binary tree where each node contains a digit from 0 to 9.  
Each root-to-leaf path represents a number formed by concatenating the digits along the path.

Return *the total sum* of all the numbers formed by every root-to-leaf path.

Example:
Input:
      1
     / \
    2   3
Output: 25  
Explanation:
Root-to-leaf paths:
 1→2 = 12  
 1→3 = 13  
Sum = 12 + 13 = 25

Approach (DFS – Passing Current Number):
1. Traverse the tree using DFS.
2. Maintain a running value for the current path number.
   - For each node, update: `current = current * 10 + node->val`.
3. When a leaf node is reached → add `current` to the total sum.
4. Return the accumulated sum.

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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;

        current = current * 10 + node->val;

        // If leaf node, return number represented by this path
        if (!node->left && !node->right) {
            return current;
        }

        // Recurse on children
        return dfs(node->left, current) + dfs(node->right, current);
    }
};