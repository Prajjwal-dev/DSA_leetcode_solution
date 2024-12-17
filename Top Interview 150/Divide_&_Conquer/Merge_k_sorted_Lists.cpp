#include <iostream>
#include <vector>
#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store (value, node) pairs for sorting
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        // Push the head of each non-empty list into the heap
        for (ListNode* list : lists) {
            if (list) minHeap.push(list);
        }

        ListNode* dummy = new ListNode(-1); // Dummy node for result list
        ListNode* tail = dummy;

        // Merge process
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top(); // Get smallest node
            minHeap.pop();
            tail->next = smallest; // Append smallest node to the result list
            tail = tail->next;

            if (smallest->next) { 
                minHeap.push(smallest->next); // Push the next node from the same list
            }
        }

        return dummy->next; // Return the merged list starting after dummy
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<ListNode*> lists1 = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };
    cout << "Merged List (Test Case 1): ";
    printList(sol.mergeKLists(lists1));

    // Test case 2
    vector<ListNode*> lists2 = {};
    cout << "Merged List (Test Case 2): ";
    printList(sol.mergeKLists(lists2));

    // Test case 3
    vector<ListNode*> lists3 = {createList({})};
    cout << "Merged List (Test Case 3): ";
    printList(sol.mergeKLists(lists3));

    return 0;
}

