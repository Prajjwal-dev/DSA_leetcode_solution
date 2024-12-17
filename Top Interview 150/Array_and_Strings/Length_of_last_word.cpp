#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLastWord(const std::string& s) {
        int count = 0;
        int n = s.length();

        // Handle base case: if the string is empty
        if (n == 0) {
            return count;
        }

        // Reverse the string to start from the end
        std::string str = s;
        std::reverse(str.begin(), str.end());

        // Traverse the reversed string
        for (int i = 0; i < n; ++i) {
            if (str[i] != ' ') {
                // Count the length of the last word
                ++count;
            } else if (count > 0) {
                // Stop counting once a space is found after counting some characters
                break;
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    
    std::string input1 = "Hello World";
    std::cout << "Length of last word in \"" << input1 << "\": " << solution.lengthOfLastWord(input1) << std::endl;
    
    std::string input2 = "   fly me   to   the moon  ";
    std::cout << "Length of last word in \"" << input2 << "\": " << solution.lengthOfLastWord(input2) << std::endl;

    std::string input3 = "luffy is still joyboy";
    std::cout << "Length of last word in \"" << input3 << "\": " << solution.lengthOfLastWord(input3) << std::endl;

    return 0;
}

