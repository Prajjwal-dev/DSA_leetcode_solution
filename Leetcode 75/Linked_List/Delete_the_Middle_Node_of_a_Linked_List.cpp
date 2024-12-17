#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // If the list has only one node, return nullptr
        if (!head || !head->next) return nullptr;

        // Two pointers: slow and fast
        ListNode *slow = head, *fast = head, *prev = nullptr;

        // Move fast pointer twice as fast as slow pointer
        while (fast && fast->next) {
            prev = slow;          // Keep track of the node before slow
            slow = slow->next;    // Move slow one step
            fast = fast->next->next; // Move fast two steps
        }

        // Slow is now at the middle node. Remove it.
        prev->next = slow->next;
        delete slow;

        return head;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {1, 3, 4, 7, 1, 2, 6};
    ListNode* head1 = createLinkedList(arr1);
    cout << "Original List: ";
    printLinkedList(head1);
    head1 = sol.deleteMiddle(head1);
    cout << "Modified List: ";
    printLinkedList(head1);

    // Test case 2
    vector<int> arr2 = {1, 2, 3, 4};
    ListNode* head2 = createLinkedList(arr2);
    cout << "Original List: ";
    printLinkedList(head2);
    head2 = sol.deleteMiddle(head2);
    cout << "Modified List: ";
    printLinkedList(head2);

    // Test case 3
    vector<int> arr3 = {2, 1};
    ListNode* head3 = createLinkedList(arr3);
    cout << "Original List: ";
    printLinkedList(head3);
    head3 = sol.deleteMiddle(head3);
    cout << "Modified List: ";
    printLinkedList(head3);

    // Test case 4: Single node
    vector<int> arr4 = {5};
    ListNode* head4 = createLinkedList(arr4);
    cout << "Original List: ";
    printLinkedList(head4);
    head4 = sol.deleteMiddle(head4);
    cout << "Modified List: ";
    printLinkedList(head4);

    return 0;
}

