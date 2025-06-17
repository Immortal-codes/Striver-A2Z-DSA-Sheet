#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

//
// 1. Infix to Postfix
//
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        } else {
            while (!st.empty() && precedence(ch) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

//
// 2. Infix to Prefix
//
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

//
// 3. Prefix to Infix
//
string prefixToInfix(string prefix) {
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string exp = "(" + op1 + c + op2 + ")";
            st.push(exp);
        }
    }
    return st.top();
}

//
// 4. Prefix to Postfix
//
string prefixToPostfix(string prefix) {
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string exp = op1 + op2 + c;
            st.push(exp);
        }
    }
    return st.top();
}

//
// 5. Postfix to Prefix
//
string postfixToPrefix(string postfix) {
    stack<string> st;
    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string exp = c + op1 + op2;
            st.push(exp);
        }
    }
    return st.top();
}

//
// 6. Postfix to Infix
//
string postfixToInfix(string postfix) {
    stack<string> st;
    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string exp = "(" + op1 + c + op2 + ")";
            st.push(exp);
        }
    }
    return st.top();
}

//
// Main function to test
//
int main() {
    string infix = "a+(b*c)";
    string prefix = "*+ABC";
    string postfix = "ab+c*";

    cout << "Infix to Postfix: " << infixToPostfix(infix) << endl;
    cout << "Infix to Prefix: " << infixToPrefix(infix) << endl;
    cout << "Prefix to Infix: " << prefixToInfix(prefix) << endl;
    cout << "Prefix to Postfix: " << prefixToPostfix(prefix) << endl;
    cout << "Postfix to Prefix: " << postfixToPrefix(postfix) << endl;
    cout << "Postfix to Infix: " << postfixToInfix(postfix) << endl;

    return 0;
}
