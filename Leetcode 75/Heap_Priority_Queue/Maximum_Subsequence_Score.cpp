#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // Step 1: Create a vector of pairs where each pair is (nums2[i], nums1[i])
        vector<pair<int, int>> pairs;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            pairs.push_back({nums2[i], nums1[i]});
        }
        
        // Step 2: Sort the pairs in descending order based on nums2 values
        sort(pairs.rbegin(), pairs.rend());

        // Step 3: Use a min-heap to maintain the k largest nums1 values
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0; // To store the sum of selected nums1 values
        long long maxScore = 0; // To store the maximum score

        // Step 4: Iterate through the sorted pairs
        for (int i = 0; i < n; ++i) {
            int num2 = pairs[i].first; // nums2 value
            int num1 = pairs[i].second; // nums1 value

            // Add nums1[i] to the current sum and push it into the min-heap
            sum += num1;
            minHeap.push(num1);

            // If the heap size exceeds k, remove the smallest element
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            // If the heap size is exactly k, calculate the score
            if (minHeap.size() == k) {
                maxScore = max(maxScore, sum * num2);
            }
        }

        // Step 5: Return the maximum score
        return maxScore;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1_1 = {1, 3, 3, 2};
    vector<int> nums2_1 = {2, 1, 3, 4};
    int k1 = 3;
    cout << "Test Case 1: " << solution.maxScore(nums1_1, nums2_1, k1) << endl;

    // Test Case 2
    vector<int> nums1_2 = {4, 2, 3, 1, 1};
    vector<int> nums2_2 = {7, 5, 10, 9, 6};
    int k2 = 1;
    cout << "Test Case 2: " << solution.maxScore(nums1_2, nums2_2, k2) << endl;

    // Additional Test Case 3
    vector<int> nums1_3 = {5, 6, 7, 8};
    vector<int> nums2_3 = {3, 1, 2, 4};
    int k3 = 2;
    cout << "Test Case 3: " << solution.maxScore(nums1_3, nums2_3, k3) << endl;

    return 0;
}

