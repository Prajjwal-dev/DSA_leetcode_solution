#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Step 1: Base case - If the input array is empty
        if (strs.empty()) {
            return "";
        }

        // Step 2: Start by assuming the first string is the common prefix
        string prefix = strs[0];

        // Step 3: Iterate through the rest of the strings in the array
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;  // Pointer to compare characters
            // Compare the prefix with each string character by character
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                j++;  // Move the pointer to check the next character
            }
            // Step 4: Truncate the prefix up to the point where the comparison stopped
            prefix = prefix.substr(0, j);

            // If the prefix becomes empty, return immediately
            if (prefix.empty()) {
                return "";
            }
        }

        // Step 5: Return the final prefix
        return prefix;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest common prefix: " << sol.longestCommonPrefix(strs1) << endl;

    // Test case 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest common prefix: " << sol.longestCommonPrefix(strs2) << endl;

    return 0;
}

