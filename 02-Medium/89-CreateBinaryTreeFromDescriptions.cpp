/*
Problem: Create Binary Tree From Descriptions
Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
Difficulty: Medium
Topic: Binary Tree / Hash Table

Problem Statement:
You are given a 2D integer array descriptions where:

descriptions[i] = [parent, child, isLeft]

- parent is the value of the parent node.
- child is the value of the child node.
- isLeft = 1 means child is the left child.
- isLeft = 0 means child is the right child.

Construct and return the root of the binary tree.

It is guaranteed that:
- The binary tree is valid.
- Every child has exactly one parent.
- There is exactly one root.

Example 1:
Input:
descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]

Output:
[50,20,80,15,17,19]

Example 2:
Input:
descriptions = [[1,2,1],[2,3,0],[3,4,1]]

Output:
[1,2,null,null,3,4]

--------------------------------------------------

Approach (Hash Map + Root Identification):

Key Insight:
To build the tree:

1. Create nodes whenever needed.
2. Connect parent and child according to isLeft.
3. Track every node that appears as a child.
4. The root is the only node that never appears as a child.

--------------------------------------------------

Steps:
1. Create a hashmap:
      value -> TreeNode*
2. Create a set of child nodes.
3. Traverse descriptions:
   - Create parent node if absent.
   - Create child node if absent.
   - Attach child to parent.
   - Mark child as a child node.
4. Traverse descriptions again:
   - The parent that never appears as a child
     is the root.
5. Return root.

--------------------------------------------------

Dry Run:

descriptions =
[[20,15,1],
 [20,17,0],
 [50,20,1]]

Connections:
20 -> left = 15
20 -> right = 17
50 -> left = 20

Child nodes:
{15,17,20}

Parents:
{20,50}

Only 50 never appears as child.

Root = 50

--------------------------------------------------

Why it works:
- Every node value uniquely identifies a node.
- Hash map ensures O(1) access to nodes.
- Root detection is easy because every
  non-root node appears as a child exactly once.
- The only node never marked as a child
  must be the root.

--------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

Where n = descriptions.size()

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto &desc : descriptions) {

            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            if (!nodes.count(parent)) {
                nodes[parent] = new TreeNode(parent);
            }

            if (!nodes.count(child)) {
                nodes[child] = new TreeNode(child);
            }

            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }

            children.insert(child);
        }

        for (auto &desc : descriptions) {

            int parent = desc[0];

            if (!children.count(parent)) {
                return nodes[parent];
            }
        }

        return nullptr;
    }
};