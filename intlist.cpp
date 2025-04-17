#include "intlist.h"
#include <iostream>
using std::cout;

// constructor sets up empty list
IntList::IntList() {
    head = nullptr;
}

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    Node* curr = source.head;
    while (curr) {
        push_back(curr->info);
        curr = curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}

// assignment operator
IntList& IntList::operator=(const IntList& source) {
    if (this == &source) return *this;

    // Delete current list
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;

    // Copy nodes from source
    curr = source.head;
    while (curr) {
        push_back(curr->info);
        curr = curr->next;
    }

    return *this;
}

// insert value at front
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = head;
    head = newNode;
}

// append value at end
void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    Node* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = newNode;
}

// count nodes
int IntList::count() const {
    int cnt = 0;
    Node* curr = head;
    while (curr) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

// sum of values
int IntList::sum() const {
    int total = 0;
    Node* curr = head;
    while (curr) {
        total += curr->info;
        curr = curr->next;
    }
    return total;
}

// check for value
bool IntList::contains(int value) const {
    Node* curr = head;
    while (curr) {
        if (curr->info == value)
            return true;
        curr = curr->next;
    }
    return false;
}

// find max value
int IntList::max() const {
    if (!head) return 0;
    int maxVal = head->info;
    Node* curr = head->next;
    while (curr) {
        if (curr->info > maxVal)
            maxVal = curr->info;
        curr = curr->next;
    }
    return maxVal;
}

// compute average
double IntList::average() const {
    if (!head) return 0.0;
    int total = 0, cnt = 0;
    Node* curr = head;
    while (curr) {
        total += curr->info;
        cnt++;
        curr = curr->next;
    }
    return static_cast<double>(total) / cnt;
}

// print values
void IntList::print() const {
    Node* n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}
