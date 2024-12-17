#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map;  // HashMap to store the value and its index
        
        for (int i = 0; i < nums.size(); ++i) {  // Loop through the array
            int complement = target - nums[i];  // Calculate the complement of the current number
            
            // Check if the complement exists in the map
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};  // Return the indices if found
            }
            
            // Store the current number and its index in the map
            num_map[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector (redundant for this problem)
        return {};
    }
};

int main() {
    // Example 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    // Example 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    // Example 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;

    Solution solution;

    // Finding the indices for the first example
    std::vector<int> result1 = solution.twoSum(nums1, target1);
    std::cout << "Indices for target " << target1 << " are: [" << result1[0] << ", " << result1[1] << "]\n";

    // Finding the indices for the second example
    std::vector<int> result2 = solution.twoSum(nums2, target2);
    std::cout << "Indices for target " << target2 << " are: [" << result2[0] << ", " << result2[1] << "]\n";

    // Finding the indices for the third example
    std::vector<int> result3 = solution.twoSum(nums3, target3);
    std::cout << "Indices for target " << target3 << " are: [" << result3[0] << ", " << result3[1] << "]\n";

    return 0;
}

