#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Insert all the numbers into a set for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());

        // Variable to track the longest sequence
        int longestStreak = 0;

        // Step 2: Iterate through each number in the set
        for (int num : numSet) {
            // Step 3: Check if num is the start of a sequence (i.e., num - 1 is not in the set)
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Step 4: Count the consecutive numbers in the sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                // Step 5: Update the longest streak if the current sequence is longer
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        // Return the length of the longest consecutive sequence
        return longestStreak;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence length (Example 1): " << solution.longestConsecutive(nums1) << endl;

    // Example 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Longest consecutive sequence length (Example 2): " << solution.longestConsecutive(nums2) << endl;

    return 0;
}

