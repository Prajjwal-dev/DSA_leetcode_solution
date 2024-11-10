#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/* Definition for a Node. */
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create new nodes interleaved with the original nodes
        Node* current = head;
        while (current) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        // Step 2: Set random pointers for the new nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Step 3: Separate the original list and the copied list
        Node* dummyHead = new Node(0);
        Node* copyCurrent = dummyHead;
        current = head;
        while (current) {
            copyCurrent->next = current->next;
            current->next = current->next->next;
            current = current->next;
            copyCurrent = copyCurrent->next;
        }

        return dummyHead->next;
    }
};

// Helper function to create a linked list with random pointers from a vector of pairs
Node* createLinkedList(const vector<pair<int, int>>& values) {
    unordered_map<int, Node*> nodeMap;
    Node* head = nullptr;
    Node* prev = nullptr;

    // Create nodes with values
    for (int i = 0; i < values.size(); ++i) {
        Node* node = new Node(values[i].first);
        nodeMap[i] = node;
        if (!head) head = node;
        if (prev) prev->next = node;
        prev = node;
    }

    // Set random pointers based on the second element in each pair
    Node* current = head;
    for (int i = 0; i < values.size(); ++i) {
        if (values[i].second != -1) {
            current->random = nodeMap[values[i].second];
        }
        current = current->next;
    }

    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << "Node value: " << head->val 
             << ", Random: " << (head->random ? to_string(head->random->val) : "null") 
             << endl;
        head = head->next;
    }
}

int main() {
    // Test case 1
    vector<pair<int, int>> listData1 = {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
    Node* head1 = createLinkedList(listData1);

    Solution solution;
    Node* copiedHead1 = solution.copyRandomList(head1);

    cout << "Original List:" << endl;
    printList(head1);
    cout << "Copied List:" << endl;
    printList(copiedHead1);

    // Test case 2
    cout << "\nTest case 2:" << endl;
    vector<pair<int, int>> listData2 = {{1, 1}, {2, 1}};
    Node* head2 = createLinkedList(listData2);
    Node* copiedHead2 = solution.copyRandomList(head2);

    cout << "Original List:" << endl;
    printList(head2);
    cout << "Copied List:" << endl;
    printList(copiedHead2);

    // Test case 3
    cout << "\nTest case 3:" << endl;
    vector<pair<int, int>> listData3 = {{3, -1}, {3, 0}, {3, -1}};
    Node* head3 = createLinkedList(listData3);
    Node* copiedHead3 = solution.copyRandomList(head3);

    cout << "Original List:" << endl;
    printList(head3);
    cout << "Copied List:" << endl;
    printList(copiedHead3);

    return 0;
}

