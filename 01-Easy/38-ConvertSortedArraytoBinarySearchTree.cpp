/*
Problem: Convert Sorted Array to Binary Search Tree
Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
Difficulty: Easy
Topic: Tree / Recursion / Divide & Conquer

Problem Statement:
Given an integer array `nums` where the elements are sorted in **ascending order**, 
convert it to a **height-balanced binary search tree (BST)**.

A height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of *every* node never differs by more than one.

Example:
Input: nums = [-10,-3,0,5,9]  
Output: [0,-3,9,-10,null,5]  (one valid BST)

Approach (Divide & Conquer – Optimal):
1. Use recursion to pick the middle element of the current subarray as the root:
   - mid = (left + right) / 2
2. Recursively build:
   - left subtree from left → mid-1
   - right subtree from mid+1 → right
3. This ensures a balanced BST because halves are split evenly.

Time Complexity: O(n)  
Space Complexity: O(h) — recursion stack (h = tree height, ~log n)
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;

        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left  = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);

        return root;
    }
};