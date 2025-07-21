// singly linked list - insert

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at the head (beginning) of the list
void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Insert at the tail (end) of the list
void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

// Insert at a specific position in the list
void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    // If position is 1, insert at the head
    if (position == 1) {
        insertAtHead(head, data);
        if (tail == NULL) {
            tail = head;  // if list was empty, head and tail are the same
        }
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the position where insertion is required
    while (cnt < position - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    // If inserting at the end, update the tail
    if (temp->next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    // Insert in the middle
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Initialize head and tail pointers
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting at head
    insertAtHead(head, 10);
    tail = head;  // As it is the first node, head and tail are the same
    display(head);

    insertAtHead(head, 20);
    display(head);

    // Inserting at tail
    insertAtTail(tail, 30);
    display(head);

    // Inserting at a specific position
    insertAtPosition(head, tail, 2, 25);
    display(head);

    return 0;
}