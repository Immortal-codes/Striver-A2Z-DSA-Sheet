// #include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;

/*
1. Maximum Rectangle Area with all 1's
   - Largest rectangle of 1s in binary matrix.
   - Uses Largest Rectangle in Histogram as subproblem.
*/

// Largest Rectangle in Histogram (Helper for problem 1)
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;
    for (int i = 0; i <= n; ++i)
    {
        int h = (i == n ? 0 : heights[i]);
        while (!st.empty() && heights[st.top()] > h)
        {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<int>> &matrix)
{
    if (matrix.empty())
        return 0;
    int maxArea = 0;
    int n = matrix.size(), m = matrix[0].size();
    vector<int> heights(m, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 1)
                heights[j]++;
            else
                heights[j] = 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

/*
2. Count Square Submatrices with All Ones
   - Count all square submatrices filled with 1s.
*/

int countSquares(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 1)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                count += dp[i][j];
            }
        }
    }
    return count;
}

/*
3 & 4. Largest Square of 1s / Maximal Square (LeetCode)
   - Find side length of largest square containing all 1s.
   - Same DP as above, just return max side length.
*/

int maximalSquare(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxSide = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 1)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide;
}

/*
5. Largest Plus Sign in a Grid
   - Find largest plus sign with equal arm lengths.
   - Uses prefix/suffix counts from all 4 directions.
*/

int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
{
    vector<vector<int>> grid(n, vector<int>(n, 1));
    for (auto &m : mines)
        grid[m[0]][m[1]] = 0;

    vector<vector<int>> left(n, vector<int>(n, 0));
    vector<vector<int>> right(n, vector<int>(n, 0));
    vector<vector<int>> up(n, vector<int>(n, 0));
    vector<vector<int>> down(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            left[i][j] = (grid[i][j] == 1) ? (j == 0 ? 1 : left[i][j - 1] + 1) : 0;
            up[i][j] = (grid[i][j] == 1) ? (i == 0 ? 1 : up[i - 1][j] + 1) : 0;
        }
        for (int j = n - 1; j >= 0; j--)
        {
            right[i][j] = (grid[i][j] == 1) ? (j == n - 1 ? 1 : right[i][j + 1] + 1) : 0;
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            down[i][j] = (grid[i][j] == 1) ? (i == n - 1 ? 1 : down[i + 1][j] + 1) : 0;
        }
    }

    int maxOrder = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int order = min({left[i][j], right[i][j], up[i][j], down[i][j]});
            maxOrder = max(maxOrder, order);
        }
    }
    return maxOrder;
}

/*
6. Count Rectangles of 1s in Binary Matrix
   - Count all rectangles consisting of all 1s.
   - For each row, count histogram rectangles and sum.
*/

int countRectangles(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    int totalRectangles = 0;

    for (int i = 0; i < n; ++i)
    {
        stack<int> st;
        int sum = 0;
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 1)
                heights[j]++;
            else
                heights[j] = 0;
        }

        for (int j = 0; j < m; ++j)
        {
            while (!st.empty() && heights[st.top()] >= heights[j])
            {
                st.pop();
            }
            if (st.empty())
                sum += heights[j] * (j + 1);
            else
                sum += heights[j] * (j - st.top());
            st.push(j);
        }
        totalRectangles += sum;
    }
    return totalRectangles;
}

/*
7. Number of Islands (DFS + DP Hybrid)
   - Count connected components of 1s.
*/

void dfsIslands(int i, int j, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
        return;
    grid[i][j] = 0; // mark visited
    dfsIslands(i + 1, j, grid);
    dfsIslands(i - 1, j, grid);
    dfsIslands(i, j + 1, grid);
    dfsIslands(i, j - 1, grid);
}

int numIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (n == 0)
        return 0;
    int m = grid[0].size();
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 1)
            {
                ++count;
                dfsIslands(i, j, grid);
            }
        }
    }
    return count;
}

/*
8. Maximum Path Sum in Grid (DP on grids)
   - Max sum path from top-left to bottom-right moving right or down.
*/

int maxPathSumGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < m; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

/*
9. Minimum Path Sum in Grid
   - Minimize sum path from top-left to bottom-right.
*/

int minPathSumGrid(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int j = 1; j < m; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

/*
10. Unique Paths & Unique Paths with Obstacles
   - Count unique ways from top-left to bottom-right.
*/

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < m; i++)
        dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
    for (int j = 1; j < n; j++)
        dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;

    for (int i = 1; i < m; i++)
    {
    }
}