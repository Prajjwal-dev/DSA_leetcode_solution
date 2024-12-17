#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to merge overlapping intervals
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If intervals list is empty, return an empty list
        if (intervals.empty()) return {};

        // Sort the intervals based on their start times
        sort(intervals.begin(), intervals.end());

        // Resultant merged intervals
        vector<vector<int>> merged;

        // Add the first interval to the merged list
        merged.push_back(intervals[0]);

        // Iterate through the rest of the intervals
        for (int i = 1; i < intervals.size(); ++i) {
            // Get the last interval in the merged list
            vector<int>& last = merged.back();

            // If current interval overlaps with the last merged interval, merge them
            if (intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // Otherwise, add the current interval as a new interval
                merged.push_back(intervals[i]);
            }
        }

        // Return the merged intervals
        return merged;
    }
};

int main() {
    // Create a Solution object to call the merge function
    Solution sol;

    // Test case 1:
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result1 = sol.merge(intervals1);

    // Output the merged intervals
    cout << "Merged Intervals for test case 1: " << endl;
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Test case 2:
    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    vector<vector<int>> result2 = sol.merge(intervals2);

    // Output the merged intervals
    cout << "Merged Intervals for test case 2: " << endl;
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

