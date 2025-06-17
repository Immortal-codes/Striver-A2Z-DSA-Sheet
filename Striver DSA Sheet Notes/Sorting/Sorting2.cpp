#include <bits/stdc++.h>
using namespace std;

// 1. Merge Sort
// Time: O(n log n), Space: O(n)
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}
void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// 2. Recursive Bubble Sort
// Time: O(n^2), Space: O(n) (due to recursion stack)
void recursiveBubbleSort(vector<int>& arr, int n) {
    if (n == 1) return;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    recursiveBubbleSort(arr, n - 1);
}

// 3. Recursive Insertion Sort
// Time: O(n^2), Space: O(n) (due to recursion stack)
void recursiveInsertionSort(vector<int>& arr, int n) {
    if (n <= 1) return;
    recursiveInsertionSort(arr, n - 1);
    int last = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

// 4. Quick Sort (Lomuto partition)
// Time: O(n log n) avg, O(n^2) worst; Space: O(log n)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ==========================
// 🔁 Sample Main Function
// ==========================
void printArray(vector<int>& arr, string name) {
    cout << name << ": ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> base = {64, 34, 25, 12, 22, 11, 90};
    
    vector<int> mergeArr = base;
    vector<int> bubbleArr = base;
    vector<int> insertionArr = base;
    vector<int> quickArr = base;

    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    recursiveBubbleSort(bubbleArr, bubbleArr.size());
    recursiveInsertionSort(insertionArr, insertionArr.size());
    quickSort(quickArr, 0, quickArr.size() - 1);

    printArray(mergeArr, "Merge Sort");
    printArray(bubbleArr, "Recursive Bubble Sort");
    printArray(insertionArr, "Recursive Insertion Sort");
    printArray(quickArr, "Quick Sort");

    return 0;
}
