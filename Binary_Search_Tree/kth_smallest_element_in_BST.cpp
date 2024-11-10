#include <iostream>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st; // Stack to hold nodes for in-order traversal
        TreeNode* current = root;
        int count = 0; // Counter to track the number of nodes visited

        // In-order traversal using a stack
        while (current != nullptr || !st.empty()) {
            // Go to the leftmost node
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            
            // Current node is the leftmost node
            current = st.top();
            st.pop();
            count++; // Increment the count as we visit the node
            
            // Check if we have found the kth smallest element
            if (count == k) {
                return current->val;
            }

            // Move to the right subtree
            current = current->right;
        }
        
        return -1; // In case k is out of bounds, though the constraints guarantee 1 <= k <= n
    }
};

// Helper function to insert nodes into the BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}

// Main function to test the code
int main() {
    Solution solution;
    TreeNode* root = nullptr;

    // Example 1: root = [3,1,4,null,2], k = 1
    root = insertIntoBST(root, 3);
    insertIntoBST(root, 1);
    insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    int k = 1;
    cout << "The " << k << "th smallest value is: " << solution.kthSmallest(root, k) << endl; // Output should be 1

    // Reset for next example
    root = nullptr;

    // Example 2: root = [5,3,6,2,4,null,null,1], k = 3
    root = insertIntoBST(root, 5);
    insertIntoBST(root, 3);
    insertIntoBST(root, 6);
    insertIntoBST(root, 2);
    insertIntoBST(root, 4);
    insertIntoBST(root, 1);
    k = 3;
    cout << "The " << k << "th smallest value is: " << solution.kthSmallest(root, k) << endl; // Output should be 3

    return 0;
}

