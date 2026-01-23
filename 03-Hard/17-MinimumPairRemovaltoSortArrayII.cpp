/*
Problem: Minimum Pair Removal to Sort Array II
Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/description/
Difficulty: Hard
Topic: Priority Queue / Linked List Simulation / Greedy

Problem Statement:
You are given an integer array `nums`. You can repeatedly perform the following operation:

1. Choose the **adjacent pair with the minimum sum**.
2. If multiple such pairs exist, choose the **leftmost** one.
3. Remove the pair and replace it with their sum.

The goal is to make the array **non-decreasing** using the **minimum number of operations**.
Return the minimum number of operations required.

Approach (Optimized Simulation with Heap + Doubly Linked List):
This problem is an optimized version of Part I and requires efficient updates.

Key Ideas:
- Use a **doubly linked list** (via `pre[]` and `nxt[]`) to simulate removals efficiently.
- Maintain a **priority queue (min-heap)** storing `(sum, leftIndex)` for adjacent pairs.
- Track how many positions violate non-decreasing order using a counter `cnt`.
- Each merge updates only local neighbors → efficient O(log n) updates.

Steps:
1. Initialize `pre[]` and `nxt[]` to simulate a linked list.
2. Store all adjacent pair sums in a min-heap.
3. Maintain `cnt` = number of places where nums[i] > nums[i+1].
4. While `cnt > 0`:
   - Extract the valid minimum-sum pair.
   - Merge the pair.
   - Update links, sums, heap entries, and violation count.
5. Stop once array becomes non-decreasing.

Time Complexity: O(n log n)  
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), nxt(n);

        for (int i = 0; i < n; ++i) {
            pre[i] = i - 1;
            nxt[i] = i + 1;
        }

        vector<long long> a(nums.begin(), nums.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            cnt += a[i] > a[i + 1];
            pq.emplace(a[i] + a[i + 1], i);
        }

        int ans = 0;

        while (cnt > 0) {
            auto [sum, l] = pq.top();
            pq.pop();

            int r = nxt[l];
            // Skip invalid or outdated heap entries
            if (r >= n || pre[r] != l || a[l] + a[r] != sum) continue;

            ans++;

            // Remove old violations
            cnt -= a[l] > a[r];
            cnt -= (nxt[r] < n && a[r] > a[nxt[r]]);
            cnt -= (pre[l] >= 0 && a[pre[l]] > a[l]);

            // Merge l and r
            a[r] = sum;

            // Fix links
            if (pre[l] >= 0) {
                pre[r] = pre[l];
                nxt[pre[l]] = r;
                cnt += a[pre[r]] > a[r];
                pq.emplace(a[pre[r]] + a[r], pre[r]);
            } else {
                pre[r] = -1;
            }

            if (nxt[r] < n) {
                cnt += a[r] > a[nxt[r]];
                pq.emplace(a[r] + a[nxt[r]], r);
            }
        }

        return ans;
    }
};