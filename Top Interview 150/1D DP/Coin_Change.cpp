#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX); // Step 1: Create dp array and initialize
        dp[0] = 0; // Step 2: Base case, 0 coins needed to make amount 0

        for (int i = 1; i <= amount; ++i) { // Step 3: Iterating through all amounts
            for (int coin : coins) { // Step 4: For each coin denomination
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) { // Step 5: Check if we can use this coin
                    dp[i] = min(dp[i], dp[i - coin] + 1); // Step 6: Update dp for amount `i`
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount]; // Step 7: Return the result
    }
};

int main() {
    // Test case 1
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    
    Solution sol;
    int result1 = sol.coinChange(coins1, amount1);
    cout << "The fewest number of coins to make " << amount1 << " is: " << result1 << endl;

    // Test case 2
    vector<int> coins2 = {2};
    int amount2 = 3;
    
    int result2 = sol.coinChange(coins2, amount2);
    cout << "The fewest number of coins to make " << amount2 << " is: " << result2 << endl;

    // Test case 3
    vector<int> coins3 = {1};
    int amount3 = 0;
    
    int result3 = sol.coinChange(coins3, amount3);
    cout << "The fewest number of coins to make " << amount3 << " is: " << result3 << endl;

    return 0;
}

