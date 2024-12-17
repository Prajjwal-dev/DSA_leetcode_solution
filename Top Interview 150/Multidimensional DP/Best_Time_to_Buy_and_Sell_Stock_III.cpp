#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;  // Handle empty input
        
        int n = prices.size();
        // Arrays to store the maximum profit from the left and right at each point
        vector<int> leftProfit(n, 0);
        vector<int> rightProfit(n, 0);

        // Calculate maximum profit from left (0 to i) - First transaction
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]); // Update the minimum price seen so far
            leftProfit[i] = max(leftProfit[i-1], prices[i] - minPrice); // Max profit by selling on day i
        }

        // Calculate maximum profit from right (i to n-1) - Second transaction
        int maxPrice = prices[n-1];
        for (int i = n - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]); // Update the maximum price seen so far from the right
            rightProfit[i] = max(rightProfit[i+1], maxPrice - prices[i]); // Max profit by buying on day i
        }

        // Combine the maximum profits from both sides
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i]);
        }

        return maxProfit;
    }
};

// Main function to test the code with different cases
int main() {
    Solution sol;

    // Test Case 1
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Max Profit (Test Case 1): " << sol.maxProfit(prices1) << endl;

    // Test Case 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Max Profit (Test Case 2): " << sol.maxProfit(prices2) << endl;

    // Test Case 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Max Profit (Test Case 3): " << sol.maxProfit(prices3) << endl;

    return 0;
}

