# C++ Standard Template Library (STL) Notes

The **C++ Standard Template Library (STL)** is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures.

---

## 📦 STL Components

### 1. **Containers**

Containers store data. There are 3 types:

* **Sequence Containers**: vector, list, deque, array, forward\_list
* **Associative Containers**: set, multiset, map, multimap
* **Unordered Associative Containers**: unordered\_set, unordered\_multiset, unordered\_map, unordered\_multimap
* **Container Adapters**: stack, queue, priority\_queue

---

## ✅ Sequence Containers

### 1. `vector`

* Dynamic array
* Random access, insertion at end is fast

```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);
v.pop_back();
sort(v.begin(), v.end());
```

### 2. `list`

* Doubly linked list

```cpp
list<int> l = {1, 2, 3};
l.push_front(0);
l.push_back(4);
```

### 3. `deque`

* Double-ended queue

```cpp
deque<int> dq;
dq.push_back(1);
dq.push_front(2);
dq.pop_back();
```

### 4. `array`

* Static fixed-size array

```cpp
array<int, 5> arr = {1, 2, 3, 4, 5};
sort(arr.begin(), arr.end());
```

### 5. `forward_list`

* Singly linked list

```cpp
forward_list<int> fl = {1, 2, 3};
fl.push_front(0);
```

---

## ✅ Associative Containers

### 1. `set`

* Stores unique elements in sorted order

```cpp
set<int> s = {4, 1, 2};
s.insert(3);
s.erase(1);
```

### 2. `multiset`

* Allows duplicate elements

```cpp
multiset<int> ms = {1, 1, 2};
```

### 3. `map`

* Key-value pairs (unique keys)

```cpp
map<int, string> m;
m[1] = "A";
m[2] = "B";
```

### 4. `multimap`

* Multiple values for the same key

```cpp
multimap<int, string> mm;
mm.insert({1, "A"});
mm.insert({1, "B"});
```

---

## ✅ Unordered Associative Containers

### 1. `unordered_set`

* Unordered, unique elements, average O(1) operations

```cpp
unordered_set<int> us;
us.insert(10);
```

### 2. `unordered_map`

* Key-value pair with average O(1) operations

```cpp
unordered_map<string, int> um;
um["apple"] = 1;
```

---

## ✅ Container Adapters

### 1. `stack`

* LIFO (Last-In-First-Out)

```cpp
stack<int> st;
st.push(1);
st.pop();
```

### 2. `queue`

* FIFO (First-In-First-Out)

```cpp
queue<int> q;
q.push(1);
q.pop();
```

### 3. `priority_queue`

* Max-heap by default

```cpp
priority_queue<int> pq;
pq.push(10);
pq.top();
```

* Min-heap:

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

---

## 🛠️ Algorithms Header

```cpp
#include <algorithm>
```

* sort(v.begin(), v.end())
* reverse(v.begin(), v.end())
* count(v.begin(), v.end(), x)
* find(v.begin(), v.end(), x)
* binary\_search(v.begin(), v.end(), x)
* lower\_bound, upper\_bound

---

## 🔁 Iterators

* `begin()` – start iterator
* `end()` – past-the-end iterator
* `rbegin()`, `rend()` – reverse iterators

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
```

---

## ✨ Useful STL Tricks

```cpp
// Sort in descending
sort(v.begin(), v.end(), greater<int>());

// Custom comparator
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}
sort(v.begin(), v.end(), cmp);

// Unique elements after sorting
v.erase(unique(v.begin(), v.end()), v.end());
```

---

## ⏱ Time Complexities (Average Case)

| Container          | Access   | Insert   | Erase    |
| ------------------ | -------- | -------- | -------- |
| vector             | O(1)     | O(1)     | O(n)     |
| list               | O(n)     | O(1)     | O(1)     |
| deque              | O(1)     | O(1)     | O(1)     |
| set/map            | O(log n) | O(log n) | O(log n) |
| unordered\_set/map | O(1)     | O(1)     | O(1)     |

---

## 🧠 STL Practice Tips

* Learn container + iterator + algorithm combo
* Know when to use `set` vs `unordered_set`
* Use `priority_queue` in Dijkstra/Greedy
* Know `map` & `unordered_map` for hashing

---

> **Remember**: STL helps reduce coding time drastically. Learn to combine containers and algorithms effectively.

Happy Coding 🚀
