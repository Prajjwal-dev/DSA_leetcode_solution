#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0;  // Keeps track of the position to place the non-zero element
        
        // First pass: move all non-zero elements to the front of the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZeroIndex] = nums[i]; // Place the non-zero element
                if (nonZeroIndex != i) nums[i] = 0; // Set current position to zero if shifted
                nonZeroIndex++; // Move to the next position for a non-zero element
            }
        }
    }
};

// Main function for testing
int main() {
    Solution solution;
    
    // Test cases
    vector<int> test1 = {0, 1, 0, 3, 12};
    cout << "Input: ";
    for (int num : test1) cout << num << " ";
    solution.moveZeroes(test1);
    cout << "\nOutput: ";
    for (int num : test1) cout << num << " ";
    cout << "\n\n";

    vector<int> test2 = {0};
    cout << "Input: ";
    for (int num : test2) cout << num << " ";
    solution.moveZeroes(test2);
    cout << "\nOutput: ";
    for (int num : test2) cout << num << " ";
    cout << "\n\n";

    vector<int> test3 = {1, 0, 2, 0, 4, 5};
    cout << "Input: ";
    for (int num : test3) cout << num << " ";
    solution.moveZeroes(test3);
    cout << "\nOutput: ";
    for (int num : test3) cout << num << " ";
    cout << "\n\n";

    vector<int> test4 = {1, 2, 3, 4};
    cout << "Input: ";
    for (int num : test4) cout << num << " ";
    solution.moveZeroes(test4);
    cout << "\nOutput: ";
    for (int num : test4) cout << num << " ";
    cout << "\n\n";

    return 0;
}

