#include <iostream>
#include <vector>
#include <algorithm>
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
    int maxLength = 0; // To store the longest ZigZag path length

    // Helper function to perform DFS
    void dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return; // If the node is null, return
        maxLength = max(maxLength, length); // Update maxLength with the current length
        if (isLeft) {
            // If moving left, explore the left child with a direction switch
            dfs(node->left, false, length + 1);
            // Reset length when exploring the right child
            dfs(node->right, true, 1);
        } else {
            // If moving right, explore the right child with a direction switch
            dfs(node->right, true, length + 1);
            // Reset length when exploring the left child
            dfs(node->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);  // Start DFS assuming the initial direction is left
        dfs(root, false, 0); // Start DFS assuming the initial direction is right
        return maxLength;    // Return the maximum ZigZag length found
    }
};

// Utility function to create a tree from a vector
TreeNode* createTree(const vector<int>& vals, int index) {
    if (index >= vals.size() || vals[index] == -1) return nullptr;
    TreeNode* root = new TreeNode(vals[index]);
    root->left = createTree(vals, 2 * index + 1);
    root->right = createTree(vals, 2 * index + 2);
    return root;
}

// Main function to test the solution
int main() {
    Solution solution;

    // Test case 1
    vector<int> vals1 = {1, -1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, 1};
    TreeNode* root1 = createTree(vals1, 0);
    cout << "Longest ZigZag Path Length (Test Case 1): " << solution.longestZigZag(root1) << endl;

    // Test case 2
    vector<int> vals2 = {1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1};
    TreeNode* root2 = createTree(vals2, 0);
    cout << "Longest ZigZag Path Length (Test Case 2): " << solution.longestZigZag(root2) << endl;

    // Test case 3
    vector<int> vals3 = {1};
    TreeNode* root3 = createTree(vals3, 0);
    cout << "Longest ZigZag Path Length (Test Case 3): " << solution.longestZigZag(root3) << endl;

    return 0;
}

