#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0; // End word not in list
        
        queue<pair<string, int>> q; // Pair of current word and its transformation step count
        q.push({beginWord, 1});
        
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            // For each character in the word
            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i];
                // Try replacing it with every other character a-z
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (word == endWord) return steps + 1; // Found the end word
                    
                    // If the new word exists in the word set
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, steps + 1});
                        wordSet.erase(word); // Remove it to prevent revisiting
                    }
                }
                word[i] = originalChar; // Restore original character
            }
        }
        return 0; // No valid transformation found
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Valid transformation sequence
    string beginWord1 = "hit";
    string endWord1 = "cog";
    vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << "Test Case 1 - Shortest Transformation Sequence Length: ";
    cout << solution.ladderLength(beginWord1, endWord1, wordList1) << endl;

    // Test Case 2: No valid transformation sequence
    string beginWord2 = "hit";
    string endWord2 = "cog";
    vector<string> wordList2 = {"hot", "dot", "dog", "lot", "log"};
    cout << "Test Case 2 - Shortest Transformation Sequence Length: ";
    cout << solution.ladderLength(beginWord2, endWord2, wordList2) << endl;

    // Test Case 3: Single step transformation
    string beginWord3 = "a";
    string endWord3 = "c";
    vector<string> wordList3 = {"a", "b", "c"};
    cout << "Test Case 3 - Shortest Transformation Sequence Length: ";
    cout << solution.ladderLength(beginWord3, endWord3, wordList3) << endl;

    // Test Case 4: No transformation possible
    string beginWord4 = "aaa";
    string endWord4 = "bbb";
    vector<string> wordList4 = {"aab", "abb", "aba"};
    cout << "Test Case 4 - Shortest Transformation Sequence Length: ";
    cout << solution.ladderLength(beginWord4, endWord4, wordList4) << endl;

    return 0;
}

