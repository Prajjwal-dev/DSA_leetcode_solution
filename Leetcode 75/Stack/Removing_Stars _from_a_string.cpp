#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // Include this for the reverse function.
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> resultStack; // A stack to store the resulting characters.
        
        for (char c : s) { // Iterate over each character in the string `s`.
            if (c == '*') {
                // If the current character is a '*', remove the top character from the stack.
                resultStack.pop();
            } else {
                // Otherwise, push the character onto the stack.
                resultStack.push(c);
            }
        }
        
        // Construct the final string from the stack.
        string result = "";
        while (!resultStack.empty()) {
            result += resultStack.top();
            resultStack.pop();
        }
        
        // Since the stack gives the reversed order, reverse the result.
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string test1 = "leet**cod*e";
    cout << "Input: " << test1 << endl;
    string output1 = sol.removeStars(test1);
    cout << "Output: " << output1 << endl;

    // Test Case 2
    string test2 = "erase*****";
    cout << "Input: " << test2 << endl;
    string output2 = sol.removeStars(test2);
    cout << "Output: " << output2 << endl;

    // Test Case 3
    string test3 = "a*b*c*";
    cout << "Input: " << test3 << endl;
    string output3 = sol.removeStars(test3);
    cout << "Output: " << output3 << endl;

    // Test Case 4
    string test4 = "abc*d*ef***g";
    cout << "Input: " << test4 << endl;
    string output4 = sol.removeStars(test4);
    cout << "Output: " << output4 << endl;

    return 0;
}

