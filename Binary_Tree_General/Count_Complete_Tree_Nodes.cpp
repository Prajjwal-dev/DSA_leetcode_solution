#include <iostream>
#include <cmath>

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        // Calculate left depth
        int leftDepth = getDepth(root->left);
        // Calculate right depth
        int rightDepth = getDepth(root->right);

        if (leftDepth == rightDepth) {
            // Left subtree is perfect
            return (1 << leftDepth) + countNodes(root->right);
        } else {
            // Right subtree is perfect
            return (1 << rightDepth) + countNodes(root->left);
        }
    }

private:
    // Helper function to calculate depth of the leftmost path
    int getDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            node = node->left;
            depth++;
        }
        return depth;
    }
};

// Main function to test the solution
int main() {
    // Example 1: root = [1,2,3,4,5,6]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);

    Solution sol;
    std::cout << "Number of nodes in the tree: " << sol.countNodes(root1) << std::endl; // Output: 6

    // Example 2: root = []
    TreeNode* root2 = nullptr;
    std::cout << "Number of nodes in the tree: " << sol.countNodes(root2) << std::endl; // Output: 0

    // Example 3: root = [1]
    TreeNode* root3 = new TreeNode(1);
    std::cout << "Number of nodes in the tree: " << sol.countNodes(root3) << std::endl; // Output: 1

    // Clean up memory (optional)
    delete root1->left->left;
    delete root1->left->right;
    delete root1->left;
    delete root1->right->left;
    delete root1->right;
    delete root1;

    delete root3;

    return 0;
}

