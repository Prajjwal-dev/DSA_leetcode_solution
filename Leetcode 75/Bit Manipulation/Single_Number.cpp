#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;  // Initialize result to 0
        
        // XOR all the elements in the array
        for(int num : nums) {
            result ^= num;  // XOR the current number with result
        }
        return result;  // Return the single element
    }
};

int main() {
    Solution solution;
    
    // Test case 1:
    vector<int> nums1 = {2, 2, 1};
    cout << "Test Case 1: " << solution.singleNumber(nums1) << endl;  // Expected output: 1
    
    // Test case 2:
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Test Case 2: " << solution.singleNumber(nums2) << endl;  // Expected output: 4
    
    // Test case 3:
    vector<int> nums3 = {1};
    cout << "Test Case 3: " << solution.singleNumber(nums3) << endl;  // Expected output: 1
    
    // Additional test case 4:
    vector<int> nums4 = {-1, -1, 0, 3, 3};
    cout << "Test Case 4: " << solution.singleNumber(nums4) << endl;  // Expected output: 0

    return 0;
}

