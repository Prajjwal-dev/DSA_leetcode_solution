#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Step 1: Create a hash map to store the last index of each element
        unordered_map<int, int> numMap;

        // Step 2: Traverse through the array nums
        for (int i = 0; i < nums.size(); i++) {
            // Step 3: If the current element exists in the map, check the index difference
            if (numMap.find(nums[i]) != numMap.end()) {
                int prevIndex = numMap[nums[i]];
                if (abs(i - prevIndex) <= k) {
                    return true; // Found a duplicate within the allowed range
                }
            }
            // Step 4: Update the current element's index in the map
            numMap[nums[i]] = i;
        }

        // Step 5: If no such pair was found, return false
        return false;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << solution.containsNearbyDuplicate(nums1, k1) << endl; // Output: true
    
    // Example 2
    vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    cout << solution.containsNearbyDuplicate(nums2, k2) << endl; // Output: true
    
    // Example 3
    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    int k3 = 2;
    cout << solution.containsNearbyDuplicate(nums3, k3) << endl; // Output: false

    return 0;
}

