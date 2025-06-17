#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Generate all binary strings of length n
void generateBinaryStrings(int n, string &s) {
    if ((int)s.size() == n) {
        cout << s << "\n";
        return;
    }
    s.push_back('0');
    generateBinaryStrings(n, s);
    s.pop_back();

    s.push_back('1');
    generateBinaryStrings(n, s);
    s.pop_back();
}

// 2. Generate valid parentheses
void generateParenthesis(int open, int close, string &s, vector<string> &res) {
    if (open == 0 && close == 0) {
        res.push_back(s);
        return;
    }
    if (open > 0) {
        s.push_back('(');
        generateParenthesis(open - 1, close, s, res);
        s.pop_back();
    }
    if (close > open) {
        s.push_back(')');
        generateParenthesis(open, close - 1, s, res);
        s.pop_back();
    }
}

// 3. Print all subsequences / power set
void printSubsequences(int index, vector<int> &arr, vector<int> &ds) {
    if (index == (int)arr.size()) {
        for (auto &x : ds) cout << x << " ";
        cout << "\n";
        return;
    }
    // Exclude current element
    printSubsequences(index + 1, arr, ds);
    // Include current element
    ds.push_back(arr[index]);
    printSubsequences(index + 1, arr, ds);
    ds.pop_back();
}

// 4. Count all subsequences with sum K
int countSubsequencesWithSumK(int index, vector<int> &arr, int sum, int k) {
    if (index == (int)arr.size()) {
        return (sum == k) ? 1 : 0;
    }
    // Include current element
    int left = countSubsequencesWithSumK(index + 1, arr, sum + arr[index], k);
    // Exclude current element
    int right = countSubsequencesWithSumK(index + 1, arr, sum, k);
    return left + right;
}

// 5. Check if there exists a subsequence with sum K
bool isSubsequenceWithSumK(int index, vector<int> &arr, int sum, int k) {
    if (index == (int)arr.size()) return sum == k;
    // Include
    if (isSubsequenceWithSumK(index + 1, arr, sum + arr[index], k)) return true;
    // Exclude
    if (isSubsequenceWithSumK(index + 1, arr, sum, k)) return true;
    return false;
}

// 6. Combination Sum (Leetcode 39)
void combinationSumHelper(int index, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &res) {
    if (target == 0) {
        res.push_back(ds);
        return;
    }
    if (index == (int)candidates.size() || target < 0) return;

    // Pick current element
    if (candidates[index] <= target) {
        ds.push_back(candidates[index]);
        combinationSumHelper(index, candidates, target - candidates[index], ds, res);
        ds.pop_back();
    }

    // Not pick current element
    combinationSumHelper(index + 1, candidates, target, ds, res);
}

// 7. Combination Sum II (Leetcode 40)
void combinationSum2Helper(int index, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &res) {
    if (target == 0) {
        res.push_back(ds);
        return;
    }
    for (int i = index; i < (int)candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1]) continue;  // skip duplicates
        if (candidates[i] > target) break;

        ds.push_back(candidates[i]);
        combinationSum2Helper(i + 1, candidates, target - candidates[i], ds, res);
        ds.pop_back();
    }
}

// 8. Combination Sum III (k numbers sum to n, 1-9, no repeats)
void combinationSum3Helper(int k, int n, int start, vector<int> &ds, vector<vector<int>> &res) {
    if (k == 0 && n == 0) {
        res.push_back(ds);
        return;
    }
    if (k == 0 || n < 0) return;

    for (int i = start; i <= 9; i++) {
        ds.push_back(i);
        combinationSum3Helper(k - 1, n - i, i + 1, ds, res);
        ds.pop_back();
    }
}

int main() {
    cout << "1. Generate Binary Strings of length 3:\n";
    string s;
    generateBinaryStrings(3, s);
    cout << "\n";

    cout << "2. Generate Parentheses for n=3:\n";
    vector<string> resParen;
    string p;
    generateParenthesis(3, 3, p, resParen);
    for (auto &str : resParen) cout << str << "\n";
    cout << "\n";

    cout << "3. Print all subsequences of [1,2,3]:\n";
    vector<int> arr = {1, 2, 3}, ds;
    printSubsequences(0, arr, ds);
    cout << "\n";

    cout << "4. Count all subsequences with sum = 3 in [1,2,1]:\n";
    vector<int> arrSum = {1, 2, 1};
    cout << countSubsequencesWithSumK(0, arrSum, 0, 3) << "\n\n";

    cout << "5. Check if subsequence with sum = 5 exists in [1,2,3]:\n";
    vector<int> arrCheck = {1, 2, 3};
    cout << (isSubsequenceWithSumK(0, arrCheck, 0, 5) ? "Yes\n" : "No\n") << "\n";

    cout << "6. Combination Sum candidates={2,3,6,7}, target=7:\n";
    vector<int> csum = {2, 3, 6, 7}, dsSum;
    vector<vector<int>> resCSum;
    combinationSumHelper(0, csum, 7, dsSum, resCSum);
    for (auto &v : resCSum) {
        for (int x : v) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";

    cout << "7. Combination Sum II candidates={10,1,2,7,6,1,5}, target=8:\n";
    vector<int> csum2 = {10,1,2,7,6,1,5};
    sort(csum2.begin(), csum2.end());
    vector<int> dsSum2;
    vector<vector<int>> resCSum2;
    combinationSum2Helper(0, csum2, 8, dsSum2, resCSum2);
    for (auto &v : resCSum2) {
        for (int x : v) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";

    cout << "8. Combination Sum III k=3, n=7:\n";
    vector<int> dsSum3;
    vector<vector<int>> resCSum3;
    combinationSum3Helper(3, 7, 1, dsSum3, resCSum3);
    for (auto &v : resCSum3) {
        for (int x : v) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";

    return 0;
}
