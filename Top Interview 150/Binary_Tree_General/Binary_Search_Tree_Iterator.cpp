#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    // Constructor that initializes the stack and performs controlled traversal to the leftmost node
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    // Returns the next smallest element in the BST
    int next() {
        TreeNode* node = nodes.top(); // Access the top node in the stack
        nodes.pop(); // Remove this node from the stack as it has been processed
        
        if (node->right) {
            pushAllLeft(node->right); // Move to the right child and push all left children of this subtree
        }
        
        return node->val; // Return the value of the current node
    }
    
    // Returns true if there exists a next element in the BST traversal
    bool hasNext() {
        return !nodes.empty(); // If stack is not empty, there are more nodes to process
    }

private:
    stack<TreeNode*> nodes; // Stack to hold the nodes for controlled in-order traversal

    // Helper function to push all left nodes of a subtree to the stack
    void pushAllLeft(TreeNode* node) {
        while (node) {
            nodes.push(node); // Push current node
            node = node->left; // Move to the left child
        }
    }
};

/**
 * Utility function to build a sample tree:
 *         7
 *        / \
 *       3   15
 *          /  \
 *         9    20
 */
TreeNode* buildTree() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    return root;
}

int main() {
    TreeNode* root = buildTree(); // Create a sample tree
    BSTIterator bSTIterator(root);

    // Run all test cases as per the example
    cout << bSTIterator.next() << endl;    // Should return 3
    cout << bSTIterator.next() << endl;    // Should return 7
    cout << bSTIterator.hasNext() << endl; // Should return true
    cout << bSTIterator.next() << endl;    // Should return 9
    cout << bSTIterator.hasNext() << endl; // Should return true
    cout << bSTIterator.next() << endl;    // Should return 15
    cout << bSTIterator.hasNext() << endl; // Should return true
    cout << bSTIterator.next() << endl;    // Should return 20
    cout << bSTIterator.hasNext() << endl; // Should return false

    return 0;
}

