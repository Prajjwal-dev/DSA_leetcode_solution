#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        // Iterate through each token in the expression
        for (string token : tokens) {
            if (isOperator(token)) {
                // Pop two operands from stack
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                
                // Apply the operator and push the result back on the stack
                if (token == "+") {
                    stk.push(a + b);
                } else if (token == "-") {
                    stk.push(a - b);
                } else if (token == "*") {
                    stk.push(a * b);
                } else if (token == "/") {
                    stk.push(a / b);
                }
            } else {
                // If the token is a number, convert it and push onto the stack
                stk.push(stoi(token));
            }
        }
        
        // The final result will be the only element in the stack
        return stk.top();
    }
    
private:
    // Helper function to check if a string is an operator
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};

int main() {
    Solution solution;
    vector<string> tokens;

    // Example 1
    tokens = {"2", "1", "+", "3", "*"};
    cout << "Input: {\"2\", \"1\", \"+\", \"3\", \"*\"}" << endl;
    cout << "Output: " << solution.evalRPN(tokens) << endl << endl;

    // Example 2
    tokens = {"4", "13", "5", "/", "+"};
    cout << "Input: {\"4\", \"13\", \"5\", \"/\", \"+\"}" << endl;
    cout << "Output: " << solution.evalRPN(tokens) << endl << endl;

    // Example 3
    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Input: {\"10\", \"6\", \"9\", \"3\", \"+\", \"-11\", \"*\", \"/\", \"*\", \"17\", \"+\", \"5\", \"+\"}" << endl;
    cout << "Output: " << solution.evalRPN(tokens) << endl;

    return 0;
}

