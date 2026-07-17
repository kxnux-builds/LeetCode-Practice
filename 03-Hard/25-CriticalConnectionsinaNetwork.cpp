/*
Problem: Critical Connections in a Network
Link: https://leetcode.com/problems/critical-connections-in-a-network/description/
Difficulty: Hard
Topic: Graph / DFS / Tarjan's Algorithm

Problem Statement:
There are n servers numbered from 0 to n - 1.

You are given a list of connections where:
connections[i] = [a, b]

There is a bidirectional connection between
servers a and b.

A critical connection (bridge) is an edge that,
if removed, disconnects some part of the network.

Return all critical connections in any order.

Example 1:
Input:
n = 4
connections = [[0,1],[1,2],[2,0],[1,3]]

Output:
[[1,3]]

Explanation:
Removing edge (1,3) disconnects server 3
from the remaining network.

Example 2:
Input:
n = 2
connections = [[0,1]]

Output:
[[0,1]]

--------------------------------------------------

Approach (Tarjan's Algorithm - DFS):

Key Insight:
During DFS maintain:

- disc[node]
    = discovery time of node

- low[node]
    = earliest discovery time reachable
      from the current node

For every DFS tree edge:
node ----> neighbor

After DFS of neighbor:

If

low[neighbor] > disc[node]

then

(node, neighbor)

is a Bridge (Critical Connection).

Why?

It means neighbor (and its subtree)
cannot reach node or any ancestor
without using this edge.

--------------------------------------------------

Steps:
1. Build adjacency list.
2. Initialize:
   - visited[]
   - disc[]
   - low[]
3. Start DFS from every unvisited node.
4. During DFS:
   - Assign discovery time.
   - Update low values.
5. If:
      low[neighbor] > disc[node]
   store the edge.
6. Return all bridges.

--------------------------------------------------

Dry Run:

n = 4

0 ----- 1
|      / \
|     /   \
2     3

DFS Order:

disc:
0 = 1
1 = 2
2 = 3
3 = 4

low:
0 = 1
1 = 1
2 = 1
3 = 4

For edge (1,3):

low[3] = 4
disc[1] = 2

4 > 2

Bridge found:
(1,3)

--------------------------------------------------

Why it works:
- low[] stores the earliest ancestor
  reachable from a subtree.
- If a subtree cannot reach an ancestor,
  removing that edge disconnects the graph.
- Tarjan's algorithm correctly identifies
  every bridge in a single DFS traversal.

--------------------------------------------------

Time Complexity: O(V + E)

Where:
V = number of vertices
E = number of edges

Space Complexity: O(V + E)

- Adjacency list
- DFS recursion stack
- disc[], low[], visited[]

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> bridges;

    vector<int> disc;
    vector<int> low;
    vector<bool> visited;

    int timer = 0;

    void dfs(int node,
             int parent,
             vector<vector<int>>& graph) {

        visited[node] = true;

        disc[node] = low[node] = timer++;

        for (int neighbor : graph[node]) {

            if (neighbor == parent)
                continue;

            if (!visited[neighbor]) {

                dfs(neighbor, node, graph);

                low[node] = min(low[node], low[neighbor]);

                if (low[neighbor] > disc[node]) {
                    bridges.push_back({node, neighbor});
                }
            }
            else {

                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }

    vector<vector<int>> criticalConnections(
        int n,
        vector<vector<int>>& connections) {

        vector<vector<int>> graph(n);

        for (auto &edge : connections) {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        disc.resize(n);
        low.resize(n);
        visited.assign(n, false);

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                dfs(i, -1, graph);
            }
        }

        return bridges;
    }
};