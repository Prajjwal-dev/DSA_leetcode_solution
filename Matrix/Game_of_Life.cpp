#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Lambda to count live neighbors
        auto countLiveNeighbors = [&](int i, int j) {
            int liveNeighbors = 0;
            for (int x = max(i - 1, 0); x <= min(i + 1, m - 1); x++) {
                for (int y = max(j - 1, 0); y <= min(j + 1, n - 1); y++) {
                    if (x == i && y == j) continue; // skip the cell itself
                    if (board[x][y] == 1 || board[x][y] == 2) liveNeighbors++;
                }
            }
            return liveNeighbors;
        };

        // Apply rules to determine the next state
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = countLiveNeighbors(i, j);

                if (board[i][j] == 1) { // Currently live cell
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = 2; // Mark to die
                    }
                } else { // Currently dead cell
                    if (liveNeighbors == 3) {
                        board[i][j] = -1; // Mark to live
                    }
                }
            }
        }

        // Finalize board by converting temporary states to final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2) board[i][j] = 0; // Change marked dead cells to dead
                else if (board[i][j] == -1) board[i][j] = 1; // Change marked live cells to live
            }
        }
    }
};

// Helper function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Example Usage in main
int main() {
    Solution solution;

    vector<vector<int>> board1 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };
    solution.gameOfLife(board1);
    cout << "Output for board1:" << endl;
    printBoard(board1);

    vector<vector<int>> board2 = {
        {1, 1},
        {1, 0}
    };
    solution.gameOfLife(board2);
    cout << "Output for board2:" << endl;
    printBoard(board2);

    return 0;
}

