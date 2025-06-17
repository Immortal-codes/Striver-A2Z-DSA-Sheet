#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

//
// 1. Longest Substring Without Repeating Characters
//
int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int left = 0, right = 0, maxLen = 0;
    while (right < s.size()) {
        if (st.find(s[right]) == st.end()) {
            st.insert(s[right++]);
            maxLen = max(maxLen, right - left);
        } else {
            st.erase(s[left++]);
        }
    }
    return maxLen;
}

//
// 2. Max Consecutive Ones III
//
int longestOnes(vector<int>& nums, int k) {
    int left = 0, maxLen = 0, zeroCount = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeroCount++;
        while (zeroCount > k) {
            if (nums[left++] == 0) zeroCount--;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

//
// 3. Fruit Into Baskets
//
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> count;
    int left = 0, maxLen = 0;
    for (int right = 0; right < fruits.size(); right++) {
        count[fruits[right]]++;
        while (count.size() > 2) {
            count[fruits[left]]--;
            if (count[fruits[left]] == 0) count.erase(fruits[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

//
// 4. Longest Repeating Character Replacement
//
int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);
    int left = 0, maxFreq = 0, maxLen = 0;
    for (int right = 0; right < s.size(); right++) {
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

//
// 5. Binary Subarrays With Sum
//
int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        if (prefixCount.count(sum - goal)) {
            count += prefixCount[sum - goal];
        }
        prefixCount[sum]++;
    }
    return count;
}

//
// 6. Count Number of Nice Subarrays
//
int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int oddCount = 0, result = 0;
    for (int num : nums) {
        oddCount += num % 2;
        result += prefixCount[oddCount - k];
        prefixCount[oddCount]++;
    }
    return result;
}

//
// 7. Number of Substrings Containing All Three Characters
//
int numberOfSubstrings(string s) {
    unordered_map<char, int> count;
    int left = 0, result = 0;
    for (int right = 0; right < s.size(); right++) {
        count[s[right]]++;
        while (count['a'] > 0 && count['b'] > 0 && count['c'] > 0) {
            result += (s.size() - right);
            count[s[left++]]--;
        }
    }
    return result;
}

//
// 8. Maximum Points You Can Obtain from Cards
//
int maxScore(vector<int>& cardPoints, int k) {
    int total = 0;
    int n = cardPoints.size();
    for (int i = 0; i < k; i++) {
        total += cardPoints[i];
    }
    int maxScore = total;

    for (int i = 0; i < k; i++) {
        total -= cardPoints[k - 1 - i];
        total += cardPoints[n - 1 - i];
        maxScore = max(maxScore, total);
    }
    return maxScore;
}

//
// Main function to test the above implementations
//
int main() {
    cout << "1. Longest Substring Without Repeating Characters: ";
    cout << lengthOfLongestSubstring("abcabcbb") << endl;

    cout << "2. Max Consecutive Ones III: ";
    vector<int> v1 = {1,1,1,0,0,0,1,1,1,1,0};
    cout << longestOnes(v1, 2) << endl;

    cout << "3. Fruit Into Baskets: ";
    vector<int> v2 = {1,2,1,2,3};
    cout << totalFruit(v2) << endl;

    cout << "4. Longest Repeating Character Replacement: ";
    cout << characterReplacement("AABABBA", 1) << endl;

    cout << "5. Binary Subarrays With Sum: ";
    vector<int> v3 = {1,0,1,0,1};
    cout << numSubarraysWithSum(v3, 2) << endl;

    cout << "6. Count Number of Nice Subarrays: ";
    vector<int> v4 = {1,1,2,1,1};
    cout << numberOfSubarrays(v4, 3) << endl;

    cout << "7. Number of Substrings Containing All Three Characters: ";
    cout << numberOfSubstrings("abcabc") << endl;

    cout << "8. Maximum Points You Can Obtain from Cards: ";
    vector<int> v5 = {1,2,3,4,5,6,1};
    cout << maxScore(v5, 3) << endl;

    return 0;
}
