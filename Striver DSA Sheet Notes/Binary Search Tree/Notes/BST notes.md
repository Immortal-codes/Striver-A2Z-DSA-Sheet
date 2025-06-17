📘 Binary Search Tree (BST) – FAANG-Level Theory Notes
======================================================

🔹 What is a Binary Search Tree?
--------------------------------
A Binary Search Tree (BST) is a binary tree where:
- Left child of a node contains only nodes with values LESS than the node.
- Right child contains only nodes with values GREATER than the node.
- This property is recursively valid for all nodes.

🔹 Why Use BST?
---------------
- Efficient searching, insertion, deletion: O(log n) average.
- Maintains a sorted structure.
- Useful for range queries, k-th smallest/largest, floor/ceiling operations.
- Backbone of many FAANG-level problems.

🔹 Time Complexity
------------------
Operation   | Best/Average Case | Worst Case (Skewed)
------------|-------------------|---------------------
Search      | O(log n)          | O(n)
Insert      | O(log n)          | O(n)
Delete      | O(log n)          | O(n)

⚠️ Worst-case happens when BST becomes skewed like a linked list.
✅ Use AVL or Red-Black Trees for guaranteed O(log n) operations.

🔹 Traversals in BST
---------------------
- Inorder Traversal: Gives nodes in sorted order.
- Preorder/Postorder used for tree reconstruction, serialization, etc.

🔹 Key BST Concepts for Interviews
----------------------------------

1. ✅ Validation of BST:
   - Ensures left < root < right for every node.
   - Validated via recursion (with min/max bounds) or inorder traversal (strictly increasing order).

2. ✅ K-th Smallest / Largest:
   - Inorder gives sorted nodes → use this to find k-th element.

3. ✅ Lowest Common Ancestor (LCA):
   - Compare both nodes to root using BST properties to find the common ancestor.

4. ✅ Inorder Successor / Predecessor:
   - Successor: Smallest node in right subtree.
   - Predecessor: Largest node in left subtree.

5. ✅ Range Sum / Count:
   - Traverse only nodes within [low, high].
   - Skip subtrees outside this range using BST rules.

6. ✅ BST Iterator:
   - Design a class to iterate through BST in sorted order (like an STL iterator).

7. ✅ Convert Sorted Array to BST:
   - Build a balanced BST by choosing mid element as root recursively.

8. ✅ Convert BST to Doubly Linked List:
   - Inorder traversal connects nodes into a doubly linked list.

9. ✅ Serialize / Deserialize BST:
   - Use preorder + BST property for compact representation.
   - No need for NULL markers as in generic binary trees.

🔹 BST vs Binary Tree
---------------------
Binary Tree: No node ordering rules.
BST        : Left < Root < Right

🔹 Limitations of BST
---------------------
- Can become unbalanced (skewed).
- Doesn't handle duplicates naturally.
- Use self-balancing trees for guaranteed performance.

🔹 When to Use BST?
-------------------
- Data needs to remain sorted.
- You need fast search/insert/delete.
- Problems involve floor/ceiling/range queries or order statistics.

🔹 Self-Balancing BSTs
----------------------
- AVL Tree: Strict balancing (height diff ≤ 1).
- Red-Black Tree: Looser balancing but faster updates.
- Used in STL map, set (C++), TreeMap (Java).

🔹 Must-Solve BST Problems for FAANG
------------------------------------
- Validate a BST
- Insert/Delete in BST
- K-th smallest/largest
- LCA in BST
- Inorder successor/predecessor
- Range sum/count in BST
- Convert BST to DLL
- Serialize/Deserialize BST
- BST Iterator
- Floor/Ceiling in BST

✅ Summary
----------
- Master BST properties and traversal logic.
- Learn and revise core interview patterns: validation, search, insert, delete, LCA, k-th queries.
- Know the difference between balanced/unbalanced BSTs.
- Understand BST limitations and when to use AVL/Red-Black Trees.

📌 Pro Tip:
-----------
Always relate BST problems to sorted data, and think in terms of how you can leverage the ordering property to optimize traversal or recursion.

