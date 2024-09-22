#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_ptr = 0;  // Pointer for string s
        int t_ptr = 0;  // Pointer for string t

        // Traverse both strings with two pointers
        while (s_ptr < s.size() && t_ptr < t.size()) {
            // If characters match, move the s pointer
            if (s[s_ptr] == t[t_ptr]) {
                s_ptr++;
            }
            // Always move the t pointer
            t_ptr++;
        }

        // If we reached the end of string s, it's a subsequence
        return s_ptr == s.size();
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: s = "abc", t = "ahbgdc" -> Output: true
    string s1 = "abc";
    string t1 = "ahbgdc";
    cout << (sol.isSubsequence(s1, t1) ? "true" : "false") << endl;  // Output: true
    
    // Test Case 2: s = "axc", t = "ahbgdc" -> Output: false
    string s2 = "axc";
    string t2 = "ahbgdc";
    cout << (sol.isSubsequence(s2, t2) ? "true" : "false") << endl;  // Output: false
    
    return 0;
}

