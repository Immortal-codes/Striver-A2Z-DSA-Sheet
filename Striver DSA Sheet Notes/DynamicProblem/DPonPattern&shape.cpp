// #include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;

/*
1. Find Largest Plus Sign in a Binary Matrix
   - Largest plus sign of 1s with equal arm length.
*/
int largestPlusSign(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    vector<vector<int>> left(n, vector<int>(m, 0));
    vector<vector<int>> right(n, vector<int>(m, 0));
    vector<vector<int>> up(n, vector<int>(m, 0));
    vector<vector<int>> down(n, vector<int>(m, 0));

    // Fill left and up
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                left[i][j] = (j == 0) ? 1 : left[i][j-1] + 1;
                up[i][j] = (i == 0) ? 1 : up[i-1][j] + 1;
            }
        }
    }

    // Fill right and down
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                right[i][j] = (j == m - 1) ? 1 : right[i][j+1] + 1;
                down[i][j] = (i == n - 1) ? 1 : down[i+1][j] + 1;
            }
        }
    }

    int maxOrder = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                int order = min({left[i][j], right[i][j], up[i][j], down[i][j]});
                maxOrder = max(maxOrder, order);
            }
        }
    }
    return maxOrder;
}

/*
2. Find Largest Cross of 1s or 0s in a Matrix
   - Largest cross shape (plus with diagonals).
   - We'll check four diagonal directions + four cardinal directions.
*/
int largestCross(const vector<vector<int>>& matrix, int target = 1) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> left(n, vector<int>(m, 0));
    vector<vector<int>> right(n, vector<int>(m, 0));
    vector<vector<int>> up(n, vector<int>(m, 0));
    vector<vector<int>> down(n, vector<int>(m, 0));
    vector<vector<int>> diag1(n, vector<int>(m, 0)); // top-left to bottom-right
    vector<vector<int>> diag2(n, vector<int>(m, 0)); // top-right to bottom-left
    vector<vector<int>> diag3(n, vector<int>(m, 0)); // bottom-left to top-right
    vector<vector<int>> diag4(n, vector<int>(m, 0)); // bottom-right to top-left

    // Compute counts for cardinal directions (left, right, up, down)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target) {
                left[i][j] = (j == 0) ? 1 : left[i][j-1] + 1;
                up[i][j] = (i == 0) ? 1 : up[i-1][j] + 1;
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (matrix[i][j] == target) {
                right[i][j] = (j == m-1) ? 1 : right[i][j+1] + 1;
                down[i][j] = (i == n-1) ? 1 : down[i+1][j] + 1;
            }
        }
    }

    // Compute counts for diagonals
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target) {
                diag1[i][j] = (i == 0 || j == 0) ? 1 : diag1[i-1][j-1] + 1;
                diag2[i][j] = (i == 0 || j == m-1) ? 1 : diag2[i-1][j+1] + 1;
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target) {
                diag3[i][j] = (i == n-1 || j == 0) ? 1 : diag3[i+1][j-1] + 1;
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (matrix[i][j] == target) {
                diag4[i][j] = (i == n-1 || j == m-1) ? 1 : diag4[i+1][j+1] + 1;
            }
        }
    }

    int maxCross = 0;
    // Minimum arm length for cross is minimum of all 8 directions divided by 2 + 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target) {
                int armLength = min({
                    left[i][j], right[i][j], up[i][j], down[i][j],
                    diag1[i][j], diag2[i][j], diag3[i][j], diag4[i][j]
                });
                maxCross = max(maxCross, armLength);
            }
        }
    }
    return maxCross;
}

/*
3. Largest Diamond Shape of 1s in Matrix
   - Diamond shape: formed by diagonals only.
   - Use two passes with diagonal prefix sums.
*/

int largestDiamond(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> diag1(n, vector<int>(m, 0)); // top-left to bottom-right
    vector<vector<int>> diag2(n, vector<int>(m, 0)); // top-right to bottom-left
    vector<vector<int>> diag3(n, vector<int>(m, 0)); // bottom-left to top-right
    vector<vector<int>> diag4(n, vector<int>(m, 0)); // bottom-right to top-left

    // forward pass - diag1 and diag2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                diag1[i][j] = (i == 0 || j == 0) ? 1 : diag1[i-1][j-1] + 1;
                diag2[i][j] = (i == 0 || j == m - 1) ? 1 : diag2[i-1][j+1] + 1;
            }
        }
    }

    // backward pass - diag3 and diag4
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                diag3[i][j] = (i == n - 1 || j == 0) ? 1 : diag3[i+1][j-1] + 1;
                diag4[i][j] = (i == n - 1 || j == m - 1) ? 1 : diag4[i+1][j+1] + 1;
            }
        }
    }

    int maxDiamond = 0;
    // Check each cell for possible diamond size
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int length = min({
                diag1[i][j], diag2[i][j], diag3[i][j], diag4[i][j]
            });
            maxDiamond = max(maxDiamond, length);
        }
    }
    // Diamond size = (length - 1) * 2 + 1 (odd length)
    return maxDiamond == 0 ? 0 : (maxDiamond * 2) - 1;
}

