#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the leftmost index of the target
    int findLeft(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int index = -1; // default value if target is not found
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                index = mid; // mark the potential answer
                right = mid - 1; // continue searching to the left
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return index;
    }

    // Function to find the rightmost index of the target
    int findRight(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int index = -1; // default value if target is not found
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                index = mid; // mark the potential answer
                left = mid + 1; // continue searching to the right
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return index;
    }

    // Function to return the starting and ending index of the target
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1); // default result [-1, -1]
        
        // Find the leftmost index of the target
        result[0] = findLeft(nums, target);
        
        // If the leftmost index is found, find the rightmost index
        if (result[0] != -1) {
            result[1] = findRight(nums, target);
        }

        return result;
    }
};

// Main function for testing the code
int main() {
    Solution sol;

    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = sol.searchRange(nums1, target1);
    cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = sol.searchRange(nums2, target2);
    cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl;

    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = sol.searchRange(nums3, target3);
    cout << "Output: [" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}

