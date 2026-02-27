/*
Problem: Binary Search Tree Iterator
Link: https://leetcode.com/problems/binary-search-tree-iterator/description/
Difficulty: Medium
Topic: Tree / Stack / Design

Problem Statement:
Implement the `BSTIterator` class that represents an iterator over the in-order traversal
of a binary search tree (BST).

The class should support:
- `BSTIterator(TreeNode* root)` — Initializes the iterator with the root of the BST.
- `bool hasNext()` — Returns `true` if there is a next smallest number in the iterator.
- `int next()` — Returns the next smallest number.

The iterator should return elements in **ascending order** (in-order traversal).

Example:
Input:
    BST = [7,3,15,null,null,9,20]
Operations:
    BSTIterator iterator = BSTIterator(root);
    iterator.next();    // return 3
    iterator.next();    // return 7
    iterator.hasNext(); // return true
    iterator.next();    // return 9
    iterator.hasNext(); // return true
    iterator.next();    // return 15
    iterator.next();    // return 20
    iterator.hasNext(); // return false

Approach (Controlled Stack In-Order Traversal – Optimal):
1. Use a stack to simulate recursion of in-order traversal.
2. On initialization:
   - Push all left children from root down to the leftmost node.
3. On each `next()`:
   - Pop the top node (smallest current).
   - If that node has a right child:
     - Push the right child and all its left descendants.
   - Return the popped node’s value.
4. `hasNext()` checks if the stack is non-empty.

This ensures:
- `next()` and `hasNext()` are **average O(1)** time.
- Space complexity is **O(h)** where *h* is tree height.

Time Complexity:  
- `next()`: amortized O(1)  
- `hasNext()`: O(1)

Space Complexity: O(h)

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
    
    // Push all left children
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    /** Returns the next smallest number */
    int next() {
        TreeNode* node = st.top(); 
        st.pop();
        int result = node->val;
        // Visit right subtree
        if (node->right) pushLeft(node->right);
        return result;
    }
    
    /** Returns whether the iterator has more nodes */
    bool hasNext() {
        return !st.empty();
    }
};