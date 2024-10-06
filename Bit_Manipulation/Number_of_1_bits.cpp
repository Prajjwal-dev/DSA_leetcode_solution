#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            count += n & 1;  // Check if the last bit of n is 1
            n >>= 1;         // Right shift n by 1 to check the next bit
        }
        return count;
    }
};

int main() {
    Solution solution;          // Create an instance of the Solution class
    int n1 = 11;                // Test case 1 (binary 1011)
    int n2 = 128;               // Test case 2 (binary 10000000)
    int n3 = 2147483645;        // Test case 3 (binary representation has 30 set bits)

    // Calling the hammingWeight function and printing the results
    cout << "Number of set bits in " << n1 << " (binary: 1011) is: " << solution.hammingWeight(n1) << endl;
    cout << "Number of set bits in " << n2 << " (binary: 10000000) is: " << solution.hammingWeight(n2) << endl;
    cout << "Number of set bits in " << n3 << " is: " << solution.hammingWeight(n3) << endl;

    return 0;
}

