#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

//////////////////////////////
// DP-48: Matrix Chain Multiplication (Top-Down)
//////////////////////////////
int matrixChainMemo(vector<int>& dims, int i, int j, vector<vector<int>>& dp) {
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i; k < j; k++) {
        int cost = matrixChainMemo(dims, i, k, dp) + matrixChainMemo(dims, k+1, j, dp) + dims[i-1]*dims[k]*dims[j];
        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}

int matrixChainMultiplication(vector<int>& dims) {
    int n = (int)dims.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return matrixChainMemo(dims, 1, n-1, dp);
}

//////////////////////////////
// DP-49: Matrix Chain Multiplication Bottom-Up
//////////////////////////////
int matrixChainMultiplicationBU(vector<int>& dims) {
    int n = (int)dims.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int length=2; length<n; length++) {
        for(int i=1; i<n-length+1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n-1];
}

//////////////////////////////
// DP-50: Minimum Cost to Cut the Stick
//////////////////////////////
int minCostCutStick(vector<int>& cuts, int i, int j, vector<vector<int>>& dp, int left, int right) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int cost = INT_MAX;
    for(int k=i; k<=j; k++) {
        int currCost = right - left + minCostCutStick(cuts, i, k-1, dp, left, cuts[k]) + minCostCutStick(cuts, k+1, j, dp, cuts[k], right);
        cost = min(cost, currCost);
    }
    return dp[i][j] = cost;
}

int minCostToCutStick(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int m = (int)cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    return minCostCutStick(cuts, 1, m-2, dp, 0, n);
}

//////////////////////////////
// DP-51: Burst Balloons
//////////////////////////////
int burstBalloonsHelper(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int maxCoins = 0;
    for(int k = i; k <= j; k++) {
        int leftVal = (i == 0) ? 1 : nums[i-1];
        int rightVal = (j == (int)nums.size()-1) ? 1 : nums[j+1];
        int coins = leftVal * nums[k] * rightVal + burstBalloonsHelper(nums, i, k-1, dp) + burstBalloonsHelper(nums, k+1, j, dp);
        maxCoins = max(maxCoins, coins);
    }
    return dp[i][j] = maxCoins;
}

int maxCoinsBurstBalloons(vector<int>& nums) {
    int n = (int)nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return burstBalloonsHelper(nums, 0, n-1, dp);
}

//////////////////////////////
// DP-52: Evaluate Boolean Expression to True
//////////////////////////////
int countWaysToTrue(string &s, int i, int j, bool isTrue, vector<vector<vector<int>>>& dp) {
    if(i > j) return 0;
    if(i == j) {
        if(isTrue)
            return s[i] == 'T' ? 1 : 0;
        else
            return s[i] == 'F' ? 1 : 0;
    }
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    int ways = 0;
    for(int k = i+1; k <= j-1; k+=2) {
        int leftTrue = countWaysToTrue(s, i, k-1, true, dp);
        int leftFalse = countWaysToTrue(s, i, k-1, false, dp);
        int rightTrue = countWaysToTrue(s, k+1, j, true, dp);
        int rightFalse = countWaysToTrue(s, k+1, j, false, dp);

        if(s[k] == '&') {
            if(isTrue) ways += leftTrue * rightTrue;
            else ways += leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse;
        } else if(s[k] == '|') {
            if(isTrue) ways += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
            else ways += leftFalse * rightFalse;
        } else if(s[k] == '^') {
            if(isTrue) ways += leftTrue * rightFalse + leftFalse * rightTrue;
            else ways += leftTrue * rightTrue + leftFalse * rightFalse;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int countWays(string s) {
    int n = (int)s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return countWaysToTrue(s, 0, n-1, true, dp);
}

//////////////////////////////
// DP-53: Palindrome Partitioning - II
//////////////////////////////
int minCutPalindromePartition(string s) {
    int n = (int)s.size();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));

    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(s[i] == s[j] && (j - i < 2 || isPal[i+1][j-1])) {
                isPal[i][j] = true;
            }
        }
    }

    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++) {
        if(isPal[0][i]) {
            dp[i] = 0;
        } else {
            dp[i] = INT_MAX;
            for(int j = 0; j < i; j++) {
                if(isPal[j+1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    return dp[n-1];
}

//////////////////////////////
// DP-54: Partition Array for Maximum Sum
//////////////////////////////
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = (int)arr.size();
    vector<int> dp(n, 0);
    for(int i=0; i<n; i++) {
        int maxElem = 0;
        for(int j=1; j<=k && i-j+1>=0; j++) {
            maxElem = max(maxElem, arr[i-j+1]);
            int curr = maxElem * j + (i-j >= 0 ? dp[i-j] : 0);
            dp[i] = max(dp[i], curr);
        }
    }
    return dp[n-1];
}

//////////////////////////////
// Main for quick testing
//////////////////////////////
int main() {
    vector<int> dims = {40, 20, 30, 10, 30};
    cout << "DP-48 Matrix Chain Multiplication (Top-Down): " << matrixChainMultiplication(dims) << "\n";
    cout << "DP-49 Matrix Chain Multiplication (Bottom-Up): " << matrixChainMultiplicationBU(dims) << "\n";

    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    cout << "DP-50 Min Cost to Cut Stick: " << minCostToCutStick(n, cuts) << "\n";

    vector<int> balloons = {3,1,5,8};
    cout << "DP-51 Max Coins Burst Balloons: " << maxCoinsBurstBalloons(balloons) << "\n";

    string boolExp = "T|F&T^F";
    cout << "DP-52 Count Ways to Evaluate True: " << countWays(boolExp) << "\n";

    string palindromeStr = "aab";
    cout << "DP-53 Min Cut Palindrome Partitioning: " << minCutPalindromePartition(palindromeStr) << "\n";

    vector<int> partitionArr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << "DP-54 Partition Array for Max Sum: " << maxSumAfterPartitioning(partitionArr, k) << "\n";

    return 0;
}
