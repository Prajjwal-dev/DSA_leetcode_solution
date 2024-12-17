#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1); // Create a vector of size n+1 to store results.
        ans[0] = 0; // Base case: Number of 1's in 0 is 0.

        // Loop from 1 to n to fill the array.
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                ans[i] = ans[i / 2];  // For even numbers: same as ans[i/2].
            } else {
                ans[i] = ans[i / 2] + 1;  // For odd numbers: ans[i/2] + 1.
            }
        }
        return ans;
    }
};

// Function to print the result array
void printResult(const vector<int>& ans) {
    for (int count : ans) {
        cout << count << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test cases:
    int n1 = 2;
    vector<int> result1 = solution.countBits(n1);
    cout << "Test Case 1 (n = 2): ";
    printResult(result1);  // Expected output: 0 1 1
    
    int n2 = 5;
    vector<int> result2 = solution.countBits(n2);
    cout << "Test Case 2 (n = 5): ";
    printResult(result2);  // Expected output: 0 1 1 2 1 2
    
    int n3 = 10;
    vector<int> result3 = solution.countBits(n3);
    cout << "Test Case 3 (n = 10): ";
    printResult(result3);  // Expected output: 0 1 1 2 1 2 2 3 1 2 2
    
    return 0;
}

