#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Iterate through all elements in the nums array
        for (int num : nums) {
            minHeap.push(num); // Push the current number into the heap

            // If the size of the heap exceeds k, pop the smallest element
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element to maintain size k
            }
        }

        // The top of the heap will now be the kth largest element
        return minHeap.top();
    }
};

int main() {
    // Test case 1
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    Solution solution;
    cout << "The 2nd largest element is: " << solution.findKthLargest(nums1, k1) << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "The 4th largest element is: " << solution.findKthLargest(nums2, k2) << endl;

    return 0;
}

