#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;
        
        // Loop over each bit position (0 to 31 for a 32-bit integer)
        for (int i = 0; i < 32; ++i) {
            int bitSum = 0; // To store the sum of the i-th bit across all numbers
            
            // Loop over all numbers and count the i-th bit
            for (int num : nums) {
                // Check if the i-th bit is set (1) in the current number
                bitSum += (num >> i) & 1;
            }
            
            // If the bitSum is not divisible by 3, it means the single number has a 1 in this bit
            if (bitSum % 3 != 0) {
                // Set the i-th bit in the result (singleNum)
                singleNum |= (1 << i);
            }
        }
        
        return singleNum;
    }
};

int main() {
    // Test case 1
    vector<int> nums1 = {2, 2, 3, 2};
    Solution solution;
    int result1 = solution.singleNumber(nums1);
    cout << "The single number in [2, 2, 3, 2] is: " << result1 << endl;

    // Test case 2
    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    int result2 = solution.singleNumber(nums2);
    cout << "The single number in [0, 1, 0, 1, 0, 1, 99] is: " << result2 << endl;

    return 0;
}

