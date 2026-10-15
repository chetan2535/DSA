#include <iostream>
using namespace std;

struct Node {
    int roll;
    string name;
    Node *next;
};

Node *head = NULL;

void insert() {
    Node *n = new Node;
    cout << "Enter roll number and name: ";
    cin >> n->roll >> n->name;
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        Node *t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
    cout << "Record inserted\n";
}

void display() {
    Node *t = head;
    if (t == NULL) {
        cout << "No records found\n";
        return;
    }

    while (t != NULL) {
        cout << "Roll: " << t->roll
             << " Name: " << t->name << endl;
        t = t->next;
    }
}

void search() {
    int r;
    cout << "Enter roll number to search: ";
    cin >> r;

    Node *t = head;
    while (t != NULL) {
        if (t->roll == r) {
            cout << "Student found: "
                 << t->name << endl;
            return;
        }
        t = t->next;
    }
    cout << "Record not found\n";
}

void deleteRecord() {
    int r;
    cout << "Enter roll number to delete: ";
    cin >> r;

    Node *t = head, *prev = NULL;

    while (t != NULL && t->roll != r) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        cout << "Record not found\n";
        return;
    }

    if (prev == NULL)
        head = t->next;
    else
        prev->next = t->next;

    delete t;
    cout << "Record deleted\n";
}

int main() {
    int ch;

    do {
        cout << "\n1.Insert 2.Display 3.Search";
        cout << "\n4.Delete 5.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: deleteRecord(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
