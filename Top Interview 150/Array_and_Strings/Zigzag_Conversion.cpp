#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // If the number of rows is 1 or the string is too short, return it as is
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Create a vector of strings to represent each row
        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        // Loop through each character in the string
        for (char c : s) {
            // Append the character to the current row
            rows[currentRow] += c;

            // If we are at the top or bottom row, reverse the direction
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move up or down based on the direction
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to form the final result
        string result;
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};

int main() {
    Solution solution;

    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Input: " << s1 << ", numRows = " << numRows1 << endl;
    cout << "Output: " << solution.convert(s1, numRows1) << endl;

    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << "Input: " << s2 << ", numRows = " << numRows2 << endl;
    cout << "Output: " << solution.convert(s2, numRows2) << endl;

    string s3 = "A";
    int numRows3 = 1;
    cout << "Input: " << s3 << ", numRows = " << numRows3 << endl;
    cout << "Output: " << solution.convert(s3, numRows3) << endl;

    return 0;
}

