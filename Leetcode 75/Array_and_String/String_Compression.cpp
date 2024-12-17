#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIndex = 0; // Index where we write the compressed characters
        int readIndex = 0;  // Index to traverse through the original array

        while (readIndex < chars.size()) {
            char currentChar = chars[readIndex];  // Current character being processed
            int count = 0;  // Count of consecutive characters

            // Count the consecutive characters
            while (readIndex < chars.size() && chars[readIndex] == currentChar) {
                readIndex++;
                count++;
            }

            // Write the character to the result
            chars[writeIndex++] = currentChar;

            // If the count is greater than 1, write the digits of the count
            if (count > 1) {
                string countStr = to_string(count);
                for (char digit : countStr) {
                    chars[writeIndex++] = digit;
                }
            }
        }

        // Return the length of the compressed array
        return writeIndex;
    }
};

// Function to print the compressed array
void printVector(const vector<char>& chars, int length) {
    for (int i = 0; i < length; i++) {
        cout << chars[i];
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int length1 = solution.compress(chars1);
    cout << "Compressed length: " << length1 << ", Result: ";
    printVector(chars1, length1);
    
    // Test case 2
    vector<char> chars2 = {'a'};
    int length2 = solution.compress(chars2);
    cout << "Compressed length: " << length2 << ", Result: ";
    printVector(chars2, length2);
    
    // Test case 3
    vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int length3 = solution.compress(chars3);
    cout << "Compressed length: " << length3 << ", Result: ";
    printVector(chars3, length3);
    
    return 0;
}

