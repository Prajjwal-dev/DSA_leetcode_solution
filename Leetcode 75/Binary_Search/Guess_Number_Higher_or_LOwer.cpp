#include <iostream>
using namespace std;

// Mock guess API for demonstration purposes
int pick; // This will hold the number to guess
int guess(int num) {
    if (num == pick) return 0;
    if (num > pick) return -1;
    return 1;
}

// Solution class with the guessNumber function
class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Prevent potential overflow
            int res = guess(mid);
            if (res == 0) return mid;          // Correct guess
            else if (res == -1) high = mid - 1; // Guess is too high
            else low = mid + 1;                // Guess is too low
        }
        return -1; // Should never reach here if inputs are valid
    }
};

// Main function to demonstrate test cases
int main() {
    Solution solution;

    // Test Case 1: Guessing number 6 in range 1 to 10
    pick = 6;
    int result1 = solution.guessNumber(10);
    cout << "Test Case 1: Guessed number is " << result1 << endl;

    // Test Case 2: Guessing number 1 in range 1 to 1
    pick = 1;
    int result2 = solution.guessNumber(1);
    cout << "Test Case 2: Guessed number is " << result2 << endl;

    // Test Case 3: Guessing number 1 in range 1 to 2
    pick = 1;
    int result3 = solution.guessNumber(2);
    cout << "Test Case 3: Guessed number is " << result3 << endl;

    // Test Case 4: Guessing number 7 in range 1 to 100
    pick = 7;
    int result4 = solution.guessNumber(100);
    cout << "Test Case 4: Guessed number is " << result4 << endl;

    return 0;
}

