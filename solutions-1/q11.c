#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getOperation(const char *str);

typedef struct Stack {
    int arr[100];
    int pos;
} Stack;


void push(Stack*, int);
int pop(Stack*);

int main(int argc, char *argv[]) {
    Stack *stack = malloc(sizeof(Stack));
    memset(stack,0,sizeof(Stack));

    for(int x = 1; x < argc; x++) {
        char* end;
        int val = strtol(argv[x], &end, 10);

        if (!*end) {
            push(stack, val);
        } else {
            char op = getOperation(argv[x]);
            int a;
            int b;
            switch(op) {
                case '+':
                    a = pop(stack);
                    b = pop(stack);
                    push(stack, a + b);
                    break;
                case '-':
                    a = pop(stack);
                    b = pop(stack);
                    push(stack, b - a);
                    break;
                case '/':
                    a = pop(stack);
                    b = pop(stack);
                    push(stack, b / a);
                    break;
                case '*':
                    a = pop(stack);
                    b = pop(stack);
                    push(stack, b * a);
                    break;
                default:
                    fprintf(stderr,"Invalid input\n");
                    exit(1);

            }
        }

    }

    int x = pop(stack);

    printf("%d", x);

    free(stack);

    return 0;
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int isNumber(const char *arr) {
    int i;
    for (i = 0; isDigit(arr[i]); i++) {}

    return (i == 0 || arr[i] != '\0');
}

char getOperation(const char *str) {
    if (strlen(str) != 1) {
        return 'F';
    }

    return str[0];
}

void push(Stack* stack, int val) {
    stack->arr[stack->pos] = val;
    (stack->pos)++;
}

int pop(Stack* stack) {
    if(stack->pos == 0) {
        fprintf(stderr,"Invalid input\n");
        exit(1);
    }
    return stack->arr[--(stack->pos)];
}
