# 📘 Binary Search Notes (Basic to FAANG Level)

## ✅ What is Binary Search?

Binary Search is an efficient search algorithm with **O(log N)** time complexity, used on sorted arrays or monotonic functions.

### Requirements:
- Array must be **sorted**.
- Operates by dividing the array into halves recursively.

---

## 🧠 Binary Search Template

```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
