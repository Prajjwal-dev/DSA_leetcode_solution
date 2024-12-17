#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0; // If no balloons, no arrows are needed.
        }
        
        // Sort the balloons by their ending position (xend).
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by the xend value.
        });
        
        int arrows = 1; // We need at least one arrow.
        int arrowPos = points[0][1]; // Shoot the first arrow at the end of the first balloon.
        
        // Traverse through all balloons.
        for (int i = 1; i < points.size(); ++i) {
            // If the current balloon starts after the last arrow's position, we need a new arrow.
            if (points[i][0] > arrowPos) {
                ++arrows; // Increment the arrow count.
                arrowPos = points[i][1]; // Update the arrow position to the end of the current balloon.
            }
        }
        
        return arrows; // Return the total number of arrows needed.
    }
};

// Main function to test the solution.
int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << "Minimum number of arrows: " << solution.findMinArrowShots(points1) << endl; // Output: 2

    // Test case 2
    vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << "Minimum number of arrows: " << solution.findMinArrowShots(points2) << endl; // Output: 4

    // Test case 3
    vector<vector<int>> points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << "Minimum number of arrows: " << solution.findMinArrowShots(points3) << endl; // Output: 2

    return 0;
}

