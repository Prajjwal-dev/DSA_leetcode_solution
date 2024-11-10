#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;  // To store the unique triplets
        sort(nums.begin(), nums.end());  // Sort the array to handle duplicates and use two-pointer technique

        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicate elements to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;               // Left pointer, right after 'i'
            int right = nums.size() - 1;    // Right pointer, at the end of the array

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});  // Found a valid triplet

                    // Move left pointer to the next different element
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Move right pointer to the previous different element
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move both pointers to continue searching
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;  // If sum is too small, move left pointer to increase the sum
                } else {
                    right--; // If sum is too large, move right pointer to decrease the sum
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Unique triplets that sum to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}

