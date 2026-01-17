/*
Problem: Maximum Square Area by Removing Fences From a Field
Link: https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/
Difficulty: Medium
Topic: Array / Enumeration / Hash Set

Problem Statement:
There is a large `(m - 1) x (n - 1)` rectangular field with corners at `(1, 1)` and `(m, n)`
that contains some horizontal and vertical fences given in arrays `hFences` and `vFences` respectively.

- Horizontal fences run from `(hFences[i], 1)` to `(hFences[i], n)`.
- Vertical fences run from `(1, vFences[i])` to `(m, vFences[i])`.

You can **remove any internal fences** (possibly none) to form a square field.  
Return *the maximum area of a square* field that can be formed by selecting two horizontal
boundary lines and two vertical boundary lines with the same distance between them,
or `-1` if it is impossible to form such a square.

Since the answer may be large, return it **modulo `10^9 + 7`**.

Note:
- The field is bordered by non-removable outer fences at `1` and `m` horizontally and `1` and `n` vertically.
- Internal fences listed in `hFences` and `vFences` can be removed to create larger gaps.

Example:
Input: m = 4, n = 3, hFences = [2,3], vFences = [2]  
Output: 4  
Explanation:
Removing the internal horizontal fences and the vertical fence at 2 lets you use positions 1 and 4
horizontally (distance = 3) and 1 and 3 vertically (distance = 2). The maximum common distance is 2,
so max square area = 2 × 2 = 4.

Constraints:
- 3 ≤ m, n ≤ 10⁹  
- 1 ≤ hFences.length, vFences.length ≤ 600  
- 1 < hFences[i] < m  
- 1 < vFences[i] < n  
- All fences are unique. :contentReference[oaicite:0]{index=0}

Approach (Enumerate All Gaps + Match Sets):
1. Append the **non-removable boundary fences** to each list:
   - For horizontal: add `1` and `m`
   - For vertical: add `1` and `n`
2. Sort both extended lists.
3. Compute all possible distances between every pair of horizontal fence positions and store them in an `unordered_set`.
4. Compute distances between all pairs of vertical fence positions and, for each one, check if it exists in the horizontal gap set.
5. Track the **maximum common distance** `maxSide`.
6. If no common distance exists → return `−1`. Otherwise:
   - Compute area = `(maxSide × maxSide) % (10⁹ + 7)`.
   - Return this area.

Time Complexity: O(H² + V²), where H = hFences.size()+2 and V = vFences.size()+2  
Space Complexity: O(H² + V²) — for gap sets
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1000000007LL;

        // Add boundaries
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // Collect all horizontal gaps
        unordered_set<long long> hGaps;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hGaps.insert((long long)hFences[j] - hFences[i]);
            }
        }

        long long maxSide = -1;
        // Check vertical gaps against horizontal
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long gap = (long long)vFences[j] - vFences[i];
                if (hGaps.count(gap)) {
                    maxSide = max(maxSide, gap);
                }
            }
        }

        if (maxSide == -1) return -1;
        return (int)((maxSide * maxSide) % MOD);
    }
};