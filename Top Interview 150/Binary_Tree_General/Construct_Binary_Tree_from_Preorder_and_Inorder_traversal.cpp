#include <iostream>
#include <vector>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        
        // Create a map to store indices of elements in the inorder array for quick access
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        // Recursive helper function
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorder_map);
    }
    
private:
    TreeNode* buildTreeHelper(const vector<int>& preorder, int preStart, int preEnd, 
                              const vector<int>& inorder, int inStart, int inEnd, 
                              unordered_map<int, int>& inorder_map) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;  // Base case: no nodes in this subtree
        }

        // The first element of preorder is the root for the current subtree
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root index in the inorder array
        int inRootIdx = inorder_map[rootVal];

        // Left subtree size is the number of nodes to the left of the root in inorder array
        int leftSize = inRootIdx - inStart;

        // Recursively build the left subtree
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSize, inorder, inStart, inRootIdx - 1, inorder_map);

        // Recursively build the right subtree
        root->right = buildTreeHelper(preorder, preStart + leftSize + 1, preEnd, inorder, inRootIdx + 1, inEnd, inorder_map);

        return root;  // Return the constructed subtree root
    }
};

// Utility function to print the tree in preorder traversal
void printPreorder(TreeNode* node) {
    if (node == nullptr) return;
    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

// Utility function to delete tree nodes to avoid memory leaks
void deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Solution solution;

    // Test Case 1: Basic test case
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    TreeNode* root1 = solution.buildTree(preorder1, inorder1);
    cout << "Preorder of constructed tree (should match input): ";
    printPreorder(root1);
    cout << "\n";
    deleteTree(root1);

    // Test Case 2: Single node tree
    vector<int> preorder2 = {-1};
    vector<int> inorder2 = {-1};
    TreeNode* root2 = solution.buildTree(preorder2, inorder2);
    cout << "Preorder of constructed tree (single node): ";
    printPreorder(root2);
    cout << "\n";
    deleteTree(root2);

    // Test Case 3: Left-skewed tree
    vector<int> preorder3 = {4, 3, 2, 1};
    vector<int> inorder3 = {1, 2, 3, 4};
    TreeNode* root3 = solution.buildTree(preorder3, inorder3);
    cout << "Preorder of constructed left-skewed tree: ";
    printPreorder(root3);
    cout << "\n";
    deleteTree(root3);

    // Test Case 4: Right-skewed tree
    vector<int> preorder4 = {1, 2, 3, 4};
    vector<int> inorder4 = {1, 2, 3, 4};
    TreeNode* root4 = solution.buildTree(preorder4, inorder4);
    cout << "Preorder of constructed right-skewed tree: ";
    printPreorder(root4);
    cout << "\n";
    deleteTree(root4);

    return 0;
}

