#include <iostream>
#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructHelper(grid, 0, 0, grid.size());
    }
    
private:
    // Recursive helper function to construct quad-tree
    Node* constructHelper(vector<vector<int>>& grid, int row, int col, int size) {
        // Base case: If the grid is a single cell, it's a leaf node.
        if (size == 1) {
            return new Node(grid[row][col] == 1, true);
        }

        // Divide the current grid into four sub-grids
        int newSize = size / 2;
        Node* topLeft = constructHelper(grid, row, col, newSize);
        Node* topRight = constructHelper(grid, row, col + newSize, newSize);
        Node* bottomLeft = constructHelper(grid, row + newSize, col, newSize);
        Node* bottomRight = constructHelper(grid, row + newSize, col + newSize, newSize);

        // If all four sub-grids are leaves and have the same value, merge them into one leaf
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val) {
            bool val = topLeft->val;
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            return new Node(val, true);
        }
        
        // Otherwise, create an internal node with four children
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};

// Function to print the Quad-Tree structure
void printQuadTree(Node* node, int indent = 0) {
    if (!node) return;
    
    // Indentation for visual hierarchy
    for (int i = 0; i < indent; ++i) cout << "  ";
    
    // Print current node
    cout << "Node(" << "isLeaf: " << node->isLeaf << ", val: " << node->val << ")\n";
    
    // If it's not a leaf, print its children
    if (!node->isLeaf) {
        printQuadTree(node->topLeft, indent + 1);
        printQuadTree(node->topRight, indent + 1);
        printQuadTree(node->bottomLeft, indent + 1);
        printQuadTree(node->bottomRight, indent + 1);
    }
}

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0}
    };
    
    Node* root = solution.construct(grid);
    
    // Print the Quad-Tree structure
    cout << "Quad-Tree structure:\n";
    printQuadTree(root);

    return 0;
}

