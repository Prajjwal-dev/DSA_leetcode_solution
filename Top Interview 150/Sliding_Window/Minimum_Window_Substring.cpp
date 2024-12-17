#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // Frequency map for the target string `t`
        unordered_map<char, int> tFreq;
        for (char c : t) tFreq[c]++;

        int required = tFreq.size(); // Number of unique characters in `t`
        int l = 0, r = 0, formed = 0;

        // Frequency map for the current window
        unordered_map<char, int> windowFreq;

        // Track the minimum window
        int minLength = INT_MAX;
        int start = 0;

        while (r < s.length()) {
            // Add the current character to the window
            char c = s[r];
            windowFreq[c]++;
            
            // If the current character's frequency matches the target, increment `formed`
            if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
                formed++;
            }

            // Try to shrink the window
            while (l <= r && formed == required) {
                c = s[l];

                // Update the minimum window if necessary
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    start = l;
                }

                // Remove the leftmost character from the window
                windowFreq[c]--;
                if (tFreq.count(c) && windowFreq[c] < tFreq[c]) {
                    formed--;
                }
                l++;
            }

            // Expand the window
            r++;
        }

        // Return the result
        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};

int main() {
    Solution solution;

    // Test case 1
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Input: s = \"" << s1 << "\", t = \"" << t1 << "\"\n";
    cout << "Output: \"" << solution.minWindow(s1, t1) << "\"\n\n";

    // Test case 2
    string s2 = "a", t2 = "a";
    cout << "Input: s = \"" << s2 << "\", t = \"" << t2 << "\"\n";
    cout << "Output: \"" << solution.minWindow(s2, t2) << "\"\n\n";

    // Test case 3
    string s3 = "a", t3 = "aa";
    cout << "Input: s = \"" << s3 << "\", t = \"" << t3 << "\"\n";
    cout << "Output: \"" << solution.minWindow(s3, t3) << "\"\n";

    return 0;
}

