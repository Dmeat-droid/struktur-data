#include <iostream>
using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah node di akhir list
void insertEnd(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    
    if (*head == nullptr) {
        *head = newNode;
        newNode->next = *head; // Menunjuk ke dirinya sendiri
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; // Kembali ke head
    }
}

// Fungsi untuk menampilkan list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* temp = head;
    cout << "Isi Circular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(kembali ke head: " << head->data << ")" << endl;
}

int main() {
    Node* head = nullptr;

    // Menambah data
    insertEnd(&head, 43);
    insertEnd(&head, 34);
    insertEnd(&head, 98);
    insertEnd(&head, 88);

    // Menampilkan data
    display(head);

    return 0;
}