#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    // HashMap to store the visited node and its clone
    unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        // If the node is null, return null
        if (node == nullptr) return nullptr;

        // If the node has already been cloned, return the clone from the map
        if (cloned.find(node) != cloned.end()) {
            return cloned[node];
        }

        // Create a new clone for the given node
        Node* clone = new Node(node->val);
        cloned[node] = clone;  // Save the clone to the map

        // Iterate through each neighbor and clone it recursively
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};

int main() {
    Solution solution;

    // Test Case 1: Graph with 4 nodes
    // Node 1 connected to 2 and 4
    // Node 2 connected to 1 and 3
    // Node 3 connected to 2 and 4
    // Node 4 connected to 1 and 3

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Node* clonedGraph = solution.cloneGraph(node1);

    // Printing the cloned graph structure
    cout << "Cloned Node 1's neighbors: ";
    for (Node* neighbor : clonedGraph->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    cout << "Cloned Node 2's neighbors: ";
    for (Node* neighbor : clonedGraph->neighbors[0]->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    // Additional cases: Empty graph, single-node graph
    Node* singleNode = new Node(1);
    Node* clonedSingle = solution.cloneGraph(singleNode);
    cout << "Single Node Graph Clone: " << clonedSingle->val << endl;  // Should print 1

    Node* emptyNode = nullptr;
    Node* clonedEmpty = solution.cloneGraph(emptyNode);
    cout << "Empty Node Graph Clone: " << (clonedEmpty == nullptr ? "null" : "not null") << endl;  // Should print "null"

    return 0;
}

