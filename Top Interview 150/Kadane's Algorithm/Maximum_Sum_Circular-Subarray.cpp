#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for accumulate
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_kadane = kadane(nums);   // Step 1: Get the maximum subarray sum (non-circular)

        int total_sum = accumulate(nums.begin(), nums.end(), 0); // Step 2: Get total sum of the array

        // Step 3: Get the minimum subarray sum (for the circular case)
        for (int& num : nums) num = -num; // Temporarily invert the array elements
        int min_kadane = kadane(nums);    // Run Kadane's on inverted array to find minimum subarray sum
        for (int& num : nums) num = -num; // Restore original array elements

        int max_circular = total_sum + min_kadane; // Step 4: Calculate max circular sum as total_sum - (-min_kadane)

        // Step 5: Special case - if max_circular is 0, return max_kadane
        if (max_circular == 0) return max_kadane;

        return max(max_kadane, max_circular); // Step 6: Return the max of both cases
    }

private:
    int kadane(const vector<int>& nums) {
        int max_sum = nums[0], current_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {1, -2, 3, -2};
    cout << "Example 1 Output: " << solution.maxSubarraySumCircular(nums1) << endl;

    // Example 2
    vector<int> nums2 = {5, -3, 5};
    cout << "Example 2 Output: " << solution.maxSubarraySumCircular(nums2) << endl;

    // Example 3
    vector<int> nums3 = {-3, -2, -3};
    cout << "Example 3 Output: " << solution.maxSubarraySumCircular(nums3) << endl;

    return 0;
}

