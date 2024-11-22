#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // To store the global maximum path sum
    int globalMax = INT_MIN;

    // Helper function to calculate the maximum path sum
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            // Base case: if the node is null, return 0
            return 0;
        }

        // Recursively find the maximum path sum for the left and right child
        int leftGain = max(maxGain(node->left), 0); // If negative, use 0
        int rightGain = max(maxGain(node->right), 0); // If negative, use 0

        // Calculate the price of the current path
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the global maximum if the current path sum is greater
        globalMax = max(globalMax, currentPathSum);

        // Return the maximum gain from this node as part of the path
        return node->val + max(leftGain, rightGain);
    }

    // Main function to find the maximum path sum
    int maxPathSum(TreeNode* root) {
        maxGain(root); // Call the helper function
        return globalMax; // Return the result
    }
};

// Function to create a binary tree for testing
TreeNode* createTree() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    // Test case 1: [1,2,3]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    Solution sol;
    cout << "Maximum Path Sum (Test Case 1): " << sol.maxPathSum(root1) << endl;

    // Test case 2: [-10,9,20,null,null,15,7]
    TreeNode* root2 = createTree();
    cout << "Maximum Path Sum (Test Case 2): " << sol.maxPathSum(root2) << endl;

    return 0;
}

