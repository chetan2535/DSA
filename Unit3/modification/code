#include <iostream>
using namespace std;

struct Node {
    int roll;
    string name;
    float marks;
    Node *next;
};

Node *head = NULL;

// Insert student record
void insert() {
    Node *n = new Node;

    cout << "Enter roll number, name and marks: ";
    cin >> n->roll >> n->name >> n->marks;
    n->next = NULL;

    if (head == NULL)
        head = n;
    else {
        Node *t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }

    cout << "Record inserted successfully\n";
}

// Display all records
void display() {
    Node *t = head;

    if (t == NULL) {
        cout << "No records found\n";
        return;
    }

    while (t != NULL) {
        cout << "Roll: " << t->roll
             << ", Name: " << t->name
             << ", Marks: " << t->marks << endl;
        t = t->next;
    }
}

// Search student
void search() {
    int r;
    cout << "Enter roll number to search: ";
    cin >> r;

    Node *t = head;
    while (t != NULL) {
        if (t->roll == r) {
            cout << "Student found: " << t->name
                 << ", Marks: " << t->marks << endl;
            return;
        }
        t = t->next;
    }

    cout << "Record not found\n";
}

// Delete student record
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
    cout << "Record deleted successfully\n";
}

// NEW: Update student record
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

    cout << "Record updated successfully\n";
}

// NEW: Sort records by marks (highest first)
void sortMarks() {
    if (head == NULL) {
        cout << "No records found\n";
        return;
    }

    for (Node *i = head; i->next != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (i->marks < j->marks) {
                int r = i->roll;
                i->roll = j->roll;
                j->roll = r;

                string n = i->name;
                i->name = j->name;
                j->name = n;

                float m = i->marks;
                i->marks = j->marks;
                j->marks = m;
            }
        }
    }

    cout << "Records sorted by marks\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Record Management ---\n";
        cout << "1. Insert Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Update Record\n";
        cout << "6. Sort by Marks\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: deleteRecord(); break;
            case 5: update(); break;
            case 6: sortMarks(); break;
            case 7: cout << "Program terminated\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
