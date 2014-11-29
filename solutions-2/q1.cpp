#include <stdio.h>

class LinkedListItem {
public:
    int val;
    LinkedListItem *next;
    LinkedListItem(const int val, LinkedListItem* next=NULL);
};

class IllegalArgumentError {};

LinkedListItem::LinkedListItem(const int val, LinkedListItem* next) {
    if(val < 0) {
        throw IllegalArgumentError();// not sure how to handle this.
    }
    this->val = val;
    this->next = next;
}

class LinkedList {
    LinkedListItem* first;
public:
    LinkedList();
    virtual ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList(const int vals[], const int length);
    LinkedList & operator=(const LinkedList& other);
    int pop();
    void print();
};

LinkedList::LinkedList() {
    this->first = NULL;
}


// Copy constructor
LinkedList::LinkedList(const LinkedList & other) {
    *this = other;
}

LinkedList::LinkedList(const int vals[], int length) {
    LinkedListItem *rv = NULL;
    for (; length > 0; length-- ) {
        rv = new LinkedListItem(vals[length - 1], rv);
    }
    this->first = rv;
}

LinkedList & LinkedList::operator=(const LinkedList & other) {
    LinkedListItem* otherCurrent = other.first;
    LinkedListItem* thisPrevious = NULL;
    while(otherCurrent != NULL) {
        LinkedListItem* thisCurrent = new LinkedListItem(otherCurrent->val, NULL);
        if (thisPrevious == NULL) {
            this->first = thisCurrent;
        } else {
            thisPrevious->next = thisCurrent;
        }

        thisPrevious = thisCurrent;
        otherCurrent = otherCurrent->next;
    }
    return *this;
}

int LinkedList::pop() {
    if(first == NULL) {
        return -1;
    }
    LinkedListItem *rv = this->first;
    this->first = this->first->next;
    return rv->val;
}

void LinkedList::print() {
    LinkedListItem* current = this->first;
    printf("Values {\n");
    while(current != NULL) {
        printf("    %d\n", current->val);
        current = current->next;
    }
    printf("}\n");
}


int main() {
    // Capital letters used in variable names for my sanity
    int test[] = {1,2,3,4,5};
    LinkedList L1(test+1,4), L2(test, 5);
    LinkedList L3 = L2, L4;
    L4 = L1;
    printf("%d %d %d\n", L1.pop(), L3.pop(), L4.pop());

    //outputs 2 1 2
}
