#include <iostream>             // For input and output
#include <vector>               // For using the vector data structure
#include <unordered_map>        // For storing occurrences of each number
#include <unordered_set>        // For checking if counts are unique
using namespace std;

class Solution {
public:
    // Function to check if occurrences of each value in the array are unique
    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Count the occurrences of each number in the array
        unordered_map<int, int> countMap;       // To store the number of occurrences
        for (int num : arr) {
            countMap[num]++;                    // Increment the count for each number
        }

        // Step 2: Check if all the occurrence counts are unique
        unordered_set<int> countSet;            // To store unique counts
        for (auto pair : countMap) {            // Iterate through each pair in the map
            int count = pair.second;            // Get the count of the current number
            if (countSet.find(count) != countSet.end()) {
                // If the count is already in the set, it's a duplicate
                return false;                   // Return false as counts are not unique
            }
            countSet.insert(count);             // Insert the count into the set
        }

        // If no duplicates found, return true
        return true;
    }
};

int main() {
    Solution solution;  // Create an instance of the Solution class

    // Example input arrays
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};            // Test case 1
    vector<int> arr2 = {1, 2};                        // Test case 2
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};  // Test case 3

    // Call the function with each array and print the results
    cout << "Example 1: " << (solution.uniqueOccurrences(arr1) ? "true" : "false") << endl;  // Output: true
    cout << "Example 2: " << (solution.uniqueOccurrences(arr2) ? "true" : "false") << endl;  // Output: false
    cout << "Example 3: " << (solution.uniqueOccurrences(arr3) ? "true" : "false") << endl;  // Output: true

    return 0;
}

