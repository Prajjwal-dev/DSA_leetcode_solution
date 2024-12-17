#include <iostream>
#include <set>
using namespace std;

class SmallestInfiniteSet {
private:
    set<int> s; // To store all the numbers in the set
    int nextSmallest; // To track the next smallest number (counter)

public:
    // Constructor: Initializes the set with all positive integers
    SmallestInfiniteSet() {
        nextSmallest = 1; // Start with 1
    }
    
    // Removes and returns the smallest integer in the set
    int popSmallest() {
        if (!s.empty()) {
            // If there are elements added back, return the smallest
            int smallest = *s.begin(); // Get the smallest element from the set
            s.erase(smallest); // Remove it from the set
            return smallest; 
        } 
        // Otherwise, return the next smallest number from the infinite set
        return nextSmallest++;
    }
    
    // Adds a number back into the set if it's not already present
    void addBack(int num) {
        if (num < nextSmallest) {
            s.insert(num); // Add back the number to the set
        }
    }
};

int main() {
    SmallestInfiniteSet smallestInfiniteSet; // Initialize the object

    // Test the given example
    cout << "Output of test case:" << endl;
    smallestInfiniteSet.addBack(2);    // No change as 2 is already present
    cout << smallestInfiniteSet.popSmallest() << endl; // 1
    cout << smallestInfiniteSet.popSmallest() << endl; // 2
    cout << smallestInfiniteSet.popSmallest() << endl; // 3
    smallestInfiniteSet.addBack(1);    // Add 1 back to the set
    cout << smallestInfiniteSet.popSmallest() << endl; // 1
    cout << smallestInfiniteSet.popSmallest() << endl; // 4
    cout << smallestInfiniteSet.popSmallest() << endl; // 5

    return 0;
}

