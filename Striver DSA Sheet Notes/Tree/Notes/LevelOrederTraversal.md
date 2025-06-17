# 📘 Level Order Traversal (Breadth-First Search)

## ✅ Problem:
Given the root of a binary tree, return a **2D vector** containing the **level order traversal** (left to right, level by level).

---

## 💡 Intuition:
- Use **Breadth-First Search (BFS)**.
- BFS naturally explores the tree **level by level** using a **queue**.

---

## 📌 Key Points:

- Use a **queue** to store nodes while traversing the tree.
- For every level:
  - **Track the number of nodes** at that level.
  - Create a temporary vector `level[]` to store values of that level.
  - Traverse each node of the level:
    - Dequeue the front node.
    - Add its value to `level[]`.
    - Enqueue its left and right children if they exist.
  - Add `level[]` to final answer `ans[]`.

---

## 🧠 Algorithm Steps:

1. **Initialize**:
   - A queue `q`.
   - A 2D vector `ans` to store final result.
   - If the tree is empty (root is `NULL`), return `ans`.

2. **Push root to queue**.

3. **While queue is not empty**:
   - Get current level size: `size = q.size()`.
   - Create an empty vector `level`.
   - Loop `size` times:
     - Dequeue node.
     - Add node's value to `level`.
     - Enqueue left child if exists.
     - Enqueue right child if exists.
   - Add `level` to `ans`.

4. **Return** the 2D vector `ans`.

---

## 🔁 Time & Space Complexity:

- **Time Complexity:** O(N) — Each node is visited once.
- **Space Complexity:** O(N) — For the queue and result vector.

---

## ✅ Output:
A 2D vector where each subvector contains the node values at each level.

---

*Need the C++ implementation next? Let me know!*
