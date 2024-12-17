#include <iostream>
#include <unordered_map>
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
    int dfs(TreeNode* node, int targetSum, unordered_map<long long, int>& prefixSum, long long currentSum) {
        if (!node) return 0; // Base case: if the node is null, return 0

        // Add the current node's value to the running sum
        currentSum += node->val;

        // Check how many times the (currentSum - targetSum) exists in prefixSum
        int paths = prefixSum[currentSum - targetSum];

        // Update the prefixSum with the currentSum
        prefixSum[currentSum]++;

        // Recur for left and right subtrees
        paths += dfs(node->left, targetSum, prefixSum, currentSum);
        paths += dfs(node->right, targetSum, prefixSum, currentSum);

        // Backtrack: remove the current node's value from prefixSum
        prefixSum[currentSum]--;

        return paths;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1; // Base case for when the path starts from the root
        return dfs(root, targetSum, prefixSum, 0);
    }
};

int main() {
    // Example 1: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(-3);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(2);
    root1->right->right = new TreeNode(11);
    root1->left->left->left = new TreeNode(3);
    root1->left->left->right = new TreeNode(-2);
    root1->left->right->right = new TreeNode(1);

    // Example 2: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(8);
    root2->left->left = new TreeNode(11);
    root2->right->left = new TreeNode(13);
    root2->right->right = new TreeNode(4);
    root2->left->left->left = new TreeNode(7);
    root2->left->left->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(5);
    root2->right->right->right = new TreeNode(1);

    // Create a Solution object
    Solution solution;

    // Run the pathSum function on each example
    cout << "Example 1: " << solution.pathSum(root1, 8) << endl; // Output: 3
    cout << "Example 2: " << solution.pathSum(root2, 22) << endl; // Output: 3

    return 0;
}

