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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null, or root is one of the nodes (p or q), return root
        if (!root || root == p || root == q) return root;
        
        // Recur for left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right are non-null, root is the LCA
        if (left && right) return root;
        
        // Otherwise, return the non-null child (either left or right)
        return left ? left : right;
    }
};

// Helper function to create a binary tree for testing
TreeNode* insertLevelOrder(vector<int> arr, TreeNode* root, int i, int n) {
    if (i < n && arr[i] != -1) {
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Helper function to find a node by value
TreeNode* findNode(TreeNode* root, int value) {
    if (!root) return nullptr;
    if (root->val == value) return root;
    TreeNode* leftSearch = findNode(root->left, value);
    return leftSearch ? leftSearch : findNode(root->right, value);
}

int main() {
    // Sample binary tree
    vector<int> treeData = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* root = insertLevelOrder(treeData, root, 0, treeData.size());

    // Test cases
    Solution solution;
    TreeNode* p = findNode(root, 5);  // Node with value 5
    TreeNode* q = findNode(root, 1);  // Node with value 1

    TreeNode* lca1 = solution.lowestCommonAncestor(root, p, q);
    cout << "LCA of 5 and 1 is: " << (lca1 ? lca1->val : -1) << endl;

    p = findNode(root, 5);  // Node with value 5
    q = findNode(root, 4);  // Node with value 4

    TreeNode* lca2 = solution.lowestCommonAncestor(root, p, q);
    cout << "LCA of 5 and 4 is: " << (lca2 ? lca2->val : -1) << endl;

    p = findNode(root, 1);  // Node with value 1
    q = findNode(root, 2);  // Node with value 2

    TreeNode* lca3 = solution.lowestCommonAncestor(root, p, q);
    cout << "LCA of 1 and 2 is: " << (lca3 ? lca3->val : -1) << endl;

    return 0;
}

