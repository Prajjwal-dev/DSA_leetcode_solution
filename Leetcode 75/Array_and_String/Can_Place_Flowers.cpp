#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; i++) {
            // Check if the current plot is empty and adjacent plots are also empty
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&  // Check the left plot
                (i == size - 1 || flowerbed[i + 1] == 0)) {  // Check the right plot
                
                // Plant a flower here
                flowerbed[i] = 1;
                n--;  // Reduce the number of flowers to be planted

                // If all flowers are planted, return true
                if (n == 0) return true;
            }
        }

        // If not enough flowers could be planted, return false
        return n <= 0;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    int n1 = 1;
    cout << (sol.canPlaceFlowers(flowerbed1, n1) ? "true" : "false") << endl;  // Output: true

    // Test case 2
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    int n2 = 2;
    cout << (sol.canPlaceFlowers(flowerbed2, n2) ? "true" : "false") << endl;  // Output: false

    // Test case 3
    vector<int> flowerbed3 = {0, 0, 1, 0, 0};
    int n3 = 1;
    cout << (sol.canPlaceFlowers(flowerbed3, n3) ? "true" : "false") << endl;  // Output: true

    // Test case 4
    vector<int> flowerbed4 = {0};
    int n4 = 1;
    cout << (sol.canPlaceFlowers(flowerbed4, n4) ? "true" : "false") << endl;  // Output: true

    return 0;
}

