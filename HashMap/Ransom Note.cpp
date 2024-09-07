#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        // Step 1: Create an unordered_map to store the frequency of each character in magazine
        std::unordered_map<char, int> magazineMap;

        // Step 2: Populate the map with characters from magazine
        for (char ch : magazine) {
            magazineMap[ch]++;
        }

        // Step 3: Traverse each character in ransomNote and check if it can be constructed
        for (char ch : ransomNote) {
            if (magazineMap[ch] > 0) {
                magazineMap[ch]--;  // Use one occurrence of the character
            } else {
                // If the character is not found or not enough in magazine, return false
                return false;
            }
        }

        // Step 4: If we can use all characters, return true
        return true;
    }
};

int main() {
    Solution solution;

    // Example 1
    std::string ransomNote1 = "a";
    std::string magazine1 = "b";
    std::cout << "Example 1: " << solution.canConstruct(ransomNote1, magazine1) << "\n";  // Output: false

    // Example 2
    std::string ransomNote2 = "aa";
    std::string magazine2 = "ab";
    std::cout << "Example 2: " << solution.canConstruct(ransomNote2, magazine2) << "\n";  // Output: false

    // Example 3
    std::string ransomNote3 = "aa";
    std::string magazine3 = "aab";
    std::cout << "Example 3: " << solution.canConstruct(ransomNote3, magazine3) << "\n";  // Output: true

    return 0;
}

