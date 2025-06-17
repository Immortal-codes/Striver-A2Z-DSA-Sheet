#include <iostream>
using namespace std;

// 1. Print numbers from 1 to N
void printNumbers(int n) {
    if (n == 0) return;
    printNumbers(n - 1);
    cout << n << " ";
}

// 2. Factorial of a number (recursive)
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// 3. Fibonacci sequence (nth term, recursive)
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 4. Sum of digits of a number (recursive)
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

// 5. Reverse a string recursively
void reverseString(string &s, int start, int end) {
    if (start >= end) return;
    swap(s[start], s[end]);
    reverseString(s, start + 1, end - 1);
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "Numbers from 1 to " << N << ": ";
    printNumbers(N);
    cout << "\n";

    cout << "Factorial of " << N << " is: " << factorial(N) << "\n";

    cout << "Fibonacci term at position " << N << " is: " << fibonacci(N) << "\n";

    cout << "Sum of digits of " << N << " is: " << sumOfDigits(N) << "\n";

    string str;
    cout << "Enter a string to reverse: ";
    cin >> str;
    reverseString(str, 0, str.size() - 1);
    cout << "Reversed string: " << str << "\n";

    return 0;
}
