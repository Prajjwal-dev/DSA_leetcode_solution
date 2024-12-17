#include <iostream>
using namespace std;

class Solution {
public:
    // Function to calculate the n-th Tribonacci number
    int tribonacci(int n) {
        // Handle the base cases directly
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        // Variables to store the three most recent Tribonacci numbers
        int a = 0, b = 1, c = 1, d;

        // Calculate the n-th Tribonacci number iteratively
        for (int i = 3; i <= n; ++i) {
            d = a + b + c;  // Calculate the next number in the sequence
            a = b;          // Move forward: a takes the value of b
            b = c;          // Move forward: b takes the value of c
            c = d;          // Move forward: c takes the new calculated value
        }
        return c;  // Return the calculated n-th Tribonacci number
    }
};

int main() {
    Solution solution;  // Create an object of the Solution class

    // Test cases
    int testCases[] = {4, 25, 0, 1, 2, 10, 20, 37};
    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    // Loop through each test case and print the result
    for (int i = 0; i < numTestCases; ++i) {
        int n = testCases[i];
        cout << "T_" << n << " = " << solution.tribonacci(n) << endl;
    }

    return 0;
}

