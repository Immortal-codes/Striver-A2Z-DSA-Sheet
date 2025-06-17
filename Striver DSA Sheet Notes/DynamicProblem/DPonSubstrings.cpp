#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

///////////////////////////////
// DP-25: Longest Common Subsequence (LCS) length
///////////////////////////////
int longestCommonSubsequence(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

///////////////////////////////
// DP-26: Print Longest Common Subsequence
///////////////////////////////
string printLCS(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // Backtracking to build LCS string
    int i = n, j = m;
    string lcs = "";
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            lcs += s1[i-1];
            i--; j--;
        } else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

///////////////////////////////
// DP-27: Longest Common Substring
///////////////////////////////
int longestCommonSubstring(string &s1, string &s2) {
    int n = s1.size(), m = s2.size(), ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            } else dp[i][j] = 0;
        }
    }
    return ans;
}

///////////////////////////////
// DP-28: Longest Palindromic Subsequence
///////////////////////////////
int longestPalindromicSubsequence(string &s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    for(int i=0; i<n; i++) dp[i][i] = 1;
    for(int len=2; len<=n; len++) {
        for(int i=0; i<=n-len; i++) {
            int j = i + len - 1;
            if(s[i] == s[j]) dp[i][j] = 2 + (i+1 <= j-1 ? dp[i+1][j-1] : 0);
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

///////////////////////////////
// DP-29: Minimum Insertions to Make String Palindrome
///////////////////////////////
int minInsertionsToPalindrome(string &s) {
    int n = s.size();
    string rev = s; reverse(rev.begin(), rev.end());
    int lps = longestCommonSubsequence(s, rev);
    return n - lps;
}

///////////////////////////////
// DP-30: Minimum Insertions/Deletions to Convert String
///////////////////////////////
int minOperationsToConvert(string &s, string &t) {
    int lcs = longestCommonSubsequence(s, t);
    return (s.size() - lcs) + (t.size() - lcs);
}

///////////////////////////////
// DP-31: Shortest Common Supersequence length
///////////////////////////////
int shortestCommonSupersequence(string &s, string &t) {
    int lcs = longestCommonSubsequence(s, t);
    return s.size() + t.size() - lcs;
}

///////////////////////////////
// DP-32: Distinct Subsequences (count how many subsequences of s equals t)
///////////////////////////////
int numDistinct(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1,0));
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
}

///////////////////////////////
// DP-33: Edit Distance (Levenshtein Distance)
///////////////////////////////
int editDistance(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int j=0; j<=m; j++) dp[0][j] = j;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    return dp[n][m];
}

///////////////////////////////
// DP-34: Wildcard Matching (with '?' and '*')
///////////////////////////////
bool isMatch(string &s, string &p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
    dp[0][0] = true;
    for(int j=1; j<=m; j++) {
        if(p[j-1] == '*') dp[0][j] = dp[0][j-1];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(p[j-1] == s[i-1] || p[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if(p[j-1] == '*') {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            } else dp[i][j] = false;
        }
    }
    return dp[n][m];
}

///////////////////////////////
// Main for quick tests
///////////////////////////////
int main() {
    string s1 = "abcde", s2 = "ace";
    cout << "LCS length: " << longestCommonSubsequence(s1, s2) << "\n";
    cout << "LCS string: " << printLCS(s1, s2) << "\n";

    cout << "Longest Common Substring: " << longestCommonSubstring(s1, s2) << "\n";

    string s3 = "bbbab";
    cout << "Longest Palindromic Subsequence: " << longestPalindromicSubsequence(s3) << "\n";
    cout << "Min insertions to palindrome: " << minInsertionsToPalindrome(s3) << "\n";

    string s4 = "heap", s5 = "pea";
    cout << "Min insertions/deletions to convert: " << minOperationsToConvert(s4, s5) << "\n";

    cout << "Shortest Common Supersequence length: " << shortestCommonSupersequence(s4, s5) << "\n";

    string s6 = "rabbbit", s7 = "rabbit";
    cout << "Distinct Subsequences count: " << numDistinct(s6, s7) << "\n";

    string s8 = "intention", s9 = "execution";
    cout << "Edit Distance: " << editDistance(s8, s9) << "\n";

    string s10 = "aa", pattern = "a*";
    cout << "Wildcard match: " << (isMatch(s10, pattern) ? "True" : "False") << "\n";

    return 0;
}
