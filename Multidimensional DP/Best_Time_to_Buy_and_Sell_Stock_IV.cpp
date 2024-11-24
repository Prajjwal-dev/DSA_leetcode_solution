#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;  // Handle edge cases

        // If k >= n/2, it's equivalent to unlimited transactions
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    maxProfit += prices[i] - prices[i - 1];
            }
            return maxProfit;
        }

        // DP array: dp[i][j] represents max profit with at most i transactions on day j
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        // Calculate maximum profit for each transaction count
        for (int i = 1; i <= k; i++) {
            int maxDiff = -prices[0];  // Track the maximum difference so far
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);  // Max profit by selling on day j
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);   // Update maxDiff for the next buy
            }
        }

        return dp[k][n - 1];  // Maximum profit after k transactions on the last day
    }
};

// Main function to test the code with different cases
int main() {
    Solution sol;

    // Test Case 1
    vector<int> prices1 = {2, 4, 1};
    int k1 = 2;
    cout << "Max Profit (Test Case 1): " << sol.maxProfit(k1, prices1) << endl;

    // Test Case 2
    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    int k2 = 2;
    cout << "Max Profit (Test Case 2): " << sol.maxProfit(k2, prices2) << endl;

    // Test Case 3: Edge case with large k
    vector<int> prices3 = {3, 3, 5, 0, 0, 3, 1, 4};
    int k3 = 3;
    cout << "Max Profit (Test Case 3): " << sol.maxProfit(k3, prices3) << endl;

    return 0;
}

