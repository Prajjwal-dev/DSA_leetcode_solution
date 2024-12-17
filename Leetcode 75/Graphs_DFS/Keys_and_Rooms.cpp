#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(); // Total number of rooms
        vector<bool> visited(n, false); // Track visited rooms
        stack<int> toVisit; // Stack for DFS
        
        // Start with room 0
        toVisit.push(0);
        visited[0] = true;
        
        // DFS traversal
        while (!toVisit.empty()) {
            int currentRoom = toVisit.top();
            toVisit.pop();
            
            // Check all keys in the current room
            for (int key : rooms[currentRoom]) {
                if (!visited[key]) {
                    visited[key] = true;
                    toVisit.push(key); // Add this room to the stack
                }
            }
        }
        
        // Check if all rooms are visited
        for (bool isVisited : visited) {
            if (!isVisited) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};
    cout << "Test Case 1: " << (solution.canVisitAllRooms(rooms1) ? "true" : "false") << endl;

    // Test case 2
    vector<vector<int>> rooms2 = {{1, 3}, {3, 0, 1}, {2}, {0}};
    cout << "Test Case 2: " << (solution.canVisitAllRooms(rooms2) ? "true" : "false") << endl;

    // Test case 3
    vector<vector<int>> rooms3 = {{1, 2, 3}, {}, {}, {}};
    cout << "Test Case 3: " << (solution.canVisitAllRooms(rooms3) ? "true" : "false") << endl;

    // Test case 4
    vector<vector<int>> rooms4 = {{}};
    cout << "Test Case 4: " << (solution.canVisitAllRooms(rooms4) ? "true" : "false") << endl;

    // Test case 5
    vector<vector<int>> rooms5 = {{1}, {}, {0, 3}, {1}};
    cout << "Test Case 5: " << (solution.canVisitAllRooms(rooms5) ? "true" : "false") << endl;

    return 0;
}

