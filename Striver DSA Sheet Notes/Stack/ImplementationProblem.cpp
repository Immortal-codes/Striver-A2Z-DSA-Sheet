#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

// 1. Sliding Window Maximum (Deque)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

// 2. Stock Span Problem
vector<int> calculateSpan(vector<int>& price) {
    int n = price.size();
    vector<int> span(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
        span[i] = (st.empty()) ? (i + 1) : (i - st.top());
        st.push(i);
    }
    return span;
}

// 3. Celebrity Problem (O(n) solution)
int celebrity(vector<vector<int>>& M, int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) st.push(i);

    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        if (M[a][b] == 1) st.push(b); // a knows b => a not celeb
        else st.push(a);              // a doesn't know b => b not celeb
    }

    int candidate = st.top();
    for (int i = 0; i < n; i++) {
        if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0))
            return -1;
    }
    return candidate;
}

// 4. LRU Cache
class LRUCache {
    int capacity;
    list<int> dll;  // keys: most recent at front
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int cap) { capacity = cap; }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        dll.erase(cache[key].second);
        dll.push_front(key);
        cache[key].second = dll.begin();
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            dll.erase(cache[key].second);
        } else if (dll.size() == capacity) {
            int lru = dll.back();
            dll.pop_back();
            cache.erase(lru);
        }
        dll.push_front(key);
        cache[key] = {value, dll.begin()};
    }
};

// 5. LFU Cache (Optimized)
class LFUCache {
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq;
    unordered_map<int, list<int>> freqToKeys;
    unordered_map<int, list<int>::iterator> keyToIter;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        int freq = keyToValFreq[key].second;
        freqToKeys[freq].erase(keyToIter[key]);

        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        freq++;
        keyToValFreq[key].second = freq;
        freqToKeys[freq].push_front(key);
        keyToIter[key] = freqToKeys[freq].begin();
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) return -1;
        updateFreq(key);
        return keyToValFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            updateFreq(key);
            return;
        }

        if (keyToValFreq.size() == capacity) {
            int evict = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);
            keyToValFreq.erase(evict);
            keyToIter.erase(evict);
        }

        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};

// Driver Function (test examples if needed)
int main() {
    // Sliding Window
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    auto res = maxSlidingWindow(nums, k);
    cout << "Sliding Window Maximum: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    // Stock Span
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    auto span = calculateSpan(prices);
    cout << "Stock Span: ";
    for (int s : span) cout << s << " ";
    cout << endl;

    // Celebrity Problem
    vector<vector<int>> M = {{0,1,0}, {0,0,0}, {0,1,0}};
    int celeb = celebrity(M, 3);
    cout << "Celebrity: " << (celeb == -1 ? "None" : to_string(celeb)) << endl;

    // LRU
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << "LRU Get(1): " << lru.get(1) << endl;
    lru.put(3, 3);
    cout << "LRU Get(2): " << lru.get(2) << endl;

    // LFU
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << "LFU Get(1): " << lfu.get(1) << endl;
    lfu.put(3, 3);
    cout << "LFU Get(2): " << lfu.get(2) << endl;
    cout << "LFU Get(3): " << lfu.get(3) << endl;

    return 0;
}
