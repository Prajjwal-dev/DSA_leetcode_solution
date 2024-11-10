#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node to simplify edge cases where head may be deleted
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;  // 'prev' points to the last node known to be distinct
        ListNode* curr = head;   // 'curr' traverses the list to detect duplicates

        // Traverse the entire list
        while (curr != nullptr) {
            // Check if 'curr' is the start of a duplicate sequence
            if (curr->next != nullptr && curr->val == curr->next->val) {
                // Skip nodes with the same value
                while (curr->next != nullptr && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                // Connect 'prev' to the node after duplicates
                prev->next = curr->next;
            } else {
                // No duplicates detected, move 'prev' forward
                prev = prev->next;
            }
            // Move 'curr' to the next node in the list
            curr = curr->next;
        }
        
        // Return the modified list, starting from dummy->next (skipping the dummy node)
        return dummy->next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Example input
    vector<int> arr = {1, 2, 3, 3, 4, 4, 5};
    
    // Create linked list from vector
    ListNode* head = createList(arr);
    
    // Print original list
    cout << "Original list: ";
    printList(head);
    
    // Call deleteDuplicates to remove duplicates
    head = solution.deleteDuplicates(head);
    
    // Print modified list after removing duplicates
    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

