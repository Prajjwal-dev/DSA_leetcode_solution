#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            n /= 5;  // Count how many times 5 is a factor
            count += n;  // Add the number of multiples of 5
        }
        return count;
    }
};

int main() {
    Solution solution;
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    int result = solution.trailingZeroes(n);
    cout << "The number of trailing zeroes in " << n << "! is: " << result << endl;
    
    return 0;
}

