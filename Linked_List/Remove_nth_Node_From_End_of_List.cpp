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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Initialize a dummy node pointing to the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Step 2: Move `first` pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Step 3: Move `first` to the end, maintaining the gap with `second`
        while (first) {
            first = first->next;
            second = second->next;
        }

        // Step 4: Skip the nth node from the end
        ListNode* toDelete = second->next;
        second->next = second->next->next;
        delete toDelete;

        // Return the head of the modified list
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
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

    head1 = solution.removeNthFromEnd(head1, 2);
    cout << "List after removing 2nd node from the end: ";
    printList(head1);

    // Test Case 2
    ListNode* head2 = new ListNode(1);
    cout << "Original List 2: ";
    printList(head2);

    head2 = solution.removeNthFromEnd(head2, 1);
    cout << "List after removing 1st node from the end: ";
    printList(head2);

    // Test Case 3
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    cout << "Original List 3: ";
    printList(head3);

    head3 = solution.removeNthFromEnd(head3, 1);
    cout << "List after removing last node: ";
    printList(head3);

    return 0;
}

