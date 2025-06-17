#include <bits/stdc++.h>
using namespace std;

// 1. Two Sum (Return indices)
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mpp.count(complement)) return {mpp[complement], i};
        mpp[nums[i]] = i;
    }
    return {};
}

// 2. Sort 0s, 1s, and 2s (Dutch National Flag)
void sort012(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
}

// 3. Majority Element (> n/2)
int majorityElement(vector<int>& nums) {
    int count = 0, candidate;
    for (int num : nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

// 4. Kadane’s Algorithm (Max Subarray Sum)
int maxSubArraySum(vector<int>& nums) {
    int maxSoFar = nums[0], currSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSoFar = max(maxSoFar, currSum);
    }
    return maxSoFar;
}

// 5. Print Subarray with Maximum Sum
pair<int, int> maxSubArrayIndices(vector<int>& nums) {
    int maxSum = nums[0], sum = nums[0], start = 0, s = 0, end = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (sum + nums[i] < nums[i]) {
            sum = nums[i];
            s = i;
        } else {
            sum += nums[i];
        }
        if (sum > maxSum) {
            maxSum = sum;
            start = s;
            end = i;
        }
    }
    return {start, end};
}

// 6. Stock Buy and Sell (1 transaction)
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, profit = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);
        profit = max(profit, price - minPrice);
    }
    return profit;
}

// 7. Rearrange Array in Alternating +ve and -ve
void rearrangeAlternately(vector<int>& arr) {
    int n = arr.size();
    vector<int> pos, neg;
    for (int x : arr) (x >= 0 ? pos : neg).push_back(x);
    int i = 0, j = 0, k = 0;
    while (i < pos.size() && j < neg.size()) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    while (i < pos.size()) arr[k++] = pos[i++];
    while (j < neg.size()) arr[k++] = neg[j++];
}

// 8. Next Permutation
void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    if (i >= 0) {
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

// 9. Leaders in an Array
vector<int> leadersInArray(vector<int>& arr) {
    int maxFromRight = INT_MIN;
    vector<int> leaders;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            leaders.push_back(arr[i]);
            maxFromRight = arr[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

// 10. Longest Consecutive Sequence
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int maxStreak = 0;
    for (int num : nums) {
        if (!s.count(num - 1)) {
            int currNum = num, currStreak = 1;
            while (s.count(currNum + 1)) {
                currNum++;
                currStreak++;
            }
            maxStreak = max(maxStreak, currStreak);
        }
    }
    return maxStreak;
}

// 11. Set Matrix Zeros
void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    bool firstRow = false, firstCol = false;

    for (int i = 0; i < rows; i++) if (matrix[i][0] == 0) firstCol = true;
    for (int j = 0; j < cols; j++) if (matrix[0][j] == 0) firstRow = true;

    for (int i = 1; i < rows; i++)
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;

    for (int i = 1; i < rows; i++)
        for (int j = 1; j < cols; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    if (firstRow)
        for (int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    if (firstCol)
        for (int i = 0; i < rows; i++)
            matrix[i][0] = 0;
}

// 12. Rotate Matrix by 90 degrees
void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());
}

// 13. Print Matrix in Spiral Order
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) res.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
        right--;
        if (top <= bottom)
            for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
        bottom--;
        if (left <= right)
            for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
        left++;
    }
    return res;
}

// 14. Count Subarrays with Given Sum (Positive only)
int countSubarraysSumK(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0, count = 0;
    prefixSumCount[0] = 1;

    for (int num : arr) {
        sum += num;
        if (prefixSumCount.find(sum - k) != prefixSumCount.end())
            count += prefixSumCount[sum - k];
        prefixSumCount[sum]++;
    }
    return count;
}

// ========================
// 🔁 Sample Main Function
// ========================
int main() {
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;

    vector<int> result = twoSum(arr, 9);
    if (!result.empty()) cout << "Two Sum Indices: " << result[0] << ", " << result[1] << endl;

    cout << "Max Subarray Sum: " << maxSubArraySum(arr) << endl;

    pair<int, int> range = maxSubArrayIndices(arr);
    cout << "Max Subarray Indices: " << range.first << " to " << range.second << endl;

    return 0;
}
