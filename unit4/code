#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* createTree() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* root = new Node(x);
    root->left = createTree();
    root->right = createTree();

    return root;
}

void mirror(Node* root) {
    if (root == NULL)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root;

    cout << "Enter nodes (-1 for NULL): ";
    root = createTree();

    cout << "Original tree: ";
    inorder(root);

    mirror(root);

    cout << "\nMirror image: ";
    inorder(root);

    return 0;
}
