#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap; // Stores the index of each character
        int maxLength = 0; // Tracks the length of the longest substring
        int start = 0; // Left boundary of the window

        for (int end = 0; end < s.length(); end++) {
            char currentChar = s[end];

            // If the current character is already in the map and its index is within the current window
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                // Move the start pointer to the right of the last occurrence of currentChar
                start = charIndexMap[currentChar] + 1;
            }

            // Update or add the character's position to the map
            charIndexMap[currentChar] = end;

            // Calculate the length of the current window and update maxLength
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "abcabcbb";
    cout << "Test case 1 - Length of longest substring: " << solution.lengthOfLongestSubstring(s1) << endl;
    // Expected output: 3 ("abc")

    // Test case 2
    string s2 = "bbbbb";
    cout << "Test case 2 - Length of longest substring: " << solution.lengthOfLongestSubstring(s2) << endl;
    // Expected output: 1 ("b")

    // Test case 3
    string s3 = "pwwkew";
    cout << "Test case 3 - Length of longest substring: " << solution.lengthOfLongestSubstring(s3) << endl;
    // Expected output: 3 ("wke")

    // Test case 4 (Additional test case)
    string s4 = "dvdf";
    cout << "Test case 4 - Length of longest substring: " << solution.lengthOfLongestSubstring(s4) << endl;
    // Expected output: 3 ("vdf")

    return 0;
}

