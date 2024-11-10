#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for doubly linked list node
struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // Maps keys to their nodes
    Node* head; // Dummy head of the linked list
    Node* tail; // Dummy tail of the linked list
    
    // Helper to remove a node from the list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    // Helper to add a node right after the head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    // Helper to move a node to the front (most recent position)
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }
    
    // Helper to remove the least recently used node (node before tail)
    Node* removeTail() {
        Node* lru = tail->prev;
        removeNode(lru);
        return lru;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        // Initialize dummy head and tail nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }
        Node* node = cache[key];
        moveToHead(node); // Make this node the most recently used
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update the value and move it to the head
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            // Key doesn't exist, create a new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode); // Add new node at the front
            
            if (cache.size() > capacity) {
                // Cache capacity exceeded, remove the least recently used item
                Node* lru = removeTail();
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
};

/**
 * Test cases
 */
int main() {
    LRUCache lRUCache(2);
    
    // Test Case 1
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout << "Get 1: " << lRUCache.get(1) << endl; // returns 1, cache is {2=2, 1=1}
    
    // Test Case 2
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << "Get 2: " << lRUCache.get(2) << endl; // returns -1 (not found)
    
    // Test Case 3
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {3=3, 4=4}
    cout << "Get 1: " << lRUCache.get(1) << endl; // returns -1 (not found)
    cout << "Get 3: " << lRUCache.get(3) << endl; // returns 3
    cout << "Get 4: " << lRUCache.get(4) << endl; // returns 4
    
    return 0;
}

