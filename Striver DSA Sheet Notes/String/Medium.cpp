#include <bits/stdc++.h>
using namespace std;

// ✅ Sort Characters by Frequency
string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    priority_queue<pair<int, char>> pq;
    for (auto& [ch, f] : freq) pq.push({f, ch});
    string res;
    while (!pq.empty()) {
        auto [f, ch] = pq.top(); pq.pop();
        res += string(f, ch);
    }
    return res;
}

// ✅ Maximum Nesting Depth of Parentheses
int maxDepth(string s) {
    int depth = 0, maxD = 0;
    for (char c : s) {
        if (c == '(') depth++;
        if (c == ')') depth--;
        maxD = max(maxD, depth);
    }
    return maxD;
}

// ✅ Roman to Integer
int romanToInt(string s) {
    unordered_map<char, int> m = {
        {'I',1}, {'V',5}, {'X',10}, {'L',50},
        {'C',100}, {'D',500}, {'M',1000}};
    int total = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i+1 < s.size() && m[s[i]] < m[s[i+1]])
            total -= m[s[i]];
        else
            total += m[s[i]];
    }
    return total;
}

// ✅ Integer to Roman
string intToRoman(int num) {
    vector<pair<int, string>> val = {
        {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"},
        {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"},
        {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"}};
    string res;
    for (auto& [v, sym] : val) {
        while (num >= v) {
            res += sym;
            num -= v;
        }
    }
    return res;
}

// ✅ Implement Atoi
int myAtoi(string s) {
    int i = 0, sign = 1, res = 0;
    while (i < s.size() && s[i] == ' ') i++;
    if (i < s.size() && (s[i] == '-' || s[i] == '+'))
        sign = (s[i++] == '-') ? -1 : 1;
    while (i < s.size() && isdigit(s[i])) {
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7))
            return sign == 1 ? INT_MAX : INT_MIN;
        res = res * 10 + (s[i++] - '0');
    }
    return res * sign;
}

// ✅ Count Number of Substrings (with unique chars)
int countGoodSubstrings(string s) {
    int count = 0;
    for (int i = 0; i + 2 < s.length(); i++) {
        unordered_set<char> st;
        st.insert(s[i]);
        st.insert(s[i+1]);
        st.insert(s[i+2]);
        if (st.size() == 3) count++;
    }
    return count;
}

// ✅ Longest Palindromic Substring (without DP)
string longestPalindrome(string s) {
    int start = 0, maxLen = 1;
    for (int i = 0; i < s.size(); i++) {
        // Odd length
        int l = i, r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }
        // Even length
        l = i, r = i+1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--; r++;
        }
    }
    return s.substr(start, maxLen);
}

// ✅ Sum of Beauty of All Substrings
int beautySum(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        vector<int> freq(26, 0);
        for (int j = i; j < s.size(); ++j) {
            freq[s[j] - 'a']++;
            int maxF = *max_element(freq.begin(), freq.end());
            int minF = INT_MAX;
            for (int f : freq) {
                if (f > 0) minF = min(minF, f);
            }
            res += (maxF - minF);
        }
    }
    return res;
}

// ✅ Reverse Every Word in a String
string reverseEachWord(string s) {
    stringstream ss(s);
    string word, result;
    while (ss >> word) {
        reverse(word.begin(), word.end());
        result += word + " ";
    }
    if (!result.empty()) result.pop_back();
    return result;
}

// 🔁 Driver Code
int main() {
    cout << "Sorted by Frequency: " << frequencySort("tree") << endl;
    cout << "Max Depth: " << maxDepth("(1+(2*3)+((8)/4))+1") << endl;
    cout << "Roman to Int: " << romanToInt("MCMXCIV") << endl;
    cout << "Int to Roman: " << intToRoman(1994) << endl;
    cout << "Atoi: " << myAtoi("   -42") << endl;
    cout << "Good Substrings: " << countGoodSubstrings("xyzzaz") << endl;
    cout << "Longest Palindrome: " << longestPalindrome("babad") << endl;
    cout << "Beauty Sum: " << beautySum("aabcb") << endl;
    cout << "Reverse Each Word: " << reverseEachWord("Hello World") << endl;
    return 0;
}
