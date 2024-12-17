#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];      // Step 1: Initialize max_sum to the first element
        int current_sum = nums[0];  // Step 2: Start current_sum at the first element

        // Step 3: Loop through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            current_sum = max(nums[i], current_sum + nums[i]); // Update current_sum
            max_sum = max(max_sum, current_sum);               // Update max_sum if current_sum is higher
        }

        return max_sum;  // Step 4: Return the largest sum found
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Example 1 Output: " << solution.maxSubArray(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1};
    cout << "Example 2 Output: " << solution.maxSubArray(nums2) << endl;

    // Example 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Example 3 Output: " << solution.maxSubArray(nums3) << endl;

    return 0;
}

