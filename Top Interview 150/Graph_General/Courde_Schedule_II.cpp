#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Create an adjacency list and in-degree array
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Step 2: Build the graph
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        // Step 3: Initialize a queue with courses having in-degree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: Process courses with no prerequisites (BFS)
        vector<int> order;  // Store the course order here
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);

            // Reduce in-degree of adjacent courses and check for new in-degree 0 courses
            for (int nextCourse : adj[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // Step 5: If order contains all courses, return it; otherwise, return empty array
        if (order.size() == numCourses) {
            return order;
        } else {
            return {};
        }
    }
};

int main() {
    Solution solution;

    // Test Case 1: Expected output is [0,1]
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    vector<int> result1 = solution.findOrder(numCourses1, prerequisites1);
    cout << "Test Case 1: ";
    for (int course : result1) cout << course << " ";
    cout << endl;

    // Test Case 2: Expected output is [0,1,2,3] or [0,2,1,3]
    int numCourses2 = 4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result2 = solution.findOrder(numCourses2, prerequisites2);
    cout << "Test Case 2: ";
    for (int course : result2) cout << course << " ";
    cout << endl;

    // Test Case 3: Expected output is [0]
    int numCourses3 = 1;
    vector<vector<int>> prerequisites3 = {};
    vector<int> result3 = solution.findOrder(numCourses3, prerequisites3);
    cout << "Test Case 3: ";
    for (int course : result3) cout << course << " ";
    cout << endl;

    // Additional Test Case: Expected output is empty array []
    int numCourses4 = 2;
    vector<vector<int>> prerequisites4 = {{1, 0}, {0, 1}};
    vector<int> result4 = solution.findOrder(numCourses4, prerequisites4);
    cout << "Test Case 4: ";
    for (int course : result4) cout << course << " ";
    cout << endl;

    return 0;
}

