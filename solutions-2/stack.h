#include <cstdio>

template <class T> class Stack {

    struct Item {
        T val;
        Item* next;
        Item(T v) : val(v), next(0) {}
        Item(T v, Item* n) : val(v), next(n) {}
    };

    Item* head;


public:
    Stack() : head(0) {}
    ~Stack();
    Stack(const Stack& s);
    Stack& operator=(const Stack& s);
    T pop();
    bool isEmpty();
    void push(T val);
    void append(T val);
};

template<class T> void Stack<T>::append(T val) {
    Item **pp = &head;
    while(*pp) {
        pp = &((*pp)->next);
    }
    *pp = new Item(val);
}

class EmptyStackError{};

template<class T> bool Stack<T>::isEmpty() {
    return this->head == NULL;
}



template<class T> void Stack<T>::push(T val) {
    this->head = new Item(val, this->head);
}

template<class T> T Stack<T>::pop() {
    if (this->head == NULL) {
        throw EmptyStackError();
    }
    Item *rv = this->head;
    T val = rv->val;
    this->head = this->head->next;
    delete rv; //need to cleanup after ourself
    return val;
}

template<class T> Stack<T>::~Stack() {
    Item **pp = &this->head; // take a pointer to the head pointer
    while(*pp) { // while the pointer is still pointing to an item:
        Item *rv = *pp; // take a reference to the current item
        pp = &rv->next; //move pp onto the next one

        // delete current one
        delete rv;
    }
}

template <class T> Stack<T>::Stack(const Stack& s) {
    *this = s;
}

template <class T> Stack<T>& Stack<T>::operator=(const Stack& s) {
    // first do some cleanup - remove current items
    while(!this->isEmpty()) {
        this->pop();
    }

    Item *otherCurrent = s.head;
    Item *thisPrevious = NULL;
    while(otherCurrent) {
        Item *thisCurrent = new Item(otherCurrent->val);

        if (!thisPrevious) {
            this->head = thisCurrent;
        } else {
            thisPrevious->next = thisCurrent;
        }

        thisPrevious = thisCurrent;
        otherCurrent = otherCurrent->next;
    }

    return *this;
}
