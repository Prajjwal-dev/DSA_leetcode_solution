#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Initialize the sum of the first window of size 'k'
        double maxSum = 0;
        for(int i = 0; i < k; i++) {
            maxSum += nums[i];
        }

        // Set current sum to the initial max sum
        double currentSum = maxSum;
        
        // Slide the window from the second element to the end
        for(int i = k; i < nums.size(); i++) {
            // Update current sum by removing the first element of the previous window
            // and adding the next element in the array
            currentSum += nums[i] - nums[i - k];
            
            // Update maxSum if the current window sum is greater
            maxSum = max(maxSum, currentSum);
        }
        
        // Return the maximum average value
        return maxSum / k;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << "Test case 1: " << solution.findMaxAverage(nums1, k1) << endl;

    // Test case 2
    vector<int> nums2 = {5};
    int k2 = 1;
    cout << "Test case 2: " << solution.findMaxAverage(nums2, k2) << endl;

    // Test case 3 (Additional check)
    vector<int> nums3 = {-1, -2, -3, -4, -5};
    int k3 = 2;
    cout << "Test case 3: " << solution.findMaxAverage(nums3, k3) << endl;

    return 0;
}

