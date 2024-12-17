#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // Create a set from the bank for quick access and to check if mutations are valid
        unordered_set<string> geneBank(bank.begin(), bank.end());
        
        // If endGene is not in the bank, return -1 as it’s not reachable
        if (!geneBank.count(endGene)) return -1;

        // Characters for mutations
        char genes[] = {'A', 'C', 'G', 'T'};
        
        // Queue to hold {current gene, number of mutations}
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        
        // Set to keep track of visited genes to prevent revisiting
        unordered_set<string> visited;
        visited.insert(startGene);
        
        // Start BFS
        while (!q.empty()) {
            auto [currentGene, mutations] = q.front();
            q.pop();
            
            // If we reached the endGene, return the mutation count
            if (currentGene == endGene) return mutations;
            
            // Try mutating each character of the current gene
            for (int i = 0; i < 8; i++) {
                char originalChar = currentGene[i];
                
                // Try all possible mutations with 'A', 'C', 'G', 'T'
                for (char gene : genes) {
                    if (gene == originalChar) continue; // Skip if same character
                    
                    // Create a new mutated gene
                    currentGene[i] = gene;
                    
                    // Check if the mutated gene is valid and hasn't been visited
                    if (geneBank.count(currentGene) && !visited.count(currentGene)) {
                        q.push({currentGene, mutations + 1});
                        visited.insert(currentGene); // Mark it as visited
                    }
                }
                
                // Restore the original character
                currentGene[i] = originalChar;
            }
        }
        
        // If we exhaust the BFS without finding the endGene, return -1
        return -1;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string startGene1 = "AACCGGTT";
    string endGene1 = "AACCGGTA";
    vector<string> bank1 = {"AACCGGTA"};
    cout << "Minimum mutations for test case 1: " << solution.minMutation(startGene1, endGene1, bank1) << endl;

    // Test case 2
    string startGene2 = "AACCGGTT";
    string endGene2 = "AAACGGTA";
    vector<string> bank2 = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    cout << "Minimum mutations for test case 2: " << solution.minMutation(startGene2, endGene2, bank2) << endl;

    // Test case 3 (No possible mutation)
    string startGene3 = "AACCGGTT";
    string endGene3 = "AACCGGTC";
    vector<string> bank3 = {"AACCGGTA"};
    cout << "Minimum mutations for test case 3: " << solution.minMutation(startGene3, endGene3, bank3) << endl;

    return 0;
}

