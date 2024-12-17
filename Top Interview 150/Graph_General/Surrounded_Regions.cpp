#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // DFS function to mark 'O's connected to the boundary
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }
        
        // Mark current 'O' as 'S' (safe)
        board[i][j] = 'S';
        
        // Visit all four adjacent cells
        dfs(board, i + 1, j); // Down
        dfs(board, i - 1, j); // Up
        dfs(board, i, j + 1); // Right
        dfs(board, i, j - 1); // Left
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // Step 1: Mark all 'O's on the boundary and their connected 'O's as safe (S)
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);         // Left boundary
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);  // Right boundary
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);         // Top boundary
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j); // Bottom boundary
        }
        
        // Step 2: Convert the remaining 'O's to 'X' (these are surrounded regions)
        // and revert 'S' (safe regions) back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';  // Capture surrounded 'O'
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O';  // Revert 'S' back to 'O'
                }
            }
        }
    }
};

int main() {
    Solution sol;
    
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    
    sol.solve(board1);
    
    cout << "Modified board1: " << endl;
    for (const auto& row : board1) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    vector<vector<char>> board2 = {
        {'X'}
    };
    
    sol.solve(board2);
    
    cout << "Modified board2: " << endl;
    for (const auto& row : board2) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    return 0;
}

