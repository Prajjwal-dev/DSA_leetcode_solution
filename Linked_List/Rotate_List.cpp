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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            // If the list is empty, has only one node, or no rotation is needed
            return head;
        }
        
        // Step 1: Find the length of the list and the last node
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Step 2: Make the list circular by connecting the tail to the head
        tail->next = head;

        // Step 3: Calculate the actual number of rotations needed (mod length)
        k = k % length;
        
        // Step 4: Find the new tail (length - k - 1 steps from head) 
        // and the new head (newTail->next)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next; // This will be the new head
        newTail->next = nullptr; // Break the circular connection
        
        return newHead;
    }
};

// Helper function to create a linked list from an array
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
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    
    // Create linked list from vector
    ListNode* head = createList(arr);
    
    // Print original list
    cout << "Original list: ";
    printList(head);
    
    // Call rotateRight to rotate the list to the right by k places
    head = solution.rotateRight(head, k);
    
    // Print modified list after rotation
    cout << "List after rotating by " << k << " places: ";
    printList(head);

    return 0;
}

