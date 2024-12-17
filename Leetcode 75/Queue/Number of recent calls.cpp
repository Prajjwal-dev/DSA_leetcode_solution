#include <iostream>
#include <queue>      // For using the queue data structure
using namespace std;

class RecentCounter {
private:
    queue<int> requests;  // To store the timestamps of the requests

public:
    // Constructor: Initializes the counter with zero recent requests
    RecentCounter() {
        // The queue is initialized empty
    }
    
    // Function to add a new request and return the number of requests in the last 3000 milliseconds
    int ping(int t) {
        // Add the new request to the queue
        requests.push(t);
        
        // Remove requests that are outside the 3000 ms range
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();  // Remove the oldest request
        }
        
        // Return the number of requests in the queue
        return requests.size();
    }
};

int main() {
    RecentCounter recentCounter;  // Create an instance of the RecentCounter class

    // Test cases
    cout << recentCounter.ping(1) << endl;     // Output: 1
    cout << recentCounter.ping(100) << endl;   // Output: 2
    cout << recentCounter.ping(3001) << endl;  // Output: 3
    cout << recentCounter.ping(3002) << endl;  // Output: 3

    return 0;
}

