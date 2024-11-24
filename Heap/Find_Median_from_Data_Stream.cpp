#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Max-heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for the larger half
    
public:
    // Constructor initializes the MedianFinder object
    MedianFinder() {
    }

    // Adds a number to the data structure
    void addNum(int num) {
        // Step 1: Add to maxHeap first
        maxHeap.push(num);
        
        // Step 2: Balance the heaps so that all elements in maxHeap are <= elements in minHeap
        minHeap.push(maxHeap.top());  // Move the largest element from maxHeap to minHeap
        maxHeap.pop();                // Remove it from maxHeap

        // Step 3: Ensure size balance: maxHeap can have one more element than minHeap
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());  // Move the smallest element back to maxHeap
            minHeap.pop();                // Remove it from minHeap
        }
    }

    // Returns the median of the current list
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            // If even number of elements, return the average of the two middle values
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            // If odd, maxHeap has the median element
            return maxHeap.top();
        }
    }
};

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    cout << "Median after adding 1: " << medianFinder.findMedian() << endl;  // Output: 1

    medianFinder.addNum(2);
    cout << "Median after adding 2: " << medianFinder.findMedian() << endl;  // Output: 1.5

    medianFinder.addNum(3);
    cout << "Median after adding 3: " << medianFinder.findMedian() << endl;  // Output: 2

    medianFinder.addNum(4);
    cout << "Median after adding 4: " << medianFinder.findMedian() << endl;  // Output: 2.5

    medianFinder.addNum(5);
    cout << "Median after adding 5: " << medianFinder.findMedian() << endl;  // Output: 3

    return 0;
}

