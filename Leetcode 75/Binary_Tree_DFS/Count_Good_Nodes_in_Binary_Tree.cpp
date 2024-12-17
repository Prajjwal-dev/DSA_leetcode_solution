#include <iostream>
#include <vector>
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

class Solution {
public:
    // Helper function for DFS traversal
    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0; // Base case: if the node is null, return 0

        int good = 0;

        // Check if the current node is "good"
        if (node->val >= maxVal) {
            good = 1; // Increment the count if the node is "good"
        }

        // Update maxVal to the maximum seen so far in the path
        maxVal = max(maxVal, node->val);

        // Recursively calculate good nodes in the left and right subtrees
        good += dfs(node->left, maxVal);
        good += dfs(node->right, maxVal);

        return good;
    }

    int goodNodes(TreeNode* root) {
        // Start the DFS with the root node and its value as the initial maxVal
        return dfs(root, root->val);
    }
};

int main() {
    // Example 1: root = [3, 1, 4, 3, null, 1, 5]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(3);
    root1->right->left = new TreeNode(1);
    root1->right->right = new TreeNode(5);

    // Example 2: root = [3, 3, null, 4, 2]
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(2);

    // Example 3: root = [1]
    TreeNode* root3 = new TreeNode(1);

    // Create a Solution object
    Solution solution;

    // Run the goodNodes function on each example
    cout << "Example 1: " << solution.goodNodes(root1) << endl; // Output: 4
    cout << "Example 2: " << solution.goodNodes(root2) << endl; // Output: 3
    cout << "Example 3: " << solution.goodNodes(root3) << endl; // Output: 1

    return 0;
}

