#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();    // number of rows
        int n = obstacleGrid[0].size(); // number of columns

        // If the starting point or the ending point is an obstacle, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }

        // Create a DP table with the same size as obstacleGrid
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize the starting point (0, 0) as 1 (1 way to start)
        dp[0][0] = 1;

        // Fill the first column (can only come from above)
        for (int i = 1; i < m; ++i) {
            dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;
        }

        // Fill the first row (can only come from the left)
        for (int j = 1; j < n; ++j) {
            dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;
        }

        // Fill the rest of the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // If the cell has an obstacle, set dp[i][j] to 0
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        // The answer is the value at the bottom-right corner of the dp table
        return dp[m-1][n-1];
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> obstacleGrid1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "Unique Paths for Test Case 1: " << solution.uniquePathsWithObstacles(obstacleGrid1) << endl;

    // Test case 2
    vector<vector<int>> obstacleGrid2 = {{0, 1}, {0, 0}};
    cout << "Unique Paths for Test Case 2: " << solution.uniquePathsWithObstacles(obstacleGrid2) << endl;

    return 0;
}

