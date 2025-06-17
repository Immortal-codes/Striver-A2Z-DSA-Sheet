#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//////////////////////////////
// DP-35: Best Time to Buy and Sell Stock (One transaction)
//////////////////////////////
int maxProfitOneTransaction(vector<int>& prices) {
    int minPrice = INT32_MAX, maxProfit = 0;
    for(int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

//////////////////////////////
// DP-36: Buy and Sell Stock - II (Infinite transactions)
//////////////////////////////
int maxProfitInfiniteTransactions(vector<int>& prices) {
    int profit = 0;
    for(int i = 1; i < (int)prices.size(); i++) {
        if(prices[i] > prices[i-1]) 
            profit += prices[i] - prices[i-1];
    }
    return profit;
}

//////////////////////////////
// DP-37: Buy and Sell Stocks III (At most 2 transactions)
//////////////////////////////
int maxProfitTwoTransactions(vector<int>& prices) {
    int n = (int)prices.size();
    if(n == 0) return 0;

    vector<int> leftProfit(n, 0);
    int minPrice = prices[0];
    for(int i = 1; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        leftProfit[i] = max(leftProfit[i-1], prices[i] - minPrice);
    }

    vector<int> rightProfit(n+1, 0);
    int maxPrice = prices[n-1];
    for(int i = n-2; i >= 0; i--) {
        maxPrice = max(maxPrice, prices[i]);
        rightProfit[i] = max(rightProfit[i+1], maxPrice - prices[i]);
    }

    int maxProfit = 0;
    for(int i = 0; i < n; i++) {
        maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i+1]);
    }
    return maxProfit;
}

//////////////////////////////
// DP-38: Buy and Sell Stock IV (At most k transactions)
//////////////////////////////
int maxProfitKTransactions(int k, vector<int>& prices) {
    int n = (int)prices.size();
    if(n == 0) return 0;
    if(k >= n/2) {  // unlimited transactions
        int profit = 0;
        for(int i=1; i<n; i++) {
            if(prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        return profit;
    }

    vector<vector<int>> dp(k+1, vector<int>(n, 0));

    for(int i=1; i<=k; i++) {
        int maxDiff = -prices[0];
        for(int j=1; j<n; j++) {
            dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
        }
    }
    return dp[k][n-1];
}

//////////////////////////////
// DP-39: Buy and Sell Stocks With Cooldown
//////////////////////////////
int maxProfitWithCooldown(vector<int>& prices) {
    int n = (int)prices.size();
    if(n == 0) return 0;
    vector<int> buy(n, 0), sell(n, 0), cooldown(n, 0);
    buy[0] = -prices[0];
    sell[0] = 0;
    cooldown[0] = 0;

    for(int i = 1; i < n; i++) {
        buy[i] = max(buy[i-1], cooldown[i-1] - prices[i]);
        sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        cooldown[i] = max(cooldown[i-1], sell[i-1]);
    }
    return max(sell[n-1], cooldown[n-1]);
}

//////////////////////////////
// DP-40: Buy and Sell Stocks With Transaction Fee
//////////////////////////////
int maxProfitWithFee(vector<int>& prices, int fee) {
    int n = (int)prices.size();
    int cash = 0, hold = -prices[0];
    for(int i = 1; i < n; i++) {
        cash = max(cash, hold + prices[i] - fee);
        hold = max(hold, cash - prices[i]);
    }
    return cash;
}

//////////////////////////////
// Main for quick testing
//////////////////////////////
int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int fee = 1;
    int k = 2;

    cout << "DP-35: Max profit (1 transaction): " << maxProfitOneTransaction(prices) << "\n";
    cout << "DP-36: Max profit (infinite transactions): " << maxProfitInfiniteTransactions(prices) << "\n";
    cout << "DP-37: Max profit (2 transactions): " << maxProfitTwoTransactions(prices) << "\n";
    cout << "DP-38: Max profit (k=" << k << " transactions): " << maxProfitKTransactions(k, prices) << "\n";
    cout << "DP-39: Max profit with cooldown: " << maxProfitWithCooldown(prices) << "\n";
    cout << "DP-40: Max profit with fee = " << fee << ": " << maxProfitWithFee(prices, fee) << "\n";

    return 0;
}
