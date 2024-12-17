#include <iostream>
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
    // Iterative approach to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;   // Previous node (starts as nullptr)
        ListNode* current = head;   // Current node starts at head
        
        while (current != nullptr) {
            ListNode* next = current->next;  // Store the next node
            current->next = prev;            // Reverse the link
            prev = current;                  // Move prev to the current node
            current = next;                  // Move current to the next node
        }
        
        return prev;  // New head of the reversed list
    }
};

// Function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Test case 1: [1, 2, 3, 4, 5]
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createLinkedList(arr1, 5);
    cout << "Original List 1: ";
    printLinkedList(head1);
    
    head1 = solution.reverseList(head1);
    cout << "Reversed List 1: ";
    printLinkedList(head1);
    
    // Test case 2: [1, 2]
    int arr2[] = {1, 2};
    ListNode* head2 = createLinkedList(arr2, 2);
    cout << "Original List 2: ";
    printLinkedList(head2);
    
    head2 = solution.reverseList(head2);
    cout << "Reversed List 2: ";
    printLinkedList(head2);
    
    // Test case 3: []
    int arr3[] = {};
    ListNode* head3 = createLinkedList(arr3, 0);
    cout << "Original List 3: ";
    printLinkedList(head3);
    
    head3 = solution.reverseList(head3);
    cout << "Reversed List 3: ";
    printLinkedList(head3);
    
    return 0;
}

