#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;  // Stores the final result
        int n = nums.size();    // Get the size of the input array
        if (n == 0) return result;  // Return an empty result if nums is empty
        
        int start = nums[0];  // Initialize the start of the range
        
        // Traverse the array to find ranges
        for (int i = 1; i <= n; ++i) {
            // If current number is not consecutive or we are at the end of the array
            if (i == n || nums[i] != nums[i - 1] + 1) {
                // If start is equal to the previous number, it's a single number range
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start));  // Add single number to result
                } else {
                    // Otherwise, it's a range from start to the previous number
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                // Update the start for the next range
                if (i < n) start = nums[i];
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    vector<string> result1 = solution.summaryRanges(nums1);
    
    cout << "Example 1 Output: ";
    for (const string& range : result1) {
        cout << range << " ";
    }
    cout << endl;
    
    // Example 2
    vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
    vector<string> result2 = solution.summaryRanges(nums2);
    
    cout << "Example 2 Output: ";
    for (const string& range : result2) {
        cout << range << " ";
    }
    cout << endl;
    
    return 0;
}

