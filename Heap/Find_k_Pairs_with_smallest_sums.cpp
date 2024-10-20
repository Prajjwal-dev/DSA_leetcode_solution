#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Priority queue (min-heap) to store pairs. We use the sum of the pairs to compare.
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        // Store the result pairs
        vector<vector<int>> result;

        // Edge case: If one of the arrays is empty, return an empty result.
        if (nums1.empty() || nums2.empty()) {
            return result;
        }

        // Push the first k pairs (nums1[0] + nums2[j]) into the heap for j from 0 to min(k, nums2.size()).
        for (int j = 0; j < min(k, (int)nums2.size()); j++) {
            minHeap.push({nums1[0] + nums2[j], {0, j}});
        }

        // Extract k pairs from the heap or until the heap is empty.
        while (k-- > 0 && !minHeap.empty()) {
            // Get the pair with the smallest sum
            auto top = minHeap.top();
            minHeap.pop();

            int i = top.second.first; // Index from nums1
            int j = top.second.second; // Index from nums2

            // Add the current pair (nums1[i], nums2[j]) to the result
            result.push_back({nums1[i], nums2[j]});

            // If there is a next element in nums1, push the pair (nums1[i+1], nums2[j])
            if (i + 1 < nums1.size()) {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            }
        }

        return result;
    }
};

int main() {
    // Test case 1
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    Solution solution;
    vector<vector<int>> result = solution.kSmallestPairs(nums1, nums2, k);

    // Print the result
    cout << "The " << k << " pairs with the smallest sums are: " << endl;
    for (auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
    }

    return 0;
}

