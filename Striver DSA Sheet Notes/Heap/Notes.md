# 📘 Heap (Priority Queue) - DSA Master Notes  
✍️ Prepared by: Rajan Sharma | 🎯 Target: FAANG SDE

---

## 🔹 What is a Heap?

A **Heap** is a special complete binary tree used to implement **Priority Queues**, satisfying:

- **Max-Heap**: Parent ≥ Children  
- **Min-Heap**: Parent ≤ Children

---

## 🔹 Types of Heap

| Type       | Description                  |
|------------|------------------------------|
| Min Heap   | Smallest element at root     |
| Max Heap   | Largest element at root      |

---

## 🔹 Heap in C++ STL

```cpp
// Min Heap
priority_queue<int, vector<int>, greater<int>> minHeap;

// Max Heap (default)
priority_queue<int> maxHeap;

// Custom Pair Min Heap
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
