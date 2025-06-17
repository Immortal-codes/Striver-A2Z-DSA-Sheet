#include <bits/stdc++.h>
using namespace std;

// ✅ 1. Count Frequency of Elements
void countFrequency(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;
    cout << "Frequency of elements:\n";
    for (auto& [key, value] : freq) {
        cout << key << " -> " << value << "\n";
    }
}

// ✅ 2. Check for Duplicates
bool hasDuplicate(vector<int>& arr) {
    unordered_set<int> s;
    for (int x : arr) {
        if (s.count(x)) return true;
        s.insert(x);
    }
    return false;
}

// ✅ 3. Two Sum
pair<int, int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int rem = target - nums[i];
        if (mp.count(rem)) return {mp[rem], i};
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

// ✅ 4. Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& it : mp) {
        result.push_back(it.second);
    }
    return result;
}

// ✅ 5. Subarrays with Sum K
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    int sum = 0, count = 0;
    for (int x : nums) {
        sum += x;
        count += prefixSum[sum - k];
        prefixSum[sum]++;
    }
    return count;
}

// ✅ 6. Longest Consecutive Sequence
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;
    for (int x : s) {
        if (!s.count(x - 1)) {
            int curr = x;
            int streak = 1;
            while (s.count(curr + 1)) {
                curr++;
                streak++;
            }
            longest = max(longest, streak);
        }
    }
    return longest;
}

// ✅ 7. Longest Subarray with Zero Sum
int longestZeroSumSubarray(vector<int>& nums) {
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum == 0) maxLen = i + 1;
        else if (mp.count(sum)) maxLen = max(maxLen, i - mp[sum]);
        else mp[sum] = i;
    }
    return maxLen;
}

// ✅ 8. Count Distinct Elements in Window of Size K
void countDistinctInWindow(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++) mp[arr[i]]++;
    cout << mp.size() << " ";

    for (int i = k; i < arr.size(); i++) {
        mp[arr[i - k]]--;
        if (mp[arr[i - k]] == 0) mp.erase(arr[i - k]);
        mp[arr[i]]++;
        cout << mp.size() << " ";
    }
    cout << "\n";
}

int main() {
    // Example usages

    vector<int> arr = {1, 2, 2, 1, 3};
    countFrequency(arr);

    cout << "Has Duplicates: " << (hasDuplicate(arr) ? "Yes" : "No") << "\n";

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto [i, j] = twoSum(nums, target);
    cout << "Two Sum indices: " << i << ", " << j << "\n";

    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto grouped = groupAnagrams(words);
    cout << "Grouped Anagrams:\n";
    for (auto group : grouped) {
        for (auto word : group) cout << word << " ";
        cout << "\n";
    }

    vector<int> nums2 = {1, 2, 3};
    cout << "Subarrays with sum 3: " << subarraySum(nums2, 3) << "\n";

    vector<int> nums3 = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive: " << longestConsecutive(nums3) << "\n";

    vector<int> nums4 = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << "Longest Zero Sum Subarray: " << longestZeroSumSubarray(nums4) << "\n";

    vector<int> nums5 = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    cout << "Distinct count in windows:\n";
    countDistinctInWindow(nums5, k);

    return 0;
}
