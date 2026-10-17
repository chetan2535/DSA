#include <iostream>
#include <string>
using namespace std;

struct Node {
    int roll;
    string name;
    float marks;
    Node *prev, *next;
};

Node *head = NULL, *tail = NULL;

// 1. Insert record
void insert() {
    Node *n = new Node;

    cout << "Enter roll, name and marks: ";
    cin >> n->roll >> n->name >> n->marks;

    n->prev = tail;
    n->next = NULL;

    if (head == NULL)
        head = tail = n;
    else {
        tail->next = n;
        tail = n;
    }

    cout << "Record inserted\n";
}

// 2. Display records forward
void display() {
    Node *t = head;

    if (t == NULL) {
        cout << "No records found\n";
        return;
    }

    while (t != NULL) {
        cout << t->roll << " "
             << t->name << " "
             << t->marks << endl;
        t = t->next;
    }
}

// 3. Search record
void search() {
    int r;
    cout << "Enter roll number: ";
    cin >> r;

    Node *t = head;

    while (t != NULL) {
        if (t->roll == r) {
            cout << "Found: " << t->name
                 << ", Marks: " << t->marks << endl;
            return;
        }
        t = t->next;
    }

    cout << "Record not found\n";
}

// 4. Delete record
void deleteRecord() {
    int r;
    cout << "Enter roll number to delete: ";
    cin >> r;

    Node *t = head;

    while (t != NULL && t->roll != r)
        t = t->next;

    if (t == NULL) {
        cout << "Record not found\n";
        return;
    }

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;
    else
        tail = t->prev;

    delete t;
    cout << "Record deleted\n";
}

// 5. Update record
void update() {
    int r;
    cout << "Enter roll number to update: ";
    cin >> r;

    Node *t = head;

    while (t != NULL && t->roll != r)
        t = t->next;

    if (t == NULL) {
        cout << "Record not found\n";
        return;
    }

    cout << "Enter new name and marks: ";
    cin >> t->name >> t->marks;

    cout << "Record updated\n";
}

// 6. Sort by marks (descending)
void sortMarks() {
    for (Node *i = head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (i->marks < j->marks) {
                swap(i->roll, j->roll);
                swap(i->name, j->name);
                swap(i->marks, j->marks);
            }
        }
    }

    cout << "Records sorted by marks\n";
}

// 7. Display records in reverse
void reverseDisplay() {
    Node *t = tail;

    if (t == NULL) {
        cout << "No records found\n";
        return;
    }

    while (t != NULL) {
        cout << t->roll << " "
             << t->name << " "
             << t->marks << endl;
        t = t->prev;
    }
}

int main() {
    int ch;

    do {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Insert Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Update Record\n";
        cout << "6. Sort by Marks\n";
        cout << "7. Reverse Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: deleteRecord(); break;
            case 5: update(); break;
            case 6: sortMarks(); break;
            case 7: reverseDisplay(); break;
            case 8: cout << "Program terminated\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 8);

    // Free remaining nodes
    while (head != NULL) {
        Node *t = head;
        head = head->next;
        delete t;
    }
    tail = NULL;

    return 0;
}
