#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Loop through each cell in the grid as the starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (backtrack(board, word, i, j, 0)) {
                    return true;  // If any path matches the word, return true
                }
            }
        }
        return false;  // If no path matches the word, return false
    }

private:
    // Backtracking function to check for the word in the grid
    bool backtrack(vector<vector<char>>& board, string word, int row, int col, int index) {
        // Base case: If we have matched all characters in the word
        if (index == word.length()) {
            return true;
        }
        
        // Check boundaries and if the current cell matches the current character in the word
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }

        // Save the current character and mark the cell as visited
        char temp = board[row][col];
        board[row][col] = '#';  // Use '#' to mark it as visited
        
        // Explore the four directions: up, down, left, right
        bool found = backtrack(board, word, row - 1, col, index + 1) ||  // up
                     backtrack(board, word, row + 1, col, index + 1) ||  // down
                     backtrack(board, word, row, col - 1, index + 1) ||  // left
                     backtrack(board, word, row, col + 1, index + 1);    // right

        // Restore the current cell back to its original value (backtracking)
        board[row][col] = temp;
        
        return found;  // Return true if we found a valid path, otherwise false
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<vector<char>> board1 = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word1 = "ABCCED";
    cout << (solution.exist(board1, word1) ? "True" : "False") << endl;

    // Test Case 2
    vector<vector<char>> board2 = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word2 = "SEE";
    cout << (solution.exist(board2, word2) ? "True" : "False") << endl;

    // Test Case 3
    vector<vector<char>> board3 = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word3 = "ABCB";
    cout << (solution.exist(board3, word3) ? "True" : "False") << endl;

    return 0;
}

