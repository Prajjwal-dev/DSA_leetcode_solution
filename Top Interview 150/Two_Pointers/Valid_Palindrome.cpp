#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // Two pointers, one from the beginning and one from the end
        int left = 0;
        int right = s.size() - 1;

        // Loop until the two pointers meet in the middle
        while (left < right) {
            // Skip non-alphanumeric characters on the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Skip non-alphanumeric characters on the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare the characters after converting to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // If mismatch, it's not a palindrome
            }

            // Move the pointers inward
            left++;
            right--;
        }

        return true; // If no mismatch found, it's a palindrome
    }
};

int main() {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << (sol.isPalindrome(s) ? "true" : "false") << endl;  // Output: true
    return 0;
}

