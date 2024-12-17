#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: if nums is empty, return 0
        if (nums.size() == 0) {
            return 0;
        }
        
        // Initialize the index for the unique element position
        int uniqueIndex = 0;
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the element at uniqueIndex
            if (nums[i] != nums[uniqueIndex]) {
                uniqueIndex++;           // Move uniqueIndex to the next position
                nums[uniqueIndex] = nums[i]; // Place the unique element at uniqueIndex
            }
        }
        
        // Return the count of unique elements
        return uniqueIndex + 1;
    }
};

int main() {
    // Create an instance of the solution class
    Solution solution;

    // Test case 1: nums = [1, 1, 2]
    vector<int> nums1 = {1, 1, 2};
    int k1 = solution.removeDuplicates(nums1);
    
    cout << "Unique elements count for nums1: " << k1 << endl;
    cout << "Updated nums1 array: ";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    
    // Test case 2: nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = solution.removeDuplicates(nums2);
    
    cout << "Unique elements count for nums2: " << k2 << endl;
    cout << "Updated nums2 array: ";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}

