#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

// 1. Recursive atoi()
int atoiRecursive(const string &s, int index = 0, int sign = 1) {
    if (index >= (int)s.size()) return 0;

    if (index == 0 && s[index] == '-') {
        return atoiRecursive(s, index + 1, -1);
    }

    if (s[index] < '0' || s[index] > '9') return 0;

    int digit = s[index] - '0';
    int partial = atoiRecursive(s, index + 1, sign);

    return sign * (digit * (int)pow(10, (int)s.size() - index - 1) + abs(partial));
}

// 2. Pow(x, n)
double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / myPow(x, -n);

    double half = myPow(x, n / 2);

    if (n % 2 == 0) return half * half;
    else return half * half * x;
}

// 3. Count Good Numbers (Binary strings of length n with no consecutive 1s)
int countGoodNumbers(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    return countGoodNumbers(n - 1) + countGoodNumbers(n - 2);
}

// 4. Sort a stack using recursion
void insertSorted(stack<int> &st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }
    int temp = st.top(); st.pop();
    insertSorted(st, x);
    st.push(temp);
}

void sortStack(stack<int> &st) {
    if (st.empty()) return;
    int x = st.top(); st.pop();
    sortStack(st);
    insertSorted(st, x);
}

// 5. Reverse a stack using recursion
void insertAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int temp = st.top(); st.pop();
    insertAtBottom(st, x);
    st.push(temp);
}

void reverseStack(stack<int> &st) {
    if (st.empty()) return;
    int x = st.top(); st.pop();
    reverseStack(st);
    insertAtBottom(st, x);
}


int main() {
    // Test 1: Recursive atoi()
    cout << "atoiRecursive(\"-12345\") = " << atoiRecursive("-12345") << "\n";

    // Test 2: Pow(x, n)
    cout << "myPow(2, 10) = " << myPow(2, 10) << "\n";
    cout << "myPow(2, -2) = " << myPow(2, -2) << "\n";

    // Test 3: Count Good Numbers
    int n = 5;
    cout << "countGoodNumbers(" << n << ") = " << countGoodNumbers(n) << "\n";

    // Test 4: Sort a stack
    stack<int> st1;
    st1.push(3);
    st1.push(1);
    st1.push(4);
    st1.push(2);
    sortStack(st1);
    cout << "Sorted stack: ";
    while (!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << "\n";

    // Test 5: Reverse a stack
    stack<int> st2;
    st2.push(1);
    st2.push(2);
    st2.push(3);
    st2.push(4);
    reverseStack(st2);
    cout << "Reversed stack: ";
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << "\n";

    return 0;
}
