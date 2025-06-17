#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 1. Generate all binary strings of length N
void generateBinaryStrings(int n, string &str) {
    if (n == 0) {
        cout << str << "\n";
        return;
    }
    str.push_back('0');
    generateBinaryStrings(n - 1, str);
    str.pop_back();

    str.push_back('1');
    generateBinaryStrings(n - 1, str);
    str.pop_back();
}

// 2. Generate all permutations of a string
void permute(string &s, int l, int r) {
    if (l == r) {
        cout << s << "\n";
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r);
        swap(s[l], s[i]);  // backtrack
    }
}

// 3. Print all subsequences / Power set of a string
void printSubsequences(string &s, int index, string &current) {
    if (index == s.size()) {
        cout << (current.empty() ? "\"\"" : current) << "\n";
        return;
    }
    // Include current char
    current.push_back(s[index]);
    printSubsequences(s, index + 1, current);

    // Exclude current char
    current.pop_back();
    printSubsequences(s, index + 1, current);
}

// 4. N-Queen problem
bool isSafe(int row, int col, vector<int> &positions) {
    for (int i = 0; i < row; i++) {
        if (positions[i] == col || abs(positions[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveNQueens(int n, int row, vector<int> &positions, vector<vector<int>> &solutions) {
    if (row == n) {
        solutions.push_back(positions);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, positions)) {
            positions[row] = col;
            solveNQueens(n, row + 1, positions, solutions);
        }
    }
}

void printSolution(const vector<int> &positions) {
    int n = positions.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (positions[i] == j ? "Q " : ". ");
        }
        cout << "\n";
    }
    cout << "\n";
}

// 5. Sudoku Solver
bool isSafeSudoku(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;
    return true;
}

bool solveSudoku(int grid[9][9], int row, int col) {
    if (row == 8 && col == 9) return true;
    if (col == 9) {
        row++;
        col = 0;
    }
    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafeSudoku(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int choice;
    cout << "Choose a problem to run:\n";
    cout << "1. Generate all binary strings of length N\n";
    cout << "2. Generate all permutations of a string\n";
    cout << "3. Print all subsequences / Power set of a string\n";
    cout << "4. Solve N-Queen problem\n";
    cout << "5. Sudoku Solver\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        int N; cout << "Enter N: "; cin >> N;
        string str = "";
        generateBinaryStrings(N, str);
    }
    else if (choice == 2) {
        string s; cout << "Enter string: "; cin >> s;
        permute(s, 0, s.size() - 1);
    }
    else if (choice == 3) {
        string s; cout << "Enter string: "; cin >> s;
        string current = "";
        printSubsequences(s, 0, current);
    }
    else if (choice == 4) {
        int N; cout << "Enter N: "; cin >> N;
        vector<int> positions(N);
        vector<vector<int>> solutions;
        solveNQueens(N, 0, positions, solutions);
        cout << "Total solutions: " << solutions.size() << "\n";
        for (auto &sol : solutions) {
            printSolution(sol);
        }
    }
    else if (choice == 5) {
        int grid[9][9];
        cout << "Enter Sudoku grid (0 for empty cells):\n";
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        if (solveSudoku(grid, 0, 0)) {
            cout << "Solved Sudoku:\n";
            printGrid(grid);
        } else {
            cout << "No solution exists.\n";
        }
    }
    else {
        cout << "Invalid choice.\n";
    }
    return 0;
}
