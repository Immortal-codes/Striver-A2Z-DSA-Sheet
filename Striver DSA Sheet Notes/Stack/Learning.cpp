#include <iostream>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

//
// 1. Implement Stack using Array
//
class StackArray {
private:
    int topIdx;
    int* arr;
    int capacity;

public:
    StackArray(int size) {
        capacity = size;
        arr = new int[capacity];
        topIdx = -1;
    }

    void push(int x) {
        if (topIdx == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIdx] = x;
    }

    void pop() {
        if (topIdx == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        topIdx--;
    }

    int top() {
        if (topIdx == -1) return -1;
        return arr[topIdx];
    }

    bool empty() {
        return topIdx == -1;
    }
};

//
// 2. Implement Queue using Array
//
class QueueArray {
private:
    int frontIdx, rearIdx, *arr, size;

public:
    QueueArray(int cap) {
        size = cap;
        arr = new int[size];
        frontIdx = 0;
        rearIdx = 0;
    }

    void enqueue(int x) {
        if (rearIdx == size) {
            cout << "Queue Full\n";
            return;
        }
        arr[rearIdx++] = x;
    }

    void dequeue() {
        if (frontIdx == rearIdx) {
            cout << "Queue Empty\n";
            return;
        }
        frontIdx++;
    }

    int front() {
        if (frontIdx == rearIdx) return -1;
        return arr[frontIdx];
    }

    bool empty() {
        return frontIdx == rearIdx;
    }
};

//
// 3. Implement Stack using Queues
//
class StackUsingQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        while (--sz) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (!q.empty()) q.pop();
    }

    int top() {
        return q.empty() ? -1 : q.front();
    }

    bool empty() {
        return q.empty();
    }
};

//
// 4. Implement Queue using Stacks
//
class QueueUsingStack {
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) s2.pop();
    }

    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.empty() ? -1 : s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

//
// 5. Implement Stack using Linked List
//
struct StackNode {
    int data;
    StackNode* next;
    StackNode(int val) : data(val), next(nullptr) {}
};

class StackLL {
    StackNode* topNode;

public:
    StackLL() : topNode(nullptr) {}

    void push(int x) {
        StackNode* node = new StackNode(x);
        node->next = topNode;
        topNode = node;
    }

    void pop() {
        if (!topNode) return;
        StackNode* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        return topNode ? topNode->data : -1;
    }

    bool empty() {
        return topNode == nullptr;
    }
};

//
// 6. Implement Queue using Linked List
//
struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int val) : data(val), next(nullptr) {}
};

class QueueLL {
    QueueNode* frontNode;
    QueueNode* rearNode;

public:
    QueueLL() : frontNode(nullptr), rearNode(nullptr) {}

    void enqueue(int x) {
        QueueNode* node = new QueueNode(x);
        if (!rearNode) {
            frontNode = rearNode = node;
            return;
        }
        rearNode->next = node;
        rearNode = node;
    }

    void dequeue() {
        if (!frontNode) return;
        QueueNode* temp = frontNode;
        frontNode = frontNode->next;
        if (!frontNode) rearNode = nullptr;
        delete temp;
    }

    int front() {
        return frontNode ? frontNode->data : -1;
    }

    bool empty() {
        return frontNode == nullptr;
    }
};

//
// 7. Check for Balanced Parentheses
//
bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) return false;
        }
    }
    return st.empty();
}

//
// 8. Implement Min Stack
//
class MinStack {
    stack<int> st, minSt;

public:
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

//
// Main function for testing
//
int main() {
    cout << "Balanced: " << isBalanced("{[()]}") << endl;

    StackArray sa(5);
    sa.push(10); sa.push(20);
    cout << "Top of StackArray: " << sa.top() << endl;

    QueueArray qa(5);
    qa.enqueue(5); qa.enqueue(10); qa.dequeue();
    cout << "Front of QueueArray: " << qa.front() << endl;

    StackUsingQueue suq;
    suq.push(1); suq.push(2);
    cout << "Top of StackUsingQueue: " << suq.top() << endl;

    QueueUsingStack qus;
    qus.enqueue(3); qus.enqueue(4);
    cout << "Front of QueueUsingStack: " << qus.front() << endl;

    StackLL sll;
    sll.push(100); sll.push(200); sll.pop();
    cout << "Top of StackLL: " << sll.top() << endl;

    QueueLL qll;
    qll.enqueue(11); qll.enqueue(22); qll.dequeue();
    cout << "Front of QueueLL: " << qll.front() << endl;

    MinStack ms;
    ms.push(3); ms.push(5); ms.push(2);
    cout << "Min in MinStack: " << ms.getMin() << endl;

    return 0;
}
