// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

//////////////////////////
// DP-3: Frog Jump
//////////////////////////
int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        int jumpOne = dp[i-1] + abs(heights[i] - heights[i-1]);
        int jumpTwo = INT_MAX;
        if(i > 1)
            jumpTwo = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(jumpOne, jumpTwo);
    }
    return dp[n-1];
}

//////////////////////////
// DP-4: Frog Jump with K Distances
//////////////////////////
int frogJumpK(int n, int k, vector<int> &heights) {
    vector<int> dp(n, 0);
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        int minSteps = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }

    return dp[n-1];
}

//////////////////////////
// DP-5: Maximum Sum of Non-Adjacent Elements
//////////////////////////
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];

    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++) {
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = prev;
        int curr = max(take, notTake);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

//////////////////////////
// DP-6: House Robber
//////////////////////////
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];

    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++) {
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = prev;
        int curr = max(take, notTake);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

//////////////////////////
// Main Function (Test Cases)
//////////////////////////
int main() {
    // Test DP-3: Frog Jump
    vector<int> heights1 = {10, 20, 30, 10};
    cout << "Frog Jump: " << frogJump(heights1.size(), heights1) << endl;

    // Test DP-4: Frog Jump with K distances
    int k = 2;
    vector<int> heights2 = {10, 20, 10, 40, 30};
    cout << "Frog Jump with K: " << frogJumpK(heights2.size(), k, heights2) << endl;

    // Test DP-5: Maximum Sum of Non-Adjacent Elements
    vector<int> arr1 = {2, 1, 4, 9};
    cout << "Max Non-Adjacent Sum: " << maximumNonAdjacentSum(arr1) << endl;

    // Test DP-6: House Robber
    vector<int> arr2 = {1, 2, 3, 1};
    cout << "House Robber: " << rob(arr2) << endl;

    return 0;
}
