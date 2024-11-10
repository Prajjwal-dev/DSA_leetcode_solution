#include <iostream>
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
    void flatten(TreeNode* root) {
        if (!root) return; // If the root is null, there's nothing to flatten.

        // Flatten the left and right subtree.
        flatten(root->left);
        flatten(root->right);

        // Store the right subtree.
        TreeNode* tempRight = root->right;

        // Attach the left subtree to the root.
        root->right = root->left;
        root->left = nullptr; // Set the left child to null.

        // Find the rightmost node of the newly attached right subtree (originally the left subtree).
        TreeNode* rightmost = root;
        while (rightmost->right) {
            rightmost = rightmost->right; // Traverse to the rightmost node.
        }

        // Attach the original right subtree to the rightmost node.
        rightmost->right = tempRight;
    }
};

// Helper function to print the flattened tree.
void printFlattenedTree(TreeNode* root) {
    while (root) {
        cout << root->val << " -> ";
        root = root->right;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Test case 1: Input: [1,2,5,3,4,null,6]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(6);

    Solution solution;
    solution.flatten(root1);
    cout << "Flattened tree 1: ";
    printFlattenedTree(root1); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr

    // Clean up memory for test case 1
    delete root1->left->left; // 3
    delete root1->left->right; // 4
    delete root1->left; // 2
    delete root1->right->right; // 6
    delete root1->right; // 5
    delete root1; // 1

    // Test case 2: Input: []
    TreeNode* root2 = nullptr;

    solution.flatten(root2);
    cout << "Flattened tree 2: ";
    printFlattenedTree(root2); // Output: nullptr

    // Test case 3: Input: [0]
    TreeNode* root3 = new TreeNode(0);

    solution.flatten(root3);
    cout << "Flattened tree 3: ";
    printFlattenedTree(root3); // Output: 0 -> nullptr

    // Clean up memory for test case 3
    delete root3; // 0

    return 0;
}

