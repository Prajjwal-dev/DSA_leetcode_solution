#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_price = INT_MAX;  // Initialize to a very large value
        int max_profit = 0;       // Tracks the maximum profit
        
        // Iterate through the prices
        for(int i = 0; i < prices.size(); i++) {
            // Update min_price to the lowest value found so far
            if(prices[i] < min_price) {
                min_price = prices[i];
            }
            
            // Calculate potential profit
            int p_profit = prices[i] - min_price;
            
            // Update max_profit if the current potential profit is greater
            if(p_profit > max_profit) {
                max_profit = p_profit;
            }
        }
        
        return max_profit;
    }
};

int main() {
    Solution sol;
    
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::cout << "Max Profit (Test Case 1): " << sol.maxProfit(prices1) << std::endl; // Expected output: 5

    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    std::cout << "Max Profit (Test Case 2): " << sol.maxProfit(prices2) << std::endl; // Expected output: 0
    
    return 0;
}

