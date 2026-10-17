#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createTree() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* n = new Node;
    n->data = x;
    n->left = createTree();
    n->right = createTree();

    return n;
}

void inorder(Node* root, string &s) {
    if (root == NULL) return;

    inorder(root->left, s);
    s += to_string(root->data) + " ";
    inorder(root->right, s);
}

void preorder(Node* root, string &s) {
    if (root == NULL) return;

    s += to_string(root->data) + " ";
    preorder(root->left, s);
    preorder(root->right, s);
}

void mirror(Node* root) {
    if (root == NULL) return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int countNodes(Node* root) {
    if (root == NULL) return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

int height(Node* root) {
    if (root == NULL) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + (l > r ? l : r);
}

int main() {
    cout << "Enter tree in preorder (-1 for NULL):\n";
    Node* root = createTree();

    string originalIn, originalPre;
    inorder(root, originalIn);
    preorder(root, originalPre);

    int nodes = countNodes(root);
    int h = height(root);

    cout << "\nOriginal Inorder: " << originalIn;
    cout << "\nOriginal Preorder: " << originalPre;

    mirror(root);

    string mirrorIn, mirrorPre;
    inorder(root, mirrorIn);
    preorder(root, mirrorPre);

    cout << "\n\nMirrored Inorder: " << mirrorIn;
    cout << "\nMirrored Preorder: " << mirrorPre;

    cout << "\n\nOriginal Nodes: " << nodes;
    cout << "\nMirrored Nodes: " << countNodes(root);
    cout << "\nOriginal Height: " << h;
    cout << "\nMirrored Height: " << height(root);

    mirror(root);

    string restoredIn, restoredPre;
    inorder(root, restoredIn);
    preorder(root, restoredPre);

    cout << "\n\nRestored Inorder: " << restoredIn;
    cout << "\nRestored Preorder: " << restoredPre;

    if (restoredIn == originalIn &&
        restoredPre == originalPre)
        cout << "\nOriginal tree restored successfully.";
    else
        cout << "\nTree restoration failed.";

    return 0;
}
