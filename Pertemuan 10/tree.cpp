#include <iostream>
#include <queue>

using namespace std;

struct Node {
  char data;
  Node* left;
  Node* right;

  Node(char val){
    data = val;
    left = right = NULL;
  }
};

void preorder(Node *root){
  if(root == NULL)
    return;
  cout << root ->data << " ";
  preorder(root -> left);
  preorder(root -> right);
}

void inorder(Node *root){
  if(root == NULL)
    return;
  inorder(root -> left);
  cout << root ->data << " ";
  inorder(root -> right);
}

void postorder(Node *root){
  if(root == NULL)
    return;
  postorder(root -> left);
  postorder(root -> right);
  cout << root ->data << " ";
}

void levelOrder(Node *root){
  if(root == NULL)
    return;

  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node *temp = q.front();
    cout << temp ->data << " ";
    q.pop();

    if(temp -> left)
      q.push(temp -> left);
    if(temp -> right)
      q.push(temp -> right);
  }
}

int main(){
  Node *root = new Node('A');
  root -> left = new Node('B');
  root -> right = new Node('C');
  root -> left -> left = new Node('D');
  root -> left -> right = new Node('E');
  root -> right -> left = new Node('F');

  cout << "Preorder: ";
  preorder(root);
  cout << endl;

  cout << "\nInorder: ";
  inorder(root);
  cout << endl;

  cout << "\nPostorder: ";
  postorder(root);
  cout << endl;

  cout << "\nLevel Order: ";
  levelOrder(root);
  cout << endl;

  return 0;
}