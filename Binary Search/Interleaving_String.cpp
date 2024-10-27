#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();

        // If the length of s3 is not the sum of s1 and s2, return false
        if (n1 + n2 != n3) return false;

        // Create a DP table with size (n1+1) x (n2+1)
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));

        // Initialize the DP table
        dp[0][0] = true; // Both s1 and s2 are empty, so s3 is also empty

        // Fill the first row (using only s2)
        for (int j = 1; j <= n2; j++) {
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }

        // Fill the first column (using only s1)
        for (int i = 1; i <= n1; i++) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        // Return the result from the last cell, which indicates if s1 and s2 can interleave to form s3
        return dp[n1][n2];
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout << "Is interleaving: " << (solution.isInterleave(s1, s2, s3) ? "true" : "false") << endl;

    // Test Case 2
    s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    cout << "Is interleaving: " << (solution.isInterleave(s1, s2, s3) ? "true" : "false") << endl;

    // Test Case 3
    s1 = "", s2 = "", s3 = "";
    cout << "Is interleaving: " << (solution.isInterleave(s1, s2, s3) ? "true" : "false") << endl;

    return 0;
}

