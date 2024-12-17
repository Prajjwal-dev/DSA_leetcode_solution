#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, zeroCount = 0;
        int maxLen = 0;

        // Sliding window approach
        while (right < n) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Shrink the window if more than one zero is in the window
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Update max length, subtracting 1 to account for one deletion
            maxLen = max(maxLen, right - left);
            right++;
        }

        return maxLen;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> testCases = {
        {1, 1, 0, 1},
        {0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1}
    };
    vector<int> expectedOutputs = {3, 5, 2};

    for (size_t i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        cout << "Input: ";
        for (int num : testCases[i]) cout << num << " ";
        cout << "\n";

        int result = solution.longestSubarray(testCases[i]);
        cout << "Output: " << result;
        cout << " (Expected: " << expectedOutputs[i] << ")\n";
        cout << (result == expectedOutputs[i] ? "PASSED" : "FAILED") << "\n";
        cout << "-------------------------------\n";
    }

    return 0;
}

