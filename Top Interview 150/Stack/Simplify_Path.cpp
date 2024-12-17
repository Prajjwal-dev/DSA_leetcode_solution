#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;       // Stack to hold valid directory names
        stringstream ss(path);   // String stream for splitting the path
        string token;            // Variable to store each part of the split path

        // Split the path by '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // Ignore empty tokens or single dot representing current directory
                continue;
            } else if (token == "..") {
                // Go up to parent directory if possible
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                // Valid directory name, push onto the stack
                stk.push(token);
            }
        }

        // Construct the simplified path from the stack
        string result;
        while (!stk.empty()) {
            result = "/" + stk.top() + result;  // Prepend directory names
            stk.pop();
        }

        // If result is empty, return root "/"
        return result.empty() ? "/" : result;
    }
};

int main() {
    Solution solution;
    string path;

    // Example 1
    path = "/home/";
    cout << "Input: \"" << path << "\"" << endl;
    cout << "Output: \"" << solution.simplifyPath(path) << "\"" << endl << endl;

    // Example 2
    path = "/home//foo/";
    cout << "Input: \"" << path << "\"" << endl;
    cout << "Output: \"" << solution.simplifyPath(path) << "\"" << endl << endl;

    // Example 3
    path = "/home/user/Documents/../Pictures";
    cout << "Input: \"" << path << "\"" << endl;
    cout << "Output: \"" << solution.simplifyPath(path) << "\"" << endl << endl;

    // Example 4
    path = "/../";
    cout << "Input: \"" << path << "\"" << endl;
    cout << "Output: \"" << solution.simplifyPath(path) << "\"" << endl << endl;

    // Example 5
    path = "/.../a/../b/c/../d/./";
    cout << "Input: \"" << path << "\"" << endl;
    cout << "Output: \"" << solution.simplifyPath(path) << "\"" << endl;

    return 0;
}

