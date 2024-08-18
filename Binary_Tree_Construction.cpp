#include <iostream>
using namespace std;

// Definition of a Node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;

    // Helper function for inserting a new node
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function for in-order traversal
    void inOrder(Node* node) const {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Helper function to delete the tree
    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Public method to insert a new value
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method to perform in-order traversal
    void inOrder() const {
        inOrder(root);
        cout << endl;
    }

    // Public method to delete the tree
    ~BinaryTree() {
        deleteTree(root);
    }
};

int main() {
    BinaryTree tree;

    // Insert values into the tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Perform in-order traversal
    cout << "In-order traversal of the binary tree: ";
    tree.inOrder();

    return 0;
}
