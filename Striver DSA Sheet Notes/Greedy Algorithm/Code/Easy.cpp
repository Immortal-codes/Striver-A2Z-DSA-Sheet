// ✅ Greedy Problems Code Collection (C++)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

//////////////////////////////////////////////////
// 1. Assign Cookies (Easy)
//////////////////////////////////////////////////
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, cookie = 0;
    while (child < g.size() && cookie < s.size()) {
        if (s[cookie] >= g[child]) child++;
        cookie++;
    }
    return child;
}

//////////////////////////////////////////////////
// 2. Fractional Knapsack (Medium)
//////////////////////////////////////////////////
struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);
    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            finalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

//////////////////////////////////////////////////
// 3. Greedy: Minimum Number of Coins (Medium)
//////////////////////////////////////////////////
int minCoins(vector<int>& coins, int V) {
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    for (int coin : coins) {
        while (V >= coin) {
            V -= coin;
            count++;
        }
        if (V == 0) break;
    }
    return count;
}

//////////////////////////////////////////////////
// 4. Lemonade Change (Easy)
//////////////////////////////////////////////////
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
        if (bill == 5) five++;
        else if (bill == 10) {
            if (five == 0) return false;
            five--; ten++;
        } else {
            if (ten > 0 && five > 0) {
                ten--; five--;
            } else if (five >= 3) {
                five -= 3;
            } else return false;
        }
    }
    return true;
}

//////////////////////////////////////////////////
// 5. Valid Parenthesis Checker (Greedy + Stack)
//////////////////////////////////////////////////
bool isValid(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

//////////////////////////////////////////////////
// 🔸 Main Function to Test
//////////////////////////////////////////////////
int main() {
    // Test 1: Assign Cookies
    vector<int> greed = {1, 2, 3};
    vector<int> size = {1, 1};
    cout << "1. Assign Cookies: " << findContentChildren(greed, size) << "\n";

    // Test 2: Fractional Knapsack
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    cout << "2. Fractional Knapsack: " << fractionalKnapsack(W, items, 3) << "\n";

    // Test 3: Minimum Coins
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int V = 93;
    cout << "3. Min Coins: " << minCoins(coins, V) << "\n";

    // Test 4: Lemonade Change
    vector<int> bills = {5,5,5,10,20};
    cout << "4. Lemonade Change: " << (lemonadeChange(bills) ? "Yes" : "No") << "\n";

    // Test 5: Valid Parenthesis
    string expr = "({[]})";
    cout << "5. Valid Parenthesis: " << (isValid(expr) ? "Yes" : "No") << "\n";

    return 0;
}
