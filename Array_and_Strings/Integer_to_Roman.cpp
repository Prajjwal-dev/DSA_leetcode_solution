#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Create arrays for Roman numerals and their corresponding values
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";  // Initialize an empty string to store the result
        
        // Loop over each value and symbol
        for (int i = 0; i < 13; i++) {
            // While the current value can be subtracted from num
            while (num >= values[i]) {
                result += symbols[i];  // Append the corresponding Roman numeral symbol
                num -= values[i];      // Subtract the value from num
            }
        }
        
        return result;  // Return the final Roman numeral
    }
};

int main() {
    Solution sol;
    
    // Example 1: Convert 3749 to Roman numerals
    int num1 = 3749;
    cout << "Roman numeral for " << num1 << " is: " << sol.intToRoman(num1) << endl;
    // Output: MMMDCCXLIX
    
    // Example 2: Convert 58 to Roman numerals
    int num2 = 58;
    cout << "Roman numeral for " << num2 << " is: " << sol.intToRoman(num2) << endl;
    // Output: LVIII
    
    // Example 3: Convert 1994 to Roman numerals
    int num3 = 1994;
    cout << "Roman numeral for " << num3 << " is: " << sol.intToRoman(num3) << endl;
    // Output: MCMXCIV
    
    return 0;
}

