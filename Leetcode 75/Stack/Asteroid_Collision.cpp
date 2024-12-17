#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // Include this for the reverse function
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; // Stack to store the state of asteroids
        
        for (int asteroid : asteroids) {
            bool destroyed = false;
            
            // Handle collision cases
            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(asteroid)) {
                    // The top asteroid is destroyed
                    st.pop();
                } else if (abs(st.top()) == abs(asteroid)) {
                    // Both asteroids are destroyed
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    // Current asteroid is destroyed
                    destroyed = true;
                    break;
                }
            }
            
            if (!destroyed) {
                st.push(asteroid);
            }
        }
        
        // Collect remaining asteroids from the stack
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end()); // Reverse to maintain order
        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> asteroids1 = {5, 10, -5};
    cout << "Input: [5, 10, -5]" << endl;
    vector<int> output1 = sol.asteroidCollision(asteroids1);
    cout << "Output: ";
    for (int x : output1) cout << x << " ";
    cout << endl;

    // Test Case 2
    vector<int> asteroids2 = {8, -8};
    cout << "Input: [8, -8]" << endl;
    vector<int> output2 = sol.asteroidCollision(asteroids2);
    cout << "Output: ";
    for (int x : output2) cout << x << " ";
    cout << endl;

    // Test Case 3
    vector<int> asteroids3 = {10, 2, -5};
    cout << "Input: [10, 2, -5]" << endl;
    vector<int> output3 = sol.asteroidCollision(asteroids3);
    cout << "Output: ";
    for (int x : output3) cout << x << " ";
    cout << endl;

    // Test Case 4
    vector<int> asteroids4 = {-2, -1, 1, 2};
    cout << "Input: [-2, -1, 1, 2]" << endl;
    vector<int> output4 = sol.asteroidCollision(asteroids4);
    cout << "Output: ";
    for (int x : output4) cout << x << " ";
    cout << endl;

    return 0;
}

