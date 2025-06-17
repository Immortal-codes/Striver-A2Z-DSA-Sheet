#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//////////////////////////////
// DP-41: Longest Increasing Subsequence (Length only)
//////////////////////////////
int lengthOfLIS(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> dp(n, 1);
    int maxLen = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

//////////////////////////////
// DP-42: Printing Longest Increasing Subsequence
//////////////////////////////
vector<int> printLIS(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> dp(n, 1), hash(n);
    int maxLen = 1, lastIndex = 0;

    for(int i=0; i<n; i++) hash[i] = i;

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if(dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    vector<int> lisSeq;
    lisSeq.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        lisSeq.push_back(nums[lastIndex]);
    }
    reverse(lisSeq.begin(), lisSeq.end());
    return lisSeq;
}

//////////////////////////////
// DP-43: Longest Increasing Subsequence (Efficient nlogn using binary search)
//////////////////////////////
int lengthOfLISBinarySearch(vector<int>& nums) {
    vector<int> temp;
    for(auto &num : nums) {
        auto it = lower_bound(temp.begin(), temp.end(), num);
        if(it == temp.end()) temp.push_back(num);
        else *it = num;
    }
    return (int)temp.size();
}

//////////////////////////////
// DP-44: Largest Divisible Subset
//////////////////////////////
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = (int)nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n,1), hash(n);
    int maxSize = 1, lastIndex = 0;
    for(int i=0; i<n; i++) hash[i] = i;

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if(dp[i] > maxSize) {
            maxSize = dp[i];
            lastIndex = i;
        }
    }

    vector<int> ans;
    ans.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        ans.push_back(nums[lastIndex]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//////////////////////////////
// DP-45: Longest String Chain
//////////////////////////////
int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string &a, const string &b){ return a.size() < b.size(); });
    int n = (int)words.size();
    vector<int> dp(n, 1);
    int maxLen = 1;

    auto canPrecede = [](const string& s1, const string& s2) {
        if(s2.size() != s1.size() + 1) return false;
        int i=0, j=0;
        while(i < (int)s1.size() && j < (int)s2.size()) {
            if(s1[i] == s2[j]) { i++; j++; }
            else j++;
            if(j - i > 1) return false;
        }
        return true;
    };

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(canPrecede(words[j], words[i]) && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

//////////////////////////////
// DP-46: Longest Bitonic Subsequence
//////////////////////////////
int longestBitonicSubsequence(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> lis(n, 1), lds(n, 1);

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[j] < nums[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    for(int i=n-2; i>=0; i--) {
        for(int j=n-1; j>i; j--) {
            if(nums[j] < nums[i])
                lds[i] = max(lds[i], lds[j] + 1);
        }
    }

    int maxLen = 1;
    for(int i=0; i<n; i++) {
        maxLen = max(maxLen, lis[i] + lds[i] - 1);
    }
    return maxLen;
}

//////////////////////////////
// DP-47: Number of Longest Increasing Subsequences
//////////////////////////////
int findNumberOfLIS(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> length(n, 1), count(n, 1);
    int maxLen = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[j] < nums[i]) {
                if(length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    count[i] = count[j];
                } else if(length[j] + 1 == length[i]) {
                    count[i] += count[j];
                }
            }
        }
        maxLen = max(maxLen, length[i]);
    }

    int totalCount = 0;
    for(int i=0; i<n; i++) {
        if(length[i] == maxLen) totalCount += count[i];
    }
    return totalCount;
}

//////////////////////////////
// Main function for quick testing
//////////////////////////////
int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    vector<string> words = {"a","b","ba","bca","bda","bdca"};

    cout << "DP-41: Length of LIS: " << lengthOfLIS(nums) << "\n";

    vector<int> lisSeq = printLIS(nums);
    cout << "DP-42: LIS sequence: ";
    for(int x : lisSeq) cout << x << " ";
    cout << "\n";

    cout << "DP-43: Length of LIS (Binary Search): " << lengthOfLISBinarySearch(nums) << "\n";

    vector<int> divisibleSet = largestDivisibleSubset(nums);
    cout << "DP-44: Largest Divisible Subset: ";
    for(int x : divisibleSet) cout << x << " ";
    cout << "\n";

    cout << "DP-45: Longest String Chain length: " << longestStrChain(words) << "\n";

    cout << "DP-46: Longest Bitonic Subsequence length: " << longestBitonicSubsequence(nums) << "\n";

    cout << "DP-47: Number of Longest Increasing Subsequences: " << findNumberOfLIS(nums) << "\n";

    return 0;
}
