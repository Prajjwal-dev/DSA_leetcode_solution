#include <iostream>
#include <vector>
#include <algorithm>  // For max function
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // Initialize the current altitude and maximum altitude
        int currentAltitude = 0;
        int maxAltitude = 0;
        
        // Iterate through the gain array to calculate altitudes
        for (int i = 0; i < gain.size(); i++) {
            currentAltitude += gain[i];  // Update the current altitude
            maxAltitude = max(maxAltitude, currentAltitude);  // Track the maximum altitude
        }
        
        return maxAltitude;  // Return the highest altitude reached
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> gain1 = {-5, 1, 5, 0, -7};
    cout << "Test case 1: " << solution.largestAltitude(gain1) << endl;  // Expected output: 1

    // Test case 2
    vector<int> gain2 = {-4, -3, -2, -1, 4, 3, 2};
    cout << "Test case 2: " << solution.largestAltitude(gain2) << endl;  // Expected output: 0

    // Test case 3 (Additional check)
    vector<int> gain3 = {10, -3, 7, -5};
    cout << "Test case 3: " << solution.largestAltitude(gain3) << endl;  // Expected output: 14

    return 0;
}

