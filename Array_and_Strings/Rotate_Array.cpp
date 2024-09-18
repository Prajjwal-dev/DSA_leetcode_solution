#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to reverse a portion of the array
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start++], nums[end--]);
        }
    }

    // Main function to rotate the array
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k is larger than array size
        
        // Step 1: Reverse the whole array
        reverse(nums, 0, n - 1);
        
        // Step 2: Reverse the first k elements
        reverse(nums, 0, k - 1);
        
        // Step 3: Reverse the remaining n - k elements
        reverse(nums, k, n - 1);
    }
};

// Function to print the array
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    cout << "Original array: ";
    printArray(nums1);
    solution.rotate(nums1, k1);
    cout << "Rotated array (k=" << k1 << "): ";
    printArray(nums1); // Output: [5, 6, 7, 1, 2, 3, 4]

    // Example 2
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    cout << "Original array: ";
    printArray(nums2);
    solution.rotate(nums2, k2);
    cout << "Rotated array (k=" << k2 << "): ";
    printArray(nums2); // Output: [3, 99, -1, -100]

    return 0;
}

