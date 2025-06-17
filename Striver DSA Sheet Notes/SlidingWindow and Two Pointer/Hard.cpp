#include <bits/stdc++.h>
using namespace std;




//
// 1. Longest Substring with At Most K Distinct Characters
//
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> count;
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.size(); right++) {
        count[s[right]]++;
        while (count.size() > k) {
            count[s[left]]--;
            if (count[s[left]] == 0) count.erase(s[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

//
// 2. Subarray with K Different Integers (Exact k distinct elements)
//     (Hint: Count(subarrays with at most k) - Count(subarrays with at most k-1))
//
int atMostK(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int left = 0, res = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (count[nums[right]]++ == 0) k--;
        while (k < 0) {
            if (--count[nums[left]] == 0) k++;
            left++;
        }
        res += right - left + 1;
    }
    return res;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

//
// 3. Minimum Window Substring (Leetcode 76)
//
string minWindow(string s, string t) {
    unordered_map<char, int> target;
    for (char c : t) target[c]++;

    int left = 0, right = 0, minLen = INT_MAX, start = 0, required = t.size();
    while (right < s.size()) {
        if (target[s[right]] > 0) required--;
        target[s[right]]--;
        right++;

        while (required == 0) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }
            target[s[left]]++;
            if (target[s[left]] > 0) required++;
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

//
// 4. Minimum Window Subsequence (Leetcode 727)
//
string minWindowSubsequence(string s, string t) {
    int minLen = INT_MAX, start = -1;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == t[0]) {
            int si = i, ti = 0;
            // forward match
            while (si < s.length() && ti < t.length()) {
                if (s[si] == t[ti]) ti++;
                si++;
            }
            if (ti == t.length()) {
                // backward match
                int end = si - 1;
                ti = t.length() - 1;
                si = end;
                while (si >= i && ti >= 0) {
                    if (s[si] == t[ti]) ti--;
                    si--;
                }
                if (end - si < minLen) {
                    minLen = end - si;
                    start = si + 1;
                }
            }
        }
    }
    return (start == -1) ? "" : s.substr(start, minLen);
}

//
// Main Function for Testing
//
int main() {
    cout << "1. Longest Substring with At Most K Distinct Characters:\n";
    cout << lengthOfLongestSubstringKDistinct("eceba", 2) << endl;

    cout << "\n2. Subarray with K Different Integers:\n";
    vector<int> nums = {1,2,1,2,3};
    cout << subarraysWithKDistinct(nums, 2) << endl;

    cout << "\n3. Minimum Window Substring:\n";
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;

    cout << "\n4. Minimum Window Subsequence:\n";
    cout << minWindowSubsequence("abcdebdde", "bde") << endl;

    return 0;
}
