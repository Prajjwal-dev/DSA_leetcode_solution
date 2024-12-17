#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;  // Left boundary of the sliding window
        int right = 0; // Right boundary of the sliding window
        int max_length = 0; // Maximum length of the subarray with at most k flips
        int zero_count = 0; // Count of zeros in the current window

        // Expand the window by moving the right pointer
        while (right < nums.size()) {
            if (nums[right] == 0) {
                zero_count++;
            }

            // If the count of zeros exceeds k, shrink the window from the left
            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }

            // Calculate the length of the current valid window
            max_length = max(max_length, right - left + 1);
            right++;
        }

        return max_length;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    cout << "Test Case 1:\n";
    cout << "Input: nums = {1,1,1,0,0,0,1,1,1,1,0}, k = " << k1 << "\n";
    cout << "Output: " << solution.longestOnes(nums1, k1) << "\n\n";

    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    cout << "Test Case 2:\n";
    cout << "Input: nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, k = " << k2 << "\n";
    cout << "Output: " << solution.longestOnes(nums2, k2) << "\n\n";

    // Test case 3 (All 1's, no flips needed)
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int k3 = 2;
    cout << "Test Case 3:\n";
    cout << "Input: nums = {1,1,1,1,1}, k = " << k3 << "\n";
    cout << "Output: " << solution.longestOnes(nums3, k3) << "\n\n";

    // Test case 4 (All 0's, all flips allowed)
    vector<int> nums4 = {0, 0, 0, 0, 0};
    int k4 = 5;
    cout << "Test Case 4:\n";
    cout << "Input: nums = {0,0,0,0,0}, k = " << k4 << "\n";
    cout << "Output: " << solution.longestOnes(nums4, k4) << "\n";

    return 0;
}

