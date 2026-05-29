#include <iostream>

// Definition of the Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    // Helper function for recursive insertion
    Node* insertNode(Node* current, int val) {
        if (current == nullptr) {
            return new Node(val);
        }

        if (val < current->data) {
            current->left = insertNode(current->left, val);
        } else if (val > current->data) {
            current->right = insertNode(current->right, val);
        }
        // Duplicate values are ignored in this standard BST implementation

        return current;
    }

    // Helper function for recursive search
    bool searchNode(Node* current, int val) {
        if (current == nullptr) return false;
        if (current->data == val) return true;

        if (val < current->data) {
            return searchNode(current->left, val);
        } else {
            return searchNode(current->right, val);
        }
    }

    // Depth-First Traversals
    void inOrderTraversal(Node* current) {
        if (current == nullptr) return;
        inOrderTraversal(current->left);
        std::cout << current->data << " ";
        inOrderTraversal(current->right);
    }

    void preOrderTraversal(Node* current) {
        if (current == nullptr) return;
        std::cout << current->data << " ";
        preOrderTraversal(current->left);
        preOrderTraversal(current->right);
    }

    void postOrderTraversal(Node* current) {
        if (current == nullptr) return;
        postOrderTraversal(current->left);
        postOrderTraversal(current->right);
        std::cout << current->data << " ";
    }

    // Helper function to deallocate memory
    void clearTree(Node* current) {
        if (current == nullptr) return;
        clearTree(current->left);
        clearTree(current->right);
        delete current;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        clearTree(root);
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    bool search(int val) {
        return searchNode(root, val);
    }

    void displayInOrder() {
        inOrderTraversal(root);
        std::cout << "\n";
    }

    void displayPreOrder() {
        preOrderTraversal(root);
        std::cout << "\n";
    }

    void displayPostOrder() {
        postOrderTraversal(root);
        std::cout << "\n";
    }
};

int main() {
    BinarySearchTree bst;

    // Simulating a tree structure
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-order Traversal (Sorted): ";
    bst.displayInOrder(); // Output: 20 30 40 50 60 70 80

    std::cout << "Pre-order Traversal: ";
    bst.displayPreOrder(); // Output: 50 30 20 40 70 60 80

    std::cout << "Post-order Traversal: ";
    bst.displayPostOrder(); // Output: 20 40 30 60 80 70 50

    // Search operations
    int target = 40;
    if (bst.search(target)) {
        std::cout << "Key " << target << " found in the tree.\n";
    } else {
        std::cout << "Key " << target << " not found in the tree.\n";
    }

    return 0;
}