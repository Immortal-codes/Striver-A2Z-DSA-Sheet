#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Helper: Check if string is palindrome
bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

// 1. Palindrome Partitioning (Print all palindrome partitions)
void palindromePartitionHelper(const string &s, int start, vector<string> &current, vector<vector<string>> &res) {
    if (start == (int)s.size()) {
        res.push_back(current);
        return;
    }
    for (int end = start; end < (int)s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            palindromePartitionHelper(s, end + 1, current, res);
            current.pop_back();
        }
    }
}

// 2. Word Search (Check if word exists in board)
bool dfsWordSearch(vector<vector<char>> &board, string &word, int i, int j, int index) {
    if (index == (int)word.size()) return true;
    if (i < 0 || j < 0 || i >= (int)board.size() || j >= (int)board[0].size() || board[i][j] != word[index])
        return false;

    char temp = board[i][j];
    board[i][j] = '#'; // visited

    bool found = dfsWordSearch(board, word, i + 1, j, index + 1) ||
                 dfsWordSearch(board, word, i - 1, j, index + 1) ||
                 dfsWordSearch(board, word, i, j + 1, index + 1) ||
                 dfsWordSearch(board, word, i, j - 1, index + 1);

    board[i][j] = temp;
    return found;
}

bool existWordSearch(vector<vector<char>> &board, string word) {
    for (int i = 0; i < (int)board.size(); i++) {
        for (int j = 0; j < (int)board[0].size(); j++) {
            if (dfsWordSearch(board, word, i, j, 0)) return true;
        }
    }
    return false;
}

// 3. N Queen (Print all solutions)
bool isSafeNQueen(int row, int col, vector<string> &board, int n) {
    // Check vertical and both diagonals
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void solveNQueen(int row, vector<string> &board, vector<vector<string>> &res, int n) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafeNQueen(row, col, board, n)) {
            board[row][col] = 'Q';
            solveNQueen(row + 1, board, res, n);
            board[row][col] = '.';
        }
    }
}

// 4. Rat in a Maze (Print all paths from (0,0) to (n-1,n-1))
void solveRatMaze(int i, int j, vector<vector<int>> &maze, int n, string &path, vector<string> &res, vector<vector<int>> &visited) {
    if (i == n - 1 && j == n - 1) {
        res.push_back(path);
        return;
    }
    // Move Down
    if (i + 1 < n && !visited[i + 1][j] && maze[i + 1][j] == 1) {
        visited[i + 1][j] = 1;
        path.push_back('D');
        solveRatMaze(i + 1, j, maze, n, path, res, visited);
        path.pop_back();
        visited[i + 1][j] = 0;
    }
    // Move Left
    if (j - 1 >= 0 && !visited[i][j - 1] && maze[i][j - 1] == 1) {
        visited[i][j - 1] = 1;
        path.push_back('L');
        solveRatMaze(i, j - 1, maze, n, path, res, visited);
        path.pop_back();
        visited[i][j - 1] = 0;
    }
    // Move Right
    if (j + 1 < n && !visited[i][j + 1] && maze[i][j + 1] == 1) {
        visited[i][j + 1] = 1;
        path.push_back('R');
        solveRatMaze(i, j + 1, maze, n, path, res, visited);
        path.pop_back();
        visited[i][j + 1] = 0;
    }
    // Move Up
    if (i - 1 >= 0 && !visited[i - 1][j] && maze[i - 1][j] == 1) {
        visited[i - 1][j] = 1;
        path.push_back('U');
        solveRatMaze(i - 1, j, maze, n, path, res, visited);
        path.pop_back();
        visited[i - 1][j] = 0;
    }
}

// 5. Word Break (Check if string can be segmented)
bool wordBreakHelper(string &s, vector<string> &dict, int start, vector<int> &dp) {
    if (start == (int)s.size()) return true;
    if (dp[start] != -1) return dp[start];

    for (int end = start; end < (int)s.size(); end++) {
        string word = s.substr(start, end - start + 1);
        if (find(dict.begin(), dict.end(), word) != dict.end() && wordBreakHelper(s, dict, end + 1, dp)) {
            return dp[start] = true;
        }
    }
    return dp[start] = false;
}

