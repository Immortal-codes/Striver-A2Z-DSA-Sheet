Here are clean, structured .md (Markdown) notes for Sliding Window and Two Pointer techniques, ready to be copy-pasted into your VS Code .md file.

# Sliding Window & Two Pointer Techniques in DSA

## 🧠 Concept Overview

### Sliding Window
Used to reduce time complexity of problems involving **subarrays or substrings** in linear data structures (like arrays or strings), especially for:
- Fixed-size windows (e.g., maximum sum of subarray of size `k`)
- Variable-size windows (e.g., longest substring without repeating characters)

### Two Pointer
Used when solving problems that require:
- Comparing elements from both ends
- Merging or traversing sorted arrays
- Finding pairs or triplets that satisfy a condition

---

## 🧰 Sliding Window Technique

### 🔹 When to Use
- Array/String based problems
- Continuous window (subarray/substring)
- Optimize brute-force O(n²) to O(n)

### 🔹 Types
#### 1. Fixed Size Window
Window size is fixed; slide the window by 1 index at a time.

```cpp
int maxSum(vector<int>& nums, int k) {
    int windowSum = 0, maxSum = 0;
    for (int i = 0; i < k; i++) windowSum += nums[i];
    maxSum = windowSum;

    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
2. Variable Size Window

Window grows/shrinks depending on a condition (like target sum or unique elements).

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, sum = 0, minLen = INT_MAX;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }
    return (minLen == INT_MAX) ? 0 : minLen;
}
🔥 Patterns
Maximum/Minimum sum subarray of size k
Longest substring with k distinct characters
Minimum window substring
Smallest subarray with sum ≥ k
🧰 Two Pointer Technique

🔹 When to Use
Input is sorted (or needs sorting)
You want to optimize nested loops
You're dealing with two moving indices
🔹 Types
1. Opposite Direction

One pointer at the beginning, one at the end.

bool hasPairWithSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}
2. Same Direction (Like Sliding Window)

Both pointers start at the beginning.

int countSubarrays(vector<int>& arr, int k) {
    int left = 0, count = 0, sum = 0;
    for (int right = 0; right < arr.size(); right++) {
        sum += arr[right];
        while (sum > k) sum -= arr[left++];
        count += (right - left + 1);
    }
    return count;
}
🧪 Common Problems (Practice List)

Sliding Window
Maximum Sum Subarray of size k
Longest Substring Without Repeating Characters
Minimum Window Substring
Maximum Number of Vowels in a Substring
Sliding Window Maximum (Monotonic Queue)
Two Pointer
Two Sum (Sorted)
3Sum / 4Sum
Container With Most Water
Remove Duplicates from Sorted Array
Merge Sorted Arrays
💡 Tips

Always identify the window condition or pairing logic
For two pointer, check if sorting is required
Dry run on paper for clarity on movement of pointers
✅ Summary

Technique	Use Case	Pointers	Data Structure
Sliding Window	Subarray/Substrings, Max/Min Sum	Left + Right	Array/String
Two Pointer	Pair Searching, Merging, Sorting	Start + End	Mostly Arrays