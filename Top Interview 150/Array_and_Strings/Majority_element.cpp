#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();  // Get the size of the array
        
        // Base case: if the array is empty (though the problem guarantees a majority element)
        if (n == 0) {
            return 0;
        }

        int count = 0;         // Initialize count
        int candidate = nums[0]; // Initial candidate

        // Iterate through the array to find the majority element
        for (int i = 0; i < n; i++) {
            // If count is zero, update the candidate
            if (count == 0) {
                candidate = nums[i];
            }
            // Update count based on whether the current number matches the candidate
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Return the majority element found
        return candidate;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {3, 2, 3};
    int result1 = solution.majorityElement(nums1);
    cout << "The majority element in [3, 2, 3] is: " << result1 << endl;

    // Example 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    int result2 = solution.majorityElement(nums2);
    cout << "The majority element in [2, 2, 1, 1, 1, 2, 2] is: " << result2 << endl;

    return 0;
}

