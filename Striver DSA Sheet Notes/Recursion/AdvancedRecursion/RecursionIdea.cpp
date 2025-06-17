#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 1. Fibonacci with memoization
int fibMemo(int n, vector<int> &dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

int fibonacci(int n) {
    vector<int> dp(n + 1, -1);
    return fibMemo(n, dp);
}

// 2. Climbing Stairs - number of ways to climb n steps (1 or 2 steps)
int climbStairsMemo(int n, vector<int> &dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
}

int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return climbStairsMemo(n, dp);
}

// 3. Decode Ways - number of ways to decode a string of digits
int numDecodingsMemo(const string &s, int index, vector<int> &dp) {
    int n = s.size();
    if (index == n) return 1;  // reached end, one valid decoding
    if (s[index] == '0') return 0;  // no decoding if starts with zero
    if (dp[index] != -1) return dp[index];

    int ways = numDecodingsMemo(s, index + 1, dp);
    if (index + 1 < n) {
        int val = stoi(s.substr(index, 2));
        if (val <= 26) ways += numDecodingsMemo(s, index + 2, dp);
    }
    return dp[index] = ways;
}

int numDecodings(string s) {
    vector<int> dp(s.size(), -1);
    return numDecodingsMemo(s, 0, dp);
}

// 4. Edit Distance - min operations to convert s1 to s2 (insert, delete, replace)
int editDistanceMemo(const string &s1, const string &s2, int i, int j, vector<vector<int>> &dp) {
    if (i == 0) return j; // insert all remaining j chars
    if (j == 0) return i; // delete all remaining i chars
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i-1] == s2[j-1]) 
        return dp[i][j] = editDistanceMemo(s1, s2, i-1, j-1, dp);
    else {
        int insertOp = editDistanceMemo(s1, s2, i, j-1, dp);
        int deleteOp = editDistanceMemo(s1, s2, i-1, j, dp);
        int replaceOp = editDistanceMemo(s1, s2, i-1, j-1, dp);
        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }
}

int editDistance(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return editDistanceMemo(s1, s2, m, n, dp);
}

// 5. Longest Increasing Subsequence (LIS) - length of LIS
int LISMemo(const vector<int> &nums, int currIndex, int prevIndex, vector<vector<int>> &dp) {
    if (currIndex == nums.size()) return 0;
    if (dp[currIndex][prevIndex + 1] != -1) return dp[currIndex][prevIndex + 1];

    int taken = 0;
    if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
        taken = 1 + LISMemo(nums, currIndex + 1, currIndex, dp);
    }
    int notTaken = LISMemo(nums, currIndex + 1, prevIndex, dp);

    return dp[currIndex][prevIndex + 1] = max(taken, notTaken);
}

int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return LISMemo(nums, 0, -1, dp);
}

// Main to test
int main() {
    cout << "Fibonacci(10): " << fibonacci(10) << "\n";
    cout << "Climbing Stairs(5): " << climbStairs(5) << "\n";
    cout << "Decode Ways(\"226\"): " << numDecodings("226") << "\n";
    cout << "Edit Distance(\"horse\", \"ros\"): " << editDistance("horse", "ros") << "\n";
    
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << "Length of LIS: " << lengthOfLIS(nums) << "\n";

    return 0;
}
