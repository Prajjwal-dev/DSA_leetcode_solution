#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>  // For rand()

class RandomizedSet {
    std::unordered_map<int, int> map; // Maps value to its index in the vector
    std::vector<int> values;          // Stores the elements for quick random access

public:
    // Constructor: Initializes the RandomizedSet object
    RandomizedSet() {}

    // Inserts an item val into the set if not already present.
    // Returns true if the item was inserted, false otherwise.
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false; // The value already exists
        }
        values.push_back(val);  // Add the value to the vector
        map[val] = values.size() - 1; // Map the value to its index in the vector
        return true;
    }

    // Removes an item val from the set if it is present.
    // Returns true if the item was removed, false otherwise.
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false; // The value doesn't exist
        }
        // Get the index of the value to be removed
        int idx = map[val];
        // Replace the element to be removed with the last element in the vector
        int lastVal = values.back();
        values[idx] = lastVal;
        map[lastVal] = idx; // Update the index of the last element in the map
        // Remove the last element from the vector and the map
        values.pop_back();
        map.erase(val); // Remove the value from the map
        return true;
    }

    // Returns a random element from the set.
    // All elements must have an equal probability of being returned.
    int getRandom() {
        int randIdx = rand() % values.size(); // Generate a random index
        return values[randIdx];               // Return the value at that index
    }
};

int main() {
    // Creating the RandomizedSet object
    RandomizedSet randomizedSet;

    // Testing insert function
    std::cout << std::boolalpha;  // Enable boolean output as true/false
    std::cout << "Insert 1: " << randomizedSet.insert(1) << std::endl; // Should return true
    std::cout << "Insert 2: " << randomizedSet.insert(2) << std::endl; // Should return true
    std::cout << "Insert 1 again: " << randomizedSet.insert(1) << std::endl; // Should return false

    // Testing remove function
    std::cout << "Remove 2: " << randomizedSet.remove(2) << std::endl; // Should return true
    std::cout << "Remove 2 again: " << randomizedSet.remove(2) << std::endl; // Should return false

    // Testing getRandom function
    std::cout << "Random element: " << randomizedSet.getRandom() << std::endl; // Should return 1, since only 1 is left

    // Further operations
    std::cout << "Insert 2 again: " << randomizedSet.insert(2) << std::endl; // Should return true
    std::cout << "Random element: " << randomizedSet.getRandom() << std::endl; // Should return either 1 or 2

    return 0;
}

