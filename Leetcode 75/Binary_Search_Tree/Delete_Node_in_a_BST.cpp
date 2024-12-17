#include <iostream>
#include <vector>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr; // If the tree is empty, return null

        // Search for the node to delete
        if (key < root->val) {
            // Key lies in the left subtree
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // Key lies in the right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // Node to be deleted is found

            // Case 1: Node has no child or only one child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root; // Delete the current node
                return temp; // Return the right subtree as the new root
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root; // Delete the current node
                return temp; // Return the left subtree as the new root
            }

            // Case 2: Node has two children
            // Find the inorder successor (smallest value in the right subtree)
            TreeNode* successor = getMinValueNode(root->right);

            // Replace the current node's value with the successor's value
            root->val = successor->val;

            // Delete the successor node from the right subtree
            root->right = deleteNode(root->right, successor->val);
        }

        return root; // Return the updated root
    }

private:
    // Helper function to find the minimum value node in a BST
    TreeNode* getMinValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }
};

// Helper function to build a tree from a vector
TreeNode* buildTree(const vector<int>& nodes, int index) {
    if (index >= nodes.size() || nodes[index] == -1) return nullptr; // -1 represents null

    TreeNode* root = new TreeNode(nodes[index]);
    root->left = buildTree(nodes, 2 * index + 1); // Left child index
    root->right = buildTree(nodes, 2 * index + 2); // Right child index

    return root;
}

// Helper function to print a tree in level order
void printTree(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }

    vector<TreeNode*> queue = {root};
    while (!queue.empty()) {
        TreeNode* current = queue[0];
        queue.erase(queue.begin());

        if (current) {
            cout << current->val << " ";
            queue.push_back(current->left);
            queue.push_back(current->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nodes1 = {5, 3, 6, 2, 4, -1, 7};
    TreeNode* root1 = buildTree(nodes1, 0);
    cout << "Original Tree (Test Case 1): ";
    printTree(root1);
    root1 = solution.deleteNode(root1, 3);
    cout << "Tree After Deletion (Key = 3): ";
    printTree(root1); // Expected: [5, 4, 6, 2, null, null, 7]

    // Test Case 2
    vector<int> nodes2 = {5, 3, 6, 2, 4, -1, 7};
    TreeNode* root2 = buildTree(nodes2, 0);
    cout << "Original Tree (Test Case 2): ";
    printTree(root2);
    root2 = solution.deleteNode(root2, 0);
    cout << "Tree After Deletion (Key = 0): ";
    printTree(root2); // Expected: [5, 3, 6, 2, 4, null, 7]

    // Test Case 3
    vector<int> nodes3 = {}; // Empty tree
    TreeNode* root3 = buildTree(nodes3, 0);
    cout << "Original Tree (Test Case 3): ";
    printTree(root3);
    root3 = solution.deleteNode(root3, 0);
    cout << "Tree After Deletion (Key = 0): ";
    printTree(root3); // Expected: []

    return 0;
}

