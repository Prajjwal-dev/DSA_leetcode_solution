#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;       // Stack to store results of expressions
        stack<int> ops;        // Stack to store signs (+1 or -1)
        int result = 0;        // Current evaluated result
        int sign = 1;          // Current sign (1 for +, -1 for -)
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                int num = 0;
                // Extract the entire number
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // Adjust for the extra increment
                result += sign * num; // Apply the sign and add to result
            } 
            else if (c == '+') {
                sign = 1; // Set sign for addition
            } 
            else if (c == '-') {
                sign = -1; // Set sign for subtraction
            } 
            else if (c == '(') {
                // Push current result and sign onto the stack
                nums.push(result);
                ops.push(sign);
                // Reset result and sign for the new sub-expression
                result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                // Complete the current sub-expression
                result = nums.top() + ops.top() * result;
                nums.pop();
                ops.pop();
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "1 + 1";
    cout << "Input: \"" << s1 << "\"\n";
    cout << "Output: " << solution.calculate(s1) << "\n\n";

    // Test case 2
    string s2 = " 2-1 + 2 ";
    cout << "Input: \"" << s2 << "\"\n";
    cout << "Output: " << solution.calculate(s2) << "\n\n";

    // Test case 3
    string s3 = "(1+(4+5+2)-3)+(6+8)";
    cout << "Input: \"" << s3 << "\"\n";
    cout << "Output: " << solution.calculate(s3) << "\n\n";

    // Test case 4
    string s4 = "10 - (3 + (2 - 1))";
    cout << "Input: \"" << s4 << "\"\n";
    cout << "Output: " << solution.calculate(s4) << "\n";

    return 0;
}