/*
4. Find Largest X Shape formed by 1s
   - X shape means both diagonals have equal arm length.
   - Similar to largest diamond but only count minimum of diag1 and diag4 for one diagonal,
     and diag2 and diag3 for the other diagonal.
*/

int largestXShape(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> diag1(n, vector<int>(m, 0)); // top-left to bottom-right
    vector<vector<int>> diag2(n, vector<int>(m, 0)); // top-right to bottom-left
    vector<vector<int>> diag3(n, vector<int>(m, 0)); // bottom-left to top-right
    vector<vector<int>> diag4(n, vector<int>(m, 0)); // bottom-right to top-left

    // forward pass
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                diag1[i][j] = (i == 0 || j == 0) ? 1 : diag1[i-1][j-1] + 1;
                diag2[i][j] = (i == 0 || j == m - 1) ? 1 : diag2[i-1][j+1] + 1;
            }
        }
    }

    // backward pass
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                diag3[i][j] = (i == n - 1 || j == 0) ? 1 : diag3[i+1][j-1] + 1;
                diag4[i][j] = (i == n - 1 || j == m - 1) ? 1 : diag4[i+1][j+1] + 1;
            }
        }
    }

    int maxX = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                int arm1 = min(diag1[i][j], diag4[i][j]); // one diagonal
                int arm2 = min(diag2[i][j], diag3[i][j]); // other diagonal
                int arm = min(arm1, arm2);
                maxX = max(maxX, arm);
            }
        }
    }
    return maxX;
}

/*
5. Count Number of Plus-Shapes of Certain Size
   - Count plus shapes with arm length exactly = k.
   - Use the largest plus sign DP from first problem, count how many cells have order >= k.
*/
int countPlusShapes(const vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> left(n, vector<int>(m, 0));
    vector<vector<int>> right(n, vector<int>(m, 0));
    vector<vector<int>> up(n, vector<int>(m, 0));
    vector<vector<int>> down(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                left[i][j] = (j == 0) ? 1 : left[i][j-1] + 1;
                up[i][j] = (i == 0) ? 1 : up[i-1][j] + 1;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                right[i][j] = (j == m - 1) ? 1 : right[i][j+1] + 1;
                down[i][j] = (i == n - 1) ? 1 : down[i+1][j] + 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                int order = min({left[i][j], right[i][j], up[i][j], down[i][j]});
                if (order >= k) count++;
            }
        }
    }
    return count;
}

/*
6. Maximal Rectangle with all 0s instead of 1s
   - Classic maximal rectangle problem but for zeros.
   - Convert 0s to 1s, 1s to 0s then run maximal rectangle in histogram.
*/

int maximalRectangleZeros(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);

    auto largestRectangleArea = [](vector<int>& heights) -> int {
        stack<int> st;
        int maxArea = 0;
        int i = 0;
        while (i < (int)heights.size()) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i++);
            } else {
                int top = st.top(); st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, heights[top] * width);
            }
        }
        while (!st.empty()) {
            int top = st.top(); st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, heights[top] * width);
        }
        return maxArea;
    };

    int maxRect = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // treat 0s as 1s, 1s as 0s
            if (matrix[i][j] == 0) heights[j]++;
            else heights[j] = 0;
        }
        maxRect = max(maxRect, largestRectangleArea(heights));
    }
    return maxRect;
}

/* 
Example usage: 
int main() {
    vector<vector<int>> mat = {
        {1,0,1,1,1},
        {1,1,1,0,1},
        {1,1,1,1,1},
        {0,1,0,1,0}
    };

    cout << "Largest Plus Sign order: " << largestPlusSign(mat) << "\n";
    cout << "Largest Cross of 1s: " << largestCross(mat, 1) << "\n";
    cout << "Largest Diamond of 1s: " << largestDiamond(mat) << "\n";
    cout << "Largest X Shape of 1s: " << largestXShape(mat) << "\n";
    cout << "Count Plus Shapes with arm length >= 2: " << countPlusShapes(mat, 2) << "\n";
    cout << "Maximal Rectangle of 0s area: " << maximalRectangleZeros(mat) << "\n";

    return 0;
}
*/

