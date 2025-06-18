# Trie (Prefix Tree) - Complete Notes

## 📘 Introduction

A **Trie**, also known as a **Prefix Tree**, is a **tree-like data structure** used to efficiently store and retrieve keys in a dataset of strings. It is especially useful for problems related to **strings, prefixes, and dictionaries**.

---

## 📂 Use-Cases

- Auto-complete systems
- Spell-checking
- IP routing (longest prefix matching)
- Search engines
- Word games (like Boggle)

---

## 🧠 Key Concepts

- Each node represents a **character**.
- A **path from root to a node** represents a **prefix** or a complete word.
- The **root** is an empty node.
- Each node has a fixed-size **children array** (typically of size 26 for lowercase a-z).
- A **boolean flag `isEnd`** is used to mark the end of a complete word.

---

## 🧩 Time Complexity

| Operation  | Complexity |
|------------|------------|
| Insert     | O(L)       |
| Search     | O(L)       |
| StartsWith | O(L)       |

Where `L` = length of the word.

---

## 🧱 Structure of Trie Node in C++

```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};


class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // 🔹 Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    // 🔹 Search for a word in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    // 🔹 Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                return false;
            node = node->children[idx];
        }
        return true;
    }
};
