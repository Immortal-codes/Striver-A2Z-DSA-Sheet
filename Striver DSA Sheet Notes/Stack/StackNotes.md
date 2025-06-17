# 📚 Stack Notes (for FAANG & Interview Prep)

---

## 🧠 What is a Stack?

A **stack** is a linear data structure that follows the **LIFO (Last In First Out)** principle.  
Think of a stack of plates — you add and remove from the **top only**.

---

## ✅ Key Operations

| Operation   | Description                            | Time Complexity |
|-------------|----------------------------------------|-----------------|
| `push(x)`   | Inserts element `x` at the top         | O(1)            |
| `pop()`     | Removes the top element                | O(1)            |
| `top()`     | Returns the top element                | O(1)            |
| `empty()`   | Checks if the stack is empty           | O(1)            |
| `size()`    | Returns the number of elements         | O(1)            |

---

## 🧰 Stack in C++

```cpp
#include <stack>
stack<int> st;

// Push
st.push(10);

// Top element
int val = st.top();

// Pop
st.pop();

// Check if empty
if (st.empty()) { /* handle */ }

// Size
int n = st.size();
🔁 Use Cases / Applications

Expression evaluation & conversion (Infix ↔ Postfix)
Balanced parentheses / brackets checking
Undo feature in editors
Backtracking (recursion stack)
DFS traversal (explicit stack)
Next Greater/Smaller Element problems
Histograms / Area problems
📌 Famous Stack-Based Patterns

1. Monotonic Stack
Maintains elements in increasing or decreasing order
Used in:
Next Greater Element
Daily Temperatures
Largest Rectangle in Histogram
2. Two Stacks
Used in:
Implement Queue using 2 Stacks
Min Stack
3. Stack of Indices
Useful when you need to track positions, not values
Eg: Valid Parentheses, Histogram Problems
🔥 Important Interview Problems

Problem Name	Type
Valid Parentheses	Matching Brackets
Next Greater Element I/II	Monotonic Stack
Daily Temperatures	Monotonic Stack
Largest Rectangle in Histogram	Area using Stack
Min Stack	Two Stacks
Asteroid Collision	Stack Simulation
Remove K Digits	Monotonic Increasing Stack
Decode String	Stack-based Recursion
Simplify Path	Stack Path Evaluation
Evaluate Reverse Polish Notation	Stack Evaluation
Implement Queue using Stacks	Two-Stack Queue