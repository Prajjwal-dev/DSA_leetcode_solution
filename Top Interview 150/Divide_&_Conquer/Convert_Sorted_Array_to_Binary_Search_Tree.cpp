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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        // Base case: if the left index is greater than the right, return nullptr
        if (left > right) {
            return nullptr;
        }

        // Choose the middle element to keep the tree balanced
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        // Recursively build the left and right subtrees
        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);

        return node;
    }
};

// Function to print a tree in order (for testing)
void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = solution.sortedArrayToBST(nums);

    // Output the tree in in-order traversal to confirm the BST properties
    printInOrder(root);
    return 0;
}

