#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Create a stack to keep track of opening brackets
        stack<char> st;
        
        // A map that associates closing brackets with their corresponding opening brackets
        unordered_map<char, char> bracket_map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        // Iterate through the string
        for (char c : s) {
            // If c is a closing bracket
            if (bracket_map.count(c)) {
                // Check the top of the stack. If the stack is not empty, get the top element, otherwise assign a dummy '#'.
                char top_element = st.empty() ? '#' : st.top();
                
                // If the top element matches the corresponding opening bracket, pop it from the stack
                if (top_element == bracket_map[c]) {
                    st.pop();
                } else {
                    // If it doesn't match, return false because the string is invalid
                    return false;
                }
            } else {
                // If it's an opening bracket, push it onto the stack
                st.push(c);
            }
        }
        
        // At the end, the stack should be empty if all opening brackets were matched
        return st.empty();
    }
};

int main() {
    Solution solution;
    
    // Example 1
    string s1 = "()";
    cout << "Example 1: " << solution.isValid(s1) << endl;
    
    // Example 2
    string s2 = "()[]{}";
    cout << "Example 2: " << solution.isValid(s2) << endl;
    
    // Example 3
    string s3 = "(]";
    cout << "Example 3: " << solution.isValid(s3) << endl;
    
    // Example 4
    string s4 = "([])";
    cout << "Example 4: " << solution.isValid(s4) << endl;
    
    return 0;
}

