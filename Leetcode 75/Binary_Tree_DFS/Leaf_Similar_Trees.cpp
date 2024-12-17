#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to collect leaf nodes
    void getLeafSequence(TreeNode* root, vector<int>& leafSequence) {
        if (!root) return;  // Base case: if the node is null, do nothing
        
        if (!root->left && !root->right) {  // If it's a leaf node
            leafSequence.push_back(root->val);
            return;
        }
        
        // Recursively process the left and right subtrees
        getLeafSequence(root->left, leafSequence);
        getLeafSequence(root->right, leafSequence);
    }
    
    // Function to compare leaf sequences of two trees
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;  // Vectors to store leaf sequences
        
        getLeafSequence(root1, leaves1);  // Collect leaf nodes for tree 1
        getLeafSequence(root2, leaves2);  // Collect leaf nodes for tree 2
        
        return leaves1 == leaves2;  // Compare the leaf sequences
    }
};

// Helper function to create a simple binary tree (for demonstration purposes)
TreeNode* createTree(vector<int> values, int index) {
    if (index >= values.size() || values[index] == -1) return nullptr;
    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);  // Left child
    root->right = createTree(values, 2 * index + 2);  // Right child
    return root;
}

// Function to print a vector (for debugging purposes)
void printVector(const vector<int>& v) {
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test case 1: Trees with same leaf sequence
    vector<int> tree1 = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
    vector<int> tree2 = {3, 5, 1, 6, 7, 4, 2, -1, -1, -1, -1, -1, -1, 9, 8};
    TreeNode* root1 = createTree(tree1, 0);
    TreeNode* root2 = createTree(tree2, 0);
    
    cout << "Test case 1: ";
    cout << (solution.leafSimilar(root1, root2) ? "True" : "False") << endl;  // Output: True
    
    // Test case 2: Trees with different leaf sequences
    vector<int> tree3 = {1, 2, 3};
    vector<int> tree4 = {1, 3, 2};
    TreeNode* root3 = createTree(tree3, 0);
    TreeNode* root4 = createTree(tree4, 0);
    
    cout << "Test case 2: ";
    cout << (solution.leafSimilar(root3, root4) ? "True" : "False") << endl;  // Output: False
    
    return 0;
}

