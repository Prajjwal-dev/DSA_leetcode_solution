#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Create sets to store unique elements from each array
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        // Vectors to store the differences
        vector<int> diff1, diff2;

        // Find elements in set1 but not in set2
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                diff1.push_back(num);  // Add unique element from nums1
            }
        }

        // Find elements in set2 but not in set1
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                diff2.push_back(num);  // Add unique element from nums2
            }
        }

        // Return the result as a vector of two vectors
        return {diff1, diff2};
    }
};

int main() {
    Solution solution;  // Create an object of the Solution class

    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> result1 = solution.findDifference(nums1, nums2);
    cout << "Test Case 1: [[";
    for (int num : result1[0]) cout << num << " ";
    cout << "],[";
    for (int num : result1[1]) cout << num << " ";
    cout << "]]" << endl;

    // Test case 2
    vector<int> nums3 = {1, 2, 3, 3};
    vector<int> nums4 = {1, 1, 2, 2};
    vector<vector<int>> result2 = solution.findDifference(nums3, nums4);
    cout << "Test Case 2: [[";
    for (int num : result2[0]) cout << num << " ";
    cout << "],[";
    for (int num : result2[1]) cout << num << " ";
    cout << "]]" << endl;

    // Additional Test case 3: Both arrays with common and unique values
    vector<int> nums5 = {5, 10, 15};
    vector<int> nums6 = {10, 20, 30};
    vector<vector<int>> result3 = solution.findDifference(nums5, nums6);
    cout << "Test Case 3: [[";
    for (int num : result3[0]) cout << num << " ";
    cout << "],[";
    for (int num : result3[1]) cout << num << " ";
    cout << "]]" << endl;

    return 0;
}

