#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Convert a square number to (row, col) coordinates on the board
    pair<int, int> getCoordinates(int square, int n) {
        int row = n - 1 - (square - 1) / n;  // Calculate row index from bottom
        int col = (square - 1) % n;
        
        // Adjust column based on row's direction (alternating order)
        if ((n - row) % 2 == 0) {
            col = n - 1 - col;
        }
        
        return {row, col};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> visited(n * n + 1, 0);  // Track visited squares
        queue<pair<int, int>> q;            // Queue for BFS with {square, moves}
        
        q.push({1, 0});       // Start from square 1 with 0 moves
        visited[1] = 1;       // Mark square 1 as visited

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();
            
            if (curr == n * n) return moves; // If reached last square, return moves
            
            for (int i = 1; i <= 6; i++) {   // Simulate dice roll (1-6)
                int next = curr + i;
                if (next > n * n) break;     // Stop if square goes beyond board
                
                // Get row and column for the square number
                auto [row, col] = getCoordinates(next, n);
                
                // If there's a ladder or snake, move to the destination square
                if (board[row][col] != -1) {
                    next = board[row][col];
                }
                
                // If not visited, mark as visited and add to the queue
                if (!visited[next]) {
                    visited[next] = 1;
                    q.push({next, moves + 1});
                }
            }
        }
        
        return -1; // Return -1 if the last square is unreachable
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<vector<int>> board1 = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };
    cout << "Minimum moves for board1: " << solution.snakesAndLadders(board1) << endl;
    
    // Test case 2
    vector<vector<int>> board2 = {
        {-1, -1},
        {-1, 3}
    };
    cout << "Minimum moves for board2: " << solution.snakesAndLadders(board2) << endl;

    // Additional test case for a larger board
    vector<vector<int>> board3 = {
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, 100, -1, -1, -1, -1, -1, -1, -1, -1}
    };
    cout << "Minimum moves for board3: " << solution.snakesAndLadders(board3) << endl;

    return 0;
}

