/*
Problem: Minimum Number of Seconds to Make Mountain Height Zero
Link: https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/
Difficulty: Medium
Topic: Binary Search / Math / Greedy

Problem Statement:
You are given an integer `mountainHeight` representing the height of a mountain
and an integer array `workerTimes` where `workerTimes[i]` is the time taken by
worker `i`.

Workers work **simultaneously** to reduce the mountain height.

For worker `i`, the time required to reduce height by `x` units is:

workerTimes[i] * (1 + 2 + ... + x)

This forms an arithmetic series:

time = workerTimes[i] * x * (x + 1) / 2

Return the **minimum number of seconds** required so that the total reduced
height by all workers is **at least `mountainHeight`**. :contentReference[oaicite:0]{index=0}

Example 1:
Input: mountainHeight = 4, workerTimes = [2,1,1]  
Output: 3

Explanation:
Worker0 → reduce 1 → time = 2  
Worker1 → reduce 2 → time = 3  
Worker2 → reduce 1 → time = 1  

They work simultaneously → total time = max(2,3,1) = 3. :contentReference[oaicite:1]{index=1}

Example 2:
Input: mountainHeight = 10, workerTimes = [3,2,2,4]  
Output: 12

--------------------------------------------------

Approach (Binary Search on Time – Optimal):

Key Idea:
If workers can reduce the mountain in `t` seconds,
they can also do it in **any time greater than `t`**.
So we can apply **Binary Search on time**.

Steps:

1. Binary search on time range `[1, 1e16]`.
2. For a given time `mid`, compute how much height each worker can reduce.

From the formula:

workerTimes[i] * x * (x + 1) / 2 ≤ mid

Solving for `x`:

x = floor( sqrt( (2 * mid) / workerTimes[i] + 0.25 ) - 0.5 )

3. Sum all `x` values for workers.
4. If total height ≥ mountainHeight → time is sufficient.
5. Otherwise increase time.

--------------------------------------------------

Time Complexity: O(n log M)  
(n = number of workers, M = search range of time)

Space Complexity: O(1)

--------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReduce(long long t, int mountainHeight, vector<int>& workerTimes) {
        long long total = 0;

        for (long long w : workerTimes) {
            long long x = (long long)(sqrt((2.0 * t) / w + 0.25) - 0.5);
            total += x;

            if (total >= mountainHeight) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1;
        long long right = 1e16;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (canReduce(mid, mountainHeight, workerTimes))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};