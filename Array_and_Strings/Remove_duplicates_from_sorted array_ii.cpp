#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: if the array is empty or has only one element, return its size
        if (nums.size() <= 1) {
            return nums.size();
        }
        
        // Pointer to place the next valid element
        int index = 1;
        int count = 1;  // Count occurrences of the current element
        
        // Start iterating from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If current element is the same as the previous one, increase the count
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                // Reset count for the new element
                count = 1;
            }
            
            // If the current element's count is <= 2, we can place it in the result
            if (count <= 2) {
                nums[index] = nums[i];
                index++;
            }
        }
        
        // Return the number of valid elements in the modified array
        return index;
    }
};

int main() {
    Solution solution;

    // Test case 1: array has duplicates
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = solution.removeDuplicates(nums1);
    cout << "Array after removing duplicates (Test 1): ";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl << "Length of new array (Test 1): " << k1 << endl;

    // Test case 2: array has duplicates, and some elements appear more than twice
    vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int k2 = solution.removeDuplicates(nums2);
    cout << "Array after removing duplicates (Test 2): ";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl << "Length of new array (Test 2): " << k2 << endl;

    // Test case 3: array has no duplicates
    vector<int> nums3 = {1, 2, 3, 4};
    int k3 = solution.removeDuplicates(nums3);
    cout << "Array after removing duplicates (Test 3): ";
    for (int i = 0; i < k3; i++) {
        cout << nums3[i] << " ";
    }
    cout << endl << "Length of new array (Test 3): " << k3 << endl;

    // Test case 4: array has only one element
    vector<int> nums4 = {1};
    int k4 = solution.removeDuplicates(nums4);
    cout << "Array after removing duplicates (Test 4): ";
    for (int i = 0; i < k4; i++) {
        cout << nums4[i] << " ";
    }
    cout << endl << "Length of new array (Test 4): " << k4 << endl;

    return 0;
}

