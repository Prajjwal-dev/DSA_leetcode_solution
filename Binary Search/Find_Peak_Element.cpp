#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // Perform binary search
        while (left < right) {
            int mid = left + (right - left) / 2;

            // If the mid element is greater than the next element, peak is on the left side
            if (nums[mid] > nums[mid + 1]) {
                right = mid;  // Move the right pointer to mid
            } else {
                // If mid element is less than the next element, peak is on the right side
                left = mid + 1;  // Move the left pointer to mid + 1
            }
        }
        // When left and right converge, we've found the peak
        return left;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Peak index in nums1: " << sol.findPeakElement(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak index in nums2: " << sol.findPeakElement(nums2) << endl;

    return 0;
}

