#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();  // Get the length of the array
    if (n == 1) return 0;  // If there is only one element, no jumps are needed
    
    int jumps = 0;  // To keep track of the number of jumps
    int currentEnd = 0;  // The farthest point that can be reached with the current number of jumps
    int farthest = 0;  // The farthest point that can be reached with the next jump

    for (int i = 0; i < n - 1; ++i) {  // Iterate through the array except the last element
        farthest = max(farthest, i + nums[i]);  // Update the farthest point that can be reached

        if (i == currentEnd) {  // When we reach the end of the current jump range
            jumps++;  // Increment the jump count
            currentEnd = farthest;  // Update the end of the current jump range
            
            if (currentEnd >= n - 1) break;  // If the end of the current jump range reaches or exceeds the last index, break the loop
        }
    }

    return jumps;  // Return the minimum number of jumps required
}

int main() {
    // Example test cases
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {2, 3, 0, 1, 4};

    cout << "Minimum jumps for nums1: " << jump(nums1) << endl;  // Output: 2
    cout << "Minimum jumps for nums2: " << jump(nums2) << endl;  // Output: 2

    return 0;
}

