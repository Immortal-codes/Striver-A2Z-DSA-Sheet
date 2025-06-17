# 🌲 Binary Tree Traversals (Iterative Approach) — Theory Notes

---

## 🔁 1. Inorder Traversal (Iterative)
### 🔹 Order: Left ➝ Root ➝ Right

### ✅ Key Idea:
- Use a **stack** to simulate recursion.
- Traverse to the **leftmost node**, then visit root, then right.

### 🧠 Algorithm:
1. Initialize empty `stack` and set `curr = root`.
2. While `curr` is not NULL **or** stack is not empty:
   - While `curr` is not NULL:
     - Push `curr` to stack.
     - Move to `curr->left`.
   - Pop from stack.
   - Visit the popped node.
   - Move to its right subtree.

### 🕒 Time: O(N), Space: O(H)

---

## 🔁 2. Preorder Traversal (Iterative)
### 🔹 Order: Root ➝ Left ➝ Right

### ✅ Key Idea:
- Use a **stack** to store right and left children.
- Visit root first, then process left and right.

### 🧠 Algorithm:
1. Initialize stack with `root`.
2. While stack is not empty:
   - Pop top node.
   - Visit it.
   - Push `right` (if exists).
   - Push `left` (if exists).

### 🕒 Time: O(N), Space: O(H)

---

## 🔁 3. Postorder Traversal (Iterative - Using 2 Stacks)
### 🔹 Order: Left ➝ Right ➝ Root

### ✅ Key Idea:
- Modify **preorder**: Root ➝ Right ➝ Left
- Then **reverse** the result to get postorder.

### 🧠 Algorithm:
1. Initialize `stack1` with root and empty `stack2`.
2. While `stack1` is not empty:
   - Pop node from `stack1`, push to `stack2`.
   - Push `left`, then `right` to `stack1`.
3. Finally, pop all elements from `stack2` (postorder result).

### 🕒 Time: O(N), Space: O(N)

### ✅ Alternative (One Stack):
- Tricky and uses current and last visited pointer.
- Can be skipped unless required for interviews.

---

## 🔁 4. Level Order Traversal (BFS - Iterative)
### 🔹 Order: Level by level (Top ➝ Bottom, Left ➝ Right)

### ✅ Key Idea:
- Use a **queue** to process nodes level by level.

### 🧠 Algorithm:
1. Initialize queue with root.
2. While queue is not empty:
   - Get number of nodes at current level (`size`).
   - For each node in the level:
     - Dequeue, store value.
     - Enqueue left and right children.
   - Store the level's result in 2D vector.

### 🕒 Time: O(N), Space: O(N)

---

## ✅ Summary Table:

| Traversal     | Order            | Data Structure | Time | Space |
|---------------|------------------|----------------|------|--------|
| Inorder       | L → R → Root     | Stack          | O(N) | O(H)   |
| Preorder      | Root → L → R     | Stack          | O(N) | O(H)   |
| Postorder     | L → R → Root     | 2 Stacks       | O(N) | O(N)   |
| Level Order   | Level-wise (BFS) | Queue          | O(N) | O(N)   |

---

