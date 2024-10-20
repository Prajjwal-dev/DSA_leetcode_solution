#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove leading, trailing, and multiple spaces
        int left = 0, right = s.length() - 1;
        
        // Trim leading spaces
        while (left <= right && s[left] == ' ') left++;
        
        // Trim trailing spaces
        while (right >= left && s[right] == ' ') right--;
        
        // Step 2: Reverse the entire string from left to right
        reverse(s.begin() + left, s.begin() + right + 1);
        
        // Step 3: Reverse each word in the reversed string
        int start = left;
        for (int i = left; i <= right; i++) {
            // Find the end of the current word
            if (s[i] == ' ' || i == right) {
                if (i == right) i++;  // Include the last character of the word
                
                // Reverse the word
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;  // Move to the start of the next word
            }
        }

        // Step 4: Remove extra spaces between words
        string result;
        bool space = false;
        for (int i = left; i <= right; i++) {
            if (s[i] != ' ') {
                result.push_back(s[i]);
                space = true;
            } else if (space) {
                result.push_back(' ');
                space = false;
            }
        }
        
        // Remove trailing space if there is one
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};

// Main function
int main() {
    Solution solution;
    string s;

    // Input the string
    cout << "Enter a string: ";
    getline(cin, s); // Reading the input string, including spaces

    // Reverse the words in the string
    string result = solution.reverseWords(s);

    // Output the result
    cout << "Reversed words: \"" << result << "\"" << endl;

    return 0;
}

