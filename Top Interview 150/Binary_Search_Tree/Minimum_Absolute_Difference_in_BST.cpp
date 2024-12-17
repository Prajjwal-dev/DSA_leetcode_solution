#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
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
    int minDiff = INT_MAX; // To store the minimum difference
    int prevVal = -1;      // Initialize previous node value as -1 (to handle the first node)

    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return minDiff;
    }

    void inorderTraversal(TreeNode* node) {
        if (!node) return; // Base case: if node is NULL, return

        // Traverse the left subtree
        inorderTraversal(node->left);

        // Process the current node
        if (prevVal != -1) {
            minDiff = min(minDiff, node->val - prevVal); // Calculate the difference with the previous node
        }
        prevVal = node->val; // Update the previous node value to the current node's value

        // Traverse the right subtree
        inorderTraversal(node->right);
    }
};

// Helper function to insert nodes into the BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

// Main function to test the code
int main() {
    Solution solution;
    TreeNode* root = nullptr;

    // Example 1: root = [4,2,6,1,3]
    root = insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 6);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);
    cout << "Minimum absolute difference: " << solution.getMinimumDifference(root) << endl; // Output should be 1

    // Reset for next example
    root = nullptr;

    // Example 2: root = [1,0,48,null,null,12,49]
    root = insertIntoBST(root, 1);
    insertIntoBST(root, 0);
    insertIntoBST(root, 48);
    insertIntoBST(root, 12);
    insertIntoBST(root, 49);
    cout << "Minimum absolute difference: " << solution.getMinimumDifference(root) << endl; // Output should be 1

    return 0;
}

