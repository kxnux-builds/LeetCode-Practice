/*
Problem: Amount of Time for Binary Tree to Be Infected
Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
Difficulty: Medium
Topic: Tree / BFS / Graph / Level Order

Problem Statement:
You are given the `root` of a binary tree and an integer `start` representing
the value of the node where a virus starts to spread.

Each minute, the virus spreads from any infected node to all uninfected neighbors
(parent and children).

Return *the amount of time* it takes for the entire tree to become infected.

Example:
Input:
    root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4

Approach (Convert Tree to Graph + BFS):
1. Build an adjacency list representation of the tree:
   - For each node, connect it with its left child (if exists)
   - Connect it with its right child (if exists)
   - Also connect child back to parent
2. Perform BFS starting from the `start` node.
3. Track infection time by counting levels in BFS.
4. Return the final BFS depth (time).

Time Complexity: O(n)  
Space Complexity: O(n)
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
    int amountOfTime(TreeNode* root, int start) {
        // Build adjacency list
        unordered_map<int, vector<int>> adj;
        buildGraph(root, nullptr, adj);

        // BFS from start
        queue<int> q;
        q.push(start);

        unordered_set<int> visited;
        visited.insert(start);

        int time = 0;
        while (!q.empty()) {
            int sz = q.size();
            bool infectedNew = false;

            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();

                for (int nei : adj[node]) {
                    if (!visited.count(nei)) {
                        visited.insert(nei);
                        q.push(nei);
                        infectedNew = true;
                    }
                }
            }

            if (infectedNew) time++;
        }

        return time;
    }

private:
    void buildGraph(TreeNode* node, TreeNode* parent,
                    unordered_map<int, vector<int>>& adj) {
        if (!node) return;

        if (parent) {
            adj[node->val].push_back(parent->val);
            adj[parent->val].push_back(node->val);
        }

        if (node->left)
            buildGraph(node->left, node, adj);
        if (node->right)
            buildGraph(node->right, node, adj);
    }
};