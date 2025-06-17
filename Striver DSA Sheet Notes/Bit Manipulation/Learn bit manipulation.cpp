#include <iostream>
#include <cmath>
using namespace std;

// ---------------------------------------------
// ✅ 1. Introduction to Bit Manipulation [Theory]
// (No code – only concepts explained in .md notes)
// ---------------------------------------------

// ---------------------------------------------
// ✅ 2. Check if the i-th bit is set or not
bool isIthBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}
// ---------------------------------------------

// ---------------------------------------------
// ✅ 3. Check if a number is odd or not
bool isOdd(int n) {
    return (n & 1);
}
// ---------------------------------------------

// ---------------------------------------------
// ✅ 4. Check if a number is power of 2 or not
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}
// ---------------------------------------------

// ---------------------------------------------
// ✅ 5. Count the number of set bits
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1); // Clear the rightmost set bit
        count++;
    }
    return count;
}
// ---------------------------------------------

// ---------------------------------------------
// ✅ 6. Set/Unset the rightmost unset bit
int setRightmostUnsetBit(int n) {
    if (~n == 0) return n; // all bits are set
    return n | (n + 1);
}
// ---------------------------------------------

// ---------------------------------------------
// ✅ 7. Swap two numbers using XOR
void swapXOR(int &a, int &b) {
    if (a != b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}
// ---------------------------------------------

// ---------------------------------------------
// ✅ 8. Divide two integers without using *, /, or %
// (Handles positive numbers only)
int divide(int dividend, int divisor) {
    int quotient = 0;
    int temp = 0;

    for (int i = 31; i >= 0; i--) {
        if (temp + (divisor << i) <= dividend) {
            temp += divisor << i;
            quotient |= 1 << i;
        }
    }
    return quotient;
}
// ---------------------------------------------

int main() {
    // Sample driver code to test all functions

    int n = 18, i = 1;
    cout << "Is " << i << "-th bit set in " << n << "? " << isIthBitSet(n, i) << "\n";
    cout << n << " is odd? " << isOdd(n) << "\n";
    cout << n << " is power of 2? " << isPowerOfTwo(n) << "\n";
    cout << "Set bits in " << n << " = " << countSetBits(n) << "\n";
    cout << "Set rightmost unset bit in " << n << " = " << setRightmostUnsetBit(n) << "\n";

    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << "\n";
    swapXOR(a, b);
    cout << "After swap: a = " << a << ", b = " << b << "\n";

    int dividend = 22, divisor = 3;
    cout << "Division of " << dividend << " by " << divisor << " = " << divide(dividend, divisor) << "\n";

    return 0;
}
