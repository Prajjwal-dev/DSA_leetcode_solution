#include <iostream>
#include <vector>
#include <algorithm>
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
    int pairSum(ListNode* head) {
        // Step 1: Use a vector to store the values of the linked list.
        vector<int> values;
        ListNode* current = head;
        while (current) {
            values.push_back(current->val);
            current = current->next;
        }

        // Step 2: Calculate the maximum twin sum.
        int maxSum = 0;
        int n = values.size();
        for (int i = 0; i < n / 2; ++i) {
            maxSum = max(maxSum, values[i] + values[n - 1 - i]);
        }

        return maxSum;
    }
};

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

// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution solution;

    // Test Case 1
    vector<int> values1 = {5, 4, 2, 1};
    ListNode* head1 = createList(values1);
    cout << "Original List 1: ";
    printList(head1);
    cout << "Maximum Twin Sum: " << solution.pairSum(head1) << endl;

    // Test Case 2
    vector<int> values2 = {4, 2, 2, 3};
    ListNode* head2 = createList(values2);
    cout << "Original List 2: ";
    printList(head2);
    cout << "Maximum Twin Sum: " << solution.pairSum(head2) << endl;

    // Test Case 3
    vector<int> values3 = {1, 100000};
    ListNode* head3 = createList(values3);
    cout << "Original List 3: ";
    printList(head3);
    cout << "Maximum Twin Sum: " << solution.pairSum(head3) << endl;

    return 0;
}

