/*
Problem: Make Sum Divisible by P
Link: https://leetcode.com/problems/make-sum-divisible-by-p/description/
Difficulty: Medium
Topic: Array / Prefix Sum / Hash Table / Greedy

Problem Statement:
Given an array of positive integers `nums` and an integer `p`, remove the **shortest subarray** (possibly empty)
such that the **sum of the remaining elements** is divisible by `p`.  
You are **not** allowed to remove the whole array.

Return the **length** of the shortest subarray that you need to remove, or `-1`
if it is impossible to achieve divisibility.

A subarray is defined as a contiguous block of elements in the array.

Example:
Input: nums = [3,1,4,2], p = 6  
Output: 1  
Explanation:
The sum of the array is 10 and `10 % 6 = 4`. Removing subarray `[4]` (sum = 4)
leaves the remaining sum divisible by `6`. :contentReference[oaicite:0]{index=0}

Approach (Prefix Sum + Hash Map – Optimal):
1. Compute `total = sum(nums) % p`. If `total == 0`, the sum is already divisible → return `0`.
2. Use a hash map `last` to store the **latest index** where a particular prefix sum modulo `p` was seen.
3. Traverse the array while building `prefix = (prefix + nums[i]) % p`.
   - The subarray to remove must have remainder equal to `total` (so that removing it makes the rest divisible).
   - For current prefix mod `prefix`, compute `target = (prefix - total + p) % p`.
   - If `target` exists in the map → potential subarray found → update answer with `i - last[target]`.
   - Store current `prefix` with index `i` in the map.
4. If answer is still the length of `nums`, return `-1` (no valid subarray), otherwise return it.

Time Complexity: O(n)  
Space Complexity: O(n) — for the hash map tracking mod values :contentReference[oaicite:1]{index=1}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (long long x : nums) {
            total += x;
        }
        int rem = total % p;
        if (rem == 0) return 0;  // already divisible

        unordered_map<int, int> last;
        last[0] = -1;  // prefix remainder 0 at index -1

        int ans = nums.size();
        long long prefix = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - rem + p) % p;

            if (last.find(target) != last.end()) {
                ans = min(ans, i - last[target]);
            }
            // update latest index for this prefix mod
            last[prefix] = i;
        }

        return (ans == nums.size()) ? -1 : ans;
    }
};