#include <iostream>
#include <queue>
#include <vector>
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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0; // If the tree is empty, return 0

        queue<TreeNode*> q; // Queue for level-order traversal
        q.push(root);

        int maxSum = root->val; // Initialize maxSum with the root value
        int maxLevel = 1;       // Initialize maxLevel to 1
        int currentLevel = 1;   // Start traversal from level 1

        while (!q.empty()) {
            int levelSum = 0; // Sum of nodes at the current level
            int levelSize = q.size(); // Number of nodes at the current level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val; // Add the value of the current node to levelSum

                // Add children to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Check if this level's sum is the largest
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currentLevel;
            }

            ++currentLevel; // Move to the next level
        }

        return maxLevel; // Return the level with the maximum sum
    }
};

// Utility function to create a binary tree from a vector
TreeNode* createTree(const vector<int>& vals, int index) {
    if (index >= vals.size() || vals[index] == -1) return nullptr;
    TreeNode* root = new TreeNode(vals[index]);
    root->left = createTree(vals, 2 * index + 1);
    root->right = createTree(vals, 2 * index + 2);
    return root;
}

int main() {
    Solution solution;

    // Test case 1
    vector<int> vals1 = {1, 7, 0, 7, -8, -1, -1};
    TreeNode* root1 = createTree(vals1, 0);
    cout << "Max Level Sum (Test Case 1): " << solution.maxLevelSum(root1) << endl;

    // Test case 2
    vector<int> vals2 = {989, -1, 10250, 98693, -89388, -1, -1, -1, -32127};
    TreeNode* root2 = createTree(vals2, 0);
    cout << "Max Level Sum (Test Case 2): " << solution.maxLevelSum(root2) << endl;

    // Test case 3
    vector<int> vals3 = {1};
    TreeNode* root3 = createTree(vals3, 0);
    cout << "Max Level Sum (Test Case 3): " << solution.maxLevelSum(root3) << endl;

    return 0;
}

