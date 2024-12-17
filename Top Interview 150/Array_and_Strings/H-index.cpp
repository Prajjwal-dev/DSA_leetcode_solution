#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int>& citations) {
    int n = citations.size();  // Get the number of papers
    sort(citations.begin(), citations.end(), greater<int>());  // Sort citations in descending order

    // Iterate through the sorted list to find the h-index
    for (int i = 0; i < n; ++i) {
        if (citations[i] <= i) {
            return i;  // If citations[i] <= i, then h-index is i
        }
    }
    return n;  // If all papers have citations greater than their index, h-index is n
}

int main() {
    // Example test cases
    vector<int> citations1 = {3, 0, 6, 1, 5};
    vector<int> citations2 = {1, 3, 1};

    cout << "H-index for citations1: " << hIndex(citations1) << endl;  // Output: 3
    cout << "H-index for citations2: " << hIndex(citations2) << endl;  // Output: 1

    return 0;
}

