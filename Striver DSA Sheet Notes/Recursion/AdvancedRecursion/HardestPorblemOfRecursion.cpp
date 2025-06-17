#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------- 1. M Coloring Problem ----------
bool isSafeColor(int node, const vector<vector<int>> &graph, vector<int> &color, int c) {
    for (int adj : graph[node]) {
        if (color[adj] == c) return false;
    }
    return true;
}

bool mColoringHelper(int node, vector<vector<int>> &graph, int m, vector<int> &color) {
    int n = graph.size();
    if (node == n) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafeColor(node, graph, color, c)) {
            color[node] = c;
            if (mColoringHelper(node + 1, graph, m, color))
                return true;
            color[node] = 0;  // backtrack
        }
    }
    return false;
}

bool mColoringProblem(vector<vector<int>> &graph, int m, vector<int> &color) {
    return mColoringHelper(0, graph, m, color);
}

// ---------- 2. Crossword Puzzle Solver ----------
bool canPlaceWordHorizontally(vector<vector<char>> &board, string &word, int row, int col) {
    int n = board.size(), m = board[0].size();
    if (col + (int)word.size() > m) return false;
    for (int i = 0; i < (int)word.size(); i++) {
        if (board[row][col + i] != '-' && board[row][col + i] != word[i])
            return false;
    }
    return true;
}

bool canPlaceWordVertically(vector<vector<char>> &board, string &word, int row, int col) {
    int n = board.size(), m = board[0].size();
    if (row + (int)word.size() > n) return false;
    for (int i = 0; i < (int)word.size(); i++) {
        if (board[row + i][col] != '-' && board[row + i][col] != word[i])
            return false;
    }
    return true;
}

vector<bool> placeWordHorizontally(vector<vector<char>> &board, string &word, int row, int col) {
    vector<bool> wePlaced(word.size(), false);
    for (int i = 0; i < (int)word.size(); i++) {
        if (board[row][col + i] == '-') {
            board[row][col + i] = word[i];
            wePlaced[i] = true;
        }
    }
    return wePlaced;
}

void unplaceWordHorizontally(vector<vector<char>> &board, int row, int col, vector<bool> &wePlaced) {
    for (int i = 0; i < (int)wePlaced.size(); i++) {
        if (wePlaced[i]) board[row][col + i] = '-';
    }
}

vector<bool> placeWordVertically(vector<vector<char>> &board, string &word, int row, int col) {
    vector<bool> wePlaced(word.size(), false);
    for (int i = 0; i < (int)word.size(); i++) {
        if (board[row + i][col] == '-') {
            board[row + i][col] = word[i];
            wePlaced[i] = true;
        }
    }
    return wePlaced;
}

void unplaceWordVertically(vector<vector<char>> &board, int row, int col, vector<bool> &wePlaced) {
    for (int i = 0; i < (int)wePlaced.size(); i++) {
        if (wePlaced[i]) board[row + i][col] = '-';
    }
}

bool crosswordSolverHelper(vector<vector<char>> &board, vector<string> &words, int index) {
    if (index == (int)words.size()) return true;

    int n = board.size(), m = board[0].size();
    string &word = words[index];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (canPlaceWordHorizontally(board, word, r, c)) {
                vector<bool> placed = placeWordHorizontally(board, word, r, c);
                if (crosswordSolverHelper(board, words, index + 1)) return true;
                unplaceWordHorizontally(board, r, c, placed);
            }
            if (canPlaceWordVertically(board, word, r, c)) {
                vector<bool> placed = placeWordVertically(board, word, r, c);
                if (crosswordSolverHelper(board, words, index + 1)) return true;
                unplaceWordVertically(board, r, c, placed);
            }
        }
    }
    return false;
}

bool crosswordPuzzleSolver(vector<vector<char>> &board, vector<string> &words) {
    return crosswordSolverHelper(board, words, 0);
}

// ---------- 3. Sudoku Solver ----------
bool isSafeSudoku(vector<vector<int>> &board, int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val) return false;
        if (board[i][col] == val) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false;
    }
    return true;
}

bool sudokuSolverHelper(vector<vector<int>> &board, int row, int col) {
    if (row == 9) return true;
    if (col == 9) return sudokuSolverHelper(board, row + 1, 0);
    if (board[row][col] != 0) return sudokuSolverHelper(board, row, col + 1);

    for (int val = 1; val <= 9; val++) {
        if (isSafeSudoku(board, row, col, val)) {
            board[row][col] = val;
            if (sudokuSolverHelper(board, row, col + 1)) return true;
            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

bool sudokuSolver(vector<vector<int>> &board) {
    return sudokuSolverHelper(board, 0, 0);
}

// ---------- 4. Hamiltonian Path ----------
bool isSafeHamiltonian(int node, vector<vector<int>> &graph, vector<int> &path, int pos) {
    // Check if node is adjacent to previous node in path
    if (find(graph[path[pos - 1]].begin(), graph[path[pos - 1]].end(), node) == graph[path[pos - 1]].end()) return false;

    // Check if node already in path
    for (int i = 0; i < pos; i++)
        if (path[i] == node) return false;

    return true;
}

bool hamiltonianPathHelper(vector<vector<int>> &graph, vector<int> &path, int pos) {
    int n = graph.size();
    if (pos == n) return true;

    for (int v = 0; v < n; v++) {
        if (isSafeHamiltonian(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianPathHelper(graph, path, pos + 1))
                return true;
            path[pos] = -1; // backtrack
        }
    }
    return false;
}

bool hamiltonianPath(vector<vector<int>> &graph, vector<int> &path) {
    int n = graph.size();
    path.assign(n, -1);
    // Try each vertex as start vertex
    for (int start = 0; start < n; start++) {
        path[0] = start;
        if (hamiltonianPathHelper(graph, path, 1))
            return true;
    }
    return false;
}

// ---------- 5. Knight's Tour Problem ----------
int movesX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int movesY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafeKnight(int x, int y, int n, vector<vector<int>> &board) {
    return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
}

bool knightTourHelper(int x, int y, int movei, int n, vector<vector<int>> &board) {
    if (movei == n * n) return true;

    for (int k = 0; k < 8; k++) {
        int nextX = x + movesX[k];
        int nextY = y + movesY[k];
        if (isSafeKnight(nextX, nextY, n, board)) {
            board[nextX][nextY] = movei;
            if (knightTourHelper(nextX, nextY, movei + 1, n, board))
                return true;
            board[nextX][nextY] = -1; // backtrack
        }
    }
    return false;
}

bool knightTour(int n, vector<vector<int>> &board, int startX, int startY) {
    board.assign(n, vector<int>(n, -1));
    board[startX][startY] = 0;  // starting position

    if (knightTourHelper(startX, startY, 1, n, board))
        return true;

    return false;
}

// -----------------------
// Main for quick testing
int main() {
    // 1. M Coloring Problem example (simple graph)
    cout << "M Coloring Problem:\n";
    int nodes = 4;
    vector<vector<int>> graph(nodes);
    // Graph edges (undirected)
    graph[0] = {1,2};
    graph[1] = {0,2,3};
    graph[2] = {0,1,3};
    graph[3] = {1,2};

    int M = 3;
    vector<int> colors(nodes, 0);
    if (mColoringProblem(graph, M, colors)) {
        cout << "Possible coloring:\n";
        for (int c : colors) cout << c << " ";
        cout << "\n";
    } else cout << "No coloring possible\n";

    // 2. Crossword Puzzle Solver example
    cout << "\nCrossword Puzzle Solver:\n";
}