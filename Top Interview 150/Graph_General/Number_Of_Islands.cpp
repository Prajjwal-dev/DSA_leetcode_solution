#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Check if we are out of bounds or the current cell is water (0)
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        
        // Mark the current cell as visited by setting it to '0'
        grid[i][j] = '0';
        
        // Visit all adjacent cells (up, down, left, right)
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        
        // Traverse every cell in the grid
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                // If we encounter a '1', it's a new island
                if (grid[i][j] == '1') {
                    ++islandCount;  // Increment the island count
                    dfs(grid, i, j);  // Use DFS to mark all the land in this island
                }
            }
        }
        
        return islandCount;  // Return the total number of islands
    }
};

int main() {
    Solution sol;
    
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    cout << "Number of islands in grid1: " << sol.numIslands(grid1) << endl;  // Output: 1
    cout << "Number of islands in grid2: " << sol.numIslands(grid2) << endl;  // Output: 3
    
    return 0;
}

