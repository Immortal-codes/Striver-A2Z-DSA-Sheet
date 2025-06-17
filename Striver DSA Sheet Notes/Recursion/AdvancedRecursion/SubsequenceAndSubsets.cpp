#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Print all subsets (power set)
void printSubsets(vector<int> &arr, int index, vector<int> &current) {
    if (index == arr.size()) {
        cout << "{ ";
        for (int x : current) cout << x << " ";
        cout << "}\n";
        return;
    }
    // Include current element
    current.push_back(arr[index]);
    printSubsets(arr, index + 1, current);

    // Exclude current element
    current.pop_back();
    printSubsets(arr, index + 1, current);
}

// 2. Count subsequences with sum K
int countSubseqSumK(vector<int> &arr, int index, int sum, int K) {
    if (index == arr.size()) {
        return (sum == K) ? 1 : 0;
    }
    // Include current element
    int left = countSubseqSumK(arr, index + 1, sum + arr[index], K);
    // Exclude current element
    int right = countSubseqSumK(arr, index + 1, sum, K);
    return left + right;
}

// 3. Combination Sum (unlimited repetition allowed)
void combinationSumUnlimited(vector<int> &candidates, int target, int start, vector<int> &current, vector<vector<int>> &result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] <= target) {
            current.push_back(candidates[i]);
            combinationSumUnlimited(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
}

// 4. Combination Sum II (no repetition)
void combinationSumNoRepeat(vector<int> &candidates, int target, int start, vector<int> &current, vector<vector<int>> &result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // skip duplicates
        if (candidates[i] > target) break;
        current.push_back(candidates[i]);
        combinationSumNoRepeat(candidates, target - candidates[i], i + 1, current, result);
        current.pop_back();
    }
}

// 5. Subset Sum Problem (yes/no)
bool subsetSum(vector<int> &arr, int index, int target) {
    if (target == 0) return true;
    if (index == arr.size() || target < 0) return false;

    // Include current element or exclude it
    return subsetSum(arr, index + 1, target - arr[index]) || subsetSum(arr, index + 1, target);
}

// Helper to print vector<vector<int>>
void printResults(const vector<vector<int>> &results) {
    for (auto &v : results) {
        cout << "{ ";
        for (int x : v) cout << x << " ";
        cout << "}\n";
    }
}

int main() {
    while (true) {
        cout << "\nChoose a problem to run:\n";
        cout << "1. Print all subsets (power set)\n";
        cout << "2. Count subsequences with sum K\n";
        cout << "3. Combination Sum (unlimited repetition allowed)\n";
        cout << "4. Combination Sum II (no repetition)\n";
        cout << "5. Subset Sum Problem (yes/no)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        int choice; cin >> choice;

        if (choice == 6) break;

        if (choice == 1) {
            int n; cout << "Enter number of elements: "; cin >> n;
            vector<int> arr(n);
            cout << "Enter elements:\n";
            for (int &x : arr) cin >> x;
            vector<int> current;
            cout << "All subsets:\n";
            printSubsets(arr, 0, current);
        }
        else if (choice == 2) {
            int n, K;
            cout << "Enter number of elements: "; cin >> n;
            vector<int> arr(n);
            cout << "Enter elements:\n";
            for (int &x : arr) cin >> x;
            cout << "Enter sum K: "; cin >> K;
            int count = countSubseqSumK(arr, 0, 0, K);
            cout << "Number of subsequences with sum " << K << ": " << count << "\n";
        }
        else if (choice == 3) {
            int n, target;
            cout << "Enter number of candidates: "; cin >> n;
            vector<int> candidates(n);
            cout << "Enter candidates:\n";
            for (int &x : candidates) cin >> x;
            cout << "Enter target sum: "; cin >> target;
            vector<vector<int>> results;
            vector<int> current;
            combinationSumUnlimited(candidates, target, 0, current, results);
            cout << "Combination Sum (unlimited) results:\n";
            printResults(results);
        }
        else if (choice == 4) {
            int n, target;
            cout << "Enter number of candidates: "; cin >> n;
            vector<int> candidates(n);
            cout << "Enter candidates:\n";
            for (int &x : candidates) cin >> x;
            cout << "Enter target sum: "; cin >> target;
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> results;
            vector<int> current;
            combinationSumNoRepeat(candidates, target, 0, current, results);
            cout << "Combination Sum II (no repetition) results:\n";
            printResults(results);
        }
        else if (choice == 5) {
            int n, target;
            cout << "Enter number of elements: "; cin >> n;
            vector<int> arr(n);
            cout << "Enter elements:\n";
            for (int &x : arr) cin >> x;
            cout << "Enter target sum: "; cin >> target;
            bool res = subsetSum(arr, 0, target);
            cout << "Subset with sum " << target << (res ? " exists.\n" : " does not exist.\n");
        }
        else {
            cout << "Invalid choice, try again.\n";
        }
    }
    cout << "Program exited.\n";
    return 0;
}
