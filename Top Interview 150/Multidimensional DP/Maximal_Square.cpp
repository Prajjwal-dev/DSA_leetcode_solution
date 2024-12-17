#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0)); // DP table to store side lengths
        int max_side = 0; // To track the maximum side length

        // Fill DP table
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1; // First row or first column
                    } else {
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    max_side = max(max_side, dp[i][j]); // Update max side
                }
            }
        }

        return max_side * max_side; // Return area (side^2)
    }
};

// Driver code
int main() {
    Solution sol;
    vector<vector<char>> matrix1 = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    vector<vector<char>> matrix2 = {
        {'0', '1'},
        {'1', '0'}
    };

    vector<vector<char>> matrix3 = {
        {'0'}
    };

    cout << "Area of largest square in matrix1: " << sol.maximalSquare(matrix1) << endl;
    cout << "Area of largest square in matrix2: " << sol.maximalSquare(matrix2) << endl;
    cout << "Area of largest square in matrix3: " << sol.maximalSquare(matrix3) << endl;

    return 0;
}

