#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;                   // Initialize left pointer
        int right = height.size() - 1;   // Initialize right pointer
        int max_area = 0;                // Initialize max_area to store the maximum area found

        // While left pointer is to the left of the right pointer
        while (left < right) {
            // Calculate the current area formed between the two lines at left and right pointers
            int width = right - left;
            int current_height = min(height[left], height[right]);
            int current_area = width * current_height;

            // Update max_area if the current area is greater
            max_area = max(max_area, current_area);

            // Move the pointer pointing to the shorter line towards the other pointer
            if (height[left] < height[right]) {
                left++;  // Move left pointer to the right if left line is shorter
            } else {
                right--; // Move right pointer to the left if right line is shorter
            }
        }
        return max_area;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};  // Sample input
    int result = sol.maxArea(height);  // Calculate max area
    cout << "Maximum water area: " << result << endl;  // Output the result
    return 0;
}

