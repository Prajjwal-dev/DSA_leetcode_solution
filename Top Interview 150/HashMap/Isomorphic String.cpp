#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Step 1: Declare two hashmaps to store mappings from s to t and t to s
        unordered_map<char, char> s_to_t_map;
        unordered_map<char, char> t_to_s_map;

        // Step 2: Traverse both strings simultaneously
        for (int i = 0; i < s.length(); ++i) {
            char s_char = s[i];
            char t_char = t[i];

            // Step 3: Check if the current character in s has been mapped to a character in t
            if (s_to_t_map.count(s_char)) {
                // If the character is mapped but not to the correct character, return false
                if (s_to_t_map[s_char] != t_char) {
                    return false;
                }
            } else {
                // If not mapped, add a new mapping from s_char to t_char
                s_to_t_map[s_char] = t_char;
            }

            // Step 4: Check if the current character in t has been mapped to a character in s
            if (t_to_s_map.count(t_char)) {
                // If the character is mapped but not to the correct character, return false
                if (t_to_s_map[t_char] != s_char) {
                    return false;
                }
            } else {
                // If not mapped, add a new mapping from t_char to s_char
                t_to_s_map[t_char] = s_char;
            }
        }

        // Step 5: If no conflicts were found, the strings are isomorphic
        return true;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "egg", t1 = "add";
    cout << solution.isIsomorphic(s1, t1) << endl;  // Output: true

    string s2 = "foo", t2 = "bar";
    cout << solution.isIsomorphic(s2, t2) << endl;  // Output: false

    string s3 = "paper", t3 = "title";
    cout << solution.isIsomorphic(s3, t3) << endl;  // Output: true

    return 0;
}

