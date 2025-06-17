#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// 1 & 5. Expression Add Operators / Generate all possible equations to reach target
// Uses backtracking to insert '+', '-', '*' between digits to form expressions equal to target
void addOperatorsHelper(const string &num, int target, int pos, long long currValue, long long lastOperand, string expr, vector<string> &result) {
    if (pos == num.size()) {
        if (currValue == target) {
            result.push_back(expr);
        }
        return;
    }

    for (int i = pos; i < num.size(); i++) {
        // Avoid numbers with leading zero
        if (i != pos && num[pos] == '0') break;

        string part = num.substr(pos, i - pos + 1);
        long long currNum = stoll(part);

        if (pos == 0) {
            // First number, no operator
            addOperatorsHelper(num, target, i + 1, currNum, currNum, part, result);
        } else {
            addOperatorsHelper(num, target, i + 1, currValue + currNum, currNum, expr + "+" + part, result);
            addOperatorsHelper(num, target, i + 1, currValue - currNum, -currNum, expr + "-" + part, result);
            // Multiplication needs special handling due to precedence
            addOperatorsHelper(num, target, i + 1, currValue - lastOperand + lastOperand * currNum, lastOperand * currNum, expr + "*" + part, result);
        }
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> result;
    if (num.empty()) return result;
    addOperatorsHelper(num, target, 0, 0, 0, "", result);
    return result;
}

// 2 & 3. Generate all valid IP Addresses / Restore IP Addresses from string
// IP address segments must be 0-255, no leading zeros unless single digit zero
void restoreIpHelper(const string &s, int start, int part, vector<string> &result, string current) {
    if (part == 4 && start == s.size()) {
        current.pop_back();  // remove trailing '.'
        result.push_back(current);
        return;
    }
    if (part == 4 || start == s.size()) return;

    for (int len = 1; len <= 3 && start + len <= s.size(); len++) {
        string segment = s.substr(start, len);
        if ((segment[0] == '0' && segment.size() > 1) || stoi(segment) > 255) continue;
        restoreIpHelper(s, start + len, part + 1, result, current + segment + ".");
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    restoreIpHelper(s, 0, 0, result, "");
    return result;
}

// 4. Arithmetic Expressions Evaluation - Evaluate expression string with +,-,*,/
// For simplicity, support +, -, * only (like Leetcode)
// Using recursion + helper to handle precedence (shunting yard or DFS eval)
long long evalExpr(const string &expr, int &pos) {
    vector<long long> nums;
    vector<char> ops;
    long long num = 0;
    char sign = '+';

    while (pos < (int)expr.size()) {
        char c = expr[pos];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        if ((!isdigit(c) && c != ' ') || pos == (int)expr.size() - 1) {
            if (sign == '+') nums.push_back(num);
            else if (sign == '-') nums.push_back(-num);
            else if (sign == '*') {
                long long prev = nums.back();
                nums.pop_back();
                nums.push_back(prev * num);
            }
            sign = c;
            num = 0;
        }
        pos++;
    }
    long long res = 0;
    for (auto &x : nums) res += x;
    return res;
}

// Wrapper to evaluate simple expression without parentheses, only +,-,*
long long evaluateExpression(const string &expr) {
    int pos = 0;
    return evalExpr(expr, pos);
}

int main() {
    // Expression Add Operators example
    string num = "123";
    int target = 6;
    auto expressions = addOperators(num, target);
    cout << "Expressions that evaluate to " << target << ":\n";
    for (auto &e : expressions) cout << e << "\n";
    cout << "\n";

    // Restore IP Addresses example
    string ipStr = "25525511135";
    auto ips = restoreIpAddresses(ipStr);
    cout << "Valid IP addresses from " << ipStr << ":\n";
    for (auto &ip : ips) cout << ip << "\n";
    cout << "\n";

    // Arithmetic expression evaluation example
    string expr = "2+3*4-5";
    cout << "Evaluation of expression " << expr << " = " << evaluateExpression(expr) << "\n";

    return 0;
}
