#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>  // For max
#include <utility>    // For pair
#include <cmath>      // For abs

using namespace std;

// Custom GCD function
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return n;  // Edge case: only one point or no points
        
        int max_points_on_line = 1;  // Minimum is 1 point
        
        // Iterate through each point as an anchor
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slope_count;  // Store slopes as strings
            int duplicate_points = 0;  // Count duplicate points
            int vertical_points = 0;   // Count points on a vertical line
            int max_points_with_anchor = 0;
            
            for (int j = i + 1; j < n; ++j) {
                int delta_x = points[j][0] - points[i][0];
                int delta_y = points[j][1] - points[i][1];
                
                // Handle duplicate points
                if (delta_x == 0 && delta_y == 0) {
                    duplicate_points++;
                    continue;
                }
                
                // Handle vertical lines explicitly
                if (delta_x == 0) {
                    vertical_points++;
                    continue;
                }
                
                // Simplify the slope using GCD
                int gcd_val = gcd(delta_x, delta_y);
                delta_x /= gcd_val;
                delta_y /= gcd_val;
                
                // Ensure consistent representation of slopes
                if (delta_x < 0) {
                    delta_x = -delta_x;
                    delta_y = -delta_y;
                }
                
                // Store the slope as a string
                string slope_key = to_string(delta_x) + "/" + to_string(delta_y);
                
                // Increment count of points on this slope
                slope_count[slope_key]++;
                
                // Track maximum points for this anchor
                max_points_with_anchor = max(max_points_with_anchor, slope_count[slope_key]);
            }
            
            // Consider vertical points and duplicates for the maximum
            max_points_with_anchor = max(max_points_with_anchor, vertical_points);
            max_points_on_line = max(max_points_on_line, max_points_with_anchor + duplicate_points + 1);
        }
        
        return max_points_on_line;
    }
};

int main() {
    Solution solution;
    
    // Test case: Vertical line
    vector<vector<int>> points1 = {{0, 1}, {0, 0}, {0, 4}, {0, -2}, {0, -1}, {0, 3}, {0, -4}};
    cout << "Max points on a line (Vertical Line Test): " << solution.maxPoints(points1) << endl;  // Output: 7
    
    // Other test cases
    vector<vector<int>> points2 = {{1, 1}, {2, 2}, {3, 3}};
    cout << "Max points on a line (Diagonal Test): " << solution.maxPoints(points2) << endl;  // Output: 3
    
    vector<vector<int>> points3 = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << "Max points on a line (Mixed Test): " << solution.maxPoints(points3) << endl;  // Output: 4
    
    return 0;
}

