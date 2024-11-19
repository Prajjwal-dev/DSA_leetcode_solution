#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Initialize all children with at least one candy.

        // Step 1: Left to right - ensure higher ratings get more candies.
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 2: Right to left - ensure higher ratings get more candies.
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Calculate the total candies.
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> ratings1 = {1, 0, 2};
    cout << "Minimum candies for ratings1: " << sol.candy(ratings1) << endl;

    // Example 2
    vector<int> ratings2 = {1, 2, 2};
    cout << "Minimum candies for ratings2: " << sol.candy(ratings2) << endl;

    return 0;
}

