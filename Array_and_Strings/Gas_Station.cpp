#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;   // Total gas available in all stations
        int totalCost = 0;  // Total cost required to travel all stations
        int tank = 0;       // Current gas in the tank
        int start = 0;      // Starting station index
        
        // Iterate over all stations
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];   // Add gas available at station i
            totalCost += cost[i]; // Add cost to travel to the next station
            
            tank += gas[i] - cost[i]; // Current tank status after traveling to the next station
            
            // If tank goes negative, the current starting station is not valid
            if (tank < 0) {
                start = i + 1;    // Reset the start index to the next station
                tank = 0;         // Reset the tank because we start fresh from the new station
            }
        }
        
        // If total gas is less than total cost, it's impossible to complete the journey
        if (totalGas < totalCost) {
            return -1;
        }
        
        // Otherwise, return the start index
        return start;
    }
};

int main() {
    Solution sol;
    
    // Example 1:
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Starting station index: " << sol.canCompleteCircuit(gas1, cost1) << endl;  // Output: 3
    
    // Example 2:
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Starting station index: " << sol.canCompleteCircuit(gas2, cost2) << endl;  // Output: -1
    
    return 0;
}

