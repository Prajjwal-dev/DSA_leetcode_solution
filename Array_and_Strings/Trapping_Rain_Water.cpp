#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0; // No water can be trapped if there are less than 3 bars.

        vector<int> leftMax(n, 0), rightMax(n, 0);
        int waterTrapped = 0;

        // Compute the left maximum heights for each position
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Compute the right maximum heights for each position
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Calculate the trapped water at each position
        for (int i = 0; i < n; i++) {
            waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
        }

        return waterTrapped;
    }
};

int main() {
    Solution sol;

    // Example input 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped water for height1: " << sol.trap(height1) << endl;

    // Example input 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Trapped water for height2: " << sol.trap(height2) << endl;

    return 0;
}

