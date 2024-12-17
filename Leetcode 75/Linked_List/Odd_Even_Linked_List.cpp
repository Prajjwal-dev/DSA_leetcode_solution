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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            // If there are no nodes or just one node, return the head as it is.
            return head;
        }

        // Pointers for odd and even lists
        ListNode* odd = head;             // Start with the first node (odd index)
        ListNode* even = head->next;      // Second node (even index)
        ListNode* evenHead = even;        // Save the start of the even list

        // Iterate through the list
        while (even && even->next) {
            odd->next = even->next;       // Connect odd nodes
            odd = odd->next;              // Move odd pointer to the next odd node

            even->next = odd->next;       // Connect even nodes
            even = even->next;            // Move even pointer to the next even node
        }

        odd->next = evenHead;             // Connect the end of odd list to the start of even list
        return head;                      // Return the reordered list
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Test Case 1
    vector<int> values1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(values1);
    cout << "Original List 1: ";
    printList(head1);
    head1 = solution.oddEvenList(head1);
    cout << "Reordered List 1: ";
    printList(head1);

    // Test Case 2
    vector<int> values2 = {2, 1, 3, 5, 6, 4, 7};
    ListNode* head2 = createList(values2);
    cout << "Original List 2: ";
    printList(head2);
    head2 = solution.oddEvenList(head2);
    cout << "Reordered List 2: ";
    printList(head2);

    // Test Case 3: Empty List
    vector<int> values3 = {};
    ListNode* head3 = createList(values3);
    cout << "Original List 3: ";
    printList(head3);
    head3 = solution.oddEvenList(head3);
    cout << "Reordered List 3: ";
    printList(head3);

    // Test Case 4: Single Node List
    vector<int> values4 = {10};
    ListNode* head4 = createList(values4);
    cout << "Original List 4: ";
    printList(head4);
    head4 = solution.oddEvenList(head4);
    cout << "Reordered List 4: ";
    printList(head4);

    return 0;
}

