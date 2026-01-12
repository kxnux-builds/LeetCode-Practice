/*
Problem: Kth Largest Element in a Stream
Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
Difficulty: Easy
Topic: Heap / Priority Queue / Design

Problem Statement:
Design a class to find the **kth largest element** in a stream.  
Note that it is the **kth largest element in the sorted order**, not the
kth distinct element.

Implement the `KthLargest` class:
- `KthLargest(int k, vector<int>& nums)` initializes with the integer `k` and
  the stream of integers `nums`.
- `int add(int val)` appends `val` to the stream and returns the **kth largest element**.

Example:
Input:
["KthLargest","add","add","add","add","add"]
[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]
Output: [null,4,5,5,8,8]

Approach (Min Heap of Size k – Optimal):
1. Maintain a **min heap** of size at most `k`.
2. For every new element:
   - Push it into the heap.
   - If heap size exceeds `k`, pop the smallest.
3. At any point, the top of the min heap is the **kth largest** element.

Time Complexity:
- Initialization: O(n log k)
- Each `add`: O(log k)

Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums) {
            minHeap.push(x);
            if (minHeap.size() > k)
                minHeap.pop();
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k)
            minHeap.pop();
        return minHeap.top();
    }
};