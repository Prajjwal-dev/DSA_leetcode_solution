#include <iostream>
#include <vector>
#include <algorithm>  // for std::min

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    // number of rows
        int n = grid[0].size(); // number of columns

        // Create a DP table with the same size as the grid
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the top-left corner of dp with the same value as grid
        dp[0][0] = grid[0][0];

        // Fill the first row (can only come from the left)
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        // Fill the first column (can only come from above)
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        // Fill the rest of the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // The minimum path sum to reach (i, j) is the minimum of coming from
                // either the left (dp[i][j-1]) or from above (dp[i-1][j]) + the current cell
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        // The answer is the value at the bottom-right corner of the dp table
        return dp[m-1][n-1];
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> grid1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "Minimum Path Sum for Test Case 1: " << solution.minPathSum(grid1) << endl;

    // Test case 2
    vector<vector<int>> grid2 = {{1, 2, 3}, {4, 5, 6}};
    cout << "Minimum Path Sum for Test Case 2: " << solution.minPathSum(grid2) << endl;

    return 0;
}

