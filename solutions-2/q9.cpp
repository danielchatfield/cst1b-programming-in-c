#include <stdio.h>
#include "stack.h"

class EmptyStackError{};

template<class T> void Stack<T>::push(T val) {
    this->head = new Item(val, this->head);
}

template<class T> T Stack<T>::pop() {
    if (this->head == NULL) {
        throw EmptyStackError();
    }
    Item *rv = this->head;
    this->head = this->head->next;
    return rv->val;
}

template<class T> Stack<T>::~Stack() {
    Item **pp = &this->head; // take a pointer to the head pointer
    while(*pp) { // while the pointer is still pointing to an item:
        Item &rv = **pp; // take a reference to the current item
        pp = &rv.next; //move pp onto the next one

        // delete current one (not sure whether need to explicitly delete the data)
        delete rv;
    }
}
