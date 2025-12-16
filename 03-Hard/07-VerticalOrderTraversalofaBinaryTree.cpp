/*
Problem: Vertical Order Traversal of a Binary Tree
Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
Difficulty: Hard
Topic: Tree / BFS / Sorting / Coordinates

Problem Statement:
Given the root of a binary tree, calculate the vertical order traversal of
its nodes’ values.
- Nodes with the same x-coordinate (column) should be grouped together.
- Within each column, nodes are ordered first by y (row) from top to bottom.
- If two nodes have the same position (same x and y), sort by node value.

Return a list of columns in order from the smallest x-coordinate to largest.

Example:
Input:
      3
     / \
    9   20
       /  \
      15   7

Output:
[
  [9],
  [3,15],
  [20],
  [7]
]

Approach (BFS to record coordinates + sort groups):
1. Do breadth-first traversal (queue) and track (x, y) for each node:
   - root: (x = 0, y = 0)
   - left child: (x − 1, y + 1)
   - right child: (x + 1, y + 1)
2. Store tuples of (x, y, value) in a vector.
3. Sort the vector by:
   - ascending x (column)
   - ascending y (row)
   - ascending node value (if same x, y)
4. Group sorted nodes by column x.
5. Return list of columns.

Time Complexity: O(n log n) — sorting  
Space Complexity: O(n) — storage of nodes
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // store (x, y, value) for each node
        vector<tuple<int,int,int>> nodes;
        queue<tuple<TreeNode*,int,int>> q; // node, x, y
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, x, y] = q.front(); q.pop();
            if (!node) continue;

            nodes.push_back({x, y, node->val});
            if (node->left)  q.push({node->left,  x - 1, y + 1});
            if (node->right) q.push({node->right, x + 1, y + 1});
        }

        // sort:
        // 1) by x ascending (column)
        // 2) by y ascending (row)
        // 3) by node value ascending
        sort(nodes.begin(), nodes.end(),
             [](const auto &a, const auto &b) {
                 if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
                 if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
                 return get<2>(a) < get<2>(b);
             });

        vector<vector<int>> result;
        int currX = INT_MIN;

        for (auto &t : nodes) {
            int x, y, val;
            tie(x, y, val) = t;
            if (result.empty() || x != currX) {
                result.push_back({val});
                currX = x;
            } else {
                result.back().push_back(val);
            }
        }

        return result;
    }
};