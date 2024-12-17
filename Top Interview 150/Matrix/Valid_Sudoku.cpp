#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays of sets to track the existence of numbers in rows, columns, and sub-boxes
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {         // Loop through each row
            for (int j = 0; j < 9; j++) {     // Loop through each column
                char num = board[i][j];

                // Skip empty cells
                if (num == '.') continue;

                // Calculate box index based on row and column index
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check for repetition in the row, column, or 3x3 sub-box
                if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num)) {
                    return false; // If duplicate found, board is invalid
                }

                // Otherwise, add the number to the respective row, column, and sub-box
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
        
        return true; // If no duplicates found, board is valid
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    bool result = solution.isValidSudoku(board);
    cout << "Is the Sudoku board valid? " << (result ? "Yes" : "No") << endl;
    
    return 0;
}

