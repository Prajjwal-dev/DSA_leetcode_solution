#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdexcept> // Include this for std::invalid_argument

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array to optimize the binary search
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();

        int low = 0, high = x;
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            // Handle edge cases with INT_MIN and INT_MAX
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxX <= minY && maxY <= minX) {
                // Found the correct partitions
                if ((x + y) % 2 == 0) {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                } else {
                    return max(maxX, maxY);
                }
            } else if (maxX > minY) {
                // Adjust the partition by moving left in nums1
                high = partitionX - 1;
            } else {
                // Adjust the partition by moving right in nums1
                low = partitionX + 1;
            }
        }

        throw invalid_argument("Input arrays are not sorted or invalid");
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test Case 1 Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Test Case 2 Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {0, 0};
    nums2 = {0, 0};
    cout << "Test Case 3 Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {};
    nums2 = {1};
    cout << "Test Case 4 Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {2};
    nums2 = {};
    cout << "Test Case 5 Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}

