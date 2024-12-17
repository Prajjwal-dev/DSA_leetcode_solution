#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <functional> // Include this for std::function
using namespace std;

class TrieNode {
public:
    TrieNode* children[26] = {nullptr}; // Pointers to child nodes
    string word = "";                  // Store the complete word at the end node
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = word; // Mark the end of the word
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Create a Trie and insert all words
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        // Lambda for backtracking
        std::function<void(int, int, TrieNode*)> backtrack = [&](int r, int c, TrieNode* node) {
            // Boundary check and visited cell handling
            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] == '#') return;

            char letter = board[r][c];
            TrieNode* nextNode = node->children[letter - 'a'];
            if (!nextNode) return; // If the letter is not in Trie, stop searching

            // If there's a word, add it to the result
            if (!nextNode->word.empty()) {
                result.push_back(nextNode->word);
                nextNode->word = ""; // Avoid duplicate words
            }

            // Mark the cell as visited
            board[r][c] = '#';

            // Explore all 4 directions
            backtrack(r + 1, c, nextNode);
            backtrack(r - 1, c, nextNode);
            backtrack(r, c + 1, nextNode);
            backtrack(r, c - 1, nextNode);

            // Restore the cell
            board[r][c] = letter;
        };

        // Start backtracking from each cell
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                backtrack(r, c, trie.root);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<char>> board1 = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words1 = {"oath", "pea", "eat", "rain"};
    vector<string> result1 = sol.findWords(board1, words1);
    cout << "Test Case 1 Result: ";
    for (const string& word : result1) cout << word << " ";
    cout << endl;

    // Test case 2
    vector<vector<char>> board2 = {
        {'a', 'b'},
        {'c', 'd'}
    };
    vector<string> words2 = {"abcb"};
    vector<string> result2 = sol.findWords(board2, words2);
    cout << "Test Case 2 Result: ";
    for (const string& word : result2) cout << word << " ";
    cout << endl;

    return 0;
}

