#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }

        int rem = 0, rev = 0, temp = x;
        while(temp != 0) {
            if(rev > INT_MAX / 10) {
                return false; // Avoid overflow
            }
            rem = temp % 10;
            rev = rev * 10 + rem;
            temp = temp / 10;
        }

        return rev == x;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    int test1 = 121;
    int test2 = -121;
    int test3 = 10;
    int test4 = 12321;

    // Outputs
    cout << "Test 1: " << solution.isPalindrome(test1) << endl;  // Expected: true
    cout << "Test 2: " << solution.isPalindrome(test2) << endl;  // Expected: false
    cout << "Test 3: " << solution.isPalindrome(test3) << endl;  // Expected: false
    cout << "Test 4: " << solution.isPalindrome(test4) << endl;  // Expected: true

    return 0;
}

