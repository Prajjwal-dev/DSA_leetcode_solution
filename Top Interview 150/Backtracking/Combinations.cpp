#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;  // To store the result
        vector<int> current;  // To store the current combination
        backtrack(1, n, k, current, result);  // Call the backtracking function
        return result;
    }

private:
    // Recursive backtracking function
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);  // If we have selected k numbers, store the current combination
            return;
        }
        for (int i = start; i <= n; i++) {
            current.push_back(i);  // Choose the number i
            backtrack(i + 1, n, k, current, result);  // Explore further with the next number
            current.pop_back();  // Backtrack by removing the last number
        }
    }
};

int main() {
    Solution solution;

    // Test Case 1
    int n = 4, k = 2;
    vector<vector<int>> result = solution.combine(n, k);
    cout << "Combinations for n = 4 and k = 2:" << endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Test Case 2
    n = 1;
    k = 1;
    result = solution.combine(n, k);
    cout << "Combinations for n = 1 and k = 1:" << endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

