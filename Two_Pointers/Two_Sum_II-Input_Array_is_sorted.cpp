#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Initialize two pointers
        int left = 0;
        int right = numbers.size() - 1;

        // Loop until the pointers meet
        while (left < right) {
            // Calculate the sum of the elements at the left and right pointers
            int sum = numbers[left] + numbers[right];

            // Check if the sum is equal to the target
            if (sum == target) {
                // If the sum is the target, return the indices (1-indexed)
                return {left + 1, right + 1};
            } 
            // If the sum is less than the target, move the left pointer to the right
            else if (sum < target) {
                left++;
            } 
            // If the sum is greater than the target, move the right pointer to the left
            else {
                right--;
            }
        }

        // Return an empty vector if no solution is found (not needed due to problem constraints)
        return {};
    }
};

int main() {
    Solution solution;

    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(numbers1, target1);
    cout << "Input: [2,7,11,15], target = 9\n";
    cout << "Output: [" << result1[0] << "," << result1[1] << "]" << endl;

    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(numbers2, target2);
    cout << "Input: [2,3,4], target = 6\n";
    cout << "Output: [" << result2[0] << "," << result2[1] << "]" << endl;

    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> result3 = solution.twoSum(numbers3, target3);
    cout << "Input: [-1,0], target = -1\n";
    cout << "Output: [" << result3[0] << "," << result3[1] << "]" << endl;

    return 0;
}

