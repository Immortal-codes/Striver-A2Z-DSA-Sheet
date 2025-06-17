#include <bits/stdc++.h>
using namespace std;

// 1. Selection Sort
// Time Complexity: O(n^2), Space Complexity: O(1)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}

// 2. Bubble Sort
// Time Complexity: O(n^2), Best Case: O(n), Space: O(1)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// 3. Insertion Sort
// Time Complexity: O(n^2), Best Case: O(n), Space: O(1)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// ==========================
// 🔁 Sample Main Function
// ==========================
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    vector<int> a1 = arr, a2 = arr, a3 = arr;

    selectionSort(a1);
    bubbleSort(a2);
    insertionSort(a3);

    cout << "\nSelection Sort: ";
    for (int x : a1) cout << x << " ";
    cout << "\n";

    cout << "Bubble Sort:    ";
    for (int x : a2) cout << x << " ";
    cout << "\n";

    cout << "Insertion Sort: ";
    for (int x : a3) cout << x << " ";
    cout << "\n";

    return 0;
}
