#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

// 1. Next Greater Element
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

// 2. Next Greater Element II (circular)
vector<int> nextGreaterElements2(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && nums[i % n] > nums[st.top()]) {
            ans[st.top()] = nums[i % n];
            st.pop();
        }
        if (i < n) st.push(i);
    }
    return ans;
}

// 3. Next Smaller Element
vector<int> nextSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            ans[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

// 4. Number of NGEs to the right
vector<int> numberOfNGEToRight(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) st.pop();
        ans[i] = st.size();
        st.push(nums[i]);
    }
    return ans;
}

// 5. Trapping Rain Water
int trap(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1, water = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right) {
        if (height[left] <= height[right]) {
            maxLeft = max(maxLeft, height[left]);
            water += maxLeft - height[left];
            left++;
        } else {
            maxRight = max(maxRight, height[right]);
            water += maxRight - height[right];
            right--;
        }
    }
    return water;
}

// 6. Sum of Subarray Minimums
int sumSubarrayMins(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    stack<int> st;
    vector<int> left(n), right(n);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += (long long)(i - left[i]) * (right[i] - i) * arr[i];
        res %= MOD;
    }

    return res;
}

// 7. Asteroid Collision
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for (int a : asteroids) {
        while (!st.empty() && st.top() > 0 && a < 0) {
            int diff = st.top() + a;
            if (diff < 0) st.pop();
            else if (diff == 0) {
                st.pop();
                a = 0;
            } else a = 0;
        }
        if (a) st.push(a);
    }
    vector<int> res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

// 8. Sum of Subarray Ranges
long long subArrayRanges(vector<int>& nums) {
    long long res = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int mx = nums[i], mn = nums[i];
        for (int j = i; j < n; j++) {
            mx = max(mx, nums[j]);
            mn = min(mn, nums[j]);
            res += mx - mn;
        }
    }
    return res;
}

// 9. Remove K Digits
string removeKdigits(string num, int k) {
    string res = "";
    for (char c : num) {
        while (!res.empty() && res.back() > c && k > 0) {
            res.pop_back();
            k--;
        }
        if (!res.empty() || c != '0') res.push_back(c);
    }
    while (!res.empty() && k--) res.pop_back();
    return res.empty() ? "0" : res;
}

// 10. Largest Rectangle in Histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.push_back(0);
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    return maxArea;
}

// 11. Maximal Rectangle (based on histograms)
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int maxArea = 0, m = matrix.size(), n = matrix[0].size();
    vector<int> heights(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            heights[j] = (matrix[i][j] == '1' ? heights[j] + 1 : 0);
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

// Main function to demonstrate/test
int main() {
    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> result = nextGreaterElement(nums);
    cout << "Next Greater Element: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Test more here as needed...

    return 0;
}
