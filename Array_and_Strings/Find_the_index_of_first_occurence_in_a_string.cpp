#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(); // Length of the haystack
        int m = needle.length();   // Length of the needle
        
        // Edge case: if needle is empty, return 0
        if (m == 0) {
            return 0;
        }
        
        // Slide the window of size 'm' across the 'haystack'
        for (int i = 0; i <= n - m; i++) {
            // Compare the substring of length 'm' starting at 'i' with 'needle'
            if (haystack.substr(i, m) == needle) {
                return i; // Return the starting index of the first match
            }
        }
        
        // If no match is found, return -1
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string haystack1 = "sadbutsad";
    string needle1 = "sad";
    cout << "First occurrence of 'sad' in 'sadbutsad': " << sol.strStr(haystack1, needle1) << endl;

    // Test Case 2
    string haystack2 = "leetcode";
    string needle2 = "leeto";
    cout << "First occurrence of 'leeto' in 'leetcode': " << sol.strStr(haystack2, needle2) << endl;
    
    return 0;
}

