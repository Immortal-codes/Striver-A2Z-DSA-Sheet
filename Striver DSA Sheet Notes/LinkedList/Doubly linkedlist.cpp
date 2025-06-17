#include <iostream>
using namespace std;

// ---------------------------------------------
// ✅ 1. Structure of Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};
// ---------------------------------------------

// ✅ Utility: Print DLL Forward
void printDLL(Node* head) {
    cout << "DLL (Forward): ";
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// ✅ Utility: Print DLL Backward
void printDLLReverse(Node* tail) {
    cout << "DLL (Backward): ";
    while (tail) {
        cout << tail->data << " <-> ";
        tail = tail->prev;
    }
    cout << "NULL\n";
}

// ---------------------------------------------
// ✅ 2. Insert at head
void insertAtHead(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}
// ---------------------------------------------

// ✅ 3. Insert at tail
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
    newNode->prev = temp;
}
// ---------------------------------------------

// ✅ 4. Delete node by value
void deleteNode(Node* &head, int val) {
    if (head == nullptr) return;

    Node* temp = head;

    // If head needs to be deleted
    if (temp->data == val) {
        head = temp->next;
        if (head) head->prev = nullptr;
        delete temp;
        return;
    }

    // Traverse to find the node
    while (temp && temp->data != val)
        temp = temp->next;

    if (!temp) return; // not found

    // Update links
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    delete temp;
}
// ---------------------------------------------

// ✅ 5. Reverse the DLL
Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* curr = head;
    Node* temp = nullptr;

    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    // New head is last node before NULL
    if (temp != nullptr)
        head = temp->prev;

    return head;
}
// ---------------------------------------------

int main() {
    Node* head = nullptr;

    // Insert values
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 5);

    printDLL(head);

    // Delete a node
    deleteNode(head, 20);
    printDLL(head);

    // Reverse DLL
    head = reverseDLL(head);
    printDLL(head);

    return 0;
}
