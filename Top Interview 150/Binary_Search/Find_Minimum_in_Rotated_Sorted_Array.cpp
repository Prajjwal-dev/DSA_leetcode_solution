#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // Binary Search to find the minimum element
        while (left < right) {
            int mid = left + (right - left) / 2;

            // If middle element is greater than the rightmost element, 
            // then the minimum element is in the right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // Otherwise, the minimum is in the left half, including mid
            else {
                right = mid;
            }
        }
        // After the loop ends, left == right and points to the smallest value
        return nums[left];
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Minimum element in {3, 4, 5, 1, 2} is: " << solution.findMin(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element in {4, 5, 6, 7, 0, 1, 2} is: " << solution.findMin(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Minimum element in {11, 13, 15, 17} is: " << solution.findMin(nums3) << endl;

    return 0;
}

