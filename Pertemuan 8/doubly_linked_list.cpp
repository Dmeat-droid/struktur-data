#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node* next, *prev;
};

Node* createNode(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void insertAtBeginning(Node** head, int data){
  // create new node
  Node *newNode = createNode(data);

  //set as head if the list empty
  if(*head == NULL){
    *head = newNode;
    return;
  }
  newNode->next = *head;
  (*head)->prev = newNode;
  *head = newNode;
}

void insertAtEnd(Node** head, int data){
  // create new node
  Node *newNode = createNode(data);

  // set as head if the list empty
  if(*head == NULL){
    *head = newNode;
    return;
  }

  Node* temp = *head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

// Function to delete a node from the beginning
void deleteAtBeginning(Node** head)
{
    // checking if the list is empty
    if (*head == NULL) {
        printf("List kosong!.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the end
void deleteAtEnd(Node** head)
{
  // checking if the list is empty
  if (*head == NULL) {
    printf("List kosong!.\n");
    return;
  }

  Node* temp = *head;
  if (temp->next == NULL) {
    *head = NULL;
    free(temp);
    return;
  }
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->prev->next = NULL;
  free(temp);
}

// Function to print the list in forward direction
void printListForward(Node* head)
{
  Node* temp = head;
  printf("Forward List: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Function to print the list in reverse direction
void printListReverse(Node* head)
{
  Node* temp = head;
  if (temp == NULL) {
    printf("List kosong.\n");
    return;
  }
  // Move to the end of the list
  while (temp->next != NULL) {
    temp = temp->next;  
  }
  // Traverse backwards
  printf("Reverse List: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}

int main(){
  Node* head = NULL;

  insertAtEnd(&head, 20);
  insertAtEnd(&head, 15);
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 53);

  cout << "After Insertion: \n";
  printListForward(head);
  printListReverse(head);

  deleteAtBeginning(&head);
  deleteAtEnd(&head);

  printf("After deletion:\n");
  printListForward(head);

  return 0;
}