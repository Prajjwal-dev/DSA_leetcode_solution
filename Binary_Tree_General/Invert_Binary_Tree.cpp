#include <iostream>
using namespace std;

// Definition of TreeNode structure
struct TreeNode {
    int val;               // Value of the node
    TreeNode *left;        // Pointer to the left child
    TreeNode *right;       // Pointer to the right child
    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // Constructor when value is passed
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor when value, left child, and right child are passed
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to invert a binary tree
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if the root is null, return null
        if (root == nullptr) return nullptr;
        
        // Recursively invert the left and right subtrees
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        
        // Swap the left and right children
        root->left = right;
        root->right = left;
        
        // Return the root of the inverted tree
        return root;
    }
};

// Function to print the binary tree in in-order traversal (left, root, right)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create a binary tree: root = [4, 2, 7, 1, 3, 6, 9]
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    Solution solution;

    cout << "Original tree (in-order): ";
    inorderTraversal(root);  // Print the original tree
    cout << endl;

    // Invert the binary tree
    solution.invertTree(root);

    cout << "Inverted tree (in-order): ";
    inorderTraversal(root);  // Print the inverted tree
    cout << endl;

    return 0;
}

