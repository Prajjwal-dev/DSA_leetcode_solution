#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Base cases
        if (n == 0) return 0;  // No house, no money
        if (n == 1) return nums[0];  // Only one house, rob it
        
        // DP array to store the max money up to each house
        vector<int> dp(n, 0);
        
        // Initialize the first two houses
        dp[0] = nums[0];  // Rob the first house
        dp[1] = max(nums[0], nums[1]);  // Max of robbing first or second house
        
        // Fill the dp array for the rest of the houses
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        
        // The last element of dp contains the result
        return dp[n - 1];
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test Case 1: Maximum money you can rob: " << solution.rob(nums1) << endl;
    
    // Test case 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Test Case 2: Maximum money you can rob: " << solution.rob(nums2) << endl;

    return 0;
}

