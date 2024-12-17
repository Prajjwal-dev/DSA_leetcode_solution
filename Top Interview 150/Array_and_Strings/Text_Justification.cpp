#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;  // To store the final result
        int n = words.size();  // Number of words
        int i = 0;  // Pointer to traverse words

        while (i < n) {
            int lineLength = words[i].length();  // Length of the current line
            int last = i + 1;  // Pointer to identify the end of the current line

            // Try to fit as many words as possible into the current line
            while (last < n && lineLength + words[last].length() + (last - i) <= maxWidth) {
                lineLength += words[last].length();
                last++;
            }

            string line;  // The current line
            int numWords = last - i;  // Number of words in the current line
            int numSpaces = maxWidth - lineLength;  // Total spaces to distribute

            // If it's the last line or the line has only one word
            if (last == n || numWords == 1) {
                for (int j = i; j < last; ++j) {
                    line += words[j];
                    if (j < last - 1) line += " ";
                }
                // Add remaining spaces to the right
                while (line.length() < maxWidth) line += " ";
            } else {
                int spaceBetween = numSpaces / (numWords - 1);  // Spaces between words
                int extraSpaces = numSpaces % (numWords - 1);  // Extra spaces to distribute

                for (int j = i; j < last; ++j) {
                    line += words[j];
                    if (j < last - 1) {
                        line += string(spaceBetween + (j - i < extraSpaces ? 1 : 0), ' ');
                    }
                }
            }

            result.push_back(line);
            i = last;  // Move to the next set of words
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    vector<string> result1 = sol.fullJustify(words1, maxWidth1);
    cout << "Test Case 1 Output:\n";
    for (const string& line : result1) {
        cout << "\"" << line << "\"" << endl;
    }
    cout << endl;

    // Test case 2
    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth2 = 16;
    vector<string> result2 = sol.fullJustify(words2, maxWidth2);
    cout << "Test Case 2 Output:\n";
    for (const string& line : result2) {
        cout << "\"" << line << "\"" << endl;
    }
    cout << endl;

    // Test case 3
    vector<string> words3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth3 = 20;
    vector<string> result3 = sol.fullJustify(words3, maxWidth3);
    cout << "Test Case 3 Output:\n";
    for (const string& line : result3) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}

