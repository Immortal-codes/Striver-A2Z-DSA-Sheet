# 📚 Queue Notes (for FAANG & Interview Prep)

---

## 🧠 What is a Queue?

A **queue** is a linear data structure that follows the **FIFO (First In First Out)** principle.  
Think of a queue at a ticket counter — the first person to enter is the first to leave.

---

## ✅ Key Operations

| Operation     | Description                         | Time Complexity |
|---------------|-------------------------------------|-----------------|
| `push(x)`     | Inserts element `x` at the back     | O(1)            |
| `pop()`       | Removes the front element           | O(1)            |
| `front()`     | Accesses the front element          | O(1)            |
| `back()`      | Accesses the rear element           | O(1)            |
| `empty()`     | Checks if the queue is empty        | O(1)            |
| `size()`      | Returns the number of elements      | O(1)            |

---

## 🧰 Queue in C++

```cpp
#include <queue>
queue<int> q;

// Push
q.push(10);

// Front
int f = q.front();

// Back
int b = q.back();

// Pop
q.pop();

// Check empty
if (q.empty()) { /* handle */ }

// Size
int sz = q.size();
🔁 Applications of Queue

BFS traversal in Graphs / Trees
Job scheduling
Round-robin CPU scheduling
Sliding Window problems
Cache implementations (LRU Cache)
Interleaving strings
Tree level-order traversal
🔀 Types of Queues

1. Simple Queue
Standard FIFO queue
2. Deque (Double-Ended Queue)
Insert/delete from both front and back
Used in: Sliding Window Maximum
3. Priority Queue (Heap)
Highest/lowest priority element is always at front
Implemented as min-heap or max-heap
4. Circular Queue
Fixed-size queue with wrap-around (used in OS, buffer)
5. Monotonic Queue
Maintains order (increasing or decreasing)
Used in: Sliding Window Maximum, Minimum
🔥 Common Interview Problems

Problem Name	Type
Implement Queue using Stack	Stack + Queue
Implement Stack using Queue	Queue Simulation
Sliding Window Maximum	Monotonic Deque
Rotten Oranges	BFS + Queue
Course Schedule (Topological Sort)	Queue in Graphs
Binary Tree Level Order Traversal	Tree + Queue
Number of Recent Calls	Timestamp Queue
Moving Average from Data Stream	Sliding Queue
Design Circular Queue	Custom Queue Struct