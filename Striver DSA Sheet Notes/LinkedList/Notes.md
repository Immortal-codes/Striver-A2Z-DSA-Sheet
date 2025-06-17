# 📘 Linked List - Theory & Interview Patterns

---

## 🔹 Introduction to Linked List

- A linear data structure where elements (nodes) are stored in non-contiguous memory.
- Each node has:
  - `data`
  - `next` pointer (points to next node)

### ✅ Structure of a Node in C++:
```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
