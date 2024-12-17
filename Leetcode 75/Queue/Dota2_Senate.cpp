#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire; // Queues to store the indices of 'R' and 'D'
        int n = senate.size();   // Total number of senators

        // Populate the queues with initial indices of Radiant and Dire senators
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        // Process the banning round-by-round
        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop(); // Get the front Radiant senator
            int d = dire.front(); dire.pop();       // Get the front Dire senator

            // The senator with the smaller index gets to ban the other
            if (r < d) {
                radiant.push(r + n); // Radiant bans Dire and gets back in the queue
            } else {
                dire.push(d + n);    // Dire bans Radiant and gets back in the queue
            }
        }

        // If Radiant queue is non-empty, Radiant wins; otherwise Dire wins
        return radiant.empty() ? "Dire" : "Radiant";
    }
};

int main() {
    Solution solution;

    string test1 = "RD";
    string test2 = "RDD";

    cout << "Test Case 1 Output: " << solution.predictPartyVictory(test1) << endl; // Expected: Radiant
    cout << "Test Case 2 Output: " << solution.predictPartyVictory(test2) << endl; // Expected: Dire

    return 0;
}

