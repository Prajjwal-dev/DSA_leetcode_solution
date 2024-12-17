#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Step 1: Create a map to group anagrams by their sorted string version
        unordered_map<string, vector<string>> anagramMap;

        // Step 2: Iterate over each string in the input array
        for (string str : strs) {
            // Step 3: Sort the string to get the key for the map
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            // Step 4: Add the original string to the map using the sorted string as the key
            anagramMap[sortedStr].push_back(str);
        }

        // Step 5: Prepare the result by extracting the grouped anagrams from the map
        vector<vector<string>> result;
        for (auto it : anagramMap) {
            result.push_back(it.second);
        }

        // Step 6: Return the grouped anagrams
        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = solution.groupAnagrams(strs1);
    for (const auto& group : result1) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    // Example 2
    vector<string> strs2 = {""};
    vector<vector<string>> result2 = solution.groupAnagrams(strs2);
    for (const auto& group : result2) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    // Example 3
    vector<string> strs3 = {"a"};
    vector<vector<string>> result3 = solution.groupAnagrams(strs3);
    for (const auto& group : result3) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}

