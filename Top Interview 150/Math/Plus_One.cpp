#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;  // Set to 0 and carry over
            } else {
                digits[i]++;  // Increment if no carry needed
                return digits;  // No need to continue, return the result
            }
        }
        
        // If we exit the loop, it means all digits were 9 (like [9,9,9])
        digits.insert(digits.begin(), 1);  // Insert 1 at the front
        return digits;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<int> digits1 = {1, 2, 3};
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> digits3 = {9};
    vector<int> digits4 = {9, 9, 9};

    // Outputs
    vector<int> result1 = solution.plusOne(digits1);
    vector<int> result2 = solution.plusOne(digits2);
    vector<int> result3 = solution.plusOne(digits3);
    vector<int> result4 = solution.plusOne(digits4);

    // Displaying results
    cout << "Result 1: ";
    for (int digit : result1) {
        cout << digit;
    }
    cout << endl;

    cout << "Result 2: ";
    for (int digit : result2) {
        cout << digit;
    }
    cout << endl;

    cout << "Result 3: ";
    for (int digit : result3) {
        cout << digit;
    }
    cout << endl;

    cout << "Result 4: ";
    for (int digit : result4) {
        cout << digit;
    }
    cout << endl;

    return 0;
}

