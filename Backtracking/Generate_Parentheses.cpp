#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to generate all combinations of n pairs of parentheses
    vector<string> generateParenthesis(int n) {
        vector<string> result;    // This will store all the valid combinations
        string current = "";      // Current combination being formed
        backtrack(result, current, 0, 0, n);  // Start the backtracking process
        return result;
    }
    
    // Helper function for backtracking
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        // If the current combination has reached the maximum length (2 * n), it's valid
        if (current.length() == max * 2) {
            result.push_back(current);  // Add the valid combination to the result
            return;
        }
        
        // If we can still add an opening bracket, do so
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        
        // If we can add a closing bracket (only if there are unmatched opening brackets), do so
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;
    
    // Call the function to generate parentheses
    vector<string> parentheses = sol.generateParenthesis(n);
    
    // Print the results
    cout << "All combinations of well-formed parentheses are:\n";
    for (const string& combo : parentheses) {
        cout << combo << endl;
    }
    
    return 0;
}

