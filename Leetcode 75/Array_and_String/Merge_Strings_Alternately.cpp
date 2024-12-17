#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = ""; // Initialize an empty string to store the result
        int i = 0;          // Iterator for word1
        int j = 0;          // Iterator for word2

        // Merge the characters alternately while both strings have characters left
        while (i < word1.length() && j < word2.length()) {
            merged += word1[i++]; // Add character from word1 and increment i
            merged += word2[j++]; // Add character from word2 and increment j
        }

        // Append the remaining characters of word1, if any
        while (i < word1.length()) {
            merged += word1[i++];
        }

        // Append the remaining characters of word2, if any
        while (j < word2.length()) {
            merged += word2[j++];
        }

        return merged; // Return the merged result
    }
};

// Test function
int main() {
    Solution solution; // Create an object of the Solution class

    // Test case 1: Both words have the same length
    string word1 = "abc";
    string word2 = "pqr";
    cout << "Test 1: " << solution.mergeAlternately(word1, word2) << endl; // Output: "apbqcr"

    // Test case 2: word2 is longer than word1
    word1 = "ab";
    word2 = "pqrs";
    cout << "Test 2: " << solution.mergeAlternately(word1, word2) << endl; // Output: "apbqrs"

    // Test case 3: word1 is longer than word2
    word1 = "abcd";
    word2 = "pq";
    cout << "Test 3: " << solution.mergeAlternately(word1, word2) << endl; // Output: "apbqcd"

    // Additional test case 4: Single characters in both words
    word1 = "a";
    word2 = "z";
    cout << "Test 4: " << solution.mergeAlternately(word1, word2) << endl; // Output: "az"

    return 0; // Indicate that the program executed successfully
}

