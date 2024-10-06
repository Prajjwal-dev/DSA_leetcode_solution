#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Step 1: Handle base cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        // Step 2: Initialize variables for the previous two steps
        int prev1 = 2; // ways to climb to step n-1
        int prev2 = 1; // ways to climb to step n-2
        int current = 0; // this will hold the number of ways to reach current step
        
        // Step 3: Loop to calculate the number of ways for each step
        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2; // Calculate the number of ways for current step
            prev2 = prev1;  // Shift prev2 to prev1
            prev1 = current; // Shift prev1 to the current result
        }
        
        // Step 4: Return the final result
        return current;
    }
};

int main() {
    Solution sol;

    // Example 1:
    int n1 = 2;
    cout << "Ways to climb " << n1 << " stairs: " << sol.climbStairs(n1) << endl;

    // Example 2:
    int n2 = 3;
    cout << "Ways to climb " << n2 << " stairs: " << sol.climbStairs(n2) << endl;

    // Test with more stairs
    int n3 = 5;
    cout << "Ways to climb " << n3 << " stairs: " << sol.climbStairs(n3) << endl;

    return 0;
}

