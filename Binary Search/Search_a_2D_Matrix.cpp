#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();         // Number of rows
        int n = matrix[0].size();      // Number of columns
        int left = 0, right = m * n - 1;  // Left and right pointers for binary search
        
        // Binary search in the flattened array view
        while (left <= right) {
            int mid = left + (right - left) / 2;   // Calculate the mid index
            int mid_value = matrix[mid / n][mid % n];  // Convert 1D index to 2D row and column
            
            if (mid_value == target) {    // If the mid value is the target, return true
                return true;
            } else if (mid_value < target) {  // If mid value is smaller, move to the right half
                left = mid + 1;
            } else {                         // If mid value is larger, move to the left half
                right = mid - 1;
            }
        }
        return false;  // If the loop ends, the target is not found
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<vector<int>> matrix1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target1 = 3;
    cout << "Test 1 - Target: " << target1 << " -> " << (sol.searchMatrix(matrix1, target1) ? "Found" : "Not Found") << endl;

    // Test case 2
    vector<vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target2 = 13;
    cout << "Test 2 - Target: " << target2 << " -> " << (sol.searchMatrix(matrix2, target2) ? "Found" : "Not Found") << endl;
    
    return 0;
}

