#include<iostream>
using namespace std;

// singly linked list node structure
class Node {
public:
    int data;
    Node* next;

    // constructor to initialize a new node with data
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

int main() {
    
    // Create the first node (head of the list)
    Node* head = new Node(11);
    Node* node2 = new Node(21);
    Node* node3 = new Node(45);
    Node* node4 = new Node(12);

    // Connecting between nodes
    head->next = node2;
    node2->next = node4;
    node3->next = nullptr;
    node4->next = node3;

    // printing linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}