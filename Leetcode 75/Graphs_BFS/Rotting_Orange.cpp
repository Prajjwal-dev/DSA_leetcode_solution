#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshCount = 0; // Count of fresh oranges
        queue<pair<int, int>> rottenQueue; // Queue for BFS to track rotten oranges

        // Step 1: Initialize the grid by counting fresh oranges and enqueueing rotten oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    ++freshCount;
                } else if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                }
            }
        }

        // If there are no fresh oranges, return 0
        if (freshCount == 0) {
            return 0;
        }

        // Step 2: BFS to rot adjacent fresh oranges
        int minutes = 0;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

        while (!rottenQueue.empty()) {
            int size = rottenQueue.size();
            bool rottedThisMinute = false;

            for (int i = 0; i < size; ++i) {
                auto current = rottenQueue.front();
                rottenQueue.pop();
                int x = current.first;
                int y = current.second;

                // Check all 4 directions
                for (int d = 0; d < 4; ++d) {
                    int newX = x + directions[d][0];
                    int newY = y + directions[d][1];

                    // If the new cell is within bounds and has a fresh orange
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; // Rot the fresh orange
                        --freshCount;
                        rottenQueue.push({newX, newY});
                        rottedThisMinute = true;
                    }
                }
            }

            // Increment the time if any fresh oranges were rotted in this round
            if (rottedThisMinute) {
                ++minutes;
            }
        }

        // If there are still fresh oranges left, return -1
        return (freshCount == 0) ? minutes : -1;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "Example 1 Output: " << solution.orangesRotting(grid1) << endl; // Expected Output: 4

    // Example 2
    vector<vector<int>> grid2 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    cout << "Example 2 Output: " << solution.orangesRotting(grid2) << endl; // Expected Output: -1

    // Example 3
    vector<vector<int>> grid3 = {{0, 2}};
    cout << "Example 3 Output: " << solution.orangesRotting(grid3) << endl; // Expected Output: 0

    return 0;
}

/*
Dry Run Explanation:
Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Initial state:
Fresh count = 5, Rotten queue = [(0,0)]

Minute 1:
Rot (0,0) spreads to (0,1) and (1,0): grid = [[2,2,1],[2,1,0],[0,1,1]]
Fresh count = 3, Rotten queue = [(0,1), (1,0)]

Minute 2:
Rot (0,1) spreads to (0,2) and (1,1): grid = [[2,2,2],[2,2,0],[0,1,1]]
Rot (1,0) spreads to (2,1): grid = [[2,2,2],[2,2,0],[0,2,1]]
Fresh count = 1, Rotten queue = [(0,2), (1,1), (2,1)]

Minute 3:
Rot (0,2) spreads no further.
Rot (1,1) spreads to (2,2): grid = [[2,2,2],[2,2,0],[0,2,2]]
Fresh count = 0, Rotten queue = [(2,2)]

Minute 4:
All fresh oranges are rotten. Return 4.
*/

