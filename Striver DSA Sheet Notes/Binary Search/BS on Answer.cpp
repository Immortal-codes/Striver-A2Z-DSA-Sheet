# Advanced Binary Search Problems (FAANG Level)

```cpp
#include <bits/stdc++.h>
using namespace std;

// 1. Find square root of a number in log n
typedef long long ll;
int floorSqrt(int x) {
    int low = 1, high = x, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if ((ll)mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// 2. Find the Nth root of a number using binary search
int NthRoot(int n, int m) {
    int low = 1, high = m;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = pow(mid, n);
        if (val == m) return mid;
        else if (val < m) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// 3. Koko Eating Bananas
bool canEat(vector<int>& piles, int h, int speed) {
    int time = 0;
    for (int pile : piles)
        time += ceil((double)pile / speed);
    return time <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canEat(piles, h, mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}

// 4. Minimum days to make M bouquets
bool isPossible(vector<int>& bloomDay, int m, int k, int days) {
    int bouquets = 0, count = 0;
    for (int day : bloomDay) {
        if (day <= days) {
            count++;
            if (count == k) {
                bouquets++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long val = 1LL * m * k;
    if (bloomDay.size() < val) return -1;
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isPossible(bloomDay, m, k, mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}

// 5. Find the smallest Divisor such that sum <= threshold
bool isPossibleDiv(vector<int>& nums, int threshold, int div) {
    int sum = 0;
    for (int num : nums) sum += ceil((double)num / div);
    return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end());
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isPossibleDiv(nums, threshold, mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}

// 6. Capacity to Ship Packages within D Days
bool canShip(vector<int>& weights, int days, int capacity) {
    int cur = 0, d = 1;
    for (int w : weights) {
        if (cur + w > capacity) {
            d++;
            cur = 0;
        }
        cur += w;
    }
    return d <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canShip(weights, days, mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}

// 7. Kth Missing Positive Number
int findKthPositive(vector<int>& arr, int k) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] - mid - 1 < k) left = mid + 1;
        else right = mid;
    }
    return left + k;
}

// 8. Aggressive Cows
bool isPossibleCows(vector<int>& stalls, int dist, int cows) {
    int count = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            count++;
            last = stalls[i];
        }
    }
    return count >= cows;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls.back() - stalls.front(), ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossibleCows(stalls, mid, cows)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// 9. Book Allocation Problem
bool isPossibleBook(vector<int>& books, int m, int pages) {
    int count = 1, sum = 0;
    for (int b : books) {
        if (b > pages) return false;
        if (sum + b > pages) {
            count++;
            sum = b;
        } else sum += b;
    }
    return count <= m;
}

int bookAllocation(vector<int>& books, int m) {
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0), ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossibleBook(books, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

// 10. Split array - Largest Sum (Same as Book Allocation)
int splitArray(vector<int>& nums, int k) {
    return bookAllocation(nums, k);
}

// 11. Painter's Partition Problem
int paintersPartition(vector<int>& boards, int k) {
    return bookAllocation(boards, k);
}

// 12. Minimize Max Distance to Gas Station
long double minimizeMaxDist(vector<int>& stations, int k) {
    auto isPossible = [&](long double dist) {
        int count = 0;
        for (int i = 1; i < stations.size(); i++) {
            count += (int)((stations[i] - stations[i-1]) / dist);
        }
        return count <= k;
    };
    
    long double low = 0, high = 1e8, mid;
    for (int i = 0; i < 100; i++) {
        mid = (low + high) / 2.0;
        if (isPossible(mid)) high = mid;
        else low = mid;
    }
    return high;
}

// 13. Median of 2 sorted arrays
int findKth(vector<int>& a, vector<int>& b, int k) {
    if (a.size() > b.size()) return findKth(b, a, k);
    int low = max(0, k - (int)b.size()), high = min(k, (int)a.size());
    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
        int r1 = cut1 == a.size() ? INT_MAX : a[cut1];
        int r2 = cut2 == b.size() ? INT_MAX : b[cut2];

        if (l1 <= r2 && l2 <= r1) return max(l1, l2);
        else if (l1 > r2) high = cut1 - 1;
        else low = cut1 + 1;
    }
    return -1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int total = n + m;
    if (total % 2 == 1) return findKth(nums1, nums2, total / 2 + 1);
    else return (findKth(nums1, nums2, total / 2) + findKth(nums1, nums2, total / 2 + 1)) / 2.0;
}

// 14. Kth element of 2 sorted arrays
int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
    return findKth(nums1, nums2, k);
}

```

> These problems use the **Binary Search on Answer** technique, a vital tool for solving FAANG-level search problems where the answer lies within a range.
