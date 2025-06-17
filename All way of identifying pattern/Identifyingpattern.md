/*******************************************
        IDENTIFYING DSA PATTERNS
        📚 Notes by Alice for Rajan
********************************************/

/*
🔍 How to Identify Patterns in DSA Problems

Mastering DSA is not about memorizing, but about recognizing common problem patterns.
Here's how to identify them step-by-step:
*/


/*-------------------------------------------
1. 🧠 Read the Problem Carefully
---------------------------------------------*/
// Ask:
- What’s the input format? (Array, Tree, Graph, etc.)
- What’s the goal? (Max/Min/Count/Subarray/Path/etc.)
- Are there constraints? (sorted, unique, length ≤ 10^5, etc.)
// These hint at specific patterns.

/*-------------------------------------------
2. 🧱 Classify by Data Structure
---------------------------------------------*/
// 📌 Main structure gives clues:
// Array       → Sliding Window, Two Pointers
// Tree        → DFS, BFS, Recursion
// Graph       → DFS, BFS, Union-Find
// Heap        → Greedy, Top K
// HashMap     → Frequency Count, Two Sum
// DP Table    → Subset Sum, Knapsack
// String      → KMP, Trie, Hashing

/*-------------------------------------------
3. 🔑 Look for Keywords
---------------------------------------------*/
// | Keyword                  | Likely Pattern           |
// |--------------------------|---------------------------|
// | "subarray of length k"   | Sliding Window            |
// | "sorted array"           | Two Pointers / Binary Search |
// | "number of ways"         | Dynamic Programming       |
// | "shortest path"          | BFS / Dijkstra            |
// | "all permutations"       | Backtracking              |
// | "max/min value"          | DP or Greedy              |
// | "tree traversal"         | DFS / BFS                 |
// | "connected components"   | Union-Find / DFS          |

/*-------------------------------------------
4. 🧠 Relate to Known Template Problems
---------------------------------------------*/
// Think:
// - "Have I seen something similar?"
// - Match with known template:
//   Two Sum → HashMap
//   Word Break → DP + Trie
//   Target Sum Ways → Subset Sum DP
//   Coin Change → Unbounded Knapsack

/*-------------------------------------------
5. 📏 Check Input Constraints
---------------------------------------------*/
// Small Input (n ≤ 20)   → Try Recursion / Backtracking
// Large Input (n ≥ 10^5) → Use O(n), O(n log n) methods
// Count-based problems   → Likely DP

/*-------------------------------------------
6. 🛠 Use Pattern Repositories
---------------------------------------------*/
// Use well-known curated pattern lists:
// - Striver's A2Z DSA Sheet
// - Blind 75 / Neetcode.io Patterns
// - Leetcode Pattern 75
// Build intuition through repetition!

/*-------------------------------------------
7. 📓 Build a Pattern Notebook
---------------------------------------------*/
// Create your own table like below:
// | Pattern Name      | Template Problem    | Key Idea                  |
// |-------------------|---------------------|----------------------------|
// | Sliding Window    | Max Sum Subarray    | Move window with size     |
// | DP (0/1 Knapsack) | Subset Sum          | Pick/Not Pick with memo   |
// | Backtracking      | N-Queens             | Try all + revert state    |
// | Graph (BFS/DFS)   | Connected Components | Explore neighbors         |

/*-------------------------------------------
🔁 Daily Practice Tip:
---------------------------------------------*/
// After solving any DSA problem:
// 1. Identify the pattern
// 2. Note it down in your notebook
// 3. Solve similar 2–3 problems of same type

*/

/*******************************************
        🚀 KEY MINDSET:
DSA problems repeat with minor twists.
Identifying the correct pattern = 80% of the solution.
********************************************/
