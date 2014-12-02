#include <stdio.h>
#include "stack.h"

int main() {
    Stack<char> s;
    s.push('a'), s.append('b'), s.push('c');

    Stack<char> t = s;

    printf("Stack s {\n");
    while(!s.isEmpty()) {
        printf("   %c,\n", s.pop() );
    }
    printf("}\n");

    printf("Stack t {\n");
    while(!t.isEmpty()) {
        printf("   %c,\n", t.pop() );
    }
    printf("}\n");
}
