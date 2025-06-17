# Tree Traversals: Inorder, Preorder, Postorder & Level Order

---

## Overview

Traversals in hierarchical data structures like Binary Trees can be broadly classified into two categories:

- **Depth-First Search (DFS)**
- **Breadth-First Search (BFS)**

Each uses a different strategy to visit nodes within the tree.

---

## Depth-First Search (DFS)

- Explores a binary tree by going as deeply as possible along each branch before backtracking.
- Starts from the root and visits nodes until it reaches a leaf node.
- Then backtracks to the most recent unexplored node and continues until all nodes are visited.
- Uses **recursion** or **stack** to traverse deeper levels before visiting nodes at the same level.
- The order of visiting nodes defines the traversal type: **Preorder**, **Inorder**, or **Postorder**.

---

## Breadth-First Search (BFS)

- Explores a binary tree level by level.
- Visits all nodes at a given level before moving to the next level.
- Uses a **queue** to maintain nodes at each level, visiting nodes from left to right.

---

## Inorder Traversal (DFS)

**Order:** Left → Root → Right

- Visit the left subtree recursively until leaf or no left child.
- Visit the current node (perform operation).
- Traverse the right subtree recursively.

**Key Point:**  
In BST, inorder traversal visits nodes in **ascending order**.

---

## Preorder Traversal (DFS)

**Order:** Root → Left → Right

- Visit the current node first.
- Recursively traverse the left subtree.
- Recursively traverse the right subtree.

**Key Point:**  
Preorder is used to **copy** trees or get prefix expression of an expression tree.

---

## Postorder Traversal (DFS)

**Order:** Left → Right → Root

- Recursively traverse the left subtree.
- Recursively traverse the right subtree.
- Visit the current node last.

**Key Point:**  
Postorder is used to **delete** trees or get postfix expression of an expression tree.

---

## Level Order Traversal (BFS)

- Visit nodes level by level starting from root (level 0).
- Visit all nodes at the current level from left to right.
- Move to next level and repeat until all nodes are visited.
- Utilizes a **queue** to maintain nodes at each level.

---

## Summary of Visitation Orders

| Traversal Type | Visit Order     | Usage Highlights                   |
|----------------|-----------------|----------------------------------|
| Inorder        | Left → Root → Right  | Sorted order in BST               |
| Preorder       | Root → Left → Right  | Copying tree, prefix expressions |
| Postorder      | Left → Right → Root  | Deleting tree, postfix expressions |
| Level Order    | Level-wise (left to right) | BFS, shortest path level info    |

---

*If you want me to provide the C++ code implementations for any of these traversals, just ask!*
