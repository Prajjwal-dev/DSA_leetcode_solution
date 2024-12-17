#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());  // Convert vector to set for faster lookup
        
        // dp[i] will be true if s[0...i-1] can be segmented using wordDict
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;  // An empty string can always be segmented
        
        // Loop over the string
        for (int i = 1; i <= s.size(); ++i) {
            // Check every possible substring ending at position i
            for (int j = 0; j < i; ++j) {
                // If the substring s[0...j-1] can be segmented (dp[j] is true) 
                // and s[j...i-1] is in the wordSet, set dp[i] to true
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;  // No need to check further if we found a valid segmentation
                }
            }
        }
        
        // Return whether the entire string s can be segmented
        return dp[s.size()];
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << "Test Case 1: " << (solution.wordBreak(s1, wordDict1) ? "True" : "False") << endl;
    
    // Test case 2
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << "Test Case 2: " << (solution.wordBreak(s2, wordDict2) ? "True" : "False") << endl;
    
    // Test case 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Test Case 3: " << (solution.wordBreak(s3, wordDict3) ? "True" : "False") << endl;
    
    return 0;
}

