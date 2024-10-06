#include <iostream>
#include <cmath> // For the pow function
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);  // Using the standard library pow function
    }
};

int main() {
    Solution solution;

    // Test case 1: x = 2.00000, n = 10
    double x1 = 2.0;
    int n1 = 10;
    cout << "pow(" << x1 << ", " << n1 << ") = " << solution.myPow(x1, n1) << endl;

    // Test case 2: x = 2.10000, n = 3
    double x2 = 2.1;
    int n2 = 3;
    cout << "pow(" << x2 << ", " << n2 << ") = " << solution.myPow(x2, n2) << endl;

    // Test case 3: x = 2.00000, n = -2
    double x3 = 2.0;
    int n3 = -2;
    cout << "pow(" << x3 << ", " << n3 << ") = " << solution.myPow(x3, n3) << endl;

    return 0;
}

