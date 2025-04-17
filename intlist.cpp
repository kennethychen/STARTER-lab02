
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
}

// return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node* curr = head;
    while (curr) {
        total += curr->info;
        curr = curr->next;
    }
    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while (curr) {
        if (curr->info == value)
            return true;
        curr = curr->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
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

// returns average (arithmetic mean) of all values, or 0 if list is empty
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

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = head;
    head = newNode;
}

// append value at end of list
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

// return count of values
int IntList::count() const {
    int cnt = 0;
    Node* curr = head;
    while (curr) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

// Assignment operator should copy the list from the source
// to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source) {
    if (this == &source) return *this;

    // Delete existing nodes
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