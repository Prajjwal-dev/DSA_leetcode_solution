#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();  // Length of each word
        int totalWords = words.size();  // Number of words
        int substringLen = wordLen * totalWords;  // Length of the concatenated substring
        int n = s.size();  // Length of the string

        unordered_map<string, int> wordCount;  // Count each word in `words`
        for (const string& word : words) {
            wordCount[word]++;
        }

        // Loop through each possible starting point
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> seen;

            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.find(word) != wordCount.end()) {
                    seen[word]++;
                    count++;

                    // If the word appears more than it should, move `left` forward
                    while (seen[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Check if we found a valid concatenated substring
                    if (count == totalWords) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the window
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};
    vector<int> result1 = sol.findSubstring(s1, words1);
    cout << "Test Case 1 Output: ";
    for (int index : result1) {
        cout << index << " ";
    }
    cout << endl;

    // Test case 2
    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};
    vector<int> result2 = sol.findSubstring(s2, words2);
    cout << "Test Case 2 Output: ";
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;

    // Test case 3
    string s3 = "barfoofoobarthefoobarman";
    vector<string> words3 = {"bar", "foo", "the"};
    vector<int> result3 = sol.findSubstring(s3, words3);
    cout << "Test Case 3 Output: ";
    for (int index : result3) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}

