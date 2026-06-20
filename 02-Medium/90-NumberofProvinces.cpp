/*
Problem: Number of Provinces
Link: https://leetcode.com/problems/number-of-provinces/description/
Difficulty: Medium
Topic: Graph / DFS

Problem Statement:
There are n cities. Some of them are directly connected,
while some are connected indirectly through other cities.

A province is a group of directly or indirectly connected cities
and no other cities outside the group.

You are given an n x n matrix isConnected where:
- isConnected[i][j] = 1 means city i and city j are connected.
- isConnected[i][j] = 0 means they are not connected.

Return the total number of provinces.

Example 1:
Input:
isConnected =
[
 [1,1,0],
 [1,1,0],
 [0,0,1]
]

Output:
2

Explanation:
- Cities 0 and 1 form one province.
- City 2 forms another province.

Example 2:
Input:
isConnected =
[
 [1,0,0],
 [0,1,0],
 [0,0,1]
]

Output:
3

Explanation:
Each city is isolated, so each city forms its own province.

--------------------------------------------------

Approach (DFS Traversal – Optimal):

Key Insight:
A province is simply a connected component in an
undirected graph.

Treat:
- Each city as a node.
- isConnected[i][j] = 1 as an edge.

For every unvisited city:
- Start a DFS.
- Mark all reachable cities.
- Increase province count by 1.

--------------------------------------------------

Steps:
1. Create a visited array.
2. Traverse all cities.
3. If a city is not visited:
   - Run DFS from that city.
   - Mark all connected cities.
   - Increase province count.
4. Return province count.

--------------------------------------------------

Dry Run:

isConnected =
[
 [1,1,0],
 [1,1,0],
 [0,0,1]
]

Start from city 0:
DFS visits {0,1}

Province count = 1

City 1 already visited

City 2 unvisited:
DFS visits {2}

Province count = 2

Answer = 2

--------------------------------------------------

Why it works:
- DFS visits all cities belonging to the same
  connected component.
- Each DFS call discovers exactly one province.
- Counting DFS starts gives the total number
  of provinces.

--------------------------------------------------

Time Complexity: O(n²)

- We may inspect every cell of the matrix.

Space Complexity: O(n)

- Visited array
- DFS recursion stack

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void dfs(int city, vector<vector<int>>& isConnected, vector<int>& visited) {

        visited[city] = 1;

        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {

            if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {

                dfs(neighbor, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> visited(n, 0);

        int provinces = 0;

        for (int city = 0; city < n; city++) {

            if (!visited[city]) {

                dfs(city, isConnected, visited);

                provinces++;
            }
        }

        return provinces;
    }
};