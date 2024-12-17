#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Trie Node definition
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // Map to store child nodes
    bool isEndOfWord; // Flag to check if node marks the end of a word

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root; // Root of the Trie

public:
    // Initializes the trie object.
    Trie() {
        root = new TrieNode();
    }

    // Inserts the string `word` into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            // If the character `ch` is not a child of the current node, add it
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            // Move to the next node
            node = node->children[ch];
        }
        node->isEndOfWord = true; // Mark the end of the word
    }

    // Returns true if the string `word` is in the trie, false otherwise.
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            // If the character `ch` is not found, return false
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            // Move to the next node
            node = node->children[ch];
        }
        // Check if the last node marks the end of the word
        return node->isEndOfWord;
    }

    // Returns true if there is any previously inserted word that has the prefix `prefix`.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            // If the character `ch` is not found, return false
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            // Move to the next node
            node = node->children[ch];
        }
        // All characters in `prefix` found, so return true
        return true;
    }
};

// Main function to demonstrate Trie operations
int main() {
    Trie trie; // Initialize the Trie

    // Insert the word "apple"
    trie.insert("apple");
    cout << "Inserted 'apple' into the trie.\n";

    // Search for the word "apple"
    if (trie.search("apple")) {
        cout << "'apple' found in the trie.\n";
    } else {
        cout << "'apple' not found in the trie.\n";
    }

    // Search for the word "app"
    if (trie.search("app")) {
        cout << "'app' found in the trie.\n";
    } else {
        cout << "'app' not found in the trie.\n";
    }

    // Check if any word starts with the prefix "app"
    if (trie.startsWith("app")) {
        cout << "There is a word starting with 'app' in the trie.\n";
    } else {
        cout << "No word starts with 'app' in the trie.\n";
    }

    // Insert the word "app"
    trie.insert("app");
    cout << "Inserted 'app' into the trie.\n";

    // Search for the word "app" again
    if (trie.search("app")) {
        cout << "'app' found in the trie after inserting it.\n";
    } else {
        cout << "'app' not found in the trie.\n";
    }

    return 0;
}

