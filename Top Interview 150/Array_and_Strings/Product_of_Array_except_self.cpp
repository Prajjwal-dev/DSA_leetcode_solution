#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(const vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1);  // Initialize output array with 1

    // First pass: Calculate the product of elements to the left of each index
    int leftProduct = 1;
    for (int i = 0; i < n; ++i) {
        answer[i] = leftProduct;  // Assign the left product so far
        leftProduct *= nums[i];   // Update left product for next index
    }

    // Second pass: Calculate the product of elements to the right of each index
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; --i) {
        answer[i] *= rightProduct;  // Multiply with the right product so far
        rightProduct *= nums[i];    // Update right product for the next iteration
    }

    return answer;
}

int main() {
    // Test case 1: nums = [1, 2, 3, 4]
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);

    // Output the result
    cout << "Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2: nums = [-1, 1, 0, -3, 3]
    nums = {-1, 1, 0, -3, 3};
    result = productExceptSelf(nums);

    // Output the result
    cout << "Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

