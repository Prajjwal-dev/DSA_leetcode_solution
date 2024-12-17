#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Pairing profits and capital, then sorting by capital
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end()); // Sort by capital required

        priority_queue<int> maxHeap; // Max-heap to store profits of feasible projects

        int i = 0;
        while (k > 0) {
            // Add all projects that can be started with the current capital
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second); // Push profits to maxHeap
                ++i;
            }

            if (maxHeap.empty()) {
                // If no project is feasible, break early
                break;
            }

            // Pick the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
            --k;
        }

        return w;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    int k1 = 2, w1 = 0;
    vector<int> profits1 = {1, 2, 3};
    vector<int> capital1 = {0, 1, 1};
    cout << "Test Case 1 Final Maximized Capital: " 
         << solution.findMaximizedCapital(k1, w1, profits1, capital1) << endl;

    // Test Case 2
    int k2 = 3, w2 = 0;
    vector<int> profits2 = {1, 2, 3};
    vector<int> capital2 = {0, 1, 2};
    cout << "Test Case 2 Final Maximized Capital: " 
         << solution.findMaximizedCapital(k2, w2, profits2, capital2) << endl;

    // Test Case 3
    int k3 = 1, w3 = 5;
    vector<int> profits3 = {10, 15, 20};
    vector<int> capital3 = {2, 3, 5};
    cout << "Test Case 3 Final Maximized Capital: " 
         << solution.findMaximizedCapital(k3, w3, profits3, capital3) << endl;

    // Test Case 4
    int k4 = 5, w4 = 0;
    vector<int> profits4 = {5, 10, 15, 20};
    vector<int> capital4 = {0, 2, 3, 5};
    cout << "Test Case 4 Final Maximized Capital: " 
         << solution.findMaximizedCapital(k4, w4, profits4, capital4) << endl;

    return 0;
}

