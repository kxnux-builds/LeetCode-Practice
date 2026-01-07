/*
Problem: Maximum Product of Splitted Binary Tree
Link: https://leetcode.com/problems/maximum-product-of-binary-tree/description/
Difficulty: Medium
Topic: Tree / DFS / Recursion / Product / Modulo

Problem Statement:
Given the root of a binary tree, split the tree into two subtrees by removing **exactly one edge**
such that the **product** of the sums of the resulting two subtrees is maximized.

Return the maximum product of their sums.  
Since the answer may be large, return it **modulo 10^9 + 7**.  
**Important:** maximize the product first, then take modulo.

Example:
Input: root = [1,2,3,4,5,6]  
Output: 110  
Explanation:
Removing the edge connecting node 3 and its parent splits the tree into:
Subtree1 sum = 11, Subtree2 sum = 10 → product = 11 × 10 = 110.

Approach (Two-Pass DFS – Optimal):
1. Do a first DFS to compute the **total sum** of the entire tree.
2. Do a second DFS to compute subtree sums:
   - For each subtree with sum `t`, the other part has sum `totalSum − t`.
   - Update the maximum product: `maxProduct = max(maxProduct, t × (totalSum − t))`.
3. Return `maxProduct % MOD` after DFS.

Key Insight:
- Removing an edge at any node essentially splits between that node’s subtree and its complement.
- The product of subtree sums can be computed in **O(n)** by tracking subtree sums during a DFS. :contentReference[oaicite:0]{index=0}

Time Complexity: O(n)  
Space Complexity: O(h) — recursion stack (h = tree height)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(TreeNode* root) {
        const long long MOD = 1000000007LL;
        // 1) Compute total sum of tree
        totalSum = dfsSum(root);

        // 2) Compute max product using subtree sums
        dfsMax(root);

        return (int)(maxProd % MOD);
    }

private:
    long long totalSum = 0;
    long long maxProd = 0;

    // DFS to compute total sum
    long long dfsSum(TreeNode* node) {
        if (!node) return 0;
        long long leftSum  = dfsSum(node->left);
        long long rightSum = dfsSum(node->right);
        return node->val + leftSum + rightSum;
    }

    // DFS to calculate subtree sums and update max product
    long long dfsMax(TreeNode* node) {
        if (!node) return 0;
        long long leftSum  = dfsMax(node->left);
        long long rightSum = dfsMax(node->right);

        long long sub = node->val + leftSum + rightSum;
        maxProd = max(maxProd, sub * (totalSum - sub));
        return sub;
    }
};