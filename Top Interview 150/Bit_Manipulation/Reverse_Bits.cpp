#include <iostream>
#include <stdint.h>  // for uint32_t
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            // Shift result left to make space for the next bit
            result <<= 1;
            
            // Take the last bit of n (n & 1) and add it to the result
            result |= (n & 1);
            
            // Shift n right to discard the bit we just processed
            n >>= 1;
        }
        return result;
    }
};

// Driver code
int main() {
    Solution solution;

    // Example 1
    uint32_t n1 = 43261596;  // Binary: 00000010100101000001111010011100
    uint32_t result1 = solution.reverseBits(n1);
    cout << "Reversed bits of " << n1 << ": " << result1 << endl;

    // Example 2
    uint32_t n2 = 4294967293;  // Binary: 11111111111111111111111111111101
    uint32_t result2 = solution.reverseBits(n2);
    cout << "Reversed bits of " << n2 << ": " << result2 << endl;

    return 0;
}

