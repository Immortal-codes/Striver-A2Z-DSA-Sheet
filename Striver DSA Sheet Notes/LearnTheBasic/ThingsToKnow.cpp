#include <bits/stdc++.h>
using namespace std;

// 1. User Input / Output
void userIO() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Sum = " << a + b << endl;
}

// 2. Data Types
void dataTypesDemo() {
    int i = 10;
    float f = 5.5;
    double d = 3.14159;
    char c = 'A';
    bool flag = true;
    cout << "Int: " << i << "\nFloat: " << f << "\nDouble: " << d
         << "\nChar: " << c << "\nBool: " << flag << endl;
}

// 3. If-Else Statement
void ifElseDemo(int x) {
    if (x > 0)
        cout << "Positive" << endl;
    else if (x < 0)
        cout << "Negative" << endl;
    else
        cout << "Zero" << endl;
}

// 4. Switch Statement
void switchDemo(char grade) {
    switch (grade) {
        case 'A': cout << "Excellent\n"; break;
        case 'B': cout << "Good\n"; break;
        case 'C': cout << "Average\n"; break;
        case 'D': cout << "Below Average\n"; break;
        default: cout << "Fail\n";
    }
}

// 5. What are Arrays and Strings
void arraysStringsDemo() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    string s = "Hello, Rajan!";
    cout << "String: " << s << endl;
}

// 6. For Loop
void forLoopDemo() {
    cout << "For Loop: ";
    for (int i = 1; i <= 5; i++) cout << i << " ";
    cout << endl;
}

// 7. While Loop
void whileLoopDemo() {
    int i = 1;
    cout << "While Loop: ";
    while (i <= 5) {
        cout << i << " ";
        i++;
    }
    cout << endl;
}

// 8. Functions - Pass by Value
void passByValue(int x) {
    x = x + 10;
    cout << "Inside Pass by Value: " << x << endl;
}

// 9. Functions - Pass by Reference
void passByReference(int &x) {
    x = x + 10;
    cout << "Inside Pass by Reference: " << x << endl;
}

// 10. Time Complexity (Basic Demo)
void timeComplexityDemo(int n) {
    cout << "Time Complexity O(n): ";
    for (int i = 0; i < n; i++)
        cout << i << " ";
    cout << endl;

    cout << "Time Complexity O(n^2):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << "(" << i << "," << j << ") ";
    cout << endl;
}

// ===========================
// 🔁 Main Function
// ===========================
int main() {
    // 1
    userIO();
    cout << "---------------------------\n";

    // 2
    dataTypesDemo();
    cout << "---------------------------\n";

    // 3
    ifElseDemo(-10);
    cout << "---------------------------\n";

    // 4
    switchDemo('B');
    cout << "---------------------------\n";

    // 5
    arraysStringsDemo();
    cout << "---------------------------\n";

    // 6
    forLoopDemo();

    // 7
    whileLoopDemo();

    // 8 & 9
    int val = 5;
    passByValue(val);
    cout << "After Pass by Value: " << val << endl;

    passByReference(val);
    cout << "After Pass by Reference: " << val << endl;
    cout << "---------------------------\n";

    // 10
    timeComplexityDemo(3);

    return 0;
}
