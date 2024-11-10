#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        // Binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;  // Midpoint of the array
            
            if (nums[mid] == target) {
                return mid;  // Target found, return the index
            }
            else if (nums[mid] < target) {
                left = mid + 1;  // Move the left boundary right, target must be in right half
            }
            else {
                right = mid - 1;  // Move the right boundary left, target must be in left half
            }
        }
        
        // If target is not found, 'left' is the insertion position
        return left;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Test Case 1: Index = " << sol.searchInsert(nums1, target1) << endl;
    
    // Test case 2
    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Test Case 2: Index = " << sol.searchInsert(nums2, target2) << endl;
    
    // Test case 3
    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Test Case 3: Index = " << sol.searchInsert(nums3, target3) << endl;
    
    // Test case 4
    vector<int> nums4 = {1, 3, 5, 6};
    int target4 = 0;
    cout << "Test Case 4: Index = " << sol.searchInsert(nums4, target4) << endl;
    
    return 0;
}

