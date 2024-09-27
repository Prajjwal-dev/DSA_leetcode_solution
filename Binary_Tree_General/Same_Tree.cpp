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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both trees are empty, they are the same
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If one tree is empty and the other is not, they are not the same
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // If the current node values are not equal, the trees are not the same
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check if the left subtrees and right subtrees are the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Example 1: p = [1,2,3], q = [1,2,3]
    TreeNode* p1 = newNode(1);
    p1->left = newNode(2);
    p1->right = newNode(3);

    TreeNode* q1 = newNode(1);
    q1->left = newNode(2);
    q1->right = newNode(3);

    Solution solution;
    cout << "Example 1: " << (solution.isSameTree(p1, q1) ? "true" : "false") << endl;

    // Example 2: p = [1,2], q = [1,null,2]
    TreeNode* p2 = newNode(1);
    p2->left = newNode(2);

    TreeNode* q2 = newNode(1);
    q2->right = newNode(2);

    cout << "Example 2: " << (solution.isSameTree(p2, q2) ? "true" : "false") << endl;

    // Example 3: p = [1,2,1], q = [1,1,2]
    TreeNode* p3 = newNode(1);
    p3->left = newNode(2);
    p3->right = newNode(1);

    TreeNode* q3 = newNode(1);
    q3->left = newNode(1);
    q3->right = newNode(2);

    cout << "Example 3: " << (solution.isSameTree(p3, q3) ? "true" : "false") << endl;

    return 0;
}

