// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

//////////////////////////
// DP-7: Ninja's Training
//////////////////////////
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n-1][3];
}

//////////////////////////
// DP-8: Unique Paths in Grid
//////////////////////////
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

//////////////////////////
// DP-9: Unique Paths 2 (With Obstacles)
//////////////////////////
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    if(obstacleGrid[0][0] == 1) return 0;
    dp[0][0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else {
                if(i > 0) dp[i][j] += dp[i-1][j];
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

//////////////////////////
// DP-10: Minimum Path Sum in Grid
//////////////////////////
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for(int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
    for(int j = 1; j < n; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

//////////////////////////
// DP-11: Minimum Path Sum in Triangular Grid
//////////////////////////
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> front = triangle[n-1];
    for(int i = n-2; i >= 0; i--) {
        vector<int> curr(i+1, 0);
        for(int j = 0; j <= i; j++) {
            curr[j] = triangle[i][j] + min(front[j], front[j+1]);
        }
        front = curr;
    }
    return front[0];
}

//////////////////////////
// DP-12: Min Falling Path Sum
//////////////////////////
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp = matrix;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int left = j > 0 ? dp[i-1][j-1] : INT_MAX;
            int up = dp[i-1][j];
            int right = j < n-1 ? dp[i-1][j+1] : INT_MAX;
            dp[i][j] += min({left, up, right});
        }
    }
    return *min_element(dp[n-1].begin(), dp[n-1].end());
}

//////////////////////////
// DP-13: Ninja and His Friends (3D DP)
//////////////////////////
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    dp[0][0][c-1] = (0 == c-1) ? grid[0][0] : grid[0][0] + grid[0][c-1];

    for(int i = 1; i < r; i++) {
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                int maxi = INT_MIN;
                for(int dj1 = -1; dj1 <= 1; dj1++) {
                    for(int dj2 = -1; dj2 <= 1; dj2++) {
                        int prev_j1 = j1 - dj1;
                        int prev_j2 = j2 - dj2;
                        if(prev_j1 >= 0 && prev_j1 < c && prev_j2 >= 0 && prev_j2 < c && dp[i-1][prev_j1][prev_j2] != -1) {
                            int val = dp[i-1][prev_j1][prev_j2];
                            if(j1 == j2)
                                val += grid[i][j1];
                            else
                                val += grid[i][j1] + grid[i][j2];
                            maxi = max(maxi, val);
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[r-1][0][c-1];
}

//////////////////////////
// Main Function (Tests)
//////////////////////////
int main() {
    // DP-7
    vector<vector<int>> points = {{10,40,70}, {20,50,80}, {30,60,90}};
    cout << "Ninja's Training: " << ninjaTraining(points.size(), points) << endl;

    // DP-8
    cout << "Unique Paths: " << uniquePaths(3, 3) << endl;

    // DP-9
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << "Unique Paths II: " << uniquePathsWithObstacles(obstacleGrid) << endl;

    // DP-10
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << "Minimum Path Sum: " << minPathSum(grid) << endl;

    // DP-11
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << "Triangle Minimum Path Sum: " << minimumTotal(triangle) << endl;

    // DP-12
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << "Min Falling Path Sum: " << minFallingPathSum(matrix) << endl;

    // DP-13
    vector<vector<int>> chocolateGrid = {
        {2,3,1,2},
        {3,4,2,2},
        {5,6,3,5}
    };
    cout << "Ninja and his Friends (Max Chocolates): " << maximumChocolates(3, 4, chocolateGrid) << endl;

    return 0;
}
