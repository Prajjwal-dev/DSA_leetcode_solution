#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        
        // Traverse through the array
        for (int num : nums) {
            if (num <= first) {
                first = num;  // Update the smallest element
            } else if (num <= second) {
                second = num;  // Update the second smallest element
            } else {
                // If current number is greater than both 'first' and 'second'
                return true;  // Triplet found
            }
        }
        return false;  // No triplet found
    }
};

int main() {
    Solution solution;
    
    // Test case 1:
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Test Case 1: " << (solution.increasingTriplet(nums1) ? "true" : "false") << endl;  // Expected: true
    
    // Test case 2:
    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << "Test Case 2: " << (solution.increasingTriplet(nums2) ? "true" : "false") << endl;  // Expected: false
    
    // Test case 3:
    vector<int> nums3 = {2, 1, 5, 0, 4, 6};
    cout << "Test Case 3: " << (solution.increasingTriplet(nums3) ? "true" : "false") << endl;  // Expected: true
    
    // Additional test case 4:
    vector<int> nums4 = {1, 2, 1, 3};
    cout << "Test Case 4: " << (solution.increasingTriplet(nums4) ? "true" : "false") << endl;  // Expected: true

    return 0;
}

