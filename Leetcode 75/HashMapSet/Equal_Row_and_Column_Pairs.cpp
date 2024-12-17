#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); // Size of the grid
        map<vector<int>, int> rowMap; // Map to count occurrences of each row
        int count = 0; // To store the number of equal row-column pairs

        // Store each row in the map with its frequency
        for (int i = 0; i < n; i++) {
            rowMap[grid[i]]++;
        }

        // Check each column against the rows stored in the map
        for (int j = 0; j < n; j++) {
            vector<int> col; // Store the current column
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }

            // Check if this column matches any row in the map
            if (rowMap.find(col) != rowMap.end()) {
                count += rowMap[col]; // Add the frequency of matching rows
            }
        }

        return count; // Return the total count
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid1 = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    vector<vector<int>> grid2 = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    
    cout << "Test Case 1 Output: " << solution.equalPairs(grid1) << endl; // Expected: 1
    cout << "Test Case 2 Output: " << solution.equalPairs(grid2) << endl; // Expected: 3

    return 0;
}

