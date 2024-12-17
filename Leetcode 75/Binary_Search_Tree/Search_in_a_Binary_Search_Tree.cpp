#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with the searchBST function
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if root is null or we find the node
        if (root == nullptr || root->val == val) {
            return root;
        }

        // If the value to search is smaller, go to the left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        // If the value to search is larger, go to the right subtree
        return searchBST(root->right, val);
    }
};

// Helper function to create a sample tree
TreeNode* createSampleTree() {
    // Creating the tree:
    //        4
    //       / \
    //      2   7
    //     / \
    //    1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    return root;
}

// Function to print the tree in-order (for testing purposes)
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Main function to demonstrate test cases
int main() {
    Solution solution;
    TreeNode* root = createSampleTree();

    int searchVal1 = 2;
    TreeNode* result1 = solution.searchBST(root, searchVal1);
    if (result1) {
        cout << "Subtree rooted at node " << searchVal1 << ": ";
        inorder(result1);
    } else {
        cout << "Node with value " << searchVal1 << " not found.";
    }
    cout << endl;

    int searchVal2 = 5;
    TreeNode* result2 = solution.searchBST(root, searchVal2);
    if (result2) {
        cout << "Subtree rooted at node " << searchVal2 << ": ";
        inorder(result2);
    } else {
        cout << "Node with value " << searchVal2 << " not found.";
    }
    cout << endl;

    return 0;
}

