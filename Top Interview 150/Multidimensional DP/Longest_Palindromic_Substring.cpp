#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to find the longest palindromic substring
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, end = 0;
        
        // Iterate through each character in the string
        for (int i = 0; i < s.size(); i++) {
            // Check for palindromes centered at a single character (odd-length palindrome)
            int len1 = expandAroundCenter(s, i, i);
            // Check for palindromes centered at two consecutive characters (even-length palindrome)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Get the maximum length palindrome found so far
            int len = max(len1, len2);
            
            // Update the start and end if the new palindrome is longer
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        
        // Return the longest palindromic substring
        return s.substr(start, end - start + 1);
    }
    
private:
    // Helper function to expand around a center and find the length of a palindrome
    int expandAroundCenter(const string& s, int left, int right) {
        // Expand outward while the characters on both sides are equal
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;
    
    // Example 1
    string s1 = "babad";
    cout << "Longest palindromic substring (Example 1): " << solution.longestPalindrome(s1) << endl;
    
    // Example 2
    string s2 = "cbbd";
    cout << "Longest palindromic substring (Example 2): " << solution.longestPalindrome(s2) << endl;
    
    // Example 3
    string s3 = "a";
    cout << "Longest palindromic substring (Example 3): " << solution.longestPalindrome(s3) << endl;
    
    // Example 4
    string s4 = "ac";
    cout << "Longest palindromic substring (Example 4): " << solution.longestPalindrome(s4) << endl;
    
    return 0;
}

