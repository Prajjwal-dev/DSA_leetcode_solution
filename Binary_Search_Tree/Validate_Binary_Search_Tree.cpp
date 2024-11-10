#include <iostream>
#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to validate the BST
    bool validate(TreeNode* node, long min, long max) {
        // Base case: if the node is null, it's a valid BST by definition
        if (!node) return true;
        
        // Check if the current node's value is within the valid range
        if (node->val <= min || node->val >= max) return false;
        
        // Recur for left and right subtrees with updated ranges
        return validate(node->left, min, node->val) && 
               validate(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};

// Main function to test the solution
int main() {
    // Example 1
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    Solution sol;
    std::cout << "Is the tree a valid BST? " << std::boolalpha << sol.isValidBST(root1) << std::endl; // Output: true

    // Example 2
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    std::cout << "Is the tree a valid BST? " << std::boolalpha << sol.isValidBST(root2) << std::endl; // Output: false

    // Clean up memory (optional)
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left;
    delete root2->right->left;
    delete root2->right->right;
    delete root2->right;
    delete root2;

    return 0;
}

