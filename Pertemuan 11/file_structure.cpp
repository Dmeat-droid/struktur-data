#include <iostream>
#include <vector>

using namespace  std;

// Class Node

class Node {
public:
  string name;
  Node* parent;
  vector<Node*> children;

  Node(string folderName, Node* p = NULL) {
    name = folderName;
    parent = p;
  }
};

// class tree
class FolderTree {
private:
  Node* root;

public:
  FolderTree(){
    root = new Node("Root");
  }

  Node* getRoot() {
    return root;
  }

  // Add folder
  void addFolder(Node* parent, string folderName) {
    Node* newFolder = new Node(folderName, parent);
    parent->children.push_back(newFolder);
    
    cout << "Folder '" << folderName << "' added to '" << parent->name << "'." << endl;
  }

  // View Tree
  void printTree(Node* node, int level = 0) {
    if(node == NULL) return;

    for(int i = 0; i < level; i++) {
      cout << "|  ";
    }

    if(level > 0) cout << "+-- ";

    cout << node->name << endl;

    // recursive to its child
    for(Node* child : node->children){
      printTree(child, level +1);
    }
  }

  // Preorder traversal
  void preOrder(Node *node) {
    if(node == NULL) return;

    cout << node->name << endl;

    for (Node* child : node->children) {
      preOrder(child);
    }
  }

  // Postorder traversal
  void postOrder(Node *node) {
    if(node == NULL) return;

    for (Node* child : node->children) {
      postOrder(child);
    }
    cout << node->name << endl;
  }

  // Folder Search
  Node* search(Node* node, string target){
    if(node == NULL) return NULL;

    if(node->name == target) return node;

    for(Node* child : node->children) {
      Node* result = search(child, target);
      if(result != NULL) return result;
    }

    return NULL;
  }

  int countFolder(Node* node){
    if(node == NULL)  return 0;
    
    int total = 1;

    for(Node* child : node->children) {
      total+=countFolder(child);
    }
    return total;
  }

  void showPath(Node* node){
    if(node == NULL) return;

    vector<string> path;

    Node* current = node;

    while(current != NULL){
      path.push_back(current-> name);
      current = current->parent;
    }

    cout << "Path : ";

    for(int i = path.size()-1; i >= 0; i--) {
      cout << path[i];

      if(i!= 0) cout << "/";
    }
    cout << endl; 
  }

  // Delete subtree
  void deleteSubtree(Node* node){
    if(node == NULL)return;

    for(Node* child : node->children) deleteSubtree(child);
    delete node;
  }

  // Delete Folder
  void deleteFolder(string folderName) {
    Node* target = search(root, folderName);

    if(target == NULL) {
      cout << "Folder isn't found!\n";
      return;
    }

    if(target == NULL){
      cout << "Root tidak dapat dihapus!\n";
      return;
    }

    Node* parent = target->parent;

    for(auto it = parent->children.begin(); it != parent->children.end(); it++) {
      if(*it == target) {
        parent->children.erase(it);
        break;
      } 
    }
    deleteSubtree(target);
    cout << "Folder succesfuly deleted!\n";
  }
};

int main(){
  FolderTree tree;

  Node* root = tree.getRoot();

  tree.addFolder(root, "Documents");
  tree.addFolder(root, "Pictures");
  tree.addFolder(root, "Music");

  Node* documents = tree.search(root, "Documents");

  tree.addFolder(documents, "Lectures");
  tree.addFolder(documents, "Task");

  //Show tree
  tree.printTree(root);

  // Traversal
  cout << "=======PreOrder=======\n";
  tree.preOrder(root);
  cout << "=======PreOrder=======\n";
  tree.postOrder(root);

  // Search folder
  cout << "=====Folder Search=====\n";

  Node* result = tree.search(root, "Tugas");
  if(result != NULL){
    cout << "Folder found: " << result->name << endl;
    tree.showPath(result);
  }else{
    cout << "Folder not found!\n";  
  }

  // Folder count
  cout << "=====Total Folder=====\n";
  cout << "Total Folder: " << tree.countFolder(root) << endl;

  // Delete Folder
  tree.deleteFolder("Music");

  cout << "Structure after deleted 'Music'\n";
  tree.printTree(root);

  return 0;
}