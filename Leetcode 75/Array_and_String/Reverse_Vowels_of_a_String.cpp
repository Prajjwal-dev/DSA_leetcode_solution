#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        // Define the set of vowels for quick lookup
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int left = 0;                 // Pointer at the beginning of the string
        int right = s.length() - 1;   // Pointer at the end of the string
        
        // Loop until both pointers meet
        while (left < right) {
            // Move left pointer until it finds a vowel
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            
            // Move right pointer until it finds a vowel
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }
            
            // Swap the vowels at the left and right pointers
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};

// Main function for testing
int main() {
    Solution solution;
    
    // Test cases
    string test1 = "IceCreAm";
    cout << "Input: " << test1 << "\nOutput: " << solution.reverseVowels(test1) << "\n\n";
    
    string test2 = "leetcode";
    cout << "Input: " << test2 << "\nOutput: " << solution.reverseVowels(test2) << "\n\n";
    
    string test3 = "programming";
    cout << "Input: " << test3 << "\nOutput: " << solution.reverseVowels(test3) << "\n\n";
    
    string test4 = "hello";
    cout << "Input: " << test4 << "\nOutput: " << solution.reverseVowels(test4) << "\n\n";

    return 0;
}

