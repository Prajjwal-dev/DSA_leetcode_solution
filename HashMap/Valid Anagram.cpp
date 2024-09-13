#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Check if the lengths of the strings are the same
        if (s.length() != t.length()) {
            return false;
        }

        // Step 2: Create a hash map to count the frequency of characters in the first string
        unordered_map<char, int> char_count;

        // Count the frequency of each character in string 's'
        for (char ch : s) {
            char_count[ch]++;
        }

        // Step 3: Decrease the frequency of characters using the second string
        for (char ch : t) {
            if (char_count.find(ch) == char_count.end()) {
                // If the character is not found in the map, it's not an anagram
                return false;
            }
            char_count[ch]--;
            if (char_count[ch] < 0) {
                // If the count of any character goes below zero, it's not an anagram
                return false;
            }
        }

        // Step 4: If all characters have been matched, return true
        return true;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    string s1 = "anagram";
    string t1 = "nagaram";
    if (solution.isAnagram(s1, t1)) {
        cout << "\"" << s1 << "\" and \"" << t1 << "\" are anagrams." << endl;
    } else {
        cout << "\"" << s1 << "\" and \"" << t1 << "\" are not anagrams." << endl;
    }
    
    // Example 2
    string s2 = "rat";
    string t2 = "car";
    if (solution.isAnagram(s2, t2)) {
        cout << "\"" << s2 << "\" and \"" << t2 << "\" are anagrams." << endl;
    } else {
        cout << "\"" << s2 << "\" and \"" << t2 << "\" are not anagrams." << endl;
    }

    return 0;
}

