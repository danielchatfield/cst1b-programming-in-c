#include <cstdio>

template <class T> class Stack {

    struct Item {
        T val;
        Item* next;
        Item(T v) : val(v), next(0) {}
        Item(T v, Item* n) : val(v), next(n) {}
    };

    Item* head;

    Stack(const Stack& s);
    Stack& operator=(const Stack& s);

public:
    Stack() : head(0) {}
    ~Stack();
    T pop();
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

int main() {
    Stack<char> s;
    s.push('a'), s.append('b'), s.pop();
}

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


template <class T> Stack<T>::Stack(const Stack& s) {

}
