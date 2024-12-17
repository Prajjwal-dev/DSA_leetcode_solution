#include <iostream>
#include <vector>
#include <algorithm> // for std::max
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1); // Step 1: Initialize dp array, each element starts with 1
        int maxLength = 1; // Step 2: Variable to track the maximum length

        for (int i = 1; i < n; ++i) { // Step 3: Traverse the array
            for (int j = 0; j < i; ++j) { // Step 4: Compare each element with previous ones
                if (nums[i] > nums[j]) { // Step 5: Check if nums[i] can extend the subsequence
                    dp[i] = max(dp[i], dp[j] + 1); // Step 6: Update dp[i]
                }
            }
            maxLength = max(maxLength, dp[i]); // Step 7: Update the maximum subsequence length
        }

        return maxLength; // Step 8: Return the length of the longest increasing subsequence
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS for [10, 9, 2, 5, 3, 7, 101, 18]: " << sol.lengthOfLIS(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Length of LIS for [0, 1, 0, 3, 2, 3]: " << sol.lengthOfLIS(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Length of LIS for [7, 7, 7, 7, 7, 7, 7]: " << sol.lengthOfLIS(nums3) << endl;

    return 0;
}

