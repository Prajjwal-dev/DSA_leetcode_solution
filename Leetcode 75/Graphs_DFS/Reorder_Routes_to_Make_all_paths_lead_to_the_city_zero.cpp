#include <iostream>
#include <vector>
#include <queue>
#include <utility> // For std::pair
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int> >& connections) {
        // Create an adjacency list for the graph
        vector<vector<pair<int, int> > > graph(n); // Pair: {neighbor city, direction of the road}
        vector<bool> visited(n, false); // To track visited cities
        int changes = 0; // Count of changes needed

        // Build the graph
        for (int i = 0; i < connections.size(); ++i) {
            int u = connections[i][0], v = connections[i][1];
            graph[u].push_back(make_pair(v, 1)); // Original direction: u -> v
            graph[v].push_back(make_pair(u, 0)); // Reverse direction: v -> u
        }

        // Breadth-First Search (BFS) starting from city 0
        queue<int> q;
        q.push(0); // Start from city 0
        visited[0] = true;

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            // Process all neighbors of the current city
            for (int i = 0; i < graph[city].size(); ++i) {
                int neighbor = graph[city][i].first;
                int direction = graph[city][i].second;

                // If the neighbor is not visited, process it
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    changes += direction; // Add to changes if road needs reorientation
                    q.push(neighbor); // Add neighbor to the BFS queue
                }
            }
        }

        return changes; // Return the total changes required
    }
};

int main() {
    Solution solution;

    // Test Case 1
    int n1 = 6;
    vector<vector<int> > connections1;
    connections1.push_back(vector<int>{0, 1});
    connections1.push_back(vector<int>{1, 3});
    connections1.push_back(vector<int>{2, 3});
    connections1.push_back(vector<int>{4, 0});
    connections1.push_back(vector<int>{4, 5});
    cout << "Test Case 1 Output: " << solution.minReorder(n1, connections1) << endl;

    // Test Case 2
    int n2 = 5;
    vector<vector<int> > connections2;
    connections2.push_back(vector<int>{1, 0});
    connections2.push_back(vector<int>{1, 2});
    connections2.push_back(vector<int>{3, 2});
    connections2.push_back(vector<int>{3, 4});
    cout << "Test Case 2 Output: " << solution.minReorder(n2, connections2) << endl;

    // Test Case 3
    int n3 = 3;
    vector<vector<int> > connections3;
    connections3.push_back(vector<int>{1, 0});
    connections3.push_back(vector<int>{2, 0});
    cout << "Test Case 3 Output: " << solution.minReorder(n3, connections3) << endl;

    return 0;
}

