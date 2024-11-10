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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;  // If tree is empty, return an empty result
        
        queue<TreeNode*> q;
        q.push(root);  // Start BFS with the root node

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* rightMostNode = nullptr;

            // Process all nodes in the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();

                // Keep track of the last node at the current level
                rightMostNode = current;

                // Enqueue left and right children, if they exist
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            // After finishing the level, add the right-most node to result
            if (rightMostNode) result.push_back(rightMostNode->val);
        }
        
        return result;
    }
};

// Test cases in main function
int main() {
    // Example 1: root = [1,2,3,null,5,null,4]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(5);
    root1->right->right = new TreeNode(4);

    Solution solution;
    vector<int> result1 = solution.rightSideView(root1);
    cout << "Output for Example 1: ";
    for (int val : result1) cout << val << " ";  // Expected: 1 3 4
    cout << endl;

    // Example 2: root = [1,null,3]
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(3);

    vector<int> result2 = solution.rightSideView(root2);
    cout << "Output for Example 2: ";
    for (int val : result2) cout << val << " ";  // Expected: 1 3
    cout << endl;

    // Example 3: root = []
    TreeNode* root3 = nullptr;

    vector<int> result3 = solution.rightSideView(root3);
    cout << "Output for Example 3: ";
    for (int val : result3) cout << val << " ";  // Expected: empty output
    cout << endl;

    return 0;
}

