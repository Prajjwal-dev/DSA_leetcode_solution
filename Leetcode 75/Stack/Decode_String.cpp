#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack; // To store the strings before '['
        stack<int> numStack;   // To store the repeat count for '['
        string currStr = "";   // To keep track of the current processed string
        int k = 0;             // To accumulate the multiplier for the string

        for (char c : s) {
            if (isdigit(c)) {
                // Build the multiplier value
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                // Push current string and multiplier to stacks
                strStack.push(currStr);
                numStack.push(k);
                // Reset current string and multiplier
                currStr = "";
                k = 0;
            } else if (c == ']') {
                // Pop multiplier and previous string
                int repeatTimes = numStack.top(); numStack.pop();
                string prevStr = strStack.top(); strStack.pop();
                // Expand the current string
                string expanded = "";
                for (int i = 0; i < repeatTimes; i++) {
                    expanded += currStr;
                }
                // Append expanded string to the previous string
                currStr = prevStr + expanded;
            } else {
                // Build the current string
                currStr += c;
            }
        }

        return currStr;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string test1 = "3[a]2[bc]";
    cout << "Input: " << test1 << endl;
    cout << "Output: " << sol.decodeString(test1) << endl;

    // Test case 2
    string test2 = "3[a2[c]]";
    cout << "Input: " << test2 << endl;
    cout << "Output: " << sol.decodeString(test2) << endl;

    // Test case 3
    string test3 = "2[abc]3[cd]ef";
    cout << "Input: " << test3 << endl;
    cout << "Output: " << sol.decodeString(test3) << endl;

    return 0;
}


