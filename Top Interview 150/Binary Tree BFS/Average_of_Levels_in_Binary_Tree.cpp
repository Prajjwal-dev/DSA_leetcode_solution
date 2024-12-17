#include <iostream>
#include <vector>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root) return result;  // If the tree is empty, return an empty result
        
        queue<TreeNode*> q;
        q.push(root);  // Start BFS with the root node

        while (!q.empty()) {
            int levelSize = q.size();
            double levelSum = 0;  // To store the sum of nodes at the current level

            // Process all nodes in the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                levelSum += current->val;  // Add the current node's value to the level sum

                // Enqueue left and right children, if they exist
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            // Calculate the average for the current level and add to result
            result.push_back(levelSum / levelSize);
        }
        
        return result;
    }
};

// Test cases in main function
int main() {
    // Example 1: root = [3,9,20,null,null,15,7]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    Solution solution;
    vector<double> result1 = solution.averageOfLevels(root1);
    cout << "Output for Example 1: ";
    for (double val : result1) cout << val << " ";  // Expected: 3.00000 14.50000 11.00000
    cout << endl;

    // Example 2: root = [3,9,20,15,7]
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->left->left = new TreeNode(15);
    root2->left->right = new TreeNode(7);

    vector<double> result2 = solution.averageOfLevels(root2);
    cout << "Output for Example 2: ";
    for (double val : result2) cout << val << " ";  // Expected: 3.00000 14.50000 11.00000
    cout << endl;

    // Example 3: root = [5]
    TreeNode* root3 = new TreeNode(5);

    vector<double> result3 = solution.averageOfLevels(root3);
    cout << "Output for Example 3: ";
    for (double val : result3) cout << val << " ";  // Expected: 5.00000
    cout << endl;

    return 0;
}

