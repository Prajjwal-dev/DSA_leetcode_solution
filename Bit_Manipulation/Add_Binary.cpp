#include <iostream>
#include <algorithm> // for reverse
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = ""; // to store the resulting binary sum
        int i = a.size() - 1; // pointer for string a (start from the last character)
        int j = b.size() - 1; // pointer for string b (start from the last character)
        int carry = 0; // to store the carry

        // Loop until both strings are exhausted or there's no carry left
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry; // initialize sum with carry
            
            // Add the corresponding bit from 'a' if available
            if (i >= 0) {
                sum += a[i] - '0'; // convert char '0'/'1' to int 0/1
                i--; // move to the next left bit in a
            }
            
            // Add the corresponding bit from 'b' if available
            if (j >= 0) {
                sum += b[j] - '0'; // convert char '0'/'1' to int 0/1
                j--; // move to the next left bit in b
            }
            
            // Append the current bit to result (sum % 2 gives 0 or 1)
            result += (sum % 2) + '0'; // convert the result back to char '0'/'1'
            
            // Calculate carry (sum / 2 gives the carry value)
            carry = sum / 2;
        }
        
        // The result is in reverse order, reverse it
        reverse(result.begin(), result.end());
        
        return result;
    }
};

// Driver code to test the function
int main() {
    Solution solution;
    string a, b;
    
    // Input binary strings
    cout << "Enter the first binary string: ";
    cin >> a;
    cout << "Enter the second binary string: ";
    cin >> b;
    
    // Call the addBinary method
    string result = solution.addBinary(a, b);
    
    // Output the result
    cout << "The sum of the two binary strings is: " << result << endl;
    
    return 0;
}

