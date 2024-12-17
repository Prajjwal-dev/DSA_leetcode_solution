#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;  // Initialize the variable to store the total sum of array elements
        for (int num : nums) {
            totalSum += num;  // Calculate the total sum of all elements in the array
        }
        
        int leftSum = 0;  // Initialize the left sum
        for (int i = 0; i < nums.size(); i++) {
            // Calculate right sum: total sum - left sum - current element
            int rightSum = totalSum - leftSum - nums[i]; 
            if (leftSum == rightSum) { // Check if the left and right sums are equal
                return i;  // Return the pivot index
            }
            leftSum += nums[i];  // Update the left sum by adding the current element
        }
        return -1;  // Return -1 if no pivot index is found
    }
};

int main() {
    Solution solution;  // Create an object of the Solution class

    // Test case 1
    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    cout << "Pivot Index (Test 1): " << solution.pivotIndex(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3};
    cout << "Pivot Index (Test 2): " << solution.pivotIndex(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {2, 1, -1};
    cout << "Pivot Index (Test 3): " << solution.pivotIndex(nums3) << endl;

    // Additional Test case 4: Edge case with one element
    vector<int> nums4 = {5};
    cout << "Pivot Index (Test 4): " << solution.pivotIndex(nums4) << endl;

    // Additional Test case 5: Edge case with all zeros
    vector<int> nums5 = {0, 0, 0, 0};
    cout << "Pivot Index (Test 5): " << solution.pivotIndex(nums5) << endl;

    return 0;
}

