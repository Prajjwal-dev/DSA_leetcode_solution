#include <iostream>
using namespace std;

// Definition for a binary tree node
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: If the current node is null, return false
        if (!root)
            return false;
        
        // If it's a leaf node (no left or right child)
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        
        // Recurse down to the left and right children, reducing the targetSum
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};

// Helper function to create the binary tree using an array
TreeNode* insertLevelOrder(int arr[], int i, int n) {
    TreeNode* root = nullptr;
    if (i < n && arr[i] != -1) {  // Only insert non-null nodes (-1 means null)
        root = new TreeNode(arr[i]);
        
        // Insert left child
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        
        // Insert right child
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

// Driver code to test the solution
int main() {
    // Input tree: [5,4,8,11,null,13,4,7,2,null,null,null,1]
    int arr[] = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};  // -1 denotes null
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 22;
    
    // Create the tree
    TreeNode* root = insertLevelOrder(arr, 0, n);
    
    // Create Solution object and check for path sum
    Solution solution;
    if (solution.hasPathSum(root, targetSum)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}

