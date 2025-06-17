#include <iostream>
using namespace std;

// ---------------------------------------------
// ✅ 1. Define the structure of Node
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
// ---------------------------------------------

// ✅ Utility: Print the Linked List
void printList(Node* head) {
    cout << "Linked List: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// ---------------------------------------------
// ✅ 2. Insert node at the end
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}
// ---------------------------------------------

// ✅ 3. Insert node at the head
void insertAtHead(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
// ---------------------------------------------

// ✅ 4. Delete a node by value
void deleteNode(Node* &head, int val) {
    if (head == nullptr) return;

    if (head->data == val) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != val)
        temp = temp->next;

    if (temp->next == nullptr) return; // Not found

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
// ---------------------------------------------

// ✅ 5. Find length of Linked List
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}
// ---------------------------------------------

// ✅ 6. Search an element in the list
bool searchElement(Node* head, int key) {
    while (head) {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}
// ---------------------------------------------

int main() {
    Node* head = nullptr;

    // Insert elements
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 5);

    printList(head); // 5 -> 10 -> 20 -> 30

    // Delete node
    deleteNode(head, 20);
    printList(head); // 5 -> 10 -> 30

    // Length of list
    cout << "Length: " << getLength(head) << "\n"; // 3

    // Search element
    int key = 10;
    cout << "Is " << key << " present? " << (searchElement(head, key) ? "Yes" : "No") << "\n";

    key = 50;
    cout << "Is " << key << " present? " << (searchElement(head, key) ? "Yes" : "No") << "\n";

    return 0;
}
