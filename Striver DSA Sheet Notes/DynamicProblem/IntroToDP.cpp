#include <iostream>
#include <vector>
using namespace std;

// ----------- Fibonacci with Memoization (Top-Down) -----------
int fibMemo(int n, vector<int> &dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];

    dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
    return dp[n];
}

// ----------- Fibonacci with Tabulation (Bottom-Up) -----------
int fibTab(int n) {
    if (n <= 1) return n;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n = 10;

    // Memoization call
    vector<int> dp(n + 1, -1);
    cout << "Fibonacci (Memoization) of " << n << " is: " << fibMemo(n, dp) << "\n";

    // Tabulation call
    cout << "Fibonacci (Tabulation) of " << n << " is: " << fibTab(n) << "\n";

    return 0;
}
