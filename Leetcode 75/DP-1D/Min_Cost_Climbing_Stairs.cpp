#include <iostream>
#include <vector>
#include <algorithm>  // For min() function
using namespace std;

class Solution {
public:
    // Function to calculate the minimum cost to climb stairs
    int minCostClimbingStairs(const vector<int>& cost) {  // Use const reference
        int n = cost.size();
        
        // Handle the base cases explicitly
        if (n == 2) return min(cost[0], cost[1]);

        // dp[i] will store the minimum cost to reach step i
        vector<int> dp(n + 1, 0);
        
        // Initialize the first two steps
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Calculate the minimum cost for each step
        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // Return the minimum cost to reach the top of the floor
        return min(dp[n - 1], dp[n - 2]);
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<vector<int>> testCases = {
        {10, 15, 20},
        {1, 100, 1, 1, 1, 100, 1, 1, 100, 1},
        {0, 2, 2, 1},
        {5, 5, 5, 5},
        {1, 2},
        {10, 15}
    };

    // Loop through each test case and print the result
    for (const auto& cost : testCases) {
        cout << "Minimum cost for [";
        for (size_t i = 0; i < cost.size(); ++i) {
            cout << cost[i] << (i < cost.size() - 1 ? ", " : "");
        }
        cout << "] is: " << solution.minCostClimbingStairs(cost) << endl;
    }

    return 0;
}

