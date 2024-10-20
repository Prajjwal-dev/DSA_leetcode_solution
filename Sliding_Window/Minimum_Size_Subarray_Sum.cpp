#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0; // Left boundary of the window
        int current_sum = 0; // Sum of the current window
        int min_length = INT_MAX; // Initialize the minimum length to a very large number

        for (int end = 0; end < n; end++) {
            // Add nums[end] to the current window sum
            current_sum += nums[end];

            // While the sum is greater than or equal to the target, try shrinking the window
            while (current_sum >= target) {
                // Update the minimum length of the subarray
                min_length = min(min_length, end - start + 1);

                // Shrink the window by moving the start pointer and subtracting nums[start] from current_sum
                current_sum -= nums[start];
                start++; // Move the left boundary of the window
            }
        }

        // If we never found a valid subarray, return 0
        return (min_length == INT_MAX) ? 0 : min_length;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    int target1 = 7;
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    cout << "Test case 1 - Minimal length of subarray: " << solution.minSubArrayLen(target1, nums1) << endl; 
    // Expected output: 2 (subarray [4, 3])
    
    // Test case 2
    int target2 = 4;
    vector<int> nums2 = {1, 4, 4};
    cout << "Test case 2 - Minimal length of subarray: " << solution.minSubArrayLen(target2, nums2) << endl; 
    // Expected output: 1 (subarray [4])
    
    // Test case 3
    int target3 = 11;
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Test case 3 - Minimal length of subarray: " << solution.minSubArrayLen(target3, nums3) << endl; 
    // Expected output: 0 (no subarray has sum >= 11)

    // Test case 4 (Additional test case)
    int target4 = 15;
    vector<int> nums4 = {1, 2, 3, 4, 5};
    cout << "Test case 4 - Minimal length of subarray: " << solution.minSubArrayLen(target4, nums4) << endl; 
    // Expected output: 5 (subarray [1, 2, 3, 4, 5] has sum exactly 15)

    return 0;
}

