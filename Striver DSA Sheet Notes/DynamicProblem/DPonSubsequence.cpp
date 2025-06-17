#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

///////////////////////////////
// DP-14: Subset Sum Equal to Target
///////////////////////////////
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(arr[i] <= target) take = dp[i-1][target - arr[i]];
            dp[i][target] = take || notTake;
        }
    }
    return dp[n-1][k];
}

///////////////////////////////
// DP-15: Partition Equal Subset Sum
///////////////////////////////
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2 != 0) return false;
    return subsetSumToK(nums.size(), sum/2, nums);
}

///////////////////////////////
// DP-16: Partition Set Into 2 Subsets With Min Absolute Sum Diff
///////////////////////////////
int minSubsetSumDifference(vector<int>& arr) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
    for(int i=0; i<n; i++) dp[i][0] = true;
    if(arr[0] <= sum) dp[0][arr[0]] = true;

    for(int i=1; i<n; i++) {
        for(int target=1; target<=sum; target++) {
            bool notTake = dp[i-1][target];
            bool take = false;
            if(arr[i] <= target) take = dp[i-1][target - arr[i]];
            dp[i][target] = take || notTake;
        }
    }

    int minDiff = INT_MAX;
    for(int s1=0; s1<=sum/2; s1++) {
        if(dp[n-1][s1]) {
            int s2 = sum - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }
    return minDiff;
}

///////////////////////////////
// DP-17: Count Subsets with Sum K
///////////////////////////////
int countSubsets(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if(arr[0] <= k) dp[0][arr[0]] = 1;

    for(int i=1; i<n; i++) {
        for(int target=0; target<=k; target++) {
            int notTake = dp[i-1][target];
            int take = 0;
            if(arr[i] <= target) take = dp[i-1][target - arr[i]];
            dp[i][target] = take + notTake;
        }
    }
    return dp[n-1][k];
}

///////////////////////////////
// DP-18: Count Partitions with Given Difference
///////////////////////////////
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum < d || (sum + d) % 2 != 0) return 0;
    int target = (sum + d) / 2;
    return countSubsets(n, target, arr);
}

///////////////////////////////
// Assign Cookies (Greedy problem, but you asked to include)
// We include it as is (not DP)
///////////////////////////////
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0, res = 0;
    while(i < g.size() && j < s.size()) {
        if(s[j] >= g[i]) {
            res++; i++; j++;
        } else {
            j++;
        }
    }
    return res;
}

///////////////////////////////
// DP-20: Minimum Coins
///////////////////////////////
int minimumCoins(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount+1, 1e9);
    dp[0] = 0;
    for(int target=1; target<=amount; target++) {
        for(int coin: coins) {
            if(coin <= target) {
                dp[target] = min(dp[target], 1 + dp[target - coin]);
            }
        }
    }
    return (dp[amount] == 1e9) ? -1 : dp[amount];
}

///////////////////////////////
// DP-21: Target Sum
///////////////////////////////
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(abs(target) > sum) return 0;
    int s = (sum + target);
    if(s % 2 != 0) return 0;
    s /= 2;

    return countSubsets(n, s, nums);
}

///////////////////////////////
// DP-22: Coin Change 2 (Count ways to make amount)
///////////////////////////////
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for(auto &coin : coins) {
        for(int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

///////////////////////////////
// DP-23: Unbounded Knapsack
///////////////////////////////
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<int> dp(w+1, 0);
    for(int cap = 0; cap <= w; cap++) {
        for(int i=0; i<n; i++) {
            if(weight[i] <= cap) {
                dp[cap] = max(dp[cap], profit[i] + dp[cap - weight[i]]);
            }
        }
    }
    return dp[w];
}

///////////////////////////////
// DP-24: Rod Cutting Problem
///////////////////////////////
int cutRod(vector<int> &price, int n) {
    vector<int> dp(n+1, 0);
    for(int length=1; length <= n; length++) {
        int maxVal = INT_MIN;
        for(int cut=1; cut <= length; cut++) {
            maxVal = max(maxVal, price[cut-1] + dp[length - cut]);
        }
        dp[length] = maxVal;
    }
    return dp[n];
}

///////////////////////////////
// Main Function - Test Cases
///////////////////////////////
int main() {
    // DP-14: Subset Sum
    vector<int> arr1 = {2,3,7,8,10};
    cout << "Subset Sum to 11: " << subsetSumToK(arr1.size(), 11, arr1) << "\n";

    // DP-15: Partition Equal Subset Sum
    vector<int> arr2 = {1,5,11,5};
    cout << "Can Partition: " << canPartition(arr2) << "\n";

    // DP-16: Min Subset Sum Diff
    vector<int> arr3 = {1,6,11,5};
    cout << "Min Subset Sum Diff: " << minSubsetSumDifference(arr3) << "\n";

    // DP-17: Count Subsets with Sum K
    vector<int> arr4 = {1,2,2,3};
    cout << "Count Subsets sum=4: " << countSubsets(arr4.size(), 4, arr4) << "\n";

    // DP-18: Count Partitions with Given Difference
    vector<int> arr5 = {1,1,2,3};
    cout << "Count Partitions with diff=1: " << countPartitions(arr5.size(), 1, arr5) << "\n";

    // Assign Cookies (Greedy)
    vector<int> children = {1,2,3};
    vector<int> cookies = {1,1};
    cout << "Assign Cookies: " << findContentChildren(children, cookies) << "\n";

    // DP-20: Minimum Coins
    vector<int> coins = {1,2,5};
    cout << "Min Coins for 11: " << minimumCoins(coins, 11) << "\n";

    // DP-21: Target Sum
    vector<int> arr6 = {1,1,1,1,1};
    cout << "Target Sum ways (3): " << findTargetSumWays(arr6, 3) << "\n";

    // DP-22: Coin Change 2
    vector<int> coins2 = {1,2,5};
    cout << "Coin Change 2 ways for 5: " << change(5, coins2) << "\n";

    // DP-23: Unbounded Knapsack
    vector<int> profit = {15,14,10,45,30};
    vector<int> weight = {2,5,1,3,4};
    int capacity = 7;
    cout << "Unbounded Knapsack: " << unboundedKnapsack(profit.size(), capacity, profit, weight) << "\n";

    // DP-24: Rod Cutting
    vector<int> price = {1,5,8,9,10,17,17,20};
    cout << "Rod Cutting max profit: " << cutRod(price, price.size()) << "\n";

    return 0;
}
