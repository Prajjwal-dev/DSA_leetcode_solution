#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // DP table of size (m+1) x (n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill base cases
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;  // Converting to an empty string by deleting all characters
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;  // Converting from an empty string by inserting all characters
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    // If characters match, no new operation is needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // If characters don't match, take the minimum of insert, delete, or replace
                    dp[i][j] = min({dp[i - 1][j] + 1,    // Delete from word1
                                    dp[i][j - 1] + 1,    // Insert into word1
                                    dp[i - 1][j - 1] + 1 // Replace character
                                   });
                }
            }
        }

        // The last cell contains the minimum number of operations required
        return dp[m][n];
    }
};

// Driver code
int main() {
    Solution sol;
    
    // Test case 1
    string word1 = "horse";
    string word2 = "ros";
    cout << "Minimum operations to convert '" << word1 << "' to '" << word2 << "': "
         << sol.minDistance(word1, word2) << endl;

    // Test case 2
    string word1_2 = "intention";
    string word2_2 = "execution";
    cout << "Minimum operations to convert '" << word1_2 << "' to '" << word2_2 << "': "
         << sol.minDistance(word1_2, word2_2) << endl;

    return 0;
}

