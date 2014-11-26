#include <stdio.h>

#define SWAP(T,x,y) {T rv = x; x = y; y = rv; }

int main(void) {
    int x = 2;
    int y = 4;

    SWAP(int,x,y);
    printf("X:%d,Y:%d\n",x,y);
}
