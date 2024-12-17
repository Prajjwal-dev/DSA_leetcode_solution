#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap; // Map to store the frequency of elements
        int operations = 0;  // Count of valid operations
        
        for (int num : nums) {
            int complement = k - num; // Find the complement of the current number
            
            // Check if the complement exists in the map and can form a pair
            if (freqMap[complement] > 0) {
                operations++;      // Increment operation count
                freqMap[complement]--; // Use one instance of the complement
            } else {
                freqMap[num]++; // Add the current number to the map
            }
        }
        
        return operations;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    int k1 = 5;
    cout << "Test case 1 result: " << solution.maxOperations(nums1, k1) << endl; // Expected output: 2
    
    // Test case 2
    vector<int> nums2 = {3, 1, 3, 4, 3};
    int k2 = 6;
    cout << "Test case 2 result: " << solution.maxOperations(nums2, k2) << endl; // Expected output: 1
    
    // Test case 3
    vector<int> nums3 = {1, 1, 1, 1};
    int k3 = 2;
    cout << "Test case 3 result: " << solution.maxOperations(nums3, k3) << endl; // Expected output: 2
    
    // Test case 4
    vector<int> nums4 = {2, 5, 4, 3, 6, 7, 1, 2};
    int k4 = 8;
    cout << "Test case 4 result: " << solution.maxOperations(nums4, k4) << endl; // Expected output: 2
    
    return 0;
}

