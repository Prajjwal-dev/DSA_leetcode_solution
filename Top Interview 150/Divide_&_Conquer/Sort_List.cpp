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
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has one element, it is already sorted.
        if (!head || !head->next) {
            return head;
        }
        
        // Step 1: Split the linked list into two halves
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Break the link to create two separate lists

        // Step 2: Sort each half
        left = sortList(left);
        right = sortList(right);

        // Step 3: Merge the sorted halves
        return merge(left, right);
    }

private:
    // Function to get the middle node of the linked list
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        // Move 'fast' pointer twice as fast as 'slow' to find the middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Merge nodes from both lists in sorted order
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Append remaining nodes
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& arr) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : arr) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    Solution solution;

    // Example input
    vector<int> arr = {4, 2, 1, 3};
    ListNode* head = createList(arr);

    cout << "Original List: ";
    printList(head);

    // Sort the list
    ListNode* sortedHead = solution.sortList(head);

    cout << "Sorted List: ";
    printList(sortedHead);

    return 0;
}

