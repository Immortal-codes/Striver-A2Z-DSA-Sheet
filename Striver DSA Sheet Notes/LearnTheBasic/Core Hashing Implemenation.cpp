#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

// Hash table class
class HashTable {
    Node** table;  // array of pointers to linked lists
    int capacity;  // size of the hash table

    // Simple hash function
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    // Constructor
    HashTable(int size) {
        capacity = size;
        table = new Node*[capacity];
        for (int i = 0; i < capacity; i++) table[i] = nullptr;
    }

    // Insert key into hash table
    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Search key in hash table
    bool search(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr) {
            if (curr->key == key) return true;
            curr = curr->next;
        }
        return false;
    }

    // Delete key from hash table
    void remove(int key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        Node* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev) prev->next = curr->next;
                else table[index] = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            Node* curr = table[i];
            while (curr) {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }

    // Destructor
    ~HashTable() {
        for (int i = 0; i < capacity; i++) {
            Node* curr = table[i];
            while (curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main() {
    HashTable ht(10);  // create a hash table of size 10

    ht.insert(15);
    ht.insert(25);
    ht.insert(35);
    ht.insert(5);

    ht.display();

    cout << "Search 25: " << (ht.search(25) ? "Found" : "Not Found") << "\n";
    cout << "Search 100: " << (ht.search(100) ? "Found" : "Not Found") << "\n";

    ht.remove(25);
    cout << "After deleting 25:\n";
    ht.display();

    return 0;
}
