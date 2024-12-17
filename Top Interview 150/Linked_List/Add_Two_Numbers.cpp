#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize a dummy node to help with the linked list creation
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry) {
            // Get values of the current nodes of l1 and l2, if available
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            // Compute the sum and carry
            int sum = x + y + carry;
            carry = sum / 10;  // Carry for the next iteration
            sum = sum % 10;    // Current digit to store

            // Create a new node with the sum value
            curr->next = new ListNode(sum);
            curr = curr->next;  // Move to the next node

            // Move to the next nodes in l1 and l2, if available
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Return the result list starting from the node after dummy
        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array of integers
ListNode* createList(int arr[], int n) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Main function
int main() {
    Solution solution;

    // Example 1:
    int arr1[] = {2, 4, 3};  // Represents the number 342
    int arr2[] = {5, 6, 4};  // Represents the number 465
    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    // Add the two numbers
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    std::cout << "Result for Example 1: ";
    printList(result);  // Output should be [7, 0, 8] (342 + 465 = 807)

    return 0;
}

