#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Create a dummy node to simplify the merging process
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;  // Pointer to build the merged list

    // While both lists are non-empty, compare their values and attach the smaller node
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;  // Attach list1 node to merged list
            list1 = list1->next;    // Move list1 to the next node
        } else {
            current->next = list2;  // Attach list2 node to merged list
            list2 = list2->next;    // Move list2 to the next node
        }
        current = current->next;  // Move the merged list's current pointer forward
    }

    // If one list is exhausted, append the remaining nodes of the other list
    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // Return the merged list (skip the dummy node)
    return dummy->next;
}

// Utility function to print a linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example: list1 = [1,2,4], list2 = [1,3,4]
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Merge the two lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    return 0;
}

