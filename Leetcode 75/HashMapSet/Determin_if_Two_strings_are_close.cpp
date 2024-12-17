#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // If lengths are not the same, they can't be close
        if (word1.length() != word2.length()) return false;

        // Frequency maps for both words
        vector<int> freq1(26, 0), freq2(26, 0);
        set<char> set1, set2;

        // Count character frequencies and unique characters
        for (char c : word1) {
            freq1[c - 'a']++;
            set1.insert(c);
        }
        for (char c : word2) {
            freq2[c - 'a']++;
            set2.insert(c);
        }

        // Check if the sets of characters are the same
        if (set1 != set2) return false;

        // Check if the sorted frequency distributions are the same
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};

int main() {
    Solution solution;

    vector<pair<string, string>> testCases = {
        {"abc", "bca"},
        {"a", "aa"},
        {"cabbba", "abbccc"},
        {"abb", "bbc"},
        {"abcd", "dcba"},
        {"abc", "xyz"}
    };
    vector<bool> expectedOutputs = {true, false, true, false, true, false};

    for (size_t i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        cout << "word1 = \"" << testCases[i].first << "\", ";
        cout << "word2 = \"" << testCases[i].second << "\"\n";

        bool result = solution.closeStrings(testCases[i].first, testCases[i].second);
        cout << "Output: " << (result ? "true" : "false");
        cout << " (Expected: " << (expectedOutputs[i] ? "true" : "false") << ")\n";
        cout << (result == expectedOutputs[i] ? "PASSED" : "FAILED") << "\n";
        cout << "-------------------------------\n";
    }

    return 0;
}

