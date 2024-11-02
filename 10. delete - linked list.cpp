// singly linked list - delete

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    // Destructor
    ~Node() {
        int val = this->data;
        cout << "Memory freed for node with value " << val << endl;
    }
};

// Function to calculate the length of the list
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Deleting from the head (start) of the list
void deleteAtHead(Node* &head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;  // Update the previous pointer of the new head
    }
    temp->next = NULL;  // Disconnect the node
    delete temp;  // Free memory
}

// Deleting from the tail (end) of the list
void deleteAtTail(Node* &head, Node* &tail) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL) {  // Single node case
        deleteAtHead(head);
        tail = NULL;  // Update tail
        return;
    }

    Node* temp = tail;  // Store the tail
    tail = tail->prev;  // Move tail pointer to the previous node
    tail->next = NULL;  // Disconnect the old tail
    temp->prev = NULL;  // Disconnect the node
    delete temp;  // Free memory
}

// Deleting from a specific position
void deleteAtPosition(Node* &head, Node* &tail, int position) {
    if (position == 1) {
        deleteAtHead(head);
        if (head == NULL) {
            tail = NULL;  // List becomes empty
        }
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    int cnt = 1;

    while (cnt < position && temp != NULL) {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (temp->next == NULL) {  // If it's the last node
        deleteAtTail(head, tail);
        return;
    }

    prev->next = temp->next;  // Link previous node to next node
    temp->next->prev = prev;  // Link next node back to previous
    temp->next = NULL;  // Disconnect the node
    temp->prev = NULL;  // Disconnect the node
    delete temp;  // Free memory
}

// Function to delete the middle node
void deleteMiddle(Node* &head, Node* &tail) {
    if (head == NULL || head->next == NULL) {
        cout << "List is too short to delete a middle node!" << endl;
        return;
    }

    // Step 1: Calculate the length of the list
    int length = getLength(head);

    // Step 2: Find the middle position
    int middle = length / 2 + 1;  // Middle node for odd and even length lists

    // Step 3: Delete the node at the middle position
    deleteAtPosition(head, tail, middle);
}

// Function to insert at the tail (for test purposes)
void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {  // If the list is empty
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;  // Link the new node
        newNode->prev = tail;  // Link back to the previous tail
        tail = newNode;  // Update the tail to the new node
    }
}

// Function to display the linked list
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

    // Insert nodes for testing
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    cout << "Initial list: ";
    display(head);

    // Delete the head node
    deleteAtHead(head);
    cout << "After deleting the head: ";
    display(head);

    // Delete the tail node
    deleteAtTail(head, tail);
    cout << "After deleting the tail: ";
    display(head);

    // Delete the middle node
    deleteMiddle(head, tail);
    cout << "After deleting the middle node: ";
    display(head);

    return 0;
}
