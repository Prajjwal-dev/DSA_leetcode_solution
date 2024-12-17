#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        int sum, rem;
        std::unordered_set<int> seenNumbers;  // To track numbers we've already seen to detect cycles
        
        while (n != 1 && seenNumbers.find(n) == seenNumbers.end()) {
            seenNumbers.insert(n);  // Add the number to the set
            
            sum = 0;
            while (n > 0) {
                rem = n % 10;
                sum += rem * rem;  // Square the digit and add to sum
                n = n / 10;  // Move to the next digit
            }
            
            n = sum;  // Set n to the sum of squares
        }
        
        return n == 1;  // If we exited the loop because n is 1, return true; otherwise, false
    }
};

int main() {
    Solution solution;
    
    // Test with some example inputs
    int n1 = 19;
    int n2 = 2;
    
    std::cout << "Is " << n1 << " a happy number? " << (solution.isHappy(n1) ? "Yes" : "No") << std::endl;
    std::cout << "Is " << n2 << " a happy number? " << (solution.isHappy(n2) ? "Yes" : "No") << std::endl;
    
    return 0;
}

