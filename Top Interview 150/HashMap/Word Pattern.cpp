#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> patternToWord;  // Map pattern characters to words
        unordered_map<string, char> wordToPattern;  // Map words to pattern characters
        
        istringstream ss(s);  // String stream to split the string 's' into words
        vector<string> words;  // Vector to store the words from 's'
        string word;
        
        // Split the string 's' into words
        while (ss >> word) {
            words.push_back(word);
        }
        
        // If the number of words and the number of pattern characters don't match, return false
        if (words.size() != pattern.size()) {
            return false;
        }
        
        // Iterate over the pattern characters and corresponding words
        for (int i = 0; i < pattern.size(); ++i) {
            char pChar = pattern[i];  // Current pattern character
            string w = words[i];  // Current word from 's'
            
            // Check if there's already a mapping for the pattern character
            if (patternToWord.find(pChar) != patternToWord.end()) {
                // If the mapped word does not match the current word, return false
                if (patternToWord[pChar] != w) {
                    return false;
                }
            } else {
                // If the word is already mapped to another pattern character, return false
                if (wordToPattern.find(w) != wordToPattern.end()) {
                    return false;
                }
                
                // Establish the new mappings
                patternToWord[pChar] = w;
                wordToPattern[w] = pChar;
            }
        }
        
        // All checks passed, return true
        return true;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string pattern1 = "abba";
    string s1 = "dog cat cat dog";
    cout << "Test case 1 result: " << (sol.wordPattern(pattern1, s1) ? "true" : "false") << endl;

    // Test case 2
    string pattern2 = "abba";
    string s2 = "dog cat cat fish";
    cout << "Test case 2 result: " << (sol.wordPattern(pattern2, s2) ? "true" : "false") << endl;

    // Test case 3
    string pattern3 = "aaaa";
    string s3 = "dog cat cat dog";
    cout << "Test case 3 result: " << (sol.wordPattern(pattern3, s3) ? "true" : "false") << endl;

    return 0;
}

