

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node* buildTree() {
    int val;
    cout << "Enter data (-1 for NULL): ";
    cin >> val;

    if (val == -1)
        return NULL;

    Node *root = new Node(val);

    cout << "Enter left child of " << val << endl;
    root->left = buildTree();

    cout << "Enter right child of " << val << endl;
    root->right = buildTree();

    return root;
}

void inOrder(Node *root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


void preOrder(Node *root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node *root = buildTree();

    cout << "\nIn-Order Traversal: ";
    inOrder(root);

    cout << "\nPre-Order Traversal: ";
    preOrder(root);

    cout << "\nPost-Order Traversal: ";
    postOrder(root);

    return 0;
}
