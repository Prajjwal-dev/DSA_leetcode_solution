#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to calculate the total number of distinct solutions
    int totalNQueens(int n) {
        vector<int> board(n, -1); // Stores column positions for queens
        return solve(0, n, board);
    }

private:
    // Recursive function to solve the N-Queens problem
    int solve(int row, int n, vector<int>& board) {
        if (row == n) {
            // If all rows are filled, we have found a valid solution
            return 1;
        }

        int count = 0;
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board)) {
                board[row] = col; // Place the queen at (row, col)
                count += solve(row + 1, n, board); // Recur for the next row
                board[row] = -1; // Backtrack: remove the queen
            }
        }
        return count;
    }

    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(int row, int col, vector<int>& board) {
        for (int i = 0; i < row; i++) {
            // Check for column conflict or diagonal conflict
            if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test case 1: n = 4
    int n = 4;
    cout << "Total solutions for n = " << n << ": " << sol.totalNQueens(n) << endl;

    // Test case 2: n = 1
    n = 1;
    cout << "Total solutions for n = " << n << ": " << sol.totalNQueens(n) << endl;

    // Test case 3: n = 8
    n = 8;
    cout << "Total solutions for n = " << n << ": " << sol.totalNQueens(n) << endl;

    return 0;
}

