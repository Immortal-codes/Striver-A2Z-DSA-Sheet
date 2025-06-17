# 🔥 Bit Manipulation - From Basics to FAANG Level (with C++)

---

## 📘 1. Bitwise Operators in C++

| Operator | Symbol | Meaning                | Example (C++) |
|----------|--------|------------------------|----------------|
| AND      | `&`    | 1 if both bits are 1   | `a & b` |
| OR       | `|`    | 1 if any one is 1      | `a | b` |
| XOR      | `^`    | 1 if bits are different| `a ^ b` |
| NOT      | `~`    | Inverts all bits       | `~a` |
| Left Shift | `<<` | Multiply by 2          | `a << 1` |
| Right Shift| `>>` | Divide by 2            | `a >> 1` |

---

## 📘 2. Useful Bit Tricks in C++

### 🔹 Check if a number is even or odd
```cpp
if (n & 1) cout << "Odd";
else cout << "Even";



Get ith bit
int bit = (n >> i) & 1;
🔹 Set ith bit
n = n | (1 << i);
🔹 Clear ith bit
n = n & (~(1 << i));
🔹 Toggle ith bit
n = n ^ (1 << i);
🔹 Count number of set bits (Brian Kernighan’s Algorithm)
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}
🔹 Check if a number is power of 2
bool isPowerOf2(int n) {
    return n && !(n & (n - 1));
}
🔹 Swap two numbers without temp
a = a ^ b;
b = a ^ b;
a = a ^ b;
🔹 Get rightmost set bit
int rightmostSetBit = n & (-n);
📘 3. Bitmasking for Subsets

void generateSubsets(vector<int>& nums) {
    int n = nums.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j))
                cout << nums[j] << " ";
        }
        cout << "\n";
    }
}
📘 4. Advanced Tricks & Concepts

🔹 Count total set bits from 1 to N
int countTotalSetBits(int n) {
    if (n == 0) return 0;
    int x = log2(n);
    int bitsUpto2PowX = x * (1 << (x - 1));
    int msb = n - (1 << x) + 1;
    return bitsUpto2PowX + msb + countTotalSetBits(n - (1 << x));
}
🔹 XOR from 1 to N
int xorFrom1ToN(int n) {
    if (n % 4 == 0) return n;
    else if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    return 0;
}
🔹 Gray Code Generation
vector<int> grayCode(int n) {
    vector<int> ans;
    for (int i = 0; i < (1 << n); i++) {
        ans.push_back(i ^ (i >> 1));
    }
    return ans;
}
📘 5. FAANG Level Bit Manipulation Problems

✅ 1. Single Number (Leetcode 136)
int singleNumber(vector<int>& nums) {
    int xorSum = 0;
    for (int num : nums) xorSum ^= num;
    return xorSum;
}
✅ 2. Two Non-Repeating Elements
vector<int> singleNumbers(vector<int>& nums) {
    int xorVal = 0;
    for (int num : nums) xorVal ^= num;
    int diffBit = xorVal & (-xorVal);

    int a = 0, b = 0;
    for (int num : nums) {
        if (num & diffBit) a ^= num;
        else b ^= num;
    }
    return {a, b};
}
✅ 3. Count Number of 1 Bits (Leetcode 191)
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
✅ 4. Counting Bits (Leetcode 338)
vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        dp[i] = dp[i >> 1] + (i & 1);
    return dp;
}
✅ 5. Maximum XOR of Two Numbers (Leetcode 421)
struct TrieNode {
    TrieNode* children[2] = {};
};

void insert(TrieNode* root, int num) {
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!root->children[bit])
            root->children[bit] = new TrieNode();
        root = root->children[bit];
    }
}

int findMaxXOR(TrieNode* root, int num) {
    int maxXOR = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (root->children[1 - bit]) {
            maxXOR |= (1 << i);
            root = root->children[1 - bit];
        } else {
            root = root->children[bit];
        }
    }
    return maxXOR;
}

int findMaximumXOR(vector<int>& nums) {
    TrieNode* root = new TrieNode();
    for (int num : nums) insert(root, num);
    int maxXOR = 0;
    for (int num : nums)
        maxXOR = max(maxXOR, findMaxXOR(root, num));
    return maxXOR;
}
📘 6. Common Interview Questions

Question	Concept
Odd/Even	n & 1
Set/Unset Bit	(1 << i)
Count Bits	n & (n - 1)
Power of 2	n & (n - 1) == 0
Subsets	Bitmask
XOR of array	a ^ b ^ c...
Rightmost set bit	n & (-n)


