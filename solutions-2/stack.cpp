#include "stack.h"

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
