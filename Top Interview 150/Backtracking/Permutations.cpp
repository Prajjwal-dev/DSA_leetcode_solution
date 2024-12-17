#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;  // To store all permutations
        vector<int> current;  // To store current permutation
        vector<bool> used(nums.size(), false);  // To track used numbers
        backtrack(nums, used, current, result);  // Start backtracking
        return result;
    }

private:
    // Backtracking function
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {  // Base case: a full permutation is formed
            result.push_back(current);  // Add it to the result
            return;
        }
        for (int i = 0; i < nums.size(); i++) {  // Iterate over each number
            if (!used[i]) {  // Only use the number if it hasn't been used in the current permutation
                used[i] = true;  // Mark the number as used
                current.push_back(nums[i]);  // Add the number to the current permutation
                backtrack(nums, used, current, result);  // Explore further
                current.pop_back();  // Backtrack by removing the number
                used[i] = false;  // Unmark the number as used
            }
        }
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.permute(nums);
    cout << "Permutations for [1, 2, 3]:" << endl;
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Test Case 2
    nums = {0, 1};
    result = solution.permute(nums);
    cout << "Permutations for [0, 1]:" << endl;
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Test Case 3
    nums = {1};
    result = solution.permute(nums);
    cout << "Permutations for [1]:" << endl;
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

