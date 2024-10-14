#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to insert and merge new interval into intervals
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;  // To store the final result
        int i = 0;
        int n = intervals.size();

        // Step 1: Add all intervals that end before the newInterval starts (i.e., no overlap).
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            ++i;
        }

        // Step 2: Merge overlapping intervals with newInterval.
        while (i < n && intervals[i][0] <= newInterval[1]) {
            // Update the newInterval by taking the min of start and max of end of overlapping intervals.
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        // Add the merged newInterval
        result.push_back(newInterval);

        // Step 3: Add remaining intervals that start after newInterval ends.
        while (i < n) {
            result.push_back(intervals[i]);
            ++i;
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    vector<vector<int>> result1 = sol.insert(intervals1, newInterval1);

    // Output the result for test case 1
    cout << "Merged Intervals after insertion (Test Case 1): " << endl;
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Test case 2
    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    vector<vector<int>> result2 = sol.insert(intervals2, newInterval2);

    // Output the result for test case 2
    cout << "Merged Intervals after insertion (Test Case 2): " << endl;
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

