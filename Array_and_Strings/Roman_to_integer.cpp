#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Step 1: Create a map that stores the value of each Roman numeral
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0; // This will store the final result

        // Step 2: Iterate through the string 's'
        for (int i = 0; i < s.length(); i++) {
            // Step 3: Check if the current numeral is smaller than the next numeral
            if (i < s.length() - 1 && roman[s[i]] < roman[s[i + 1]]) {
                // If the current numeral is smaller than the next, subtract its value
                result -= roman[s[i]];
            } else {
                // Otherwise, add its value
                result += roman[s[i]];
            }
        }

        return result; // Return the final result
    }
};

int main() {
    Solution sol;
    
    // Test cases
    string roman1 = "III";
    cout << "Roman: " << roman1 << ", Integer: " << sol.romanToInt(roman1) << endl;

    string roman2 = "LVIII";
    cout << "Roman: " << roman2 << ", Integer: " << sol.romanToInt(roman2) << endl;

    string roman3 = "MCMXCIV";
    cout << "Roman: " << roman3 << ", Integer: " << sol.romanToInt(roman3) << endl;

    return 0;
}

