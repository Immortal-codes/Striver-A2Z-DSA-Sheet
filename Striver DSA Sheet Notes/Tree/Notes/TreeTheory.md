# 🌳 Tree Theory Notes for FAANG Revision

---

## 1. What is a Tree?
- Non-linear, hierarchical data structure.
- Nodes connected by edges.
- Root is the topmost node.
- Nodes have zero or more children.
- No cycles (acyclic).

---

## 2. Terminology
- **Root**: Top node.
- **Parent**: Node with children.
- **Child**: Node derived from parent.
- **Leaf**: Node with no children.
- **Siblings**: Nodes sharing the same parent.
- **Subtree**: Tree formed by any node and its descendants.
- **Height of Tree**: Longest path from root to leaf.
- **Depth of Node**: Distance from root to that node.
- **Binary Tree**: Each node has at most 2 children.

---

## 3. Types of Trees

| Type                | Description                                           |
|---------------------|-----------------------------------------------------|
| Binary Tree         | Each node has at most 2 children, no specific order |
| Binary Search Tree  | Left subtree < Root < Right subtree                  |

| Balanced Binary Tree | Height difference between left & right ≤ 1          |
| Full Binary Tree     | Every node has 0 or 2 children                       |
| Complete Binary Tree | All levels filled except possibly last, left filled |
| Perfect Binary Tree  | All internal nodes have 2 children, all leaves same level |
| Degenerate Tree     | Each parent has only one child (like a linked list) |

---

## 4. Tree Traversals

- **DFS (Depth-First Search):**
  - Inorder: Left → Root → Right
  - Preorder: Root → Left → Right
  - Postorder: Left → Right → Root

- **BFS (Breadth-First Search):**
  - Level order traversal using queue.

---

## 5. Applications of Trees

- Hierarchical data (File systems, DOM, Org charts)
- Binary Search Trees for fast search, insert, delete
- Expression Trees in compilers/calculators
- Heaps (Priority Queues)
- Tries (Fast prefix word searching)
- Segment Trees / Fenwick Trees (Range queries)
- Huffman Trees (Data compression)

---

## 6. Tree Properties

- Tree with n nodes has exactly n-1 edges.
- Max nodes at level l = 2^l (0-indexed)
- Max nodes in binary tree of height h = 2^(h+1) - 1
- Perfect binary tree:
  - Height = log₂(n+1) - 1
  - Leaves = (n + 1)/2

---

## 7. Common Operations

- Insert
- Delete
- Search
- Traversals (Inorder, Preorder, Postorder, Level Order)
- Finding Height, Diameter, Balanced check
- Lowest Common Ancestor (LCA)
- Views (Top, Bottom, Left, Right)
- Serialize / Deserialize
- Mirror Tree

---

## 8. Difference between Tree & Graph

| Feature        | Tree                      | Graph                      |
|----------------|---------------------------|----------------------------|
| Cycles         | No                        | May have cycles            |
| Connectivity   | Always connected          | May or may not be connected |
| Number of Edges| Exactly n-1 for n nodes   | Can have any number         |
| Hierarchical   | Yes                       | Not necessarily            |

---

*End of Notes*

<!-- ************* -->

# 🔥 Advanced Tree Theory Concepts (Bonus for FAANG)

---

## 1. Binary Tree Properties & Formulas
- Number of leaf nodes in a full binary tree = number of internal nodes + 1
- In any binary tree, number of nodes with two children = number of leaf nodes - 1

---

## 2. Tree Height vs Depth
- **Height of a node:** Number of edges on longest downward path to a leaf.
- **Depth of a node:** Number of edges from root to that node.

---

## 3. Tree Balancing Techniques
- Why balancing matters: Reduces time complexity of operations.
- Common self-balancing BSTs:
  - **AVL Tree:** Balance factor (-1, 0, 1), rotations used to maintain balance.
  - **Red-Black Tree:** Color-based properties to maintain approximate balance.

---

## 4. Tree Representations in Memory
- **Linked representation:** Each node has pointers to children.
- **Array representation:** Mainly for complete binary trees (like heaps).
  - For node at index i:
    - Left child = 2i + 1
    - Right child = 2i + 2
    - Parent = (i - 1) / 2 (integer division)

---

## 5. Tree Metrics
- **Diameter of a tree:** Longest path between any two nodes.
- Can be found using two DFS traversals or one DFS with global max tracking.

---

## 6. Lowest Common Ancestor (LCA)
- Lowest node that has both given nodes as descendants.
- **Naive approach:** Traverse from root and find paths.
- **Optimized approaches:**
  - Binary lifting (for large trees)
  - Euler Tour + Segment Tree / RMQ

---

## 7. Special Trees
- **Trie:** Efficient retrieval of strings and prefixes.
- **Segment Tree / Fenwick Tree:** Data structures for interval/range queries.
- **Suffix Tree:** Used for pattern matching in strings.

---

## 8. Miscellaneous
- **Serialization/Deserialization:** Converting tree to string and back.
- **Threaded Binary Trees:** To speed up inorder traversal without using stack or recursion.
- **Morris Traversal:** Inorder traversal using O(1) space (no recursion or stack).

---

## Summary
For most FAANG interviews, mastering basics, tree types, traversals, properties, balancing, and LCA gives you a strong foundation.  
Advanced topics help in standing out and tackling system design or complex questions.

---

*If you want detailed theory notes on any advanced topic above, just ask!*
