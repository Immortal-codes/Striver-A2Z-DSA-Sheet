#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

// ------------------------
// 1. Design Twitter
// ------------------------
class Twitter {
    int time = 0;
    unordered_map<int, set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets; // user -> (time, tweetId)
public:
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> feed;
        for (int followee : followers[userId]) {
            for (auto& t : tweets[followee])
                feed.push(t);
        }
        for (auto& t : tweets[userId]) feed.push(t);

        vector<int> result;
        while (!feed.empty() && result.size() < 10) {
            result.push_back(feed.top().second);
            feed.pop();
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

// ------------------------
// 2. Connect `n` Ropes with Min Cost
// ------------------------
int connectRopes(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());
    int cost = 0;
    while (pq.size() > 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        cost += first + second;
        pq.push(first + second);
    }
    return cost;
}

// ------------------------
// 3. Kth Largest Element in a Stream
// ------------------------
class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) add(num);
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};

// ------------------------
// 4. Maximum Sum Combination
// ------------------------
vector<int> maxCombinations(vector<int>& A, vector<int>& B, int k) {
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    priority_queue<tuple<int, int, int>> pq;
    set<pair<int, int>> used;

    pq.push({A[0] + B[0], 0, 0});
    used.insert({0, 0});

    vector<int> result;
    while (k-- && !pq.empty()) {
        auto [sum, i, j] = pq.top(); pq.pop();
        result.push_back(sum);

        if (i + 1 < A.size() && !used.count({i + 1, j})) {
            pq.push({A[i + 1] + B[j], i + 1, j});
            used.insert({i + 1, j});
        }

        if (j + 1 < B.size() && !used.count({i, j + 1})) {
            pq.push({A[i] + B[j + 1], i, j + 1});
            used.insert({i, j + 1});
        }
    }

    return result;
}

// ------------------------
// 5. Find Median from Data Stream
// ------------------------
class MedianFinder {
    priority_queue<int> maxHeap; // left half
    priority_queue<int, vector<int>, greater<int>> minHeap; // right half
public:
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top()); maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

// ------------------------
// 6. K Most Frequent Elements
// ------------------------
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int n : nums) freq[n]++;

    priority_queue<pair<int, int>> pq;
    for (auto& [num, count] : freq)
        pq.push({count, num});

    vector<int> result;
    while (k-- && !pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

// ------------------------
// Main Function to Demonstrate
// ------------------------
int main() {
    // Problem 2: Connect ropes
    vector<int> ropes = {4, 3, 2, 6};
    cout << "Min Cost to Connect Ropes: " << connectRopes(ropes) << endl;

    // Problem 3: Kth largest element in stream
    vector<int> stream = {4, 5, 8, 2};
    KthLargest kth(3, stream);
    cout << "Kth Largest after adding 3: " << kth.add(3) << endl;

    // Problem 4: Max Sum Combinations
    vector<int> A = {1, 4, 2, 3}, B = {2, 5, 1, 6};
    vector<int> comb = maxCombinations(A, B, 4);
    cout << "Top 4 Max Sum Combinations: ";
    for (int x : comb) cout << x << " "; cout << endl;

    // Problem 5: Find Median
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl;
    mf.addNum(3);
    cout << "Median after adding 3: " << mf.findMedian() << endl;

    // Problem 6: K most frequent
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> freqK = topKFrequent(nums, 2);
    cout << "Top 2 Frequent Elements: ";
    for (int n : freqK) cout << n << " "; cout << endl;

    // Problem 1 (Twitter)
    Twitter twitter;
    twitter.postTweet(1, 5);
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    vector<int> feed = twitter.getNewsFeed(1);
    cout << "User 1 News Feed: ";
    for (int t : feed) cout << t << " "; cout << endl;

    return 0;
}
