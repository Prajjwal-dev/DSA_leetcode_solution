#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head; // If list is empty or k=1, return head
        
        ListNode dummy(0); // Dummy node for easier manipulation
        dummy.next = head;
        ListNode* prev = &dummy, *curr = head, *next = nullptr;
        
        // Count total nodes in the list
        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }
        
        curr = head; // Reset current pointer to head
        
        // Process groups of size k
        while (count >= k) {
            next = curr->next; // Store next node
            // Reverse k nodes
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;       // Move prev to the last node of the reversed group
            curr = curr->next; // Move curr to the start of the next group
            count -= k;        // Decrease count by k
        }
        
        return dummy.next; // Return new head of the list
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test Case 1: Normal case
    vector<int> vals1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    ListNode* head1 = createList(vals1);
    cout << "Original List: ";
    printList(head1);
    ListNode* result1 = solution.reverseKGroup(head1, k1);
    cout << "Reversed in groups of " << k1 << ": ";
    printList(result1);

    // Test Case 2: Normal case with k = 3
    vector<int> vals2 = {1, 2, 3, 4, 5};
    int k2 = 3;
    ListNode* head2 = createList(vals2);
    cout << "Original List: ";
    printList(head2);
    ListNode* result2 = solution.reverseKGroup(head2, k2);
    cout << "Reversed in groups of " << k2 << ": ";
    printList(result2);

    // Test Case 3: Single node
    vector<int> vals3 = {1};
    int k3 = 1;
    ListNode* head3 = createList(vals3);
    cout << "Original List: ";
    printList(head3);
    ListNode* result3 = solution.reverseKGroup(head3, k3);
    cout << "Reversed in groups of " << k3 << ": ";
    printList(result3);

    // Test Case 4: k larger than the list length
    vector<int> vals4 = {1, 2, 3};
    int k4 = 4;
    ListNode* head4 = createList(vals4);
    cout << "Original List: ";
    printList(head4);
    ListNode* result4 = solution.reverseKGroup(head4, k4);
    cout << "Reversed in groups of " << k4 << ": ";
    printList(result4);

    // Test Case 5: k = list length
    vector<int> vals5 = {1, 2, 3, 4, 5};
    int k5 = 5;
    ListNode* head5 = createList(vals5);
    cout << "Original List: ";
    printList(head5);
    ListNode* result5 = solution.reverseKGroup(head5, k5);
    cout << "Reversed in groups of " << k5 << ": ";
    printList(result5);

    return 0;
}

