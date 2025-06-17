#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ------------------------
// 1. Min Heap and Max Heap Implementation
// ------------------------
void minMaxHeapDemo() {
    // Min Heap using priority_queue
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(4);
    minHeap.push(15);
    minHeap.push(20);

    cout << "Min Heap Top Element: " << minHeap.top() << endl;

    // Max Heap (default)
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(4);
    maxHeap.push(15);
    maxHeap.push(20);

    cout << "Max Heap Top Element: " << maxHeap.top() << endl;
}

// ------------------------
// 2. Check if array represents a Min Heap
// ------------------------
bool isMinHeap(vector<int>& arr, int i, int n) {
    // If leaf node, return true
    if (i >= (n - 2) / 2) return true;

    // Check current node with its left and right child
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[i] > arr[left]) return false;
    if (right < n && arr[i] > arr[right]) return false;

    return isMinHeap(arr, left, n) && isMinHeap(arr, right, n);
}

// ------------------------
// 3. Convert Min Heap to Max Heap
// ------------------------
void heapifyMax(vector<int>& arr, int i, int n) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, largest, n);
    }
}

void convertMinToMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = (n-2)/2; i >= 0; i--) {
        heapifyMax(arr, i, n);
    }
}

// ------------------------
// Main Function
// ------------------------
int main() {
    cout << "=== Min Heap and Max Heap Implementation ===" << endl;
    minMaxHeapDemo();
    cout << endl;

    cout << "=== Check if Array is a Min Heap ===" << endl;
    vector<int> minHeapArr = {1, 3, 5, 7, 9, 11};
    cout << "Is Min Heap: " << (isMinHeap(minHeapArr, 0, minHeapArr.size()) ? "Yes" : "No") << endl;
    cout << endl;

    cout << "=== Convert Min Heap to Max Heap ===" << endl;
    vector<int> convertArr = {1, 3, 5, 7, 9, 11};
    convertMinToMaxHeap(convertArr);
    cout << "Converted Max Heap Array: ";
    for (int val : convertArr) cout << val << " ";
    cout << endl;

    return 0;
}
