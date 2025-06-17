#include <bits/stdc++.h>
using namespace std;

// 1. Pascal's Triangle
vector<vector<int>> generatePascal(int numRows) {
    vector<vector<int>> triangle(numRows);
    for (int i = 0; i < numRows; ++i) {
        triangle[i].resize(i + 1, 1);
        for (int j = 1; j < i; ++j)
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    }
    return triangle;
}

// 2. Majority Element > n/3 (Boyer-Moore Extended)
vector<int> majorityElementNby3(vector<int>& nums) {
    int n = nums.size();
    int count1 = 0, count2 = 0, el1 = INT_MIN, el2 = INT_MIN;
    for (int num : nums) {
        if (num == el1) count1++;
        else if (num == el2) count2++;
        else if (count1 == 0) el1 = num, count1 = 1;
        else if (count2 == 0) el2 = num, count2 = 1;
        else count1--, count2--;
    }
    count1 = count2 = 0;
    for (int num : nums) {
        if (num == el1) count1++;
        else if (num == el2) count2++;
    }
    vector<int> res;
    if (count1 > n / 3) res.push_back(el1);
    if (count2 > n / 3) res.push_back(el2);
    return res;
}

// 3. 3Sum Problem
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int lo = i + 1, hi = n - 1, sum = -nums[i];
        while (lo < hi) {
            if (nums[lo] + nums[hi] == sum) {
                res.push_back({nums[i], nums[lo], nums[hi]});
                while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                lo++, hi--;
            } else if (nums[lo] + nums[hi] < sum)
                lo++;
            else
                hi--;
        }
    }
    return res;
}

// 4. 4Sum Problem
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            long long target2 = (long long)target - nums[i] - nums[j];
            int lo = j + 1, hi = n - 1;
            while (lo < hi) {
                long long sum = nums[lo] + nums[hi];
                if (sum < target2) lo++;
                else if (sum > target2) hi--;
                else {
                    res.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                    while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
                    lo++, hi--;
                }
            }
        }
    }
    return res;
}

// 5. Largest Subarray with Sum = 0
int largestSubarrayWithZeroSum(vector<int>& nums) {
    unordered_map<int, int> mpp;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum == 0) maxLen = i + 1;
        else if (mpp.count(sum)) maxLen = max(maxLen, i - mpp[sum]);
        else mpp[sum] = i;
    }
    return maxLen;
}

// 6. Count Subarrays with XOR K
int countSubarraysWithXorK(vector<int>& arr, int K) {
    unordered_map<int, int> freq;
    int xorSum = 0, count = 0;
    for (int num : arr) {
        xorSum ^= num;
        if (xorSum == K) count++;
        if (freq.count(xorSum ^ K)) count += freq[xorSum ^ K];
        freq[xorSum]++;
    }
    return count;
}

// 7. Merge Overlapping Intervals
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (merged.back()[1] >= intervals[i][0])
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        else
            merged.push_back(intervals[i]);
    }
    return merged;
}

// 8. Merge 2 Sorted Arrays without Extra Space (Gap method)
void mergeWithoutExtraSpace(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int gap = (n + m + 1) / 2;
    while (gap > 0) {
        int i = 0, j = gap;
        while (j < n + m) {
            int val1 = (i < n) ? a[i] : b[i - n];
            int val2 = (j < n) ? a[j] : b[j - n];
            if (val1 > val2) {
                if (i < n && j < n) swap(a[i], a[j]);
                else if (i < n && j >= n) swap(a[i], b[j - n]);
                else swap(b[i - n], b[j - n]);
            }
            i++, j++;
        }
        gap = (gap <= 1) ? 0 : (gap + 1) / 2;
    }
}

// 9. Repeating and Missing Number
pair<int, int> findRepeatingMissing(vector<int>& nums) {
    long long n = nums.size();
    long long sumN = n * (n + 1) / 2;
    long long sumSqN = n * (n + 1) * (2 * n + 1) / 6;
    long long sum = 0, sumSq = 0;
    for (int x : nums) {
        sum += x;
        sumSq += (long long)x * x;
    }
    long long diff = sum - sumN;                  // x - y
    long long sqDiff = sumSq - sumSqN;            // x^2 - y^2 = (x - y)(x + y)
    long long sumXY = sqDiff / diff;              // x + y
    long long x = (diff + sumXY) / 2;
    long long y = sumXY - x;
    return {(int)x, (int)y};
}

// 10. Count Inversions (Modified Merge Sort)
long long mergeAndCount(vector<int>& arr, int l, int mid, int r) {
    vector<int> temp;
    long long inv = 0;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else {
            temp.push_back(arr[j++]);
            inv += (mid - i + 1);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);
    for (int k = l; k <= r; k++) arr[k] = temp[k - l];
    return inv;
}
long long countInversions(vector<int>& arr, int l, int r) {
    long long inv = 0;
    if (l < r) {
        int mid = (l + r) / 2;
        inv += countInversions(arr, l, mid);
        inv += countInversions(arr, mid + 1, r);
        inv += mergeAndCount(arr, l, mid, r);
    }
    return inv;
}

// 11. Reverse Pairs (Like inversion count but with nums[i] > 2*nums[j])
int mergeAndCountReversePairs(vector<int>& nums, int low, int mid, int high) {
    int count = 0, j = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (j <= high && nums[i] > 2LL * nums[j]) j++;
        count += (j - (mid + 1));
    }
    vector<int> temp;
    int i = low; j = mid + 1;
    while (i <= mid && j <= high) {
        if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
        else temp.push_back(nums[j++]);
    }
    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= high) temp.push_back(nums[j++]);
    for (int k = low; k <= high; k++) nums[k] = temp[k - low];
    return count;
}
int countReversePairs(vector<int>& nums, int low, int high) {
    if (low >= high) return 0;
    int mid = (low + high) / 2;
    int inv = countReversePairs(nums, low, mid);
    inv += countReversePairs(nums, mid + 1, high);
    inv += mergeAndCountReversePairs(nums, low, mid, high);
    return inv;
}

// 12. Maximum Product Subarray
int maxProduct(vector<int>& nums) {
    int maxProd = nums[0], minProd = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) swap(maxProd, minProd);
        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);
        ans = max(ans, maxProd);
    }
    return ans;
}

// ========================
// 🔁 Sample Main Function
// ========================
int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> pascal = generatePascal(5);
    for (auto row : pascal) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}
