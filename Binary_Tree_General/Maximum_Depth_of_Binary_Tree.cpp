#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor to initialize node
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to find maximum depth of the binary tree
    int maxDepth(TreeNode* root) {
        // If the current node is NULL, return depth as 0
        if (root == NULL) {
            return 0;
        }
        
        // Recursively find the depth of left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // Return the maximum depth of the current node by adding 1 to the greater depth
        return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    // Construct the binary tree from the example: [3, 9, 20, null, null, 15, 7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create a Solution object and use it to find the maximum depth
    Solution sol;
    cout << "Maximum depth: " << sol.maxDepth(root) << endl;

    return 0;
}

