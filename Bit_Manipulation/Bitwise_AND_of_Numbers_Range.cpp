#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // Step 1: Initialize shift count
        int shift = 0;
        
        // Step 2: Keep shifting left and right until they are the same
        while (left < right) {
            left >>= 1;   // Right-shift left
            right >>= 1;  // Right-shift right
            shift++;      // Count the shifts
        }
        
        // Step 3: Left-shift back to restore the result
        return left << shift;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int left1 = 5, right1 = 7;
    cout << "Bitwise AND of range [" << left1 << ", " << right1 << "] is: " 
         << sol.rangeBitwiseAnd(left1, right1) << endl;

    // Example 2
    int left2 = 0, right2 = 0;
    cout << "Bitwise AND of range [" << left2 << ", " << right2 << "] is: " 
         << sol.rangeBitwiseAnd(left2, right2) << endl;
         
    // Example 3
    int left3 = 1, right3 = 2147483647;
    cout << "Bitwise AND of range [" << left3 << ", " << right3 << "] is: " 
         << sol.rangeBitwiseAnd(left3, right3) << endl;

    return 0;
}