// 6. M Coloring Problem (Check if graph can be colored with M colors)
bool isSafeColor(int node, vector<vector<int>> &graph, vector<int> &color, int c) {
    for (int i = 0; i < (int)graph.size(); i++) {
        if (i != node && graph[node][i] && color[i] == c) return false;
    }
    return true;
}

bool graphColoringHelper(int node, vector<vector<int>> &graph, int m, vector<int> &color) {
    if (node == (int)graph.size()) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafeColor(node, graph, color, c)) {
            color[node] = c;
            if (graphColoringHelper(node + 1, graph, m, color)) return true;
            color[node] = 0;
        }
    }
    return false;
}

// 7. Sudoku Solver
bool isSafeSudoku(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;
        if (board[i][col] == c) return false;
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isSafeSudoku(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// 8. Expression Add Operators
void addOperatorsHelper(string &num, int target, int pos, long long currVal, long long last, string expr, vector<string> &res) {
    if (pos == (int)num.size()) {
        if (currVal == target) res.push_back(expr);
        return;
    }
    for (int i = pos; i < (int)num.size(); i++) {
        if (i != pos && num[pos] == '0') break;  // skip leading zero numbers
        string currStr = num.substr(pos, i - pos + 1);
        long long currNum = stoll(currStr);

        if (pos == 0) {
            addOperatorsHelper(num, target, i + 1, currNum, currNum, currStr, res);
        } else {
            addOperatorsHelper(num, target, i + 1, currVal + currNum, currNum, expr + "+" + currStr, res);
            addOperatorsHelper(num, target, i + 1, currVal - currNum, -currNum, expr + "-" + currStr, res);
            addOperatorsHelper(num, target, i + 1, currVal - last + last * currNum, last * currNum, expr + "*" + currStr, res);
        }
    }
}

int main() {
    // Palindrome Partitioning
    string s = "aab";
    vector<vector<string>> palRes;
    vector<string> curr;
    palindromePartitionHelper(s, 0, curr, palRes);
    cout << "Palindrome Partitions of '" << s << "':\n";
    for (auto &v : palRes) {
        for (auto &x : v) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";

    // Word Search
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << "Word Search for '" << word << "': " << (existWordSearch(board, word) ? "Found\n" : "Not Found\n");
    cout << "\n";

    // N Queen
    int n = 4;
    vector<string> boardNQueen(n, string(n, '.'));
    vector<vector<string>> resNQueen;
    solveNQueen(0, boardNQueen, resNQueen, n);
    cout << "N Queen solutions for n=4:\n";
    for (auto &sol : resNQueen) {
        for (auto &row : sol) cout << row << "\n";
        cout << "\n";
    }

    // Rat in a Maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> ratPaths;
    string path = "";
    vector<vector<int>> visited(4, vector<int>(4, 0));
    visited[0][0] = 1;
    solveRatMaze(0, 0, maze, 4, path, ratPaths, visited);
    cout << "Rat in a Maze paths:\n";
    for (auto &p : ratPaths) cout << p << "\n";
    cout << "\n";

    // Word Break
    string str = "leetcode";
    vector<string> dict = {"leet", "code"};
    vector<int> dp(str.size(), -1);
    cout << "Word Break for '" << str << "': " << (wordBreakHelper(str, dict, 0, dp) ? "Yes\n" : "No\n");
    cout << "\n";

    // M Coloring Problem
    vector<vector<int>> graph = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };
    int m = 3;
    vector<int> color(graph.size(), 0);
    cout << "M Coloring Problem with m=3: " << (graphColoringHelper(0, graph, m, color) ? "Possible\n" : "Not Possible\n");
    cout << "\n";

    // Sudoku Solver
    vector<vector<char>> sudoku = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    if (solveSudoku(sudoku)) {
        cout << "Sudoku solved:\n";
        for (auto &row : sudoku) {
            for (auto &ch : row) cout << ch << " ";
            cout << "\n";
        }
    } else {
        cout << "No solution for Sudoku\n";
    }
    cout << "\n";

    // Expression Add Operators
    string num = "123";
    int target = 6;
    vector<string> exprRes;
    addOperatorsHelper(num, target, 0, 0, 0, "", exprRes);
    cout << "Expression Add Operators results for target = " << target << ":\n";
    for (auto &expr : exprRes) cout << expr << "\n";

    return 0;
}
