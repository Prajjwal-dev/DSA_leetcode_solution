#include <iostream>
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
    int sumNumbers(TreeNode* root) {
        return sumRootToLeaf(root, 0);
    }

private:
    int sumRootToLeaf(TreeNode* node, int currentSum) {
        if (node == nullptr) return 0;  // base case for null node
        
        currentSum = currentSum * 10 + node->val;  // update the path sum by appending current node's value

        // if it's a leaf node, return the current path sum
        if (node->left == nullptr && node->right == nullptr) {
            return currentSum;
        }
        
        // recursively calculate the sum for left and right subtree paths
        int leftSum = sumRootToLeaf(node->left, currentSum);
        int rightSum = sumRootToLeaf(node->right, currentSum);
        
        return leftSum + rightSum;  // total sum for this node
    }
};

// Utility function to build a basic tree for testing
TreeNode* buildTree() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = buildTree();
    int result = solution.sumNumbers(root);
    cout << "Total Sum of Root-to-Leaf Numbers: " << result << endl;
    return 0;
}

