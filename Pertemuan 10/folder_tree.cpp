#include <iostream>
#include <vector>

using namespace  std;

class Node {
public:
  string name;
  Node* parent;
  vector<Node *> children;

  Node(string folderName, Node* p = NULL) {
    name = folderName;
    parent = p;
  }
};

class FolderTree {
  private:
    Node* root;

  public:
    FolderTree() {
      root = new Node("root");
    }

    Node* getRoot() {
      return root;
    }

    void addFolder(Node *parent, string folderName) {
      Node *newFolder = new Node(folderName, parent);
      parent->children.push_back(newFolder);
      cout << "Folder '" << folderName << "' added to '" << parent->name << "'." << endl;
    }

    void printTree(Node* node, int level = 0) {
      if(node == NULL) return;

      for(int i = 0; i < level; i++) {
        cout << "|  ";
      }

      if(level > 0) cout << "+--";
      cout << node->name << endl;

      for(Node* child : node->children) {
        printTree(child, level + 1);
      }
    }

    void preorder(Node* node) {
      if (node == NULL) return;

      cout << node->name << endl;

      for (Node* child : node->children) {
        preorder(child);
      }
    }

    void postorder(Node* node) {
      if (node == NULL) return;
      
      for (Node* child: node->children) {
        postorder(child);
      }
      cout << node->name << endl;
    }

    Node* search(Node* node, string target) {
      if(node == NULL) return NULL;

      if (node->name == target) return node;

      for(Node* child : node->children) {
        Node* result = search(child, target);
        if(result != NULL) return result;
      }
      return NULL;
    }

    int countFolder(Node* node) {
      if(node == NULL) return 0;

      int count = 1;
      for(Node* child : node->children) {
        count += countFolder(child);
      }
      return count;
    }

    void showPath (Node* node) {
      if (node == NULL) return;
      
      vector<string> path;
      Node* current = node;
      while (current != NULL) {
        path.push_back(current->name);
        current = current->parent;
      }

      cout << "Path : ";

      for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if(i != 0) cout << "/";
      }
      cout << endl;
    }

    void deleteSubtree(Node* node) {
      if (node == NULL) return;

      for(Node* child : node->children){
        deleteSubtree(child);
      }
    }

    void deleteFolder(string folderName) {
      Node *target = search(root, folderName);
      if(target == NULL) {
        cout << "Folder tidak ditemukan!\n";
        return;
      }

      if(target == root) {
        cout << "Tidak bisa menghapus root!\n";
        return;
      }

      Node* parent = target->parent;

      for (auto it = parent ->children.begin(); it != parent->children.end(); it++) {
        if (*it == target) {
          parent->children.erase(it);
          break;
        }
      }

      // remove subtree
      deleteSubtree(target);

      cout << "Folder berhasil dihapus!\n";
      
    }
 };

int main(){
  FolderTree tree;

  Node *root = tree.getRoot();

  //Making folder structure
  tree.addFolder(root, "Documents");
  tree.addFolder(root, "Pictures");
  tree.addFolder(root, "Music");

  Node* documents = tree.search(root, "Documents");
  
  tree.addFolder(documents, "Kuliah");
  tree.addFolder(documents, "Tugas");

  cout << "folder structure";

  tree.printTree(root);



  return 0;
}