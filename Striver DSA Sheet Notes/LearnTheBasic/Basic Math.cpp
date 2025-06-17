# C++ STL Notes & Basic Number Theory Problems

---

## 🧠 STL Practice Tips

* Learn container + iterator + algorithm combo
* Know when to use `set` vs `unordered_set`
* Use `priority_queue` in Dijkstra/Greedy
* Know `map` & `unordered_map` for hashing

---

## 🔢 Number Theory Practice Problems (with C++ Code)

### ✅ 1. Count Digits

```cpp
int countDigits(int n) {
    int count = 0;
    while(n != 0) {
        count++;
        n /= 10;
    }
    return count;
}
```

### ✅ 2. Reverse a Number

```cpp
int reverseNumber(int n) {
    int rev = 0;
    while(n != 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return rev;
}
```

### ✅ 3. Check Palindrome

```cpp
bool isPalindrome(int n) {
    int original = n;
    int reversed = 0;
    while(n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}
```

### ✅ 4. GCD or HCF (Euclidean Algorithm)

```cpp
int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

### ✅ 5. Armstrong Number

```cpp
bool isArmstrong(int n) {
    int original = n;
    int sum = 0;
    int digits = 0;
    int temp = n;

    while(temp) {
        digits++;
        temp /= 10;
    }

    temp = n;
    while(temp) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return original == sum;
}
```

### ✅ 6. Print All Divisors

```cpp
void printDivisors(int n) {
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            cout << i << " ";
            if(i != n / i)
                cout << n / i << " ";
        }
    }
}
```

### ✅ 7. Check for Prime

```cpp
bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
```

---

> **Note:** These are foundational problems that are often asked in coding interviews. Master them before jumping into advanced number theory.

Happy Coding 🚀
