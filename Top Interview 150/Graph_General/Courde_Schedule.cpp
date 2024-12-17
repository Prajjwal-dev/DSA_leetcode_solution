#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int count = 0;  // Count of courses we can take
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            // Reduce in-degree of adjacent courses and check for new in-degree 0 courses
            for (int nextCourse : adj[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // Step 5: If count equals numCourses, we can finish all courses
        return count == numCourses;
    }
};

int main() {
    Solution solution;

    // Test Case 1: Expected output is true
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Test Case 1: " << solution.canFinish(numCourses1, prerequisites1) << endl;

    // Test Case 2: Expected output is false
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Test Case 2: " << solution.canFinish(numCourses2, prerequisites2) << endl;

    // Additional Test Case: Expected output is true
    int numCourses3 = 3;
    vector<vector<int>> prerequisites3 = {{2, 1}, {1, 0}};
    cout << "Test Case 3: " << solution.canFinish(numCourses3, prerequisites3) << endl;

    return 0;
}

