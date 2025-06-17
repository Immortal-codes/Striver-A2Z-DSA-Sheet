# Array Notes (Basic to FAANG Level)

## Basics

* Definition: A contiguous block of memory storing elements of the same type.
* Time Complexity:

  * Access: O(1)
  * Search: O(n)
  * Insertion/Deletion (middle): O(n)

## Traversal

```cpp
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
```

## Common Techniques & Patterns

* **Two Pointer Technique**
* **Sliding Window**
* **Prefix Sum / Difference Array**
* **Binary Search on Sorted Arrays**
* **Sorting and Searching**
* **Hashing (using unordered\_map)**

---

## Easy Problems

### 1. Find Largest and Smallest Element

```cpp
int maxElement = arr[0], minElement = arr[0];
for (int i = 1; i < n; i++) {
    maxElement = max(maxElement, arr[i]);
    minElement = min(minElement, arr[i]);
}
```

### 2. Reverse an Array

```cpp
int l = 0, r = n - 1;
while (l < r) swap(arr[l++], arr[r--]);
```

### 3. Check if Array is Sorted

```cpp
bool sorted = true;
for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i-1]) sorted = false;
}
```

---

## Medium Level Problems

### 1. Move Zeroes to End

```cpp
int j = 0;
for (int i = 0; i < n; i++) {
    if (arr[i] != 0) swap(arr[i], arr[j++]);
}
```

### 2. Kadane’s Algorithm (Max Subarray Sum)

```cpp
int maxSum = arr[0], curSum = arr[0];
for (int i = 1; i < n; i++) {
    curSum = max(arr[i], curSum + arr[i]);
    maxSum = max(maxSum, curSum);
}
```

### 3. Majority Element (Moore's Voting)

```cpp
int count = 0, candidate;
for (int num : arr) {
    if (count == 0) candidate = num;
    count += (num == candidate) ? 1 : -1;
}
```

---

## Advanced / FAANG Level

### 1. Merge Intervals

### 2. Longest Consecutive Subsequence

### 3. Trapping Rain Water

### 4. Container With Most Water

### 5. Subarray Sum Equals K (using prefix sum + map)

### 6. Product of Array Except Self

### 7. Sliding Window Maximum

### 8. Maximum Subarray Sum of Size K

---

## Must-Know Patterns

* **Kadane’s for max sum subarrays**
* **Prefix sum for range queries**
* **Sliding window for subarrays of fixed size**
* **Hashing for frequency/count**
* **Two pointers for sorted arrays**
* **Binary Search for sorted and rotated arrays**

---

Let me know if you want code for any specific problem or all advanced-level problems in C++.
