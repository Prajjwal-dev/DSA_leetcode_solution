#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find all combinations that sum up to target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;  // This will store the final valid combinations
        vector<int> combination;     // This will store the current combination being formed
        backtrack(candidates, target, 0, combination, result);  // Start backtracking from index 0
        return result;
    }

    // Helper function for backtracking
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& result) {
        // Base case: if the target is 0, the current combination is valid
        if (target == 0) {
            result.push_back(combination);  // Add the valid combination to the result
            return;
        }

        // Iterate through the candidates starting from the index 'start'
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                // Choose the current candidate
                combination.push_back(candidates[i]);
                // Recur with the reduced target, allowing the same candidate to be reused (hence 'i' not 'i + 1')
                backtrack(candidates, target - candidates[i], i, combination, result);
                // Backtrack by removing the last chosen number
                combination.pop_back();
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates;
    int n, target;

    // Input the number of candidates and the target
    cout << "Enter the number of candidates: ";
    cin >> n;
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        candidates.push_back(x);
    }
    cout << "Enter the target: ";
    cin >> target;

    // Call the combinationSum function
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    // Print the result
    cout << "Combinations that sum to " << target << " are:\n";
    for (const vector<int>& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}

