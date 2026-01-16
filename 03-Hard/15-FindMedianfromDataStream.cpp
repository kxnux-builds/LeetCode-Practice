/*
Problem: Find Median from Data Stream
Link: https://leetcode.com/problems/find-median-from-data-stream/description/
Difficulty: Hard
Topic: Heap / Priority Queue / Data Stream

Problem Statement:
The median is the middle value in an ordered integer list.
If the size of the list is even, the median is the average of the two middle values.

Design a data structure that supports:
- addNum(int num): adds a number to the data structure.
- findMedian(): returns the median of all elements so far.

Example:
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2.0

Approach (Two Heaps – Optimal):
1. Use two heaps:
   - maxHeap (left half): stores the smaller half of numbers.
   - minHeap (right half): stores the larger half of numbers.
2. Balance the heaps such that:
   - maxHeap size == minHeap size, or
   - maxHeap has exactly one extra element.
3. Median rules:
   - If sizes are equal → median = (top of both heaps) / 2.
   - If sizes differ → median = top of maxHeap.

Why this works:
- Heaps keep elements partially sorted.
- Ensures O(log n) insertion and O(1) median retrieval.

Time Complexity:
- addNum(): O(log n)
- findMedian(): O(1)

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // left half (max heap)
    priority_queue<int, vector<int>, greater<int>> minHeap; // right half (min heap)

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Add to maxHeap
        maxHeap.push(num);

        // Step 2: Balance by moving top to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: Maintain size property
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};