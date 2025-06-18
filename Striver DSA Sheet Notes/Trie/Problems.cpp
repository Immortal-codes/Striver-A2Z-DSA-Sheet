#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

// ------------------ Problem 1: Implement Trie - 2 ------------------
class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

// ------------------ Problem 2: Longest String with All Prefixes ------------------
string longestWordWithAllPrefixes(vector<string>& words) {
    Trie trie;
    for (auto& word : words)
        trie.insert(word);

    string ans = "";
    for (auto& word : words) {
        TrieNode* node = trie.root;
        bool allPrefix = true;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            node = node->children[idx];
            if (!node || !node->isEnd) {
                allPrefix = false;
                break;
            }
        }
        if (allPrefix) {
            if (word.size() > ans.size() || (word.size() == ans.size() && word < ans))
                ans = word;
        }
    }
    return ans;
}

// ------------------ Problem 3: Number of Distinct Substrings ------------------
struct DSNode {
    DSNode* links[26] = {};
};

int countDistinctSubstrings(string s) {
    DSNode* root = new DSNode();
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        DSNode* node = root;
        for (int j = i; j < s.size(); j++) {
            int idx = s[j] - 'a';
            if (!node->links[idx]) {
                node->links[idx] = new DSNode();
                count++;
            }
            node = node->links[idx];
        }
    }
    return count + 1;  // +1 for empty substring
}

// ------------------ Bit Trie Node ------------------
struct BitTrieNode {
    BitTrieNode* bit[2] = {};
};

class BitTrie {
public:
    BitTrieNode* root;
    BitTrie() { root = new BitTrieNode(); }

    void insert(int num) {
        BitTrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bitVal = (num >> i) & 1;
            if (!node->bit[bitVal])
                node->bit[bitVal] = new BitTrieNode();
            node = node->bit[bitVal];
        }
    }

    int getMaxXOR(int num) {
        BitTrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bitVal = (num >> i) & 1;
            int opp = 1 - bitVal;
            if (node->bit[opp]) {
                maxXor |= (1 << i);
                node = node->bit[opp];
            } else {
                node = node->bit[bitVal];
            }
        }
        return maxXor;
    }
};

// ------------------ Problem 4: Maximum XOR of Two Numbers ------------------
int findMaximumXOR(vector<int>& nums) {
    BitTrie bt;
    for (int num : nums)
        bt.insert(num);

    int maxXor = 0;
    for (int num : nums)
        maxXor = max(maxXor, bt.getMaxXOR(num));
    return maxXor;
}

// ------------------ Problem 5: Maximum XOR With an Element From Array ------------------
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(), nums.end());
    vector<pair<int, pair<int, int>>> offlineQueries;
    for (int i = 0; i < queries.size(); i++) {
        offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());

    BitTrie bt;
    vector<int> result(queries.size(), -1);
    int idx = 0;

    for (auto& [mi, q] : offlineQueries) {
        int xi = q.first, qidx = q.second;

        while (idx < nums.size() && nums[idx] <= mi)
            bt.insert(nums[idx++]);

        if (idx == 0) continue;  // No valid elements ≤ mi
        result[qidx] = bt.getMaxXOR(xi);
    }
    return result;
}

// ------------------ Main Function to Test ------------------
int main() {
    // Test 1: Implement Trie
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;     // 1
    cout << trie.search("app") << endl;       // 0
    cout << trie.startsWith("app") << endl;   // 1
    trie.insert("app");
    cout << trie.search("app") << endl;       // 1

    // Test 2: Longest Word with All Prefixes
    vector<string> words = {"a", "ap", "app", "appl", "apple", "apply"};
    cout << "Longest valid word: " << longestWordWithAllPrefixes(words) << endl;

    // Test 3: Number of Distinct Substrings
    string s = "ababa";
    cout << "Distinct substrings: " << countDistinctSubstrings(s) << endl;

    // Test 4: Maximum XOR of Two Numbers
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Max XOR: " << findMaximumXOR(nums) << endl;

    // Test 5: Maximum XOR With an Element From Array
    vector<int> arr = {0, 1, 2, 3, 4};
    vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};
    vector<int> res = maximizeXor(arr, queries);
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
