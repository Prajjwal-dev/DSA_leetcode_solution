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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_map;
        
        // Map to store the indices of inorder elements for quick lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        // Call the recursive helper function
        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorder_map);
    }
    
private:
    TreeNode* buildTreeHelper(const vector<int>& inorder, int inStart, int inEnd, 
                              const vector<int>& postorder, int postStart, int postEnd, 
                              unordered_map<int, int>& inorder_map) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr; // Base case: no elements to process
        }

        // The last element in postorder is the root for the current subtree
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root index in the inorder array
        int inRootIdx = inorder_map[rootVal];

        // Left subtree size is the number of nodes to the left of the root in inorder array
        int leftSize = inRootIdx - inStart;

        // Recursively build the left subtree
        root->left = buildTreeHelper(inorder, inStart, inRootIdx - 1, postorder, postStart, postStart + leftSize - 1, inorder_map);

        // Recursively build the right subtree
        root->right = buildTreeHelper(inorder, inRootIdx + 1, inEnd, postorder, postStart + leftSize, postEnd - 1, inorder_map);

        return root; // Return the constructed subtree root
    }
};

// Utility function to print the tree in inorder traversal
void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Utility function to delete the tree nodes to avoid memory leaks
void deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Solution solution;

    // Test Case 1: Basic example
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    vector<int> postorder1 = {9, 15, 7, 20, 3};
    TreeNode* root1 = solution.buildTree(inorder1, postorder1);
    cout << "Inorder of constructed tree (should match input): ";
    printInorder(root1);
    cout << "\n";
    deleteTree(root1);

    // Test Case 2: Single node tree
    vector<int> inorder2 = {-1};
    vector<int> postorder2 = {-1};
    TreeNode* root2 = solution.buildTree(inorder2, postorder2);
    cout << "Inorder of constructed tree (single node): ";
    printInorder(root2);
    cout << "\n";
    deleteTree(root2);

    // Test Case 3: Left-skewed tree
    vector<int> inorder3 = {1, 2, 3, 4};
    vector<int> postorder3 = {1, 2, 3, 4};
    TreeNode* root3 = solution.buildTree(inorder3, postorder3);
    cout << "Inorder of constructed left-skewed tree: ";
    printInorder(root3);
    cout << "\n";
    deleteTree(root3);

    // Test Case 4: Right-skewed tree
    vector<int> inorder4 = {4, 3, 2, 1};
    vector<int> postorder4 = {4, 3, 2, 1};
    TreeNode* root4 = solution.buildTree(inorder4, postorder4);
    cout << "Inorder of constructed right-skewed tree: ";
    printInorder(root4);
    cout << "\n";
    deleteTree(root4);

    return 0;
}

