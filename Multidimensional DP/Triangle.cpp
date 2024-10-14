#include <iostream>
#include <vector>
#include <algorithm>  // for std::min

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Check if the triangle is empty
        if (triangle.empty()) return 0;

        // Start from the second-last row and work upwards
        for (int row = triangle.size() - 2; row >= 0; --row) {
            // Iterate through each element in the row
            for (int col = 0; col < triangle[row].size(); ++col) {
                // Update the current element with the minimum path sum
                triangle[row][col] += std::min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }

        // The top element now contains the minimum path sum
        return triangle[0][0];
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example 1: triangle with multiple rows
    vector<vector<int>> triangle1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Minimum path sum (Example 1): " << solution.minimumTotal(triangle1) << endl;

    // Example 2: triangle with a single element
    vector<vector<int>> triangle2 = {{-10}};
    cout << "Minimum path sum (Example 2): " << solution.minimumTotal(triangle2) << endl;

    // Example 3: larger triangle
    vector<vector<int>> triangle3 = {
        {1}, 
        {2, 3}, 
        {3, 6, 7}, 
        {8, 5, 9, 3}
    };
    cout << "Minimum path sum (Example 3): " << solution.minimumTotal(triangle3) << endl;

    return 0;
}

