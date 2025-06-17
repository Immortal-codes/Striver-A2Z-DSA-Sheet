# Advanced Binary Search Problems (FAANG Level)

```cpp
#include <bits/stdc++.h>
using namespace std;

// 15. Find the row with maximum number of 1's
int rowWithMax1s(vector<vector<int>> &matrix) {
    int maxRow = -1, maxCount = 0;
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        int count = m - (lower_bound(matrix[i].begin(), matrix[i].end(), 1) - matrix[i].begin());
        if (count > maxCount) {
            maxCount = count;
            maxRow = i;
        }
    }
    return maxRow;
}

// 16. Search in a 2D matrix (Leetcode 74)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int val = matrix[mid / m][mid % m];
        if (val == target) return true;
        else if (val < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// 17. Search in row-wise and column-wise sorted matrix
bool searchSortedMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m - 1;
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) col--;
        else row++;
    }
    return false;
}

// 18. Find Peak Element in 2D Matrix
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int maxRow = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][mid] > mat[maxRow][mid]) {
                maxRow = i;
            }
        }
        bool leftIsSmaller = mid == 0 || mat[maxRow][mid] > mat[maxRow][mid - 1];
        bool rightIsSmaller = mid == m - 1 || mat[maxRow][mid] > mat[maxRow][mid + 1];

        if (leftIsSmaller && rightIsSmaller) return {maxRow, mid};
        else if (!leftIsSmaller) high = mid - 1;
        else low = mid + 1;
    }
    return {-1, -1};
}

// 19. Matrix Median
int countSmallerThanMid(vector<int>& row, int mid) {
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

int matrixMedian(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int low = 1, high = 1e9;
    while (low <= high) {
        int mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += countSmallerThanMid(matrix[i], mid);
        }
        if (count <= (n * m) / 2) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
```

> These problems use the **Binary Search in 2D Matrix** and **Matrix-based Search Patterns**, essential for FAANG-level interviews.
