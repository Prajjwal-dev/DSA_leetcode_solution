#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Trie Node definition
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // Map to store child nodes
    bool isEndOfWord; // Flag to indicate end of word

    TrieNode() : isEndOfWord(false) {}
};

class WordDictionary {
private:
    TrieNode* root; // Root of the Trie

    // Helper function for recursive search with '.' support
    bool searchInNode(string word, TrieNode* node, int index) {
        if (index == word.size()) {
            return node->isEndOfWord; // Check if it's a complete word
        }
        
        char ch = word[index];
        
        if (ch == '.') { // Wildcard case
            for (auto& [key, childNode] : node->children) {
                if (searchInNode(word, childNode, index + 1)) {
                    return true; // Match found
                }
            }
            return false; // No matches found
        } else { // Regular character case
            if (node->children.find(ch) == node->children.end()) {
                return false; // Character not found
            }
            return searchInNode(word, node->children[ch], index + 1);
        }
    }

public:
    // Initialize the WordDictionary object
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word to the data structure
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode(); // Add new node if character not found
            }
            node = node->children[ch]; // Move to the child node
        }
        node->isEndOfWord = true; // Mark the end of the word
    }

    // Returns true if the word matches any word in the Trie, allowing '.' wildcard
    bool search(string word) {
        return searchInNode(word, root, 0);
    }
};

// Main function to test the WordDictionary class
int main() {
    WordDictionary wordDictionary;

    // Add words "bad", "dad", and "mad"
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << "Added words 'bad', 'dad', and 'mad' to the WordDictionary.\n";

    // Test cases for search function
    cout << (wordDictionary.search("pad") ? "Found 'pad'\n" : "'pad' not found\n");
    cout << (wordDictionary.search("bad") ? "Found 'bad'\n" : "'bad' not found\n");
    cout << (wordDictionary.search(".ad") ? "Found '.ad'\n" : "'.ad' not found\n");
    cout << (wordDictionary.search("b..") ? "Found 'b..'\n" : "'b..' not found\n");

    return 0;
}

