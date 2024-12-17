#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        
        int top = 0;                          // Define the initial boundary for the top row
        int bottom = matrix.size() - 1;        // Define the initial boundary for the bottom row
        int left = 0;                          // Define the initial boundary for the left column
        int right = matrix[0].size() - 1;      // Define the initial boundary for the right column

        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top boundary
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down
            
            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary to the left
            
            // Traverse from right to left along the bottom boundary, if there's still space
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }
            
            // Traverse from bottom to top along the left boundary, if there's still space
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary to the right
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    vector<int> result = sol.spiralOrder(matrix);
    
    // Output the result
    cout << "Spiral order: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}

