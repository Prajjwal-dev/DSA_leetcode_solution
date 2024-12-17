#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of cities (or nodes)
        vector<bool> visited(n, false); // Track if a city is already visited
        int provinces = 0; // Count of provinces
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // If the city is not visited, start a BFS
                provinces++; // Found a new province
                bfs(i, isConnected, visited);
            }
        }
        return provinces; // Return the total number of provinces
    }
    
    void bfs(int start, vector<vector<int>>& isConnected, vector<bool>& visited) {
        queue<int> q;
        q.push(start); // Add the start city to the queue
        visited[start] = true; // Mark the start city as visited
        
        while (!q.empty()) {
            int city = q.front(); // Get the current city
            q.pop();
            
            // Explore all directly connected cities
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[city][j] == 1 && !visited[j]) { // Direct connection & not visited
                    q.push(j); // Add to queue
                    visited[j] = true; // Mark as visited
                }
            }
        }
    }
};

int main() {
    // Test cases
    vector<vector<int>> testCase1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    vector<vector<int>> testCase2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<int>> testCase3 = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    
    Solution sol;
    
    cout << "Test Case 1: " << sol.findCircleNum(testCase1) << endl; // Expected output: 2
    cout << "Test Case 2: " << sol.findCircleNum(testCase2) << endl; // Expected output: 3
    cout << "Test Case 3: " << sol.findCircleNum(testCase3) << endl; // Expected output: 1

    return 0;
}

