/*
Problem: Construct Binary Search Tree from Preorder Traversal
Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
Difficulty: Medium
Topic: Tree / Recursion / BST / Divide and Conquer

Problem Statement:
Given an array of integers `preorder`, where `preorder` is the preorder traversal of a BST (binary search tree),
construct the BST and return its root.

Example:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Explanation:
The first element is the root. All subsequent elements smaller than root go to the left subtree,
and all larger elements go to the right subtree, while maintaining BST properties.

Approach (Recursion with Value Bounds – Optimal):
1. Use a global index pointing into the preorder array.
2. Define a recursive helper with a bound (`upper`) limiting values:
   - If the current value > `upper` or index == n → return nullptr.
3. Create a node with current value.
4. Recurse to build left child with bound = current value.
5. Recurse to build right child with bound = previous `upper` bound.
6. Return constructed subtree.

Time Complexity: O(n)  
Space Complexity: O(n) — recursion stack + tree nodes
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx = 0;
        return build(preorder, INT_MAX);
    }

private:
    int idx;

    TreeNode* build(const vector<int>& preorder, int upper) {
        if (idx == preorder.size() || preorder[idx] > upper)
            return nullptr;

        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);

        root->left = build(preorder, val);
        root->right = build(preorder, upper);

        return root;
    }
};