#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect cycle in the linked list
bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        // No cycle if the list is empty or has only one node
        return false;
    }
    
    ListNode *slow = head;  // Slow pointer
    ListNode *fast = head;  // Fast pointer

    // Traverse the list with slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow pointer by 1 step
        fast = fast->next->next;     // Move fast pointer by 2 steps
        
        if (slow == fast) {          // If they meet, a cycle exists
            return true;
        }
    }

    // No cycle found
    return false;
}

// Utility function to create a cycle in the linked list at the given position
void createCycle(ListNode *head, int pos) {
    if (pos == -1) return;  // No cycle if position is -1

    ListNode *cycleNode = nullptr;
    ListNode *tail = head;
    int index = 0;

    // Traverse the list to find the tail and the node at position `pos`
    while (tail->next != nullptr) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }

    // Create the cycle by connecting the tail to the cycleNode
    if (cycleNode != nullptr) {
        tail->next = cycleNode;
    }
}

// Utility function to print the linked list (for debugging purposes)
void printList(ListNode *head) {
    ListNode *temp = head;
    int count = 0; // Limit the number of printed nodes to avoid infinite loops in case of a cycle
    while (temp != nullptr && count < 20) {
        cout << temp->val << " -> ";
        temp = temp->next;
        count++;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating the linked list [3,2,0,-4]
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    int pos = 1;  // The tail connects to the node at index 1 (0-indexed)
    
    // Create a cycle in the linked list
    createCycle(head, pos);

    // Check if the linked list has a cycle
    bool result = hasCycle(head);

    // Output the result
    if (result) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}

