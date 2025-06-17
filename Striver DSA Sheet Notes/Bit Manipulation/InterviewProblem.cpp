#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ---------------------------------------------
// ✅ 1. Count number of bits to be flipped to convert A to B
int countBitsToFlip(int A, int B) {
    int XOR = A ^ B;
    int count = 0;
    while (XOR) {
        XOR = XOR & (XOR - 1);
        count++;
    }
    return count;
}
// ---------------------------------------------

// ---------------------------------------------
// ✅ 2. Find the number that appears odd number of times
int findOddOccurrence(vector<int> &arr) {
    int xorSum = 0;
    for (int num : arr) xorSum ^= num;
    return xorSum;
}
// ---------------------------------------------

// ---------------------------------------------
// ✅ 3. Power Set (All subsets using bitmask)
vector<vector<int>> powerSet(vector<int> &arr) {
    int n = arr.size();
    int total = 1 << n;
    vector<vector<int>> res;

    for (int mask = 0; mask < total; mask++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j))
                subset.push_back(arr[j]);
        }
        res.push_back(subset);
    }
    return res;
}
// ---------------------------------------------

// ---------------------------------------------
// ✅ 4. XOR of numbers from L to R
int xorUpto(int n) {
    if (n % 4 == 0) return n;
    else if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    return 0;
}

int xorFromLToR(int L, int R) {
    return xorUpto(R) ^ xorUpto(L - 1);
}
// ---------------------------------------------

// ---------------------------------------------
// ✅ 5. Find the two numbers appearing odd number of times
vector<int> findTwoOddNumbers(vector<int> &arr) {
    int xorSum = 0;
    for (int num : arr) xorSum ^= num;

    int setBit = xorSum & -xorSum; // rightmost set bit

    int a = 0, b = 0;
    for (int num : arr) {
        if (num & setBit) a ^= num;
        else b ^= num;
    }
    return {a, b};
}
// ---------------------------------------------

int main() {
    // 1. Count bits to flip
    int A = 10, B = 20;
    cout << "Bits to flip from " << A << " to " << B << " = " << countBitsToFlip(A, B) << "\n";

    // 2. Find number with odd occurrences
    vector<int> arr1 = {1, 2, 3, 2, 3, 1, 3};
    cout << "Odd occurring number = " << findOddOccurrence(arr1) << "\n";

    // 3. Power Set
    vector<int> arr2 = {1, 2, 3};
    cout << "Power Set:\n";
    vector<vector<int>> subsets = powerSet(arr2);
    for (auto subset : subsets) {
        cout << "{ ";
        for (int num : subset) cout << num << " ";
        cout << "}\n";
    }

    // 4. XOR from L to R
    int L = 3, R = 9;
    cout << "XOR from " << L << " to " << R << " = " << xorFromLToR(L, R) << "\n";

    // 5. Find two numbers with odd occurrences
    vector<int> arr3 = {4, 2, 4, 5, 2, 3, 3, 1};
    vector<int> res = findTwoOddNumbers(arr3);
    cout << "Two odd occurring numbers are: " << res[0] << " and " << res[1] << "\n";

    return 0;
}
