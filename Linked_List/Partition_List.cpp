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

// Solution class with partition function
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Creating two dummy nodes for two lists
        ListNode* lessHead = new ListNode(0); // dummy head for nodes less than x
        ListNode* greaterHead = new ListNode(0); // dummy head for nodes greater or equal to x
        
        ListNode* less = lessHead; // pointer to the current end of the 'less' list
        ListNode* greater = greaterHead; // pointer to the current end of the 'greater' list
        
        while (head) {
            if (head->val < x) {
                less->next = head; // attach current node to 'less' list
                less = less->next; // move to next node in 'less' list
            } else {
                greater->next = head; // attach current node to 'greater' list
                greater = greater->next; // move to next node in 'greater' list
            }
            head = head->next; // move to the next node in the original list
        }
        
        greater->next = nullptr; // end of 'greater' list
        less->next = greaterHead->next; // connect 'less' list with 'greater' list

        return lessHead->next; // return the head of the modified list
    }
};

// Function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the partition function
int main() {
    // Test case 1: head = [1,4,3,2,5,2], x = 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;
    
    Solution solution;
    ListNode* result = solution.partition(head, x);
    
    cout << "Partitioned List for x = " << x << ": ";
    printList(result); // Expected output: 1 2 2 4 3 5
    
    // Test case 2: head = [2,1], x = 2
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);

    x = 2;
    
    result = solution.partition(head2, x);
    
    cout << "Partitioned List for x = " << x << ": ";
    printList(result); // Expected output: 1 2

    return 0;
}

