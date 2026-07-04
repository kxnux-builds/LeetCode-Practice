/*
Problem: Minimum Score of a Path Between Two Cities
Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
Difficulty: Medium
Topic: Graph / DFS

Problem Statement:
There are n cities numbered from 1 to n.

You are given an array roads where:
roads[i] = [a, b, distance]

- There is a bidirectional road between cities a and b.
- distance is the length of the road.

The score of a path between two cities is defined as
the minimum distance of any road on that path.

Return the minimum possible score of a path between
city 1 and city n.

Note:
- A path may visit the same city or road multiple times.
- It is guaranteed that there is at least one path
  between city 1 and city n.

Example 1:
Input:
n = 4
roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]

Output:
5

Explanation:
One possible path:
1 → 2 → 4

Road distances:
9, 5

Score = min(9,5) = 5

Example 2:
Input:
n = 4
roads = [[1,2,2],[1,3,4],[3,4,7]]

Output:
2

--------------------------------------------------

Approach (DFS + Graph Traversal – Optimal):

Key Insight:
Since revisiting cities and roads is allowed,
the answer is simply the minimum road distance
among all roads in the connected component
containing city 1.

Why?
- Every city in the connected component is reachable.
- We can always travel through any road in the component
  and still reach city n.

So,
1. Build the graph.
2. Perform DFS from city 1.
3. While traversing, keep updating the minimum edge weight.
4. Return the minimum value found.

--------------------------------------------------

Steps:
1. Build an adjacency list.
2. Create a visited array.
3. Start DFS from city 1.
4. For every adjacent road:
   - Update answer = min(answer, road distance)
   - Visit unvisited neighboring cities.
5. Return answer.

--------------------------------------------------

Dry Run:

n = 4

roads =
[[1,2,9],
 [2,3,6],
 [2,4,5],
 [1,4,7]]

DFS from city 1

Visit:
1 → 2
Minimum = 9

2 → 3
Minimum = 6

2 → 4
Minimum = 5

1 → 4
Minimum remains 5

Answer = 5

--------------------------------------------------

Why it works:
- DFS visits every city reachable from city 1.
- Every road in this connected component can be
  part of some valid path because revisiting is allowed.
- Therefore, the minimum edge in the component is
  the minimum possible path score.

--------------------------------------------------

Time Complexity: O(n + m)

Where:
- n = number of cities
- m = number of roads

Space Complexity: O(n + m)

- Adjacency list
- Visited array
- DFS recursion stack

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node,
             vector<vector<pair<int, int>>>& graph,
             vector<bool>& visited) {

        visited[node] = true;

        for (auto& [neighbor, dist] : graph[node]) {

            ans = min(ans, dist);

            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& road : roads) {

            int u = road[0];
            int v = road[1];
            int d = road[2];

            graph[u].push_back({v, d});
            graph[v].push_back({u, d});
        }

        vector<bool> visited(n + 1, false);

        dfs(1, graph, visited);

        return ans;
    }
};