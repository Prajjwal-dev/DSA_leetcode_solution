#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // Edge case: if input is empty
        vector<string> result;  // To store the result
        string current;  // To store current combination
        vector<string> mapping = {
            "",     // Placeholder for '0'
            "",     // Placeholder for '1'
            "abc",  // Mapping for '2'
            "def",  // Mapping for '3'
            "ghi",  // Mapping for '4'
            "jkl",  // Mapping for '5'
            "mno",  // Mapping for '6'
            "pqrs", // Mapping for '7'
            "tuv",  // Mapping for '8'
            "wxyz"  // Mapping for '9'
        };
        backtrack(0, digits, current, result, mapping);  // Call helper function
        return result;
    }

private:
    // Recursive helper function to generate combinations
    void backtrack(int index, const string& digits, string& current, vector<string>& result, const vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);  // Base case: full combination formed
            return;
        }
        string letters = mapping[digits[index] - '0'];  // Get the letters corresponding to current digit
        for (char letter : letters) {  // Iterate over all possible letters
            current.push_back(letter);  // Choose a letter
            backtrack(index + 1, digits, current, result, mapping);  // Explore further
            current.pop_back();  // Backtrack to try the next letter
        }
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    string digits = "23";
    vector<string> result = solution.letterCombinations(digits);
    cout << "Output for digits '23': ";
    for (string combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    // Test Case 2
    digits = "";
    result = solution.letterCombinations(digits);
    cout << "Output for empty digits: ";
    for (string combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    // Test Case 3
    digits = "2";
    result = solution.letterCombinations(digits);
    cout << "Output for digits '2': ";
    for (string combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}

