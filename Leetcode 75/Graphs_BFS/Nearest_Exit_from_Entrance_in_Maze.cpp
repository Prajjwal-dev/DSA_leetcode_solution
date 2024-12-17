#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char> >& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        // Queue to store the position and steps: (row, col, steps)
        queue<pair<pair<int, int>, int> > q;

        // Directions for moving: up, down, left, right
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Mark the entrance as visited
        maze[entrance[0]][entrance[1]] = '+';
        q.push(make_pair(make_pair(entrance[0], entrance[1]), 0));

        while (!q.empty()) {
            pair<pair<int, int>, int> current = q.front();
            q.pop();

            int x = current.first.first;
            int y = current.first.second;
            int steps = current.second;

            // Check all 4 possible directions
            for (int i = 0; i < 4; ++i) {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];

                // Check if the new position is within bounds and not a wall
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && maze[newX][newY] == '.') {
                    // Check if it is an exit (on the border but not the entrance)
                    if (newX == 0 || newX == rows - 1 || newY == 0 || newY == cols - 1) {
                        return steps + 1;
                    }

                    // Mark the cell as visited and push it to the queue
                    maze[newX][newY] = '+';
                    q.push(make_pair(make_pair(newX, newY), steps + 1));
                }
            }
        }

        // If no exit is found, return -1
        return -1;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<char> > maze1;
    maze1.push_back(vector<char>{'+', '+', '.', '+'});
    maze1.push_back(vector<char>{'.', '.', '.', '+'});
    maze1.push_back(vector<char>{'+', '+', '+', '.'});
    vector<int> entrance1;
    entrance1.push_back(1);
    entrance1.push_back(2);
    cout << "Example 1 Output: " << solution.nearestExit(maze1, entrance1) << endl;

    // Example 2
    vector<vector<char> > maze2;
    maze2.push_back(vector<char>{'+', '+', '+'});
    maze2.push_back(vector<char>{'.', '.', '.'});
    maze2.push_back(vector<char>{'+', '+', '+'});
    vector<int> entrance2;
    entrance2.push_back(1);
    entrance2.push_back(0);
    cout << "Example 2 Output: " << solution.nearestExit(maze2, entrance2) << endl;

    // Example 3
    vector<vector<char> > maze3;
    maze3.push_back(vector<char>{'.', '+'});
    vector<int> entrance3;
    entrance3.push_back(0);
    entrance3.push_back(0);
    cout << "Example 3 Output: " << solution.nearestExit(maze3, entrance3) << endl;

    return 0;
}

/*
Explanation:
1. **Queue-Based BFS**: Each queue element stores the current cell and the number of steps taken.
2. **Marking Visited**: To avoid revisiting cells, mark them with '+'.
3. **Boundary Check**: Ensure movement stays within the maze and does not hit walls ('+').
4. **Finding Exit**: If an empty cell ('.') on the boundary is reached, return the steps count.
5. **Returning -1**: If BFS completes without finding an exit, return -1.
*/

