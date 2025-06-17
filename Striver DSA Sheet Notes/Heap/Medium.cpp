#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ------------------------
// 1. Kth Largest Element in Array
// ------------------------
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

// ------------------------
// 2. Kth Smallest Element in Array
// ------------------------
int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;
    for (int num : nums) {
        maxHeap.push(num);
        if (maxHeap.size() > k) maxHeap.pop();
    }
    return maxHeap.top();
}

// ------------------------
// 3. Sort a K Sorted Array
// ------------------------
vector<int> sortKSortedArray(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        minHeap.push(arr[i]);
        if (minHeap.size() > k) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}

// ------------------------
// 4. Merge M Sorted Lists
// ------------------------
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

struct compareNode {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*>& lists) {
    priority_queue<Node*, vector<Node*>, compareNode> pq;
    for (auto list : lists) {
        if (list) pq.push(list);
    }

    Node dummy(0);
    Node* tail = &dummy;

    while (!pq.empty()) {
        Node* smallest = pq.top(); pq.pop();
        tail->next = smallest;
        tail = tail->next;
        if (smallest->next) pq.push(smallest->next);
    }

    return dummy.next;
}

// ------------------------
// 5. Replace Each Element by Its Rank
// ------------------------
vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    unordered_map<int, int> rank;
    int r = 1;
    for (int num : sortedArr) {
        if (rank.count(num) == 0) rank[num] = r++;
    }
    for (int& num : arr) {
        num = rank[num];
    }
    return arr;
}

// ------------------------
// 6. Task Scheduler
// ------------------------
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    for (char task : tasks) freq[task]++;
    priority_queue<int> pq;
    for (auto& [t, f] : freq) pq.push(f);

    int time = 0;
    while (!pq.empty()) {
        int cycle = n + 1;
        vector<int> temp;

        for (int i = 0; i < cycle && !pq.empty(); ++i) {
            temp.push_back(pq.top() - 1);
            pq.pop();
            time++;
        }

        for (int cnt : temp) {
            if (cnt > 0) pq.push(cnt);
        }

        if (!pq.empty()) time += cycle - temp.size();  // idle time
    }

    return time;
}

// ------------------------
// 7. Hands of Straights
// ------------------------
bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;

    map<int, int> freq;
    for (int card : hand) freq[card]++;

    for (auto& [start, count] : freq) {
        if (count > 0) {
            for (int i = 0; i < groupSize; i++) {
                if (freq[start + i] < count) return false;
                freq[start + i] -= count;
            }
        }
    }

    return true;
}

// ------------------------
// Main Function to Demo Usage
// ------------------------
int main() {
    // Problem 1 & 2
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    cout << "Kth Largest (2): " << findKthLargest(arr, 2) << endl;
    cout << "Kth Smallest (2): " << findKthSmallest(arr, 2) << endl;

    // Problem 3
    vector<int> kSorted = {6, 5, 3, 2, 8, 10, 9};
    vector<int> sortedK = sortKSortedArray(kSorted, 3);
    cout << "Sorted K-Sorted Array: ";
    for (int i : sortedK) cout << i << " "; cout << endl;

    // Problem 4
    Node* a = new Node(1); a->next = new Node(4);
    Node* b = new Node(2); b->next = new Node(5);
    Node* c = new Node(3); c->next = new Node(6);
    vector<Node*> lists = {a, b, c};
    Node* merged = mergeKLists(lists);
    cout << "Merged Linked Lists: ";
    while (merged) { cout << merged->data << " "; merged = merged->next; } cout << endl;

    // Problem 5
    vector<int> toRank = {40, 10, 20, 30, 20};
    vector<int> ranked = arrayRankTransform(toRank);
    cout << "Array with Ranks: ";
    for (int val : ranked) cout << val << " "; cout << endl;

    // Problem 6
    vector<char> tasks = {'A','A','A','B','B','B'};
    cout << "Task Scheduler Time (n=2): " << leastInterval(tasks, 2) << endl;

    // Problem 7
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    cout << "Is NStraightHand (groupSize=3): " << (isNStraightHand(hand, 3) ? "Yes" : "No") << endl;

    return 0;
}
