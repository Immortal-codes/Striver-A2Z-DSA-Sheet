#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ----------------------------------------------------
// ✅ 1. Print Prime Factors of a Number (Naive Method)
void printPrimeFactors(int n) {
    cout << "Prime Factors of " << n << " are: ";
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) cout << n << " ";
    cout << "\n";
}
// ----------------------------------------------------

// ----------------------------------------------------
// ✅ 2. All Divisors of a Number
void printAllDivisors(int n) {
    cout << "Divisors of " << n << " are: ";
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i) cout << n / i << " ";
        }
    }
    cout << "\n";
}
// ----------------------------------------------------

// ----------------------------------------------------
// ✅ 3. Sieve of Eratosthenes (Generate all primes <= N)
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    cout << "Primes up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << "\n";

    return isPrime;
}
// ----------------------------------------------------

// ----------------------------------------------------
// ✅ 4. Prime Factorization using Sieve (O(log N) per query)
const int N = 1e5 + 10;
vector<int> spf(N); // smallest prime factor

void buildSPF() {
    for (int i = 1; i < N; i++) spf[i] = i;

    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<int> getPrimeFactorsUsingSieve(int x) {
    vector<int> factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x = x / spf[x];
    }
    return factors;
}
// ----------------------------------------------------

// ----------------------------------------------------
// ✅ 5. Power Function (Binary Exponentiation)
long long power(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1)
            result *= base;
        base *= base;
        exponent >>= 1;
    }
    return result;
}
// ----------------------------------------------------

int main() {
    // 1. Prime Factors
    int num1 = 84;
    printPrimeFactors(num1);

    // 2. All Divisors
    int num2 = 36;
    printAllDivisors(num2);

    // 3. Sieve of Eratosthenes
    int limit = 50;
    vector<bool> isPrime = sieve(limit);

    // 4. Prime Factorization using Sieve
    buildSPF();
    int num3 = 100;
    vector<int> pf = getPrimeFactorsUsingSieve(num3);
    cout << "Prime Factors of " << num3 << " using sieve: ";
    for (int x : pf) cout << x << " ";
    cout << "\n";

    // 5. Power
    cout << "Power(2, 10) = " << power(2, 10) << "\n";

    return 0;
}
