#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxCandies = 0;

        // Find the current maximum number of candies any kid has
        for (int candy : candies) {
            if (candy > maxCandies) {
                maxCandies = candy;
            }
        }

        // Check each kid if, after receiving extraCandies, they will have the maximum
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> candies1 = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;
    vector<bool> result1 = sol.kidsWithCandies(candies1, extraCandies1);
    for (bool res : result1) {
        cout << (res ? "true " : "false ");
    }
    cout << endl;

    // Test case 2
    vector<int> candies2 = {4, 2, 1, 1, 2};
    int extraCandies2 = 1;
    vector<bool> result2 = sol.kidsWithCandies(candies2, extraCandies2);
    for (bool res : result2) {
        cout << (res ? "true " : "false ");
    }
    cout << endl;

    // Test case 3
    vector<int> candies3 = {12, 1, 12};
    int extraCandies3 = 10;
    vector<bool> result3 = sol.kidsWithCandies(candies3, extraCandies3);
    for (bool res : result3) {
        cout << (res ? "true " : "false ");
    }
    cout << endl;

    return 0;
}

