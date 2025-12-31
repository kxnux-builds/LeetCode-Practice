/*
Problem: Find in Mountain Array
Link: https://leetcode.com/problems/find-in-mountain-array/description/
Difficulty: Hard
Topic: Binary Search / Interactive / Two-Phase Search

Problem Statement:
(This is an interactive problem.)
You are given a **mountain array** `mountainArr`. An array is a mountain if:
- It strictly increases up to a peak, then strictly decreases after.
- There exists an index `i` (`0 < i < n−1`) such that:
    mountainArr.get(0) < … < mountainArr.get(i)
    mountainArr.get(i) > … > mountainArr.get(n−1)

You can only access the array through the provided interface:
- `mountainArr.get(k)` → returns the element at index `k`
- `mountainArr.length()` → returns the length

Return the **minimum index** where `mountainArr.get(index) == target`.  
If not found, return `−1`.

You must make no more than **100 calls** to `MountainArray.get`. :contentReference[oaicite:0]{index=0}

Approach (Binary Search → Peak → Two Halves):
1. First, find the peak index of the mountain using binary search:
   - While left < right:
       - mid = (left + right) / 2
       - If get(mid) > get(mid + 1): we’re on the descending side → move left
       - Else → move right
2. Binary search the **ascending** part [0..peak] for the target.
3. If not found, binary search the **descending** part [peak+1..n−1] with reversed comparisons.
4. Return the smallest index found, or −1 if neither found.

Time Complexity: O(log n) calls (peak + 2 searches)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/*
This is the MountainArray's API interface.
You should not implement it or speculate about its implementation.
*/
class MountainArray {
public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // 1. find peak
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int peak = l;

        // 2. binary search on ascending part
        int idx = binSearch(mountainArr, target, 0, peak, true);
        if (idx != -1) return idx;

        // 3. binary search on descending part
        return binSearch(mountainArr, target, peak + 1, n - 1, false);
    }

private:
    // binary search helper
    int binSearch(MountainArray &mountainArr, int target,
                  int left, int right, bool asc) {
        while (left <= right) {
            int mid = (left + right) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;

            if (asc) {
                if (val < target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (val > target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};