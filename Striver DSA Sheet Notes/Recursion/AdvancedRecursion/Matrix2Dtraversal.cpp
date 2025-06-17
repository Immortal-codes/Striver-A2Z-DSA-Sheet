#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1. Rat in a Maze - print all paths from (0,0) to (N-1,N-1)
void ratInMazeHelper(vector<vector<int>> &maze, int x, int y, vector<string> &paths, string path) {
    int n = maze.size();
    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }
    // Mark current cell as visited by setting it 0 temporarily
    maze[x][y] = 0;

    // Move Down
    if (x + 1 < n && maze[x + 1][y] == 1) {
        ratInMazeHelper(maze, x + 1, y, paths, path + "D");
    }
    // Move Left
    if (y - 1 >= 0 && maze[x][y - 1] == 1) {
        ratInMazeHelper(maze, x, y - 1, paths, path + "L");
    }
    // Move Right
    if (y + 1 < n && maze[x][y + 1] == 1) {
        ratInMazeHelper(maze, x, y + 1, paths, path + "R");
    }
    // Move Up
    if (x - 1 >= 0 && maze[x - 1][y] == 1) {
        ratInMazeHelper(maze, x - 1, y, paths, path + "U");
    }
    maze[x][y] = 1; // backtrack
}

vector<string> ratInMaze(vector<vector<int>> &maze) {
    vector<string> paths;
    if (maze[0][0] == 0) return paths;
    ratInMazeHelper(maze, 0, 0, paths, "");
    return paths;
}

// 2. Word Search - check if word exists in grid (DFS)
bool existHelper(vector<vector<char>> &board, string &word, int index, int x, int y) {
    if (index == word.size()) return true;
    int m = board.size(), n = board[0].size();
    if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != word[index]) return false;

    char temp = board[x][y];
    board[x][y] = '#'; // mark visited

    bool found = existHelper(board, word, index + 1, x + 1, y) ||
                 existHelper(board, word, index + 1, x - 1, y) ||
                 existHelper(board, word, index + 1, x, y + 1) ||
                 existHelper(board, word, index + 1, x, y - 1);

    board[x][y] = temp; // backtrack
    return found;
}

bool wordSearch(vector<vector<char>> &board, string word) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                if (existHelper(board, word, 0, i, j)) return true;
            }
        }
    }
    return false;
}

// 3. Number of Islands - count connected components (DFS)
void dfsIsland(vector<vector<char>> &grid, int x, int y) {
    int m = grid.size(), n = grid[0].size();
    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0') return;

    grid[x][y] = '0'; // mark visited
    dfsIsland(grid, x + 1, y);
    dfsIsland(grid, x - 1, y);
    dfsIsland(grid, x, y + 1);
    dfsIsland(grid, x, y - 1);
}

int numIslands(vector<vector<char>> &grid) {
    int count = 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfsIsland(grid, i, j);
            }
        }
    }
    return count;
}

// 4. Unique Paths in a grid (from top-left to bottom-right)
int uniquePathsHelper(int m, int n, int x, int y, vector<vector<int>> &dp) {
    if (x == m - 1 && y == n - 1) return 1;
    if (x >= m || y >= n) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = uniquePathsHelper(m, n, x + 1, y, dp) + uniquePathsHelper(m, n, x, y + 1, dp);
    return dp[x][y];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePathsHelper(m, n, 0, 0, dp);
}

// 5. Flood Fill Algorithm (change color connected area)
void floodFillHelper(vector<vector<int>> &image, int x, int y, int oldColor, int newColor) {
    int m = image.size(), n = image[0].size();
    if (x < 0 || y < 0 || x >= m || y >= n) return;
    if (image[x][y] != oldColor) return;

    image[x][y] = newColor;
    floodFillHelper(image, x + 1, y, oldColor, newColor);
    floodFillHelper(image, x - 1, y, oldColor, newColor);
    floodFillHelper(image, x, y + 1, oldColor, newColor);
    floodFillHelper(image, x, y - 1, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor != newColor) {
        floodFillHelper(image, sr, sc, oldColor, newColor);
    }
    return image;
}

int main() {
    // 1. Rat in Maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    auto paths = ratInMaze(maze);
    cout << "Rat in Maze paths:\n";
    for (auto &p : paths) cout << p << "\n";
    cout << "\n";

    // 2. Word Search
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << "Word Search for \"" << word << "\": " << (wordSearch(board, word) ? "Found\n" : "Not Found\n");
    cout << "\n";

    // 3. Number of Islands
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of Islands: " << numIslands(grid) << "\n\n";

    // 4. Unique Paths
    int m = 3, n = 3;
    cout << "Unique paths in a " << m << "x" << n << " grid: " << uniquePaths(m, n) << "\n\n";

    // 5. Flood Fill
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> filledImage = floodFill(image, sr, sc, newColor);
    cout << "Flood fill result:\n";
    for (auto &row : filledImage) {
        for (auto &val : row) cout << val << " ";
        cout << "\n";
    }

    return 0;
}
