/***************************************
       🏁 COMMON GOALS IN DSA
     (Pattern Clues Based on Problem Type)
        ✅ Notes by Alice for Rajan
***************************************/

/*------------------------------------------------------
1. ✅ Find a VALUE (Min, Max, Kth, Count, True/False)
--------------------------------------------------------*/

// 🔹 "Find the maximum/minimum ___":
//   - Max subarray sum → Kadane's Algo
//   - Min cost path → DP / Dijkstra
//   - Min jumps to reach end → Greedy / DP
//   - Kth smallest → Heap / Quickselect

// 🔹 "Return true/false":
//   - Two Sum → HashMap
//   - Cycle detection → DFS / Union-Find

// 🔹 "Count number of ___":
//   - Subsets → Recursion / DP
//   - Paths → DFS / Memoization
//   - Islands → BFS / DFS / Union-Find

/*------------------------------------------------------
2. 📏 Optimize Something (Greedy / DP / Binary Search)
--------------------------------------------------------*/

// 🔹 "Minimize maximum ___":
//   - Binary Search on Answer (e.g., Painters Partition, Split Array)

// 🔹 "Maximize minimum ___":
//   - Use Binary Search + Greedy (e.g., Aggressive Cows, Min Distance Between Balls)

// 🔹 "Get optimal profit / value":
//   - Unbounded Knapsack → DP
//   - Activity Selection → Greedy
//   - Buy and Sell Stocks → Greedy / DP

/*------------------------------------------------------
3. 🔁 Generate or Return Structures (Subsets, Permutations)
--------------------------------------------------------*/

// 🔹 "Return all subsets / permutations / combinations":
//   - Backtracking (Pick/Not Pick)
//   - Use recursion with state restoration

// 🔹 "Generate all valid ___":
//   - N-Queens → Backtracking
//   - Balanced Parentheses → Backtracking

// 🔹 "Construct a structure":
//   - Tree from preorder/inorder → Recursion
//   - Trie → Insertion logic

/*------------------------------------------------------
4. 📊 Sort or Rearrange Elements
--------------------------------------------------------*/

// 🔹 "Sort based on conditions":
//   - Custom comparator (struct or lambda)
//   - Bucket Sort / Counting Sort

// 🔹 "Rearrange to satisfy condition":
//   - Heap (e.g., Rearrange String)
//   - Greedy (e.g., Non-overlapping Intervals)

/*------------------------------------------------------
5. 📦 Process Ranges / Windows / Subarrays
--------------------------------------------------------*/

// 🔹 "Find longest/shortest subarray ___":
//   - Sliding Window
//   - Prefix Sum + HashMap

// 🔹 "Max sum/min sum subarray":
//   - Sliding Window / Kadane’s

// 🔹 "Number of subarrays that ___":
//   - HashMap + Prefix Sum
//   - Two pointers

/*------------------------------------------------------
6. 🧠 Answer Queries or Do Updates (Online/Offline)
--------------------------------------------------------*/

// 🔹 "Range queries (sum/min/max)":
//   - Segment Tree / Binary Indexed Tree (Fenwick Tree)

// 🔹 "Dynamic updates on data":
//   - Lazy Propagation
//   - Treap / Sqrt Decomposition

/*------------------------------------------------------
7. 📈 Find a Path or Reachability
--------------------------------------------------------*/

// 🔹 "Is there a path from A to B?":
//   - Graph DFS/BFS

// 🔹 "Shortest path":
//   - BFS (Unweighted)
//   - Dijkstra / Bellman-Ford / A*

// 🔹 "Topological sort":
//   - Kahn’s Algorithm / DFS

/*------------------------------------------------------
8. 🧩 Partitioning / Splitting
--------------------------------------------------------*/

// 🔹 "Can array be divided into ___":
//   - Subset Sum / DP
//   - Greedy + Sorting
//   - Backtracking

// 🔹 "Split array with min/max constraints":
//   - Binary Search on Answer + Greedy

/*------------------------------------------------------
9. 🔄 Detect Cycles / Connectivity
--------------------------------------------------------*/

// 🔹 "Cycle detection":
//   - DFS with visited stack
//   - Union-Find (DSU)

// 🔹 "Number of connected components":
//   - BFS / DFS
//   - Disjoint Set Union (DSU)

/*------------------------------------------------------
10. 🔐 Matching / Assigning / Scheduling
--------------------------------------------------------*/

// 🔹 "Assign tasks/jobs/resources optimally":
//   - Greedy (Earliest end time first)
//   - Priority Queue
//   - Interval Scheduling

// 🔹 "Can match pattern X?":
//   - KMP / Z-Algorithm / Trie

// 🔹 "Minimum platforms / rooms needed":
//   - Sweep Line Algorithm
//   - Event Sorting

