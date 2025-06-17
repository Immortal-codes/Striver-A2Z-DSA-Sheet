📘 Greedy Algorithms – FAANG-Level Theory Notes
==============================================

🔹 What is a Greedy Algorithm?
------------------------------
A greedy algorithm builds up a solution piece by piece, always choosing the **locally optimal** option at each step, **hoping that this leads to a globally optimal solution**.

🧠 It **does not** consider future consequences — it commits to the current best decision.

✅ Greedy works **only when the problem exhibits**:
1. **Greedy Choice Property**: A global optimum can be reached by choosing the best local option.
2. **Optimal Substructure**: Optimal solution can be constructed from optimal solutions of subproblems.

🧪 If a problem lacks these, Greedy may fail — DP is often preferred instead.

🔹 Time Complexity
------------------
Greedy solutions often sort data first, leading to:
- O(n log n) for sorting + O(n) for iteration.
- Very efficient, usually faster than DP.

🔹 When to Apply Greedy?
------------------------
- You're asked to **maximize or minimize** something.
- Choices must be made step-by-step (e.g., weights, deadlines, profits).
- Problem hints at **non-overlapping**, **lexicographical order**, **ratios**, or **local wins**.

🔹 Common Patterns in Greedy
----------------------------
1. **Sort by value/weight/ratio/deadline/start-end**.
2. **Pick next best option** (min/max).
3. **Use priority queue/heap/greedy jumps**.
4. **Greedy + Two Pointers or Greedy + Stack** hybrid is common.

🔹 Must-Know FAANG-Level Greedy Problems
----------------------------------------

1. ✅ Activity Selection Problem  
   → Choose max non-overlapping intervals by sorting end times.

2. ✅ Fractional Knapsack  
   → Sort by profit/weight ratio, take greedy amount.

3. ✅ Job Sequencing with Deadlines  
   → Greedy by profit, and place each job at latest free time before deadline.

4. ✅ Huffman Encoding  
   → Greedy choice using min-heap to build prefix-free binary codes.

5. ✅ Minimum Number of Platforms (Train Schedule)  
   → Greedy with two pointers + sorting arrival/departure.

6. ✅ N Meetings in One Room  
   → Classic interval scheduling (sort by end time).

7. ✅ Gas Station Problem  
   → Greedy scan to find circular path with enough fuel.

8. ✅ Candy Distribution  
   → Greedy from left to right and right to left.

9. ✅ Jump Game  
   → Greedy max jump coverage.

10. ✅ Merge Intervals  
    → Sort and greedily merge overlapping intervals.

11. ✅ Reorganize String  
    → Greedy + Heap to distribute high-frequency chars.

12. ✅ Minimum Coins/Notes (Indian Coin Change)  
    → Greedy pick highest denomination first.

🔹 Greedy vs DP
---------------
| Feature              | Greedy         | Dynamic Programming   |
|----------------------|----------------|------------------------|
| Local vs Global       | Local          | Global                 |
| Memory                | Low (O(1)/O(n))| High (Memoization)     |
| Speed                 | Fast           | Slower                 |
| Guarantees Optimality | Not always     | Yes                    |

✅ If Greedy works, it’s preferred over DP due to simplicity and performance.

🔹 Key Interview Tips
---------------------
- Always **prove greedy choice is safe**. Think: “Can I safely discard all other options?”
- Use **counterexamples** to test greedy logic.
- Greedy can be combined with sorting, heaps, stacks, two pointers.
- **Corner case analysis is critical** (e.g., 0-length intervals, overlapping conditions).

🔹 Summary Checklist
--------------------
- [ ] Identify greedy choice property?
- [ ] Prove optimal substructure?
- [ ] Check if sorting helps?
- [ ] Consider heap/two pointers if needed?
- [ ] Validate greedy is optimal with edge cases?

📌 Pro Tip:
-----------
Before applying greedy, always ask:
**“If I make this move now, will I regret it later?”**

If yes → ❌ Greedy won’t work → Try DP.
If no → ✅ Greedy may work!

<!-- ***********Notes 2.O  ************************ -->


/***************************************************************
 📘 GREEDY ALGORITHM MASTER NOTES
 ✍️ Prepared by: Rajan Sharma | Target: FAANG SDE
***************************************************************/

/***************************************************************
🔹 What is Greedy Algorithm?
---------------------------------------------------------------
A Greedy Algorithm makes the locally optimal choice at each step
with the hope of finding a global optimum.
***************************************************************/

/***************************************************************
🔹 When to Use Greedy
---------------------------------------------------------------
✅ Problem asks for MAX/MIN/OPTIMAL result
✅ Sorting by value, cost, time, etc. helps
✅ No need to backtrack or revisit decisions
✅ No overlapping subproblems (unlike DP)
***************************************************************/

/***************************************************************
🔹 Common Greedy Patterns
***************************************************************/
1. Sort by End Time         → N Meetings in One Room
2. Sort by Profit/Weight    → Job Sequencing, Knapsack
3. Use Min/Max Heap         → Platforms, Huffman Coding
4. Two Pointers             → Gas Station, Candy
5. Greedy + Sliding Window  → Jump Game II
6. Prefix Sum Tracking      → Gas Station, Circular Track

/***************************************************************
🔹 Greedy vs Dynamic Programming
---------------------------------------------------------------
| Feature                  | Greedy         | DP               |
|--------------------------|----------------|------------------|
| Optimal Substructure     | ✅              | ✅                |
| Overlapping Subproblems  | ❌              | ✅                |
| Stores Intermediate Data | ❌              | ✅                |
| Backtracking Required?   | ❌              | ✅                |
***************************************************************/

/***************************************************************
🔹 Top Greedy Problems to Master
***************************************************************/
