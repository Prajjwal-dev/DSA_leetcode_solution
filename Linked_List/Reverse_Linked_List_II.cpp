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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Step 1: Initialize a dummy node to handle edge cases easily.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Step 2: Move `prev` to the node before the `left` position.
        ListNode* prev = dummy;
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // Step 3: Start reversing from `left` to `right`.
        ListNode* current = prev->next;
        ListNode* next = nullptr;
        ListNode* reverseHead = nullptr;
        
        for (int i = 0; i < right - left + 1; ++i) {
            next = current->next;        // Store the next node
            current->next = reverseHead; // Reverse the link
            reverseHead = current;       // Move reverseHead forward
            current = next;              // Move current forward
        }

        // Step 4: Connect the reversed portion back to the list
        prev->next->next = current; // Connect the end of reversed list to the remaining list
        prev->next = reverseHead;   // Connect the beginning of reversed list to prev

        // Return the new head
        return dummy->next;
    }
};

// Helper functions for testing
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test Case 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    Solution solution;
    cout << "Original List 1: ";
    printList(head1);

    head1 = solution.reverseBetween(head1, 2, 4);
    cout << "Reversed List 1 (positions 2 to 4): ";
    printList(head1);

    // Test Case 2
    ListNode* head2 = new ListNode(5);
    cout << "Original List 2: ";
    printList(head2);

    head2 = solution.reverseBetween(head2, 1, 1);
    cout << "Reversed List 2 (positions 1 to 1): ";
    printList(head2);

    return 0;
}

