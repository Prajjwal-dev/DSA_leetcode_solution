#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        // Return empty result if the root is null
        if (!root) return result;

        // Queue to hold nodes at each level
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; // Flag to track the direction of traversal

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Determine the position to insert the value based on the direction
                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = node->val;

                // Enqueue child nodes for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // After processing the level, flip the traversal direction
            result.push_back(currentLevel);
            leftToRight = !leftToRight;
        }
        
        return result;
    }
};

// Helper function to create test cases and run the solution
int main() {
    Solution solution;

    // Example 1: Tree [3,9,20,null,null,15,7]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    
    vector<vector<int>> result1 = solution.zigzagLevelOrder(root1);
    cout << "Zigzag Level Order Traversal of Example 1: ";
    for (const auto& level : result1) {
        cout << "[ ";
        for (int val : level) cout << val << " ";
        cout << "] ";
    }
    cout << endl;

    // Example 2: Tree [1]
    TreeNode* root2 = new TreeNode(1);
    vector<vector<int>> result2 = solution.zigzagLevelOrder(root2);
    cout << "Zigzag Level Order Traversal of Example 2: ";
    for (const auto& level : result2) {
        cout << "[ ";
        for (int val : level) cout << val << " ";
        cout << "] ";
    }
    cout << endl;

    // Example 3: Empty tree []
    TreeNode* root3 = nullptr;
    vector<vector<int>> result3 = solution.zigzagLevelOrder(root3);
    cout << "Zigzag Level Order Traversal of Example 3: ";
    for (const auto& level : result3) {
        cout << "[ ";
        for (int val : level) cout << val << " ";
        cout << "] ";
    }
    cout << endl;

    return 0;
}

