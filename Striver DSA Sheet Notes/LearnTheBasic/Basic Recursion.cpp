#include <iostream>
#include <string>
using namespace std;

// 1. Print name N times using recursion
void printName(int i, int n) {
    if (i > n) return;
    cout << "Alice" << endl;
    printName(i + 1, n);
}

// 2. Print 1 to N using recursion
void print1ToN(int i, int n) {
    if (i > n) return;
    cout << i << " ";
    print1ToN(i + 1, n);
}

// 3. Print N to 1 using recursion
void printNTo1(int n) {
    if (n < 1) return;
    cout << n << " ";
    printNTo1(n - 1);
}

// 4. Sum of first N numbers
int sumN(int n) {
    if (n == 0) return 0;
    return n + sumN(n - 1);
}

// 5. Factorial of N
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// 6. Reverse an array using recursion
void reverseArray(int arr[], int l, int r) {
    if (l >= r) return;
    swap(arr[l], arr[r]);
    reverseArray(arr, l + 1, r - 1);
}

// 7. Check if a string is palindrome
bool isPalindrome(string &s, int l, int r) {
    if (l >= r) return true;
    if (s[l] != s[r]) return false;
    return isPalindrome(s, l + 1, r - 1);
}

// 8. Fibonacci number
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 5;
    cout << "1. Print name N times:\n";
    printName(1, n);

    cout << "\n2. Print 1 to N:\n";
    print1ToN(1, n);

    cout << "\n\n3. Print N to 1:\n";
    printNTo1(n);

    cout << "\n\n4. Sum of first N numbers: " << sumN(n) << endl;

    cout << "5. Factorial of " << n << ": " << factorial(n) << endl;

    cout << "\n6. Reverse an array:\n";
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "\n7. Check Palindrome:\n";
    string s = "madam";
    cout << s << (isPalindrome(s, 0, s.size() - 1) ? " is" : " is not") << " a palindrome.\n";

    cout << "\n8. Fibonacci of " << n << ": " << fibonacci(n) << endl;

    return 0;
}
