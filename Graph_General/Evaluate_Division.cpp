#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // To store the graph, where graph[A][B] = value means A/B = value
    unordered_map<string, unordered_map<string, double>> graph;

    // Helper function to build the graph
    void buildGraph(const vector<vector<string>>& equations, const vector<double>& values) {
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0];
            string B = equations[i][1];
            double value = values[i];

            graph[A][B] = value;
            graph[B][A] = 1.0 / value;
        }
    }

    // Helper function to perform DFS and find the result of A / B
    double dfs(const string& start, const string& end, unordered_set<string>& visited) {
        // If start node is not in the graph, return -1.0
        if (graph.find(start) == graph.end()) return -1.0;

        // If start and end are the same node, return 1.0
        if (start == end) return 1.0;

        visited.insert(start);  // Mark start node as visited

        // Traverse through the neighbors of the start node
        for (const auto& neighbor : graph[start]) {
            if (visited.find(neighbor.first) == visited.end()) {  // If not visited
                double result = dfs(neighbor.first, end, visited);  // Recursive call
                if (result != -1.0) {
                    return neighbor.second * result;  // Multiply current value with result of sub-problem
                }
            }
        }

        return -1.0;  // No valid path found
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        buildGraph(equations, values);  // Build the graph with given equations and values

        vector<double> results;

        for (const auto& query : queries) {
            string A = query[0];
            string B = query[1];

            // If either A or B is not in the graph, result is -1.0
            if (graph.find(A) == graph.end() || graph.find(B) == graph.end()) {
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                results.push_back(dfs(A, B, visited));  // Perform DFS to get the result
            }
        }

        return results;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<vector<string>> equations1 = {{"a", "b"}, {"b", "c"}};
    vector<double> values1 = {2.0, 3.0};
    vector<vector<string>> queries1 = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> results1 = solution.calcEquation(equations1, values1, queries1);

    cout << "Test Case 1 Results:" << endl;
    for (double res : results1) {
        cout << res << " ";
    }
    cout << endl;

    // Test Case 2
    vector<vector<string>> equations2 = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> values2 = {1.5, 2.5, 5.0};
    vector<vector<string>> queries2 = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    vector<double> results2 = solution.calcEquation(equations2, values2, queries2);

    cout << "Test Case 2 Results:" << endl;
    for (double res : results2) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}

