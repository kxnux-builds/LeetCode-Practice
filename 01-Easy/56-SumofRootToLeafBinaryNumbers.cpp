/*
Problem: Sum of Root To Leaf Binary Numbers
Link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
Difficulty: Easy
Topic: Tree / DFS / Bit Manipulation

Problem Statement:
Given a binary tree where each node’s value is either 0 or 1, every root-to-leaf path represents 
a binary number. The binary number is formed by concatenating the node values along the path.

Return *the sum of all root-to-leaf binary numbers*.

Example:
Input: root = [1,0,1,0,1,0,1]  
Output: 22  
Explanation:
The root-to-leaf paths are:
1→0→0  => binary `100` => 4  
1→0→1  => binary `101` => 5  
1→1→0  => binary `110` => 6  
1→1→1  => binary `111` => 7  
Sum = 4 + 5 + 6 + 7 = 22

Example:
Input: root = [0]  
Output: 0  
Explanation: Only one path: `0`.

Approach (DFS + Running Value – Optimal):
1. Use DFS to traverse the tree, carrying the **current binary value** down the path.
2. At each node, update the current binary number:
   - `current = (current << 1) | node->val` — shift left then add this node’s bit.
3. When reaching a leaf node, add the `current` value to the total sum.
4. Return the accumulated sum.

Time Complexity: O(n) — visit each node once  
Space Complexity: O(h) — recursion stack (h is tree height)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;
        
        // Update running binary value
        current = (current << 1) | node->val;
        
        // If leaf, return the accumulated value
        if (!node->left && !node->right) {
            return current;
        }
        
        // Otherwise sum from both sides
        return dfs(node->left, current) + dfs(node->right, current);
    }
};