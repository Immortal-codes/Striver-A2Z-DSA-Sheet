#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// 1. Palindrome Partitioning - print all palindrome partitions of a string

bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

void palindromePartitioning(string &s, int start, vector<string> &current, vector<vector<string>> &result) {
    if (start == s.size()) {
        result.push_back(current);
        return;
    }
    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            palindromePartitioning(s, end + 1, current, result);
            current.pop_back();
        }
    }
}

// 2. Word Break - check if string can be segmented into words from dictionary

bool wordBreakHelper(const string &s, int start, unordered_set<string> &dict, vector<int> &memo) {
    if (start == s.size()) return true;
    if (memo[start] != -1) return memo[start];

    for (int end = start + 1; end <= s.size(); end++) {
        string word = s.substr(start, end - start);
        if (dict.count(word) && wordBreakHelper(s, end, dict, memo)) {
            memo[start] = 1;
            return true;
        }
    }
    memo[start] = 0;
    return false;
}

bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> memo(s.size(), -1);
    return wordBreakHelper(s, 0, dict, memo);
}

// 3. Generate all valid Parentheses (n pairs)

void generateParenthesisHelper(int open, int close, string &current, vector<string> &result) {
    if (open == 0 && close == 0) {
        result.push_back(current);
        return;
    }
    if (open > 0) {
        current.push_back('(');
        generateParenthesisHelper(open - 1, close, current, result);
        current.pop_back();
    }
    if (close > open) {
        current.push_back(')');
        generateParenthesisHelper(open, close - 1, current, result);
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    generateParenthesisHelper(n, n, current, result);
    return result;
}

// 4. Letter Combinations of Phone Number

const vector<string> phoneMap = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void letterCombinationsHelper(const string &digits, int index, string &current, vector<string> &result) {
    if (index == digits.size()) {
        result.push_back(current);
        return;
    }
    int digit = digits[index] - '0';
    if (digit < 2 || digit > 9) {
        letterCombinationsHelper(digits, index + 1, current, result);
        return;
    }
    string letters = phoneMap[digit];
    for (char ch : letters) {
        current.push_back(ch);
        letterCombinationsHelper(digits, index + 1, current, result);
        current.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) return result;
    string current;
    letterCombinationsHelper(digits, 0, current, result);
    return result;
}

// 5. Print all permutations of a string

void permute(string &s, int start, vector<string> &result) {
    if (start == s.size() - 1) {
        result.push_back(s);
        return;
    }
    for (int i = start; i < s.size(); i++) {
        swap(s[start], s[i]);
        permute(s, start + 1, result);
        swap(s[start], s[i]); // backtrack
    }
}

int main() {
    // 1. Palindrome Partitioning example
    string s1 = "aab";
    vector<vector<string>> palindromeResults;
    vector<string> current;
    palindromePartitioning(s1, 0, current, palindromeResults);
    cout << "Palindrome partitions of \"" << s1 << "\":\n";
    for (auto &part : palindromeResults) {
        for (string &seg : part) cout << seg << " ";
        cout << "\n";
    }
    cout << "\n";

    // 2. Word Break example
    string s2 = "leetcode";
    vector<string> dict = {"leet", "code"};
    cout << "Word Break for \"" << s2 << "\": " << (wordBreak(s2, dict) ? "Yes\n" : "No\n");

    // 3. Generate all valid parentheses
    int n = 3;
    cout << "Valid parentheses for n = " << n << ":\n";
    vector<string> parentheses = generateParenthesis(n);
    for (auto &p : parentheses) cout << p << "\n";
    cout << "\n";

    // 4. Letter Combinations of Phone Number
    string digits = "23";
    cout << "Letter combinations for digits \"" << digits << "\":\n";
    vector<string> combos = letterCombinations(digits);
    for (auto &comb : combos) cout << comb << " ";
    cout << "\n\n";

    // 5. Print all permutations of a string
    string s3 = "ABC";
    vector<string> permResults;
    permute(s3, 0, permResults);
    cout << "Permutations of \"" << s3 << "\":\n";
    for (auto &perm : permResults) cout << perm << "\n";

    return 0;
}
