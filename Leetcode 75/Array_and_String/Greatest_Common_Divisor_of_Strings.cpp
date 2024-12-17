#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Custom GCD function using Euclidean Algorithm
    int customGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    string gcdOfStrings(string str1, string str2) {
        // Check if concatenating the strings in both orders gives the same result.
        if (str1 + str2 != str2 + str1) {
            return ""; // If not, there's no common divisor string.
        }

        // Find the greatest common divisor (GCD) of the lengths of the two strings.
        int gcdLength = customGCD(str1.length(), str2.length());

        // Return the substring of str1 from 0 to gcdLength.
        return str1.substr(0, gcdLength);
    }
};

int main() {
    Solution solution; // Create an object of the Solution class

    // Test cases
    cout << "Test 1: " << solution.gcdOfStrings("ABCABC", "ABC") << endl; // Output: "ABC"
    cout << "Test 2: " << solution.gcdOfStrings("ABABAB", "ABAB") << endl; // Output: "AB"
    cout << "Test 3: " << solution.gcdOfStrings("LEET", "CODE") << endl; // Output: ""
    cout << "Test 4: " << solution.gcdOfStrings("AAAA", "AAAA") << endl; // Output: "AAAA"
    cout << "Test 5: " << solution.gcdOfStrings("ABC", "ABCABC") << endl; // Output: "ABC"

    return 0;
}

