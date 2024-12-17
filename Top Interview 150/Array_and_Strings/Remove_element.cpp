#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0; // Initialize a counter for elements not equal to val

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i]; // Place the non-val element at the kth position
            k++; // Increment the count of non-val elements
        }
    }

    return k; // Return the count of non-val elements
}

int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    int k = removeElement(nums, val);

    cout << "Number of elements not equal to " << val << ": " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

