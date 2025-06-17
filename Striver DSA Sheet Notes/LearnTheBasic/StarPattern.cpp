#include <iostream>
using namespace std;

// 1. Solid Rectangle
void solidRectangle(int rows, int cols) {
    /*
    *****
    *****
    *****
    *****
    */
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cout << "*\n"[j == cols - 1];
}

// 2. Hollow Rectangle
void hollowRectangle(int rows, int cols) {
    /*
    *****
    *   *
    *   *
    *****
    */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) cout << "*";
            else cout << " ";
        cout << endl;
    }
}

// 3. Half Pyramid
void halfPyramid(int n) {
    /*
    *
    **
    ***
    ****
    *****
    */
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << "*";
        cout << endl;
    }
}

// 4. Inverted Half Pyramid
void invertedHalfPyramid(int n) {
    /*
    *****
    ****
    ***
    **
    *
    */
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) cout << "*";
        cout << endl;
    }
}

// 5. Right-Aligned Half Pyramid
void rightAlignedHalfPyramid(int n) {
    /*
        *
       **
      ***
     ****
    *****
    */
    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ') << string(i, '*') << endl;
    }
}

// 6. Inverted Right-Aligned Half Pyramid
void invertedRightAlignedHalfPyramid(int n) {
    /*
    *****
     ****
      ***
       **
        *
    */
    for (int i = n; i >= 1; i--) {
        cout << string(n - i, ' ') << string(i, '*') << endl;
    }
}

// 7. Full Pyramid
void fullPyramid(int n) {
    /*
        *
       ***
      *****
     *******
    *********
    */
    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ') << string(2 * i - 1, '*') << endl;
    }
}

// 8. Inverted Full Pyramid
void invertedFullPyramid(int n) {
    /*
    *********
     *******
      *****
       ***
        *
    */
    for (int i = n; i >= 1; i--) {
        cout << string(n - i, ' ') << string(2 * i - 1, '*') << endl;
    }
}

// 9. Diamond Pattern
void diamond(int n) {
    /*
        *
       ***
      *****
     *******
    *********
     *******
      *****
       ***
        *
    */
    for (int i = 1; i <= n; i++)
        cout << string(n - i, ' ') << string(2 * i - 1, '*') << endl;
    for (int i = n - 1; i >= 1; i--)
        cout << string(n - i, ' ') << string(2 * i - 1, '*') << endl;
}

// 10. Hollow Diamond
void hollowDiamond(int n) {
    /*
        *
       * *
      *   *
     *     *
    *       *
     *     *
      *   *
       * *
        *
    */
    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ') << "*";
        if (i > 1) cout << string(2 * i - 3, ' ') << "*";
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--) {
        cout << string(n - i, ' ') << "*";
        if (i > 1) cout << string(2 * i - 3, ' ') << "*";
        cout << endl;
    }
}

// 11. Pascal-like Pyramid
void pascalLikePyramid(int n) {
    /*
        * 
       * * 
      * * * 
     * * * * 
    * * * * * 
    */
    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ');
        for (int j = 1; j <= i; j++) cout << "* ";
        cout << endl;
    }
}

// 12. Hourglass
void hourglass(int n) {
    /*
    *********
     *******
      *****
       ***
        *
       ***
      *****
     *******
    *********
    */
    for (int i = n; i >= 1; i--)
        cout << string(n - i, ' ') << string(2 * i - 1, '*') << endl;
    for (int i = 2; i <= n; i++)
        cout << string(n - i, ' ') << string(2 * i - 1, '*') << endl;
}

// 13. Zig-Zag Pattern
void zigZagPattern(int n) {
    /*
      *   *   *   *  
     * * * * * * * * 
    *   *   *   *   *
    */
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 4 == 0 || (i == 2 && j % 4 == 0)) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5;
    solidRectangle(n, n);
    cout << endl;
    hollowRectangle(n, n);
    cout << endl;
    halfPyramid(n);
    cout << endl;
    invertedHalfPyramid(n);
    cout << endl;
    rightAlignedHalfPyramid(n);
    cout << endl;
    invertedRightAlignedHalfPyramid(n);
    cout << endl;
    fullPyramid(n);
    cout << endl;
    invertedFullPyramid(n);
    cout << endl;
    diamond(n);
    cout << endl;
    hollowDiamond(n);
    cout << endl;
    pascalLikePyramid(n);
    cout << endl;
    hourglass(n);
    cout << endl;
    zigZagPattern(15);
    return 0;
}
