#include <iostream>
using namespace std;

int mySqrt(int x) {
    // Edge case: square root of 0 or 1 is the number itself
    if (x == 0 || x == 1) return x;

    // Initialize left and right pointers for binary search
    int left = 0, right = x, result = 0;

    // Binary search loop
    while (left <= right) {
        // Calculate mid
        int mid = left + (right - left) / 2;

        // If mid*mid equals x, return mid as the square root
        if (mid <= x / mid) {
            result = mid; // Store the potential result
            left = mid + 1; // Narrow search to higher values
        }
        else {
            right = mid - 1; // Narrow search to lower values
        }
    }

    // Return the floor value of the square root
    return result;
}

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Square root of " << x << " is " << mySqrt(x) << endl;
    return 0;
}

