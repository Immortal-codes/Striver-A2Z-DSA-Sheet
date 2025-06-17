/***********************
 🔥 DSA Notes - Must Solve
 📘 Author: Rajan Sharma
 🏆 Level: Medium to Hard (FAANG Level)
***********************/


#include <vector>
#include <numeric>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/****************************************************
1. N Meetings in One Room
****************************************************/
struct Meeting {
    int start, end, pos;
};
bool comp(Meeting m1, Meeting m2) {
    if (m1.end == m2.end) return m1.pos < m2.pos;
    return m1.end < m2.end;
}
int maxMeetings(int start[], int end[], int n) {
    vector<Meeting> meetings(n);
    for (int i = 0; i < n; i++) meetings[i] = {start[i], end[i], i + 1};
    sort(meetings.begin(), meetings.end(), comp);

    int count = 1, lastEnd = meetings[0].end;
    for (int i = 1; i < n; i++) {
        if (meetings[i].start > lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }
    return count;
}

/****************************************************
2. Jump Game
****************************************************/
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}

/****************************************************
3. Jump Game II (Min Jumps to End)
****************************************************/
int jump(vector<int>& nums) {
    int jumps = 0, farthest = 0, currEnd = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == currEnd) {
            jumps++;
            currEnd = farthest;
        }
    }
    return jumps;
}

/****************************************************
4. Minimum Number of Platforms Required
****************************************************/
int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    int plat_needed = 1, result = 1, i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        } else {
            plat_needed--;
            j++;
        }
        result = max(result, plat_needed);
    }
    return result;
}

/****************************************************
5. Job Sequencing Problem
****************************************************/
struct Job {
    int id, deadline, profit;
};
bool comp(Job a, Job b) {
    return a.profit > b.profit;
}
pair<int, int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comp);
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, arr[i].deadline);

    vector<int> slot(maxDeadline + 1, -1);
    int count = 0, totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                count++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }
    return {count, totalProfit};
}

/****************************************************
6. Candy (Leetcode Hard)
****************************************************/
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);

    for (int i = 1; i < n; i++)
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;

    for (int i = n - 2; i >= 0; i--)
        if (ratings[i] > ratings[i + 1])
            candies[i] = max(candies[i], candies[i + 1] + 1);

    return accumulate(candies.begin(), candies.end(), 0);
}

/****************************************************
7. Shortest Job First (SJF) - Non-preemptive
****************************************************/
struct Process {
    int id, bt;
};
bool comp2(Process a, Process b) {
    return a.bt < b.bt;
}
void findAvgTime(Process proc[], int n) {
    sort(proc, proc + n, comp2);
    int wt[n], tat[n];
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = proc[i - 1].bt + wt[i - 1];

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + proc[i].bt;

    double total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "Average Waiting Time: " << total_wt / n << endl;
    cout << "Average Turnaround Time: " << total_tat / n << endl;
}

/****************************************************
8. Least Recently Used (LRU) Cache
****************************************************/
class LRUCache {
    int cap;
    list<int> dll;
    unordered_map<int, pair<int, list<int>::iterator>> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        dll.erase(mp[key].second);
        dll.push_front(key);
        mp[key].second = dll.begin();
        return mp[key].first;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key].second);
        } else if (dll.size() == cap) {
            int last = dll.back();
            dll.pop_back();
            mp.erase(last);
        }
        dll.push_front(key);
        mp[key] = {value, dll.begin()};
    }
};

/****************************************************
9. Insert Interval
****************************************************/
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0, n = intervals.size();

    while (i < n && intervals[i][1] < newInterval[0])
        res.push_back(intervals[i++]);

    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);

    while (i < n)
        res.push_back(intervals[i++]);

    return res;
}

/****************************************************
10. Merge Intervals
****************************************************/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (res.back()[1] >= intervals[i][0]) {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }
    return res;
}
