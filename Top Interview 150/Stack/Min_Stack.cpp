#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> s; // Stack to store all elements
    stack<int> minStack; // Stack to store minimum elements

    MinStack() {
        // Constructor initializes empty stacks.
    }

    // Push the value onto the main stack and update the min stack.
    void push(int val) {
        s.push(val); // Push to the main stack
        // If minStack is empty or val is <= current minimum, push to minStack.
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    // Pop the value from the main stack and update the min stack.
    void pop() {
        if (s.top() == minStack.top()) {
            minStack.pop(); // If the top of both stacks are the same, pop from minStack
        }
        s.pop(); // Pop from the main stack
    }

    // Get the top value from the main stack.
    int top() {
        return s.top();
    }

    // Get the minimum value from the minStack.
    int getMin() {
        return minStack.top(); // The minimum value is at the top of minStack.
    }
};

// Main function to test the MinStack
int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    // getMin() should return -3
    cout << "Current Minimum: " << minStack.getMin() << endl; // Output: -3

    // Pop the top element (-3)
    minStack.pop();

    // top() should return 0
    cout << "Top Element: " << minStack.top() << endl; // Output: 0

    // getMin() should return -2
    cout << "Current Minimum: " << minStack.getMin() << endl; // Output: -2

    return 0;
}

