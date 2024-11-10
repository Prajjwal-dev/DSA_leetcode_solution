#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* current = root;  // Start from the root node.
        
        while (current) {
            Node* dummy = new Node();  // Dummy node for the level below.
            Node* tail = dummy;  // Tail is used to connect nodes at the next level.

            // Iterate over the current level nodes.
            while (current) {
                if (current->left) {
                    tail->next = current->left;  // Connect tail to the current's left child.
                    tail = tail->next;  // Move tail.
                }
                if (current->right) {
                    tail->next = current->right;  // Connect tail to the current's right child.
                    tail = tail->next;  // Move tail.
                }
                current = current->next;  // Move to the next node in the current level.
            }
            
            // Move to the next level, which starts at dummy->next.
            current = dummy->next;
        }

        return root;  // Return the modified tree.
    }
};

// Helper function to print level order using 'next' pointers.
void printLevelOrderWithNext(Node* root) {
    Node* level = root;
    while (level) {
        Node* current = level;
        while (current) {
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "# ";
        level = level->left ? level->left : (level->right ? level->right : nullptr);
    }
    cout << endl;
}

int main() {
    // Construct the tree [1,2,3,4,5,null,7]
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    Solution solution;
    root = solution.connect(root);

    // Test by printing level order with next pointers
    cout << "Level order with next pointers: ";
    printLevelOrderWithNext(root);

    // Clean up dynamically allocated nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

