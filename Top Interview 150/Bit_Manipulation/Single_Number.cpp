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

    // Example 1: nums = [2, 2, 1]
    vector<int> nums1 = {2, 2, 1};
    cout << "The single number in nums1 is: " << solution.singleNumber(nums1) << endl;

    // Example 2: nums = [4, 1, 2, 1, 2]
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "The single number in nums2 is: " << solution.singleNumber(nums2) << endl;

    // Example 3: nums = [1]
    vector<int> nums3 = {1};
    cout << "The single number in nums3 is: " << solution.singleNumber(nums3) << endl;

    return 0;
}

