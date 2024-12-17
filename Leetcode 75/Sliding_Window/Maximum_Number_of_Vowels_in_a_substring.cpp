#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        // Define a set of vowels for quick lookup
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max_count = 0; // Maximum number of vowels found
        int current_count = 0; // Current count of vowels in the sliding window

        // Count vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) {
                current_count++;
            }
        }
        max_count = current_count;

        // Slide the window across the string
        for (int i = k; i < s.size(); i++) {
            // Remove the character leaving the window
            if (vowels.count(s[i - k])) {
                current_count--;
            }
            // Add the character entering the window
            if (vowels.count(s[i])) {
                current_count++;
            }
            // Update the maximum count
            max_count = max(max_count, current_count);
        }

        return max_count;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "abciiidef";
    int k1 = 3;
    cout << "Test Case 1:\n";
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << "\n";
    cout << "Output: " << solution.maxVowels(s1, k1) << "\n\n";

    // Test case 2
    string s2 = "aeiou";
    int k2 = 2;
    cout << "Test Case 2:\n";
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << "\n";
    cout << "Output: " << solution.maxVowels(s2, k2) << "\n\n";

    // Test case 3
    string s3 = "leetcode";
    int k3 = 3;
    cout << "Test Case 3:\n";
    cout << "Input: s = \"" << s3 << "\", k = " << k3 << "\n";
    cout << "Output: " << solution.maxVowels(s3, k3) << "\n\n";

    // Test case 4 (edge case: all consonants)
    string s4 = "bcdfgh";
    int k4 = 3;
    cout << "Test Case 4:\n";
    cout << "Input: s = \"" << s4 << "\", k = " << k4 << "\n";
    cout << "Output: " << solution.maxVowels(s4, k4) << "\n\n";

    // Test case 5 (edge case: k = length of the string)
    string s5 = "aeiou";
    int k5 = 5;
    cout << "Test Case 5:\n";
    cout << "Input: s = \"" << s5 << "\", k = " << k5 << "\n";
    cout << "Output: " << solution.maxVowels(s5, k5) << "\n";

    return 0;
}

